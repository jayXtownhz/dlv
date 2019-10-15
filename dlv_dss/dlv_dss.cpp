#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winBase.h>
#include <iostream>
#include <tchar.h>
#include <time.h>
#include <io.h>
#include <direct.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dlv_dss.h"

// 大华dss
#include "../include/dh_dss/DPSDK_Core.h"
#include "../include/dh_dss/DPSDK_Core_Define.h"
#include "../include/dh_dss/DPSDK_Core_Error.h"
#include "../include/dh_dss/WideMultiChange.h"
#include "../include/dh_dss/DPSDK_Ext.h"

// redis
#include "../include/acl/acl_cpp/lib_acl.hpp"
#include "../include/acl/lib_acl.h"
using namespace std;

// logger
#include "../logger/Logger.h"
using namespace LOGGER;
CLogger g_log(LogLevel_Info, CLogger::GetAppPathA().append("dss_log\\"));

const LPCWSTR  lpTitle = TEXT("DSS_SERVICE V1.0.190823");
bool g_isExit = false;
int g_nLoginHandle = -1;
HANDLE g_hEvent[DLV_MAX_THREAD];

// 获取console窗口的窗口句柄
HWND GetSelfWindow()
{
	return FindWindow(NULL, lpTitle);
}

// 控制光标显示状态
void SetCursor(bool flag)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);    // 获取控制台光标信息
	CursorInfo.bVisible = flag;                   // 隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);    // 设置控制台光标状态
}

// 校验IP是否合法
int check_ip(char* ip)
{
	char s[256] = { 0 };
	int a = -1, b = -1, c = -1, d = -1;

	sscanf_s(ip, "%d.%d.%d.%d%s", &a, &b, &c, &d, s);
	if (a>255 || a<0 || b>255 || b<0 || c>255 || c<0 || d>255 || d<0)
		return -1;
	if (s[0] != 0)
		return -1;

	return 0;
}

// 创建文件夹
bool MakeDir(const char* fileName)
{
	const char* tag;
	char buf[256] = { 0 };
	char path[256] = { 0 };

	for (tag = fileName; *tag; tag++)
	{
		if (*tag == '\\')
		{
			strcpy_s(buf, fileName);
			buf[strlen(fileName) - strlen(tag) + 1] = NULL;
			strcpy_s(path, buf);

			if (_access(path, 6) == -1)
				if (_mkdir(path) == -1)
					return false;
		}
	}

	return true;
}

string TcharToChar(TCHAR * tchar)
{
	string sz;

	for (TCHAR * s = tchar; *s; s += _tcslen(s) + 1)
	{
		char * _char = new char[100];
		int iLength;

		// 获取字节长度    
		iLength = WideCharToMultiByte(CP_ACP, 0, s, -1, NULL, 0, NULL, NULL);
		// 将tchar值赋给_char      
		WideCharToMultiByte(CP_ACP, 0, s, -1, _char, iLength, NULL, NULL);
		string t(_char);
		sz.append(t);

		delete[] _char;
	}

	return sz;
}

string getDriveStrings()
{
	TCHAR szBuf[100];
	memset(szBuf, 0, 100);

	DWORD len = GetLogicalDriveStrings(sizeof(szBuf) / sizeof(TCHAR), szBuf);
	string s = TcharToChar(szBuf);

	return s;
}

int checkDrive(string drives, string userPath)
{
	int position;
	char driveTag = userPath.at(0);

	if (driveTag > 'a' && driveTag < 'z')
		driveTag -= 32;

	if ((driveTag > 'A' && driveTag<'Z') || (driveTag>'a' && driveTag < 'z'))
	{
		position = (int)drives.find(driveTag);
		if (position == drives.npos)        // 输入的盘符不存在
			return -1;
	}
	else                                    // 非法盘符
		return -2;

	return 0;
}

bool checkUserPath(string userPath)
{
	bool isRight = true;
	string::iterator it;

	for (it = userPath.begin(); it != userPath.end(); ++it)
	{
		if (*it == '/')
		{
			isRight = false;
			break;
		}
	}

	return isRight;
}

int check_path(const char* userPath)
{
	string drives = getDriveStrings();
	int ret = checkDrive(drives, userPath);

	if (ret != 0)
		return ret;

	if (checkUserPath(userPath) == false)
		return -3;

	return 0;
}

// 字符串格式时间转time
time_t StringToTime(const char* szTime)
{
	const char* cha = szTime;
	tm tm_;
	int year, month, day, hour, minute, second;

	sscanf_s(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
	tm_.tm_year = year - 1900;    // 年，由于tm结构体存储的是从1900年开始的时间，所以tm_year为int临时变量减去1900
	tm_.tm_mon = month - 1;       // 月，由于tm结构体的月份存储范围为0-11，所以tm_mon为int临时变量减去1
	tm_.tm_mday = day;
	tm_.tm_hour = hour;
	tm_.tm_min = minute;
	tm_.tm_sec = second;
	tm_.tm_isdst = 0;             // 非夏令时

	time_t t_ = mktime(&tm_);     // 将tm结构体转换成time_t格式
	return t_;
}

// DSS录像下载完成回调
int32_t DPSDK_CALLTYPE fnDownloadFinishedCallback(IN int32_t nPDLLHandle, IN int32_t nDownloadSeq, IN void *pUserParam)
{
	SetEvent((HANDLE)pUserParam);

	return 1;
}
// DSS录像下载进度回调
int32_t DPSDK_CALLTYPE fnDownloadProgressCallback(IN int32_t nPDLLHandle, IN int32_t nDownloadSeq, IN int32_t nPos, IN void *pUserParam)
{
	return 0;
}

// redis
// 验证密码
bool redis_auth(acl::redis_connection& redis, const char* szpwd)
{
	acl::string passwd(szpwd);

	redis.clear();
	if (redis.auth(passwd.c_str()) == false)
		return false;

	return true;
}

bool redis_select(acl::redis_connection& redis, int n)
{
	redis.clear();
	if (redis.select(n) == false)
		return false;

	return true;
}

bool redis_hmget(acl::redis_hash& redis, const char* key_ipc, DLV_DSS_IPC& dlv_dss)
{
	acl::string key(key_ipc);
	acl::string attr0, attr1, attr2, attr3;
	const char* attrs[4];
	std::vector<acl::string> result;

	attr0.format("ip");
	attr1.format("chan");
	attr2.format("region");
	attr3.format("devcode");
	attrs[0] = attr0.c_str();
	attrs[1] = attr1.c_str();
	attrs[2] = attr2.c_str();
	attrs[3] = attr3.c_str();

	result.clear();
	redis.clear();
	if (redis.hmget(key, attrs, 4, &result) == false)
		return false;

	if (redis.result_value(0) == NULL)
		return false;

	memcpy(dlv_dss.szIpcIp, redis.result_value(0), sizeof(dlv_dss.szIpcIp));
	memcpy(dlv_dss.szChan, redis.result_value(1), sizeof(dlv_dss.szChan));
	memcpy(dlv_dss.szRegion, redis.result_value(2), sizeof(dlv_dss.szRegion));
	memcpy(dlv_dss.szDevCode, redis.result_value(3), sizeof(dlv_dss.szDevCode));

	return true;
}

bool redis_rpop(acl::redis_list &redis, const char* key_rec, char* szTime, size_t size)
{
	int ret;
	acl::string buf, __key(key_rec);

	redis.clear();
	buf.clear();
	ret = redis.rpop(__key, buf);
	if (ret <= 0)
		return false;

	memcpy(szTime, buf.c_str(), size);

	return true;
}
// redis

unsigned int __stdcall ThreadFun(PVOID pM)
{
	DLV_THREAD_PARAM* pParam = (DLV_THREAD_PARAM*)pM;

	int conn_timeout = 10, rw_timeout = 10;
	bool cluster_mode = false;
	bool slice_req = false;
	acl::string addr(pParam->szRedisIpAddr), err;

	acl::acl_cpp_init();
	acl::log::stdout_open(false);
	acl::redis_client client(addr.c_str(), conn_timeout, rw_timeout);
	client.set_slice_request(slice_req);
	acl::redis_connection redis_con(&client);
	err = redis_con.result_error();

	if (err != "操作成功完成。")
	{
		printf_s("->> channel[%-2d], redis连接错误: [%s], [请输入(E)退出程序, 重新尝试].\n", pParam->nQueue, err.c_str());
		return 0;
	}
	else
		printf_s("--> channel[%-2d], redis连接: [%s].\n", pParam->nQueue, err.c_str());

	if (redis_auth(redis_con, pParam->szRedisPwd) == false)
	{
		printf_s("->> channel[%-2d], redis密码验证出错. [请输入(E)退出程序, 重新尝试].\n", pParam->nQueue);
		return 0;
	}
	else
		printf_s("--> channel[%-2d], redis密码验证成功.\n", pParam->nQueue);

	if (redis_select(redis_con, pParam->nRedisDB) == false)
	{
		printf_s("->> channel[%-2d], redis选择数据库[%d]出错. [请输入(E)退出程序, 重新尝试].\n", pParam->nQueue, pParam->nRedisDB);
		return 0;
	}
	else
		printf_s("--> channel[%-2d], redis选择数据库[%d]成功.\n", pParam->nQueue, pParam->nRedisDB);

	DLV_DSS_IPC dlv_dss[DLV_MAX_IPC];
	acl::string key_ipc, key_rec;
	acl::string __key_ipc("dss");
	acl::string __key_rec("rec");
	acl::redis_hash redis_h;
	key_rec.format("%s_%d", __key_rec.c_str(), pParam->nQueue);

	redis_h.set_client(&client);
	for (int i = 0; i < DLV_MAX_IPC; i++)
	{
		// 初始化结构体
		memcpy_s(dlv_dss[i].szIpcIp, sizeof(dlv_dss[i].szIpcIp), "", sizeof(dlv_dss[i].szIpcIp));
		memcpy_s(dlv_dss[i].szChan, sizeof(dlv_dss[i].szChan), "", sizeof(dlv_dss[i].szChan));
		memcpy_s(dlv_dss[i].szRegion, sizeof(dlv_dss[i].szRegion), "", sizeof(dlv_dss[i].szRegion));
		memcpy_s(dlv_dss[i].szDevCode, sizeof(dlv_dss[i].szDevCode), "", sizeof(dlv_dss[i].szDevCode));

		// 获取IPC登录信息
		key_ipc.format("%s_%d_%d", __key_ipc.c_str(), pParam->nQueue, i);
		if (redis_hmget(redis_h, key_ipc.c_str(), dlv_dss[i]) == false)
		{
			printf_s("--> channel[%-2d], 可配置IPC通道[%d]台, 已配置[%d]台.\n", pParam->nQueue, DLV_MAX_IPC, i);
			break;
		}
	}

	char* p = NULL;
	char* ptr = NULL;
	char szIp[32] = "";
	char szRec[64] = "";
	char szRecTime[32] = "";
	char szFilePath[256] = "";
	int nQueue = -1;
	int nRet = -1;
	int nDownloadSeq = -1;	
	int nY, nM, nD, nH, nMin, nS;
	time_t tt_start, tt_cur;
	time_t tt;
	uint64_t tt_s, tt_e;

	DPSDK_SetDownloadFinishedCallback(g_nLoginHandle, fnDownloadFinishedCallback, (void*)g_hEvent[pParam->nQueue]);

	// 从redis消息队列中获取记录, 下载视频
	acl::redis_list redis_li(&client);
	for (;;)
	{
		if (g_isExit == true)
		{
			printf_s("--> channel[%-2d], 收到退出指令, 正在退出...\n", pParam->nQueue);
			break;
		}

		if (redis_rpop(redis_li, key_rec.c_str(), szRec, sizeof(szRec)) == false)        // 获取list中记录
		{
			err = redis_li.result_error();        // 检测redis是否断连
			if (err == "NOAUTH Authentication required.")
			{
				redis_auth(redis_con, pParam->szRedisPwd);
				redis_select(redis_con, pParam->nRedisDB);
				printf_s("--> channel[%-2d], redis_rpop重新验证密码成功.\n", pParam->nQueue);

				err = redis_li.result_error();
			}
			if (err != "操作成功完成。")
				printf_s("->> channel[%-2d], redis_rpop错误: [%s]\n", pParam->nQueue, err.c_str());

			Sleep(DLV_EMPTY_WAIT);
			continue;
		}
		else
			printf_s("--> channel[%-2d], redis_rpop下载记录[%s], 开始下载...\n", pParam->nQueue, szRec);

		p = NULL;
		ptr = NULL;
		ptr = strtok_s(szRec, ",", &p);
		if (ptr != NULL)
			memcpy(szIp, ptr, sizeof(szIp));
		else
			continue;
		ptr = strtok_s(NULL, ",", &p);
		if (ptr != NULL)
			memcpy(szRecTime, ptr, sizeof(szRecTime));
		else
			continue;

		// 匹配下载记录中对应的IPC
		nQueue = -1;
		for (int i = 0; i < DLV_MAX_IPC; i++)
		{
			if (strcmp(dlv_dss[i].szIpcIp, szIp) == 0)
			{
				nQueue = i;
				break;
			}
		}
		if (nQueue == -1)
			continue;

		// 解析时间
		tt = StringToTime(szRecTime);
		tt_s = tt - 5;
		tt_e = tt + 10;
		// 生成路径
		sscanf_s(szRecTime, "%d-%d-%d %d:%d:%d", &nY, &nM, &nD, &nH, &nMin, &nS);
		if (pParam->szFilePath[strlen(pParam->szFilePath) - 1] == '\\')
			sprintf_s(szFilePath, sizeof(szFilePath), "%s%s\\%s\\%04d%02d%02d\\%04d%02d%02d%02d%02d%02d.mp4",
			pParam->szFilePath, dlv_dss[nQueue].szRegion, dlv_dss[nQueue].szDevCode, nY, nM, nD, nY, nM, nD, nH, nMin, nS);
		else
			sprintf_s(szFilePath, sizeof(szFilePath), "%s\\%s\\%s\\%04d%02d%02d\\%04d%02d%02d%02d%02d%02d.mp4",
			pParam->szFilePath, dlv_dss[nQueue].szRegion, dlv_dss[nQueue].szDevCode, nY, nM, nD, nY, nM, nD, nH, nMin, nS);

		if (MakeDir(szFilePath) == false)
		{
			printf_s("->> channel[%-2d], 无法创建下载路径[%s].\n", pParam->nQueue, szFilePath);
			// 输出log
			g_log.TraceError("非法路径. lpush rec_%d \"%s,%s\"\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szRecTime);
			continue;
		}

		// 下载视频
		time(&tt_start);
		nDownloadSeq = -1;
		nRet = DPSDK_DownloadRecordByTimeEx(g_nLoginHandle, nDownloadSeq, dlv_dss[nQueue].szChan, (dpsdk_recsource_type_e)2, tt_s, tt_e, szFilePath, 3);
		if (nRet != 0)
		{
			printf_s("->> channel[%-2d], IPC[%s], 下载视频[%s]失败, 错误代码[%d].\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szFilePath, nRet);
			// 输出log
			g_log.TraceError("下载失败. lpush rec_%d \"%s,%s\"\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szRecTime);
		}
		else
		{
			if (WaitForSingleObject(g_hEvent[pParam->nQueue], DLV_MAX_WAITEVENT) == WAIT_OBJECT_0)
			{
				time(&tt_cur);
				ResetEvent(g_hEvent[pParam->nQueue]);
				printf_s("--> channel[%-2d], IPC[%s], 下载视频[%s]成功, 耗时[%lld]秒.\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szFilePath, tt_cur - tt_start);
			}
			else
			{
				printf_s("->> channel[%-2d], IPC[%s], 下载视频[%s]超时, 错误代码[%d].\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szFilePath, nRet);
				// 输出log
				g_log.TraceError("下载超时. lpush rec_%d \"%s,%s\"\n", pParam->nQueue, dlv_dss[nQueue].szIpcIp, szRecTime);
			}
		}
		// 下载视频
	}

	return 1;
}

int main(int argc, char* argv[])
{
	SetConsoleTitle(lpTitle);

	int nDB = 0;
	int nPort = 0;
	size_t size = 0;
	char szRip[64] = { 0 };
	char szRport[8] = { 0 };
	char szRpwd[32] = { 0 };
	char szRdb[8] = { 0 };

	getenv_s(&size, szRip, sizeof(szRip), "redis_ip");
	if (size == 0)
	{
		printf_s("<-- 请输入redis的ip地址:\n");
		for (;;)
		{
			scanf_s("%s", szRip, (unsigned int)sizeof(szRip));
			scanf_s("%*[^\n]");
			if (check_ip(szRip) == 0)
				break;
			else
				printf_s("->> ip格式错误. 请输入redis的ip地址:\n");
		}
	}

	getenv_s(&size, szRport, sizeof(szRport), "redis_port");
	if (size == 0)
	{
		printf_s("<-- 请输入redis的端口号:\n");
		for (;;)
		{
			scanf_s("%d", &nPort);
			scanf_s("%*[^\n]");
			if (nPort <= 0 || nPort > 65535)
				printf_s("->> 端口值错误. 请输入redis的端口号:\n");
			else
				break;
		}
		// 组成acl调用字符串
		sprintf_s(szRip, sizeof(szRip), "%s:%d", szRip, nPort);
	}
	else
		sprintf_s(szRip, sizeof(szRip), "%s:%s", szRip, szRport);

	getenv_s(&size, szRpwd, sizeof(szRpwd), "redis_pwd");
	if (size == 0)
	{
		printf_s("<-- 请输入redis的验证密码(1~32个字符):\n");
		for (;;)
		{
			scanf_s("%s", szRpwd, (unsigned int)sizeof(szRpwd));
			scanf_s("%*[^\n]");
			if (strlen(szRpwd) == 0)
				printf_s("->> 密码长度错误. 请输入redis的验证密码(1~32个字符):\n");
			else
				break;
		}
	}

	getenv_s(&size, szRdb, sizeof(szRdb), "redis_db");
	if (size == 0)
	{
		printf_s("<-- 请输入redis的数据库编号(0~15):\n");
		for (;;)
		{
			int ret = scanf_s("%d", &nDB);
			scanf_s("%*[^\n]");
			if (ret == 0 || nDB > 15 || nDB < 0)
				printf_s("->> 数据库编号错误. 请输入redis的数据库编号(0~15):\n");
			else
				break;
		}
	}
	else
		nDB = atoi(szRdb);

	int nDport = 0;
	int nDchan = 0;
	char szDip[64] = { 0 };
	char szDport[8] = { 0 };
	char szDuser[32] = { 0 };
	char szDpwd[32] = { 0 };
	char szDchan[8] = { 0 };

	getenv_s(&size, szDip, sizeof(szDip), "dss_ip");
	if (size == 0)
	{
		printf_s("<-- 请输入7016服务器的ip地址:\n");
		for (;;)
		{
			scanf_s("%s", szDip, (unsigned int)sizeof(szDip));
			scanf_s("%*[^\n]");
			if (check_ip(szDip) == 0)
				break;
			else
				printf_s("->> ip格式错误. 请输入7016服务器的ip地址:\n");
		}
	}

	getenv_s(&size, szDport, sizeof(szDport), "dss_port");
	if (size == 0)
	{
		printf_s("<-- 请输入7016服务器的端口号:\n");
		for (;;)
		{
			scanf_s("%d", &nDport);
			scanf_s("%*[^\n]");
			if (nDport <= 0 || nDport > 65535)
				printf_s("->> 端口值错误. 请输入7016服务器的端口号:\n");
			else
				break;
		}
	}
	else
		nDport = atoi(szDport);

	getenv_s(&size, szDuser, sizeof(szDuser), "dss_user");
	if (size == 0)
	{
		printf_s("<-- 请输入7016服务器登录用户名:\n");
		for (;;)
		{
			scanf_s("%s", szDuser, (unsigned int)sizeof(szDuser));
			scanf_s("%*[^\n]");
			if (strlen(szDuser) == 0)
				printf_s("->> 用户名不能超过32个字符. 请输入7016服务器登录密码:\n");
			else
				break;
		}
	}

	getenv_s(&size, szDpwd, sizeof(szDpwd), "dss_pwd");
	if (size == 0)
	{
		printf_s("<-- 请输入7016服务器登录密码:\n");
		for (;;)
		{
			scanf_s("%s", szDpwd, (unsigned int)sizeof(szDpwd));
			scanf_s("%*[^\n]");
			if (strlen(szDpwd) == 0)
				printf_s("->> 密码不能超过32个字符. 请输入7016服务器登录密码:\n");
			else
				break;
		}
	}

	getenv_s(&size, szDchan, sizeof(szDchan), "dss_chan");
	if (size == 0)
	{
		printf_s("<-- 请输入需要从7016服务器下载视频的IPC总通道数:\n");
		for (;;)
		{
			scanf_s("%d", &nDchan);
			scanf_s("%*[^\n]");
			if (nDchan <= 0 || nDchan > 400)
				printf_s("->> 总通道数不能超过400. 请输入需要从7016服务器下载视频的IPC总通道数:\n");
			else
				break;
		}
	}
	else
		nDchan = atoi(szDchan);

	char szVideoPath[64] = { 0 };
	getenv_s(&size, szVideoPath, sizeof(szVideoPath), "video_path");
	if (size == 0)
	{
		printf_s("<-- 请输入录像文件存储根目录路径(1~64字符):\n");
		for (;;)
		{
			scanf_s("%s", szVideoPath, (unsigned int)sizeof(szVideoPath));
			scanf_s("%*[^\n]");
			int ret = check_path(szVideoPath);
			if (ret == -1)
				printf_s("->> 盘符不存在. 请输入录像文件存储根目录路径(1~64字符):\n");
			else if (ret == -2)
				printf_s("->> 非法盘符. 请输入录像文件存储根目录路径(1~64字符):\n");
			else if (ret == -3)
				printf_s("->> 非法路径字符. 请输入录像文件存储根目录路径(1~64字符):\n");
			else
			{
				if (strlen(szVideoPath) == 1)
					sprintf_s(szVideoPath, sizeof(szVideoPath), "%s:", szVideoPath);
				break;
			}
		}
	}

	printf_s("--> [DSS_SERVICE]:[%s]服务正在启动...\n", szDip);
	printf_s("--> 退出程序请输入(E)\n");

	int nRet = -1;
	// 初始化SDK资源
	nRet = DPSDK_Create(DPSDK_CORE_SDK_SERVER, g_nLoginHandle);
	if (nRet != DPSDK_RET_SUCCESS)
	{
		printf_s("->> 初始化DSS组件失败, 错误代码[%d].\n", nRet);
		system("pause");
		return nRet;
	}

	Login_Info_t stuLoginInfo = { 0 };
	strcpy_s(stuLoginInfo.szIp, sizeof(stuLoginInfo.szIp), szDip);
	stuLoginInfo.nPort = nDport;
	strcpy_s(stuLoginInfo.szUsername, sizeof(stuLoginInfo.szUsername), szDuser);
	strcpy_s(stuLoginInfo.szPassword, sizeof(stuLoginInfo.szPassword), szDpwd);
	stuLoginInfo.nProtocol = DPSDK_PROTOCOL_VERSION_II;
	stuLoginInfo.iType = 1;

	nRet = DPSDK_Login(g_nLoginHandle, &stuLoginInfo);
	if (nRet != 0)
	{
		DPSDK_Destroy(g_nLoginHandle);
		printf_s("->> 登录7016服务器失败, 错误代码[%d].\n", nRet);
		system("pause");
		return nRet;
	}
	else
		printf_s("--> 登录7016服务器成功, handle[%d].\n", g_nLoginHandle);

	HANDLE handle[DLV_MAX_THREAD];
	DLV_THREAD_PARAM param[DLV_MAX_THREAD];
	int nThread = nDchan / 20 + 1;
	for (int i = 0; i < nThread; i++)
	{
		g_hEvent[i] = CreateEvent(NULL, TRUE, FALSE, NULL);

		memcpy(param[i].szRedisIpAddr, szRip, sizeof(param[i].szRedisIpAddr));
		memcpy(param[i].szRedisPwd, szRpwd, sizeof(param[i].szRedisPwd));
		memcpy(param[i].szFilePath, szVideoPath, sizeof(param[i].szFilePath));
		param[i].nRedisDB = nDB;
		param[i].nQueue = i;

		handle[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, &param[i], 0, NULL);
	}

	char cmd = 0;
	time_t tt_start;
	time(&tt_start);
	for (;;)
	{
		cmd = getchar();
		if (cmd == 'e' || cmd == 'E')
		{
			printf_s("--> [DSS_SERVICE]:[%s]服务正在退出...\n", szDip);
			g_isExit = true;
			break;
		}
		else if (cmd == 't' || cmd == 'T')
		{
			time_t tt_cur;
			time(&tt_cur);

			tt_cur = tt_cur - tt_start;
			printf_s("--> 程序已正常运行[%lld]小时[%lld]分[%lld]秒.\n", tt_cur / 3600, (tt_cur % 3600) / 60, tt_cur % 3600 % 60);
		}
	}

	// 等待所有线程结束
	WaitForMultipleObjects(nThread, handle, true, INFINITE);
	// 清理线程资源
	for (int i = 0; i < nThread; i++)
	{
		if (handle[i] != 0)
		    CloseHandle(handle[i]);
		if (g_hEvent[i] != 0)
		    CloseHandle(g_hEvent[i]);
	}

	// 清理SDK资源
	DPSDK_Logout(g_nLoginHandle);
	DPSDK_Destroy(g_nLoginHandle);

	return 0;
}