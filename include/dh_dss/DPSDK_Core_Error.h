#ifndef INCLUDED_DPSDK_CORE_ERROR_H
#define INCLUDED_DPSDK_CORE_ERROR_H

#include "DPSDK_Core_Define.h"

#define CFL_ERROR_SUCCESS						200						// 成功错误码值
#define CLIENT_ERROR_BASE						420						// 客户端错误码值
#define SERVER_ERROR_BASE						520						// 服务错误码值
#define DSS_ERROR_BASE							720						// 基本错误码值
#define DSS_ERROR_CODE_BASE						1000000					// 服务错误码起始
#define DSS_DMS_BASE							1000					// DMS 错误码起始
#define DSS_VMS_BASE							2000					// VMS 错误码起始
#define DSS_RTSP_BASE							3000					// RTSP 错误码起始
#define DSS_ALARM_BASE							4000					// ALARM 错误码起始
#define DSS_MS_BASE								5000					// MS 错误码起始
#define DSS_PCS_BASE							6000					// PCS 错误码起始
#define DSS_FMS_BASE							7000					// FMS 错误码起始
#define DSS_ANA_BASE							8000					// ANA 错误码起始
#define PSS_ERROR_CODE_BASE						1050000

//消息错误码
typedef enum
{
	//<0 同步返回错误
	DPSDK_RET_SYNC_FAIL                     = -1,

	DPSDK_RET_SUCCESS                       = 0,			// 成功																   
	DPSDK_RET_SERIALIZE_PDU_FAILED          = 1,			// 协议解析失败
	DPSDK_RET_SENDDATA_FAILED               = 2,			// 数据发送失败
	DPSDK_RET_NET_CONNECT_FAILED            = 3,			// 连接远端失败
	DPSDK_RET_ALREADY_LOGIN                 = 4,			// 登录已存在
	DPSDK_RET_ALREADY_LOGOUT                = 5,			// 已登出
	DPSDK_RET_SERIALIZE_XML_FAILED          = 6,			// Xml解析失败
	DPSDK_RET_NODE_NO_RIGHT                 = 7,			// 无操作权限	
	DPSDK_RET_UNKNOW_DEVICE                 = 8,			// 未知设备
	DPSDK_RET_UNKNOW_CHANNEL                = 9,			// 未知通道
	DPSDK_RET_DEVICE_OFFLINE                = 10,			// 设备离线
	DPSDK_RET_RTSP_CONNECT_FAILED           = 11,			// rtsp连接失败
	DPSDK_RET_RTP_LISTEN_FAILED             = 12,			// rtp监听失败
	DPSDK_RET_RTP_CONNECT_FAILED            = 13,			// rtp连接失败
	DPSDK_RET_PARSE_TRANSPORT_FAILED        = 14,			// rtsp解析端口失败
	DPSDK_RET_ALREADY_CANCELED              = 15,			// 命令已被取消
	DPSDK_RET_UNKNOWN_SESSION               = 16,			// 无效的session fixme:检查已有情况统一为此应答
	//talk相关									   
	DPSDK_RET_TALK_INNVALIDPARAM            = 17,			// 对讲参数有误
	DPSDK_RET_TALK_NOT_SUPPORT              = 18,			// 对讲不支持									   
	DPSDK_RET_DMSSESSION_NOT_FOUND          = 19,			// 没找到对应的dmsSession
	//alarm相关									   
	DPSDK_RET_ADSSESSION_NOT_FOUND          = 20,			// 未找到ADS
	DPSDK_RET_ADSSESSION_NOT_LOGIN          = 21,			// 未登录成功ADS
	DPSDK_RET_DATABASE_NO_RECORD            = 22,			// 没有找到ALARM相关记录
	DPSDK_RET_ALARMTYPE_NOT_MATCH           = 23,			// 报警类型不匹配
	//回放										   
	DPSDK_RET_PLAYBACK_SESSION_NOT_FOUND    = 24,			// 无法找到回放会话
	DPSDK_RET_PLAYBACK_UNKNOW_PLAYTYPE      = 25,			// 无法区分播放类型
	DPSDK_RET_PLAYBACK_NETSDK_SEEK_FAIL     = 26,			// 网络SDK的seek命令失败
	DPSDK_RET_PLAYBACK_SEEK_SIZE_ERROR      = 27,			// 回放定位的size错误
	DPSDK_RET_PLAYBACK_SEEK_TIME_ERROR      = 28,			// 回放定位的时间错误
	DPSDK_RET_PLAYBACK_DEVICE_NOT_FOUND     = 29,			// 回放时没有找到想要的设备
	DPSDK_RET_PLAYBACK_PLAY_REPEAT          = 30,			// 该通道只允许回放一路
	DPSDK_RET_INVALID_CONFIGTYPE            = 31,			// 该配置信息的类型不支持
	DPSDK_RET_UNSUPPORTED_STREAM            = 32,			// 该码流类型不支持
	DPSDK_RET_PLAYBACK_NOTFIND_DEV          = 33,			// 设备信息未找到
	DPSDK_RET_PLAYBACK_PARAM                = 34,			// 回放参数错误
	DPSDK_RET_PLAYBACK_PARAM_CAMERA         = 35,			// 回放未知摄像头
	DPSDK_RET_FTPSERVER_NOT_FIND            = 36,			// FTP服务器没找到
	DPSDK_RET_FTPCURL_ERROR                 = 37,			// 调用curl返回错误
	DPSDK_RET_FTPCURL_LOCALFILE_NOT_OPEN    = 38,			// 调用curl返回未找到本地文件
	DPSDK_RET_FTPCURL_LOCALFILE_NOT_READ    = 39,			// 调用curl返回打开本地文件出错
	DPSDK_RET_FTPCURL_FTPFILE_ERROR         = 40,			// 调用curl返回操作远程文件出错
	DPSDK_RET_FTPCURL_FREE_ERROR            = 41,			// 调用curl返回释放出错
	DPSDK_RET_PCS_ERROR                     = 42,           // PCS发生错误
	DPSDK_RET_PES_ERROR                     = 43,           // PES发生错误
	DPSDK_RET_PES_NOT_LOGIN                 = 44,			// 未登陆到PES
	DPSDK_RET_PES_ENCODE_AHSOTCMD_FAILED    = 45,			// 报警主机命令组包失败
	DPSDK_RET_PES_ENCODE_DCTRL_FAILED       = 46,           // 门禁命令组包失败
	DPSDK_RET_PES_ENCODE_PGRID_FAILED       = 47,           // 电网命令组包失败

	DPSDK_RET_CHANNEL_EMPTY                 = 48,			// 通道号为空
	DPSDK_RET_MSG_EMPTY                     = 49,			// 处理消息为空
	DPSDK_RET_MSG_INVALID_CMD               = 50,			// 未定义的消息操作
	DPSDK_RET_DECODE_PDU_FAILED             = 51,			// 协议解析失败
	DPSDK_RET_SENDDATA_EMPTY                = 52,			// 发送数据为空
	DPSDK_RET_PESSESSION_NOT_FOUND          = 53,			// 没找到对应的pesSession
	DPSDK_RET_ALARMREPORT_NEW_FAILED        = 54,			// 报警消息中内存申请失败
	DPSDK_RET_PCS_NOT_LOGIN                 = 55,			// 未登陆到PCS
	DPSDK_RET_RTSPMDL_NOT_FIND              = 56,			// 没找到对应的RTSPMDL
	DPSDK_RET_RTSPMSG_INVALID_CMD           = 57,			// 未定义的RTSP消息操作
	DPSDK_RET_LOAD_XML                      = 58,			// 解析Xml失败

	//配置模块ex
	DPSDK_RET_CONFIGEX_LOGIN_FAIL           = 59,			// 设备登陆失败
	DPSDK_RET_CONFIGEX_LOGINOUT_FAIL        = 60,			// 设备登出失败

	//返回netsdk的错误
	DPSDK_RET_NETSDK_ERROR                         = 61,
	DPSDK_RET_DEVCONFIG_STRUCT_UNABLE_OPERATOR     = 62,	// 该结构不支持该操作
	DPSDK_RET_LOCAL_INVALID_USERNAME               = 63,    // 无效的本地用户名
	DPSDK_RET_LOCAL_INVALID_PASSWORD               = 64,    // 无效的本地密码

	//服务返回错误未定义
	DPSDK_RET_CMS_RET_ERROR                 = 65,			// CMS 返回错误
	DPSDK_RET_DMS_RET_ERROR                 = 66,			// DMS 返回错误
	DPSDK_RET_PCS_RET_ERROR                 = 67,			// PCS 返回错误
	DPSDK_RET_RTSP_RET_ERROR                = 68,			// RTSP 返回错误

	DPSDK_RET_CMS_ERR_NOT_FOUND             = 69,			// CMS 返回错误 -- 未找到

	DPSDK_RET_RTSP_DISCONNECTED             = 70,           // RTSP链接断开
	
	DPSDK_CORE_BEGIN                        = 1000,
	DPSDK_CORE_ERROR_NOT_SUPPORT,				// 不支持
	DPSDK_CORE_ERROR_GET_MEMORY_FAIL,			// 获取内存失败
	DPSDK_CORE_ERROR_WITHOUT_CREATE,			// 没有创建
	DPSDK_CORE_ERROR_CREATE_FAIL,				// 创建失败
	DPSDK_CORE_ERROR_INIT_FAIL,					// 初始化失败
	DPSDK_CORE_ERROR_UINIT_FAIL,				// 反初始化失败
	DPSDK_CORE_ERROR_WITHOUT_INIT,				// 没有初始化
	DPSDK_CORE_ERROR_INVALID_HANDLE,			// 无效的句柄
	DPSDK_CORE_ERROR_INVALID_PARAM,				// 无效的参数
	DPSDK_CORE_ERROR_TIMEOUT,					// 操作超时
	DPSDK_CORE_ERROR_SYNCFUN_ERROR,				// 同步调用错误
	DPSDK_CORE_ERROR_SERIES,					// 串行化失败
	DPSDK_CORE_ERROR_FOUND_FAIL,				// 查找失败
	DPSDK_CORE_ERROR_SIZE_ZERO,					// 大小为零
	DPSDK_CORE_ERROR_PARSE_ALARM_ENABLE_FAIL,	// 解析报警布控失败
	DPSDK_CORE_ERROR_GET_FREEPORT_FAIL,			// 获取空闲Port失败
	DPSDK_CORE_ERROR_INVALID_SEQ,               // 无效的SEQ
	DPSDK_CORE_ERROR_WITHOUT_LOGIN,             // 没有登录
	DPSDK_CORE_ERROR_WITHOUT_LOADGROUP,         // 没有加组织信息
	DPSDK_CORE_ERROR_ERROR_LEN,					// 长度错误
	DPSDK_CORE_ERROR_RANGE_OVER,				// 范围越界
	DPSDK_CORE_ERROR_CAPTURE_FAIL,				// 抓图失败
	DPSDK_CORE_ERROR_OPEN_FILE_FAIL,			// 打开文件失败
	DPSDK_CORE_ERROR_SAVE_FILE_FAIL,			// 保存文件失败
	DPSDK_CORE_ERROR_VIDEO_NOT_PLAYING,               // 还没有开始播放视频
	DPSDK_CORE_ERROR_STARTRECORD_FAIL,			// 录制实时视频失败
	DPSDK_CORE_ERROR_STOPRECORD_FAIL,			// 停止录制视频失败
	DPSDK_CORE_ERROR_SETOSDTXT_FAIL,			// 设置osd信息失败   
	DPSDK_CORE_ERROR_CLEANUP_OSDTXT_FAIL,       // 清除osd信息失败
	DPSDK_CORE_ERROR_OPENWINDOW_FAIL,			// 开窗失败(目前暂定最大开4窗)
	DPSDK_CORE_ERROR_GETDEVICEINFO_FAIL,		// 获取设备信息失败
	DPSDK_CORE_ERROR_STREAMCONVERTOR_FAIL,      // 调用转码库函数失败
	DPSDK_CORE_ERROR_PLAYSDK_FAIL,              // 调用播放库函数失败  
	DPSDK_CORE_ERROR_STREAMANALYSER_FAIL,       // 调用码流解析库函数失败
	DPSDK_CORE_ERROR_CANCELED,                  // 人为取消操作
	DPSDK_CORE_ERROR_NONE_LOGIC_ORG,			// 没有业务树
	DPSDK_CORE_ERROR_GET_LOGIC_ID,				// 获取业务树指定节点下 设备或者通道ID有误
	DPSDK_CORE_ERROR_OPENWINDOW_NOT_BIGSCREEN,	// 开窗失败(不是融合屏)
	DPSDK_CORE_ERROR_CREATE_JNI_ERROR = 1999,	//创建JNI对象失败
	DPSDK_CORE_END = 2000,

	DPSDK_RET_END = 5000,

	SERVER_RET_CMS_ERR_BEGIN            = DSS_ERROR_CODE_BASE,						// CMS返回开始，不做返回值判断
	SERVER_RET_CMS_ERR_QUERY_PU_SUCCESS,											// 查询全部录像时,只有前端查询成功
	SERVER_RET_CMS_ERR_QUERY_CENTER_SUCCESS,										// 查询全部录像时,只有中心查询成功

	SERVER_RET_CMS_CLIENT_ERROR_BEGIN   = SERVER_RET_CMS_ERR_BEGIN + CLIENT_ERROR_BASE,	// CMS客户端协议返回开始，不做返回值判断
	SERVER_RET_CMS_ERR_NO_USER_ID,													// 用户ID不存在
	SERVER_RET_CMS_ERR_NO_USER_NAME_TO_ID,											// 该用户名匹配不到ID
	SERVER_RET_CMS_ERR_NO_USER_NAME,												// 用户名不存在
	SERVER_RET_CMS_ERR_PASSWORD_INVALID,											// 密码无效
	SERVER_RET_CMS_ERR_INVALID_USER_ID,												// 无效的用户ID
	SERVER_RET_CMS_ERR_USER_LOCKED,													// 用户被锁定
	SERVER_RET_CMS_ERR_SESSION_EXIST,												// 用户已经存在登录会话
	SERVER_RET_CMS_ERR_NO_SESSION,													// 会话不存在
	SERVER_RET_CMS_ERR_SERVER_REGISTERED,											// 服务已经注册
	SERVER_RET_CMS_ERR_SERVER_NOT_REGISTER,											// 功能服务没有注册
	SERVER_RET_CMS_ERR_INVALID_CAMERA_ID,											// 摄像头id无效
	SERVER_RET_CMS_ERR_NO_DEVICE,													// 找不到设备
	SERVER_RET_CMS_ERR_MEDIA_SESSION_EXIST,											// 媒体会话已存在
	SERVER_RET_CMS_ERR_GRANT_SESSION_EXIST,											// 授权会话已存在
	SERVER_RET_CMS_ERR_NO_CAMERA_ROW,												// 找不到摄像头表
	SERVER_RET_CMS_ERR_UNKNOWN_TYPE,												// 无效的类型值
	SERVER_RET_CMS_ERR_TOO_MANY_GROUP_COUNT,										// 用户从属的组太多
	SERVER_RET_CMS_ERR_TOO_MANY,													// 数量太多
	SERVER_RET_CMS_ERR_EXIST_HIGH_USER,												// 存在高级别用户 add by fengjian 2012.8.8
	SERVER_RET_CMS_ERR_REACH_SESSION_LIMIT,											// 用户并发登陆数达到上限 
	SERVER_RET_CMS_ERR_USER_TIMEOUT,												// 用户已过期
	SERVER_RET_CMS_ERR_INVALID_MAC_ADDR,											// 无效的MAC地
	SERVER_RET_CMS_ERR_UNAUTHORIZED,												// 需要加密认证
	SERVER_RET_CMS_ERR_INVALID_CU_VERSION,											// 客户端版本错误
	SERVER_RET_CMS_ERR_INVALID_PHONE_NUM,											// 无效的手机号码
	SERVER_RET_CMS_ERR_PASSWORD_LOCKED,												// 密码被锁定（暂时不能登陆，会自动解锁）
	SERVER_RET_CMS_CLIENT_ERROR_END = SERVER_RET_CMS_ERR_BEGIN + CLIENT_ERROR_BASE + 100,

	SERVER_RET_CMS_SERVER_ERROR_BEGIN   = SERVER_RET_CMS_ERR_BEGIN + SERVER_ERROR_BASE,	// CMS服务协议返回开始，不做返回值判断
	SERVER_RET_CMS_ERR_NO_CONNECTION,												// 连接不存在
	SERVER_RET_CMS_ERR_INVALID_SERVER,												// 未在系统中登记的服务
	SERVER_RET_CMS_ERR_NO_DOMAIN,													// 服务域不存在
	SERVER_RET_CMS_ERR_NO_SERVER_BEAN,												// 服务对象不存在
	SERVER_RET_CMS_ERR_NO_MTS_TO_USE,												// 没有MTS可用
	SERVER_RET_CMS_ERR_SESSION_DELETE,												// 会话已经拆除
	SERVER_RET_CMS_ERR_SERVER_RECONNECT,											// 功能服务正在重连
	SERVER_RET_CMS_ERR_ADD_CAMERA_FAILED,											// 添加摄像头失败
	SERVER_RET_CMS_ERR_ADD_CLIENT_FAILED,											// 添加客户端失败
	SERVER_RET_CMS_ERR_DATABASE_ACCESS_FAILED,										// 数据库访问失败
	SERVER_RET_CMS_ERR_DATABASE_NO_RECORD,											// 数据库没有记录
	SERVER_RET_CMS_ERR_DATA_TOO_LONG,												// 数据太长了
	SERVER_RET_CMS_ERR_NO_GROUPS_OF_USER,											// 没有找到用户所从属的组
	SERVER_RET_CMS_ERR_QUERY_RECORD_FAILED,											// 查询录像失败
	SERVER_RET_CMS_ERR_OTHER_USER_PLAYBACK,											// 其他用户在回放该摄像头
	SERVER_RET_CMS_ERR_REACH_PU_PLAYBACK_LIMIT,										// 达到前端回放地限制
	SERVER_RET_CMS_ERR_NO_DMS_TO_USE,												// 没有DMS可用
	SERVER_RET_CMS_ERR_DEV_GRANT_CHANGED,											// 设备授权更改到其他服务
	SERVER_RET_CMS_ERR_ADD_DVR_FAILED,												// 添加DVR失败
	SERVER_RET_CMS_ERR_GRANT_FAILED,												// 授权到DMS失败
	SERVER_RET_CMS_ERR_SS_PLAYBACK_FAILED,											// SS回放失败
	SERVER_RET_CMS_ERR_REACH_SYSTEM_LIMIT,											// 达到系统上限
	SERVER_RET_CMS_ERR_INVALID_DEVICE_PROVIDER,										// 无效的设备厂家
	SERVER_RET_CMS_ERR_NO_URL,														// 没有升级URL
	SERVER_RET_CMS_ERR_NO_SS_TO_USE,						 						// 没有SS可用
	SERVER_RET_CMS_ERR_PU_QUERY_TIMEOUT,					 						// 前端查询超时
	SERVER_RET_CMS_ERR_PU_QUERY_RECORD_FAILED,										// 前端查询录像失败
	SERVER_RET_CMS_ERR_NO_MTS_FOR_DEVICE,											// 没有和这个设备管理的MTS
	SERVER_RET_CMS_ERR_DEVICE_IN_TALKING,											// 设备正在进行语音对讲
	SERVER_RET_CMS_ERR_DEVICE_NOT_TALKING,											// 设备没有在进行语音对讲
	SERVER_RET_CMS_ERR_ENCODE_PDU,													// CMS在准备应答时候，进行Encode操作失败
	SERVER_RET_CMS_ERR_DECODE_PDU,													// CMS在准备应答时候，进行Decode操作失败
	SERVER_RET_CMS_ERR_NOT_FOUND_LOWER_DOMAIN,										// 没有找到下级域
	SERVER_RET_CMS_ERR_NOT_LOGIN_LOWER_DOMAIN,										// 未登陆下级域
	SERVER_RET_CMS_ERR_NO_RIGHT,													// 无权限
	SERVER_RET_CMS_ERR_QUERY_ALARM_FAILED,											// 查询报警失败
	SERVER_RET_CMS_ERR_DEIVCE_OFFLINE,												// 设备不在线
	SERVER_RET_CMS_ERR_LOWER_DOMAIN_EXCEPTION,										// 下级域异常
	SERVER_RET_CMS_ERR_ALARM_PRE_RECORD_OPENED,										// 报警预录已经打开
	SERVER_RET_CMS_ERR_RECONNECT_DEVICE,											// 功能服务正在重连设备
	SERVER_RET_CMS_ERR_SEND_FUN_SVR_REQ_FAIL,										// 向功能服务器发送请求失败

	//add by fengjian 2012.8.7
	SERVER_RET_CMS_ERR_CU_START_RECORD_FAIL,										// 开始录像失败
	SERVER_RET_CMS_ERR_CU_RECORING_NOW,												// 正在录像
	SERVER_RET_CMS_ERR_CU_STOP_RECORD_FAIL,											// 停止录像失败
	SERVER_RET_CMS_ERR_CU_OTHERUSER_RECORDING,										// 其他用户正在录像
	SERVER_RET_CMS_ERR_CU_START_RECORD_RUNNING = DSS_ERROR_CODE_BASE + 566,			// 开始录像失败，运行中
	SERVER_RET_CMS_ERR_CU_START_RECORD_LIMITE,										// 开始录像失败，被禁止
	SERVER_RET_CMS_ERR_CU_START_RECORD_NO_SS,										// 开始录像失败，没有可用的SS
	SERVER_RET_CMS_ERR_NO_PES_TO_USE,												// 没有可用的PES服务器 
	//add end																		 
	SERVER_RET_CMS_ERR_UNKNOWN_PROTOCOL,											// 不支持的协议类型
	SERVER_RET_CMS_ERR_CONFIG_FILE_TIMEOUT,											// 组配置文件过期
	SERVER_RET_CMS_ERR_NO_BOLCK,													// 无可用的block
	SERVER_RET_CMS_ERR_END = SERVER_RET_CMS_ERR_BEGIN + 1000,						// CMS返回结束


	SERVER_RET_DMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_DMS_BASE,					    // DMS返回开始，不做返回值判断
	SERVER_RET_DMS_ERR_HAS_NO_RIGHT = SERVER_RET_DMS_ERR_BEGIN + 401,					// 没有权限
	SERVER_RET_DMS_CLIENT_ERROR_BEGIN = SERVER_RET_DMS_ERR_BEGIN + CLIENT_ERROR_BASE,	// DMS客户端协议返回开始，不做返回值判断
	SERVER_RET_DMS_ERR_NO_PRIVILEGE,													// 没有权限
	SERVER_RET_DMS_CLIENT_ERROR_END = SERVER_RET_DMS_ERR_BEGIN + CLIENT_ERROR_BASE + 100,
	
	SERVER_RET_DMS_SERVER_ERROR_BEGIN  = SERVER_RET_DMS_ERR_BEGIN + SERVER_ERROR_BASE,	// DMS服务协议返回开始，不做返回值判断
	SERVER_RET_DMS_ERR_PTZ_FAILED,														// 云台内部控制出错
	SERVER_RET_DMS_ERR_CONFIG_SET_FAILED,												// 设备配置内部控制出错
	SERVER_RET_DMS_ERR_CONFIG_GET_FAILED,												// 设备配置内部控制出错
	SERVER_RET_DMS_ERR_CAMERA_OCCUPY,													// 摄像头被其他用户锁定
	SERVER_RET_DMS_ERR_PTZ_ACCESS_FAILED,												// 象云台协商管理模块请求访问失败
	SERVER_RET_DMS_ERR_TCP_COMM_NO_CLIENT,												// 用户连接没有绑定到授权的客户端
	SERVER_RET_DMS_ERR_CLIENT_UNIT_NOT_FOUND,											// 没有找到没有添加过的客户端
	SERVER_RET_DMS_ERR_DEVICE_NOT_FOUND,												// 设备没找到
	SERVER_RET_DMS_ERR_PRIVILEGE_NOT_FOUND,												// 没有找到授权信息
	SERVER_RET_DMS_ERR_UNKNOWN_COMMAND,													// 未知命令
	SERVER_RET_DMS_ERR_OCCUPY_BY_HIGHER_USER,											// 被高级用户占用
	SERVER_RET_DMS_ERR_NORMAL_LOCK_FAILED,												// 需要Server检查的Lock失败错误
	SERVER_RET_DMS_ERR_OCCUPY_BY_OTHER_USER,											// 被其他用户占用
	SERVER_RET_DMS_ERR_NORMAL_UNLOCK_FAILED,											// 需要Server检查的UnLock失败错误
	SERVER_RET_DMS_ERR_NO_DEVICE,														// 没有设备
	SERVER_RET_DMS_ERR_NO_RIGHT,														// 没有权限
	SERVER_RET_DMS_ERR_NOT_FOUND_LOWER_DOMAIN,											// 没有找到下级域
	SERVER_RET_DMS_ERR_NOT_LOGIN_LOWER_DOMAIN,											// 没有登录下级域
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_ID,												// 查询视频诊断ID失败
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_TYPE_COUNT,										// 查询视频诊断类型数目失败
	SERVER_RET_DMS_ERR_QUERY_DIAGNOSIS_INFO,											// 查询视频诊断信息失败
	SERVER_RET_DMS_ERR_STOP_QUERY_DIAGNOSIS_INFO,										// 停止视频诊断信息查询失败
	SERVER_RET_DMS_ERR_START_QUERY_PERSON_COUNT,										// 开始查询人数统计信息失败
	SERVER_RET_DMS_ERR_QUERY_PERSON_COUNT,												// 查询人数统计信息失败
	SERVER_RET_DMS_ERR_STOP_QUERY_PERSON_COUNT,											// 停止人数统计信息查询失败
	SERVER_RET_DMS_ERR_END = SERVER_RET_DMS_ERR_BEGIN + 1000,						    // DMS返回结束

	SERVER_RET_VMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_VMS_BASE,                
	SERVER_RET_VMS_SERVER_ERROR_BEGIN  = SERVER_RET_VMS_ERR_BEGIN + SERVER_ERROR_BASE,	// DMS服务协议返回开始，不做返回值判断
	SERVER_RET_VMS_ERR_FAILED = SERVER_RET_VMS_SERVER_ERROR_BEGIN,						// 失败-其他原因
	SERVER_RET_VMS_ERR_ID_ALREADY_EXIST,												// NVD ID已存在
	SERVER_RET_VMS_ERR_INVALID_ID,														// 无效的ID
	SERVER_RET_VMS_ERR_REACH_LIMIT,														// 达到上限
	SERVER_RET_VMS_ERR_END = SERVER_RET_VMS_ERR_BEGIN + 1000,						    // DMS返回结束


	SERVER_RET_RTSP_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_RTSP_BASE,  
	SERVER_RET_RTSP_ERR_SETUP_FAILED = SERVER_RET_RTSP_ERR_BEGIN + 503,					// Rtsp建立失败
	SERVER_RET_RTSP_SERVER_ERROR_BEGIN  = SERVER_RET_RTSP_ERR_BEGIN + SERVER_ERROR_BASE,// DMS服务协议返回开始，不做返回值判断
	SERVER_RET_RTSP_ERR_RECONNECT_DEVICE,												// 正在重连设备
	SERVER_RET_RTSP_ERR_END = SERVER_RET_RTSP_ERR_BEGIN + 1000,						    // DMS返回结束

	SERVER_RET_ALARM_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_ALARM_BASE + DSS_ERROR_BASE,                
	SERVER_RET_ALARM_ERR_URL,															// 无效的URL
	SERVER_RET_ALARM_ERR_RES,															// 无效的数据
	SERVER_RET_ALARM_ERR_MDL_TYPE,														// 无效的单元类型
	SERVER_RET_ALARM_ERR_SCHEME_INDEX,													// 无效的预案索引
	SERVER_RET_ALARM_ERR_SCHEME_TYPE,													// 无效的预案类型
	SERVER_RET_ALARM_ERR_SCHEME_STRING,													// 预案字符串解析失败
	SERVER_RET_ALARM_ERR_ALARM_NODE,													// 无效的报警节点
	SERVER_RET_ALARM_ERR_END = SERVER_RET_ALARM_ERR_BEGIN + 1000,					    // DMS返回结束


	SERVER_RET_MS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_MS_BASE,                
	SERVER_RET_MS_CLIENT_ERROR_BEGIN = SERVER_RET_MS_ERR_BEGIN + CLIENT_ERROR_BASE,
	SERVER_RET_MS_ERR_ALREADY_LOGIN,													// 已经登录
	SERVER_RET_MS_ERR_INVALID_SESSION_ID,												// 无效的会话ID
	SERVER_RET_MS_ERR_NOT_LOGIN,														// 未登录
	SERVER_RET_MS_ERR_INVALID_CONNECTION,												// 无效连接
	SERVER_RET_MS_ERR_INVALID_DEV_TYPE,													// 无效的设备类型
	SERVER_RET_MS_ERR_INVALID_CAMERA_ID,												// 无效的摄像头id
	SERVER_RET_MS_ERR_CAMERA_SESSION_EXIST,												// 摄像头已经添加过
	SERVER_RET_MS_ERR_NO_CAMERA_SESSION,												// 摄像头会话不存在
	SERVER_RET_MS_ERR_FIND_SAME_TOKEN,													// 找到相同的token
	SERVER_RET_MS_ERR_UNKNOWN_RECORD_TYPE,												// 无法识别的录像类型
	SERVER_RET_MS_ERR_INVALID_FILE_NAME,												// 无效的录像文件名称
	SERVER_RET_MS_ERR_INVALID_TIME_VALUE,												// 无效的录像时间值
	SERVER_RET_MS_ERR_NOT_FOUND_SESSION,												// 没有找到会话
	SERVER_RET_MS_ERR_INVALID_RTSP_URL,													// 无效的RTSP URL
	SERVER_RET_MS_ERR_PLAN_EXIST,														// 计划已经存在
	SERVER_RET_MS_CLIENT_ERROR_END = SERVER_RET_MS_CLIENT_ERROR_BEGIN + 100,

	SERVER_RET_MS_SERVER_ERROR_BEGIN = SERVER_RET_MS_ERR_BEGIN + SERVER_ERROR_BASE,
	SERVER_RET_MS_ERR_DEV_NOT_LOGIN,													// 设备还未登录
	SERVER_RET_MS_ERR_SDK_OPERATE_FAILED,												// sdk调用失败
	SERVER_RET_MS_ERR_SESSION_USE_OUT,													// 会话用完
	SERVER_RET_MS_ERR_RTSP_CONNECT_FAILED,												// rtsp连接失败
	SERVER_RET_MS_ERR_RTP_LISTEN_FAILED,												// RTP侦听失败
	SERVER_RET_MS_ERR_RTSP_SETUP_FAILED,												// RTSP Setup操作失败
	SERVER_RET_MS_ERR_RTSP_PLAY_FAILED,													// RTSP PLAY操作失败
	SERVER_RET_MS_ERR_ADD_RTP_SESSION_FAILED,											// 添加RTP SESSION到serverbase失败
	SERVER_RET_MS_ERR_DISK_SPACE_NOT_ENOUGH,											// 磁盘空间不足
	SERVER_RET_MS_ERR_OPEN_FILE_FAILED,													// 文件打开失败
	SERVER_RET_MS_ERR_NOT_FOUND_RTSP_CLIENT,											// 找不到RTSP客户端连接
	SERVER_RET_MS_ERR_RTSP_DISCONNECTED,												// RTSP连接断开
	SERVER_RET_MS_ERR_RECORD_QUERY_TIMEOUT,												// 录像查询超时
	SERVER_RET_MS_ERR_SDK_CALLBACK_INVALID_DATA,										// sdk 返回数据不正确
	SERVER_RET_MS_ERR_SNAP_STORE_PATH_INVALID,											// 设置的SS端SNAP存储路径有问题
	SERVER_RET_MS_ERR_SNAP_STORE_FILE_FAILED,											// SS在存储文件时候操作失败
	SERVER_RET_MS_ERR_SNAP_ENCODE_FAILED,												// SS在编码回复pdu时候失败
	SERVER_RET_MS_ERR_IFRAME_2_BMP,														// SS在转换I帧到BMP时候失败
	SERVER_RET_MS_ERR_DUPLICATE_PLAN_FOUND,												// 重复的PlanId发现
	SERVER_RET_MS_ERR_SDK_CALLBACK_TIMEOUT,												// SDK调用Callback超时，没有返回数据																						   
	SERVER_RET_MS_ERR_NOT_FOUND_SESSION_ID,												// 未找到camera_session_id
	SERVER_RET_MS_ERR_INVALID_STREAM_TYPE,												// 非法的码流类型
	SERVER_RET_MS_ERR_ADD_LIVECHANNEL_FAILED,											// 添加直播频道失败
	SERVER_RET_MS_ERR_GET_TALKDECODE_FAILED,											// 获取对讲格式失败
	SERVER_RET_MS_ERR_LOGIN_DEV_FAILED,													// 登陆语音设备失败
	SERVER_RET_MS_ERR_NOT_MATCH_AUDIO_TYPE,												// 音频格式不匹配
	SERVER_RET_MS_ERR_NOT_FOUND_DISK,													// 未找到磁盘
	SERVER_RET_MS_ERR_NOT_FOUND_RECORD_PLAN,											// 未找到录像计划
	SERVER_RET_MS_SERVER_ERROR_END = SERVER_RET_MS_SERVER_ERROR_BEGIN + 100,
	SERVER_RET_MS_ERR_END = SERVER_RET_MS_ERR_BEGIN + 1000,								 // MS返回结束

	SERVER_RET_PCS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_PCS_BASE,						// PCS服务协议返回开始，不做返回值判断
	SERVER_RET_PCS_ERR_NOT_FOUND = SERVER_RET_PCS_ERR_BEGIN + 404,						// 级联设备未下发
	SERVER_RET_PCS_ERR_NOT_ACCEPTABLE = SERVER_RET_PCS_ERR_BEGIN + 406,					// 级联订阅，本级PTS监听失败
	SERVER_RET_PCS_ERR_DEVICE_OFFLINE = SERVER_RET_PCS_ERR_BEGIN + 710,					// 设备断线
	SERVER_RET_PCS_ERR_DOMIAN_OFFLINE = SERVER_RET_PCS_ERR_BEGIN + 713,					// 下级域不在线
	SERVER_RET_PCS_ERR_PTS_CANNOT_PING = SERVER_RET_PCS_ERR_BEGIN + 714,				// 上级连接下级PTS失败
	SERVER_RET_PCS_ERR_NO_ACK = SERVER_RET_PCS_ERR_BEGIN + 715,							// 无应答
	SERVER_RET_PCS_ERR_END = SERVER_RET_PCS_ERR_BEGIN + 1000,							// PCS返回结束

	SERVER_RET_FMS_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_FMS_BASE,						// FMS返回开始
	SERVER_RET_FMS_ERR_RTMP_CLIENT_POOL_ALREADY_EXIST,									// RTMP client池已经存在
	SERVER_RET_FMS_ERR_NO_FREE_RTMPCLIENT,												// RTMP Client池里面没有空闲的地址
	SERVER_RET_FMS_ERR_STARTSTREAM,														// 调用StartStream失败
	SERVER_RET_FMS_ERR_ADDMEDIA,														// 调用AddMedia失败
	SERVER_RET_FMS_ERR_DELMEDIA,														// 调用DelMedia失败
	SERVER_RET_FMS_ERR_STOPSTREAM,														// 调用StopStream失败
	SERVER_RET_FMS_ERR_END = SERVER_RET_FMS_ERR_BEGIN + 1000,							// FMS返回结束

	SERVER_RET_ANA_ERR_BEGIN = DSS_ERROR_CODE_BASE + DSS_ANA_BASE,						// ANA返回开始
	SERVER_RET_ANA_ERR_CREATE,															// 调用码流分析库的ANA_CreateStream失败
	SERVER_RET_MP3_ENC_INIT_FAILED,                                                     // MP3编码库初始化失败
	SERVER_RET_ANA_ERR_END = SERVER_RET_ANA_ERR_BEGIN + 1000,							// FMS返回结束

	DPSDK_CORE_ERROR_NO_RECORD_FILES,													// 没有录像文件
	DPSDK_CORE_ERROR_JSON_RETURN_FALSE,													// json协议返回的result:false
	DPSDK_CORE_ERROR_OSD_TO0_LONG,														// OSD字符串太长

	SERVER_RET_JD_ERR_BEGIN = 1010000,													// 京东鉴权返回开始
	SERVER_RET_JD_ERR_END = 1011000,													// 京东鉴权返回结束
}dpsdk_retval_e;




#endif