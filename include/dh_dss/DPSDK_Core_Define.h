#ifndef INCLUDED_DPSDK_CORE_DEFINE_H
#define INCLUDED_DPSDK_CORE_DEFINE_H

/***************************************************************************************
										宏定义
***************************************************************************************/

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

#ifndef NULL
#define NULL 0
#endif

#ifdef _WIN32
// 放在class关键字后面，以及函数或者变量定义的前面
#define DPSDK_DLL_DEPRECATED	__declspec(deprecated)
#else
#define DPSDK_DLL_DEPRECATED	__attribute__ ((deprecated))
#endif // #ifdef WIN32
#include <vector>
#include <map>
#include <list>
#include <iostream>
#ifdef _WIN32

	#ifdef DPSDK_EXPORTS
		#define DPSDK_DLL_API extern "C" __declspec(dllexport)
	#else
		#define DPSDK_DLL_API extern "C" __declspec(dllimport)
	#endif

	#define DPSDK_CALLTYPE				__stdcall
	#define DPSDK_CALL_METHOD			__stdcall  //__cdecl

	#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x0502
	#endif	

	#ifndef __int8_t_defined
		#define __int8_t_defined
		typedef signed char			int8_t;
		typedef unsigned char		uint8_t;
		typedef short int			int16_t;
		typedef unsigned short int	uint16_t;
		typedef int					int32_t;
		typedef unsigned int		uint32_t;
		typedef __int64				int64_t;
		typedef unsigned __int64	uint64_t;
	#endif
#else//fixme: delete these defs
	//	#include <stdio.h>
	#include <string.h> // memset(), linux platform need this
	#include <stddef.h> // NULL
	#include <stdint.h> // int8_t
	//	#include <errno.h>

	#define DPSDK_DLL_API extern "C"
	#define DPSDK_CALLTYPE
	#define DPSDK_CALL_METHOD

	#define WORD		unsigned short
	#define DWORD		unsigned int
	#define LONG		int
	#define LONGINT		long int
	#define DWORDINT	long int
	#define LPDWORD		DWORD*
	#define BOOL		int
	#define TRUE		1
	#define FALSE		0
	#define BYTE		unsigned char
	#define UINT		unsigned int
	#define HDC			void*
	#define HWND		void*
	#define LPVOID		void*
	//	#define NULL		0
	#define LLONG		long
	#define INT64		long long
	#define LDWORD		long 

	#ifndef MAX_PATH
	#define MAX_PATH	260
	#endif
#endif

#define DPSDK_CORE_LEN                          16
#define DPSDK_CORE_IP_LEN						48						// 远端IP地址长度
#define DPSDK_CORE_USER_NAME_LEN				64						// 设备登陆用户名长度
#define DPSDK_CORE_PASSWORD_LEN					64						// 密码长度
#define DPSDK_CORE_REC_FILENAME_LEN				64						// 录像文件名长度
#define DPSDK_CORE_DEV_ID_LEN					64						// 设备ID长度
#define	DPSDK_CORE_AREA_ID_LEN                  50                      // 区间长度
#define DPSDK_CORE_AREA_NAME_LEN                256                     // 区间名称长度
#define DPSDK_CORE_MSG_LEN				       (4*1024)				    // 消息上报信息长度
#define DPSDK_CORE_REC_DISKID_LEN				64						// 录像磁盘ID长度
#define DPSDK_CORE_CHL_ID_LEN					64						// 通道ID长度
#define DPSDK_CORE_TASK_LEN                     1024*1024               // 任务信息
#define DPSDK_TAG_URL_LEN						1024                    // Url的长度
#define DPSDK_CORE_POINT_COUNT					300						// 预置点数量
#define DPSDK_CORE_POINT_NAME_LEN               32                      // 预置点名称长度'
#define DPSDK_CORE_POINT_TIME_LEN               32                      // 预置点时间长度
#define DPSDK_CORE_ALARM_MSG_LEN				(4*1024)				// 报警查询结果信息长度
#define DPSDK_CORE_ALARM_TITLE_LEN				256			      		// 报警查询结果title长度
#define DPSDK_CORE_DEFAULT_TIMEOUT				(600*1000)              // 默认超时 单位毫秒
#define DPSDK_CORE_DGROUP_DGPNAME_LEN			256						// 组织名称长度
#define DPSDK_CORE_DGROUP_DGPCODE_LEN			128						// 组织Code长度
#define DPSDK_CORE_28181_SN_LENGTH				64						// SN长度
#define	MAX_CONFIG_NUM			                32			            // 每个云台的最大配置数
#define MAX_TIME_SCHEDULE_NUM			        8			            // 时间表元素个数
#define MAX_REC_TSECT			                6					    // 录像时间段个数
#define DPSDK_CORE_TIME_LENGTH					32					 	// 时间串长度
#define DPSDK_CORE_DGROUP_DEVICENAME_LEN		256						// 设备名称长度
#define DPSDK_CORE_FILEPATH_LEN					256						// 文件路径长度
#define DPSDK_CORE_IMG_PATH_LEN			    	256						// 图片文件路径长度
#define DPSDK_CORE_BAY_IMG_NUM					6						// 图片数目
#define DPSDK_CORE_IMG_URL					    1024					// 客户端http请求的URL 的长度
#define DPSDK_CORE_DGROUP_CHNNAME_LEN           256                     // 设备通道名称长度
#define DPSDK_CORE_POS_ID_LEN                   50                      // 地点位置名称长度
#define DPSDK_CORE_POS_NAME_LEN                 256                     // 地点名称长度
#define DPSDK_CORE_ORG_CODE_LEN				    128                     // 组织节点长度
#define DPSDK_CORE_ORG_NAME_LEN                 256                     // 组织名称长度
#define DPSDK_CORE_ORG_SN_LEN                   256                     // 组织节点唯一码
#define DPSDK_CORE_ORG_TYPE_LEN                 16                      // 组织节点类型
#define DPSDK_CORE_ORG_GPS_LEN                  64                      // 组织节点经度
#define DPSDK_CORE_ORG_MEMO_LEN                 1024                    // 组织节点描述
#define DPSDK_CORE_DIRECT_LEN                   4                       // 方向编号
#define DPSDK_CORE_CAR_RECORD_ID_LEN            128                     // 记录ID
#define DPSDK_CORE_OPT_NOTE_LEN                 256                     // 备注长度
#define DPSDK_CORE_TIME_LEN                     128                     // 时间（以秒为单位）长度
#define DPSDK_CORE_COORDINATE_LEN               4                       // 车牌坐标长度
#define DPSDK_CORE_PERSON_CODE_LEN              256                     // 身份证ID
#define DPSDK_CORE_PERSON_NAME_LEN              256                     // 人员名称长度
#define DPSDK_CORE_PERSON_DEPTCODE_LEN          128                     // 所属部门长度
#define DPSDK_CORE_PERSON_SN_LEN                256                     // 人员唯一编号长度
#define DPSDK_CORE_PERSON_TYPE_LEN              16                      // 人员类型长度
#define DPSDK_CORE_PERSON_OFFICE_LEN            256                     // 人员办公地点  
#define DPSDK_CORE_PERSON_MOBILENUM_LEN         64                      // 人员移动电话
#define DPSDK_CORE_PERSON_VIRTUALNUM_LEN        64                      // 人员虚拟短号
#define DPSDK_CORE_PERSON_STATE_LEN             16                      // 人员状态 
#define DPSDK_CORE_CAR_CODE_LEN                 50                      // 车辆code
#define DPSDK_CORE_CAR_COLOR_LEN                16                      // 车辆颜色10
#define DPSDK_CORE_CAR_TYPE_LEN                 16                      // 车辆类型10
#define DPSDK_CORE_CAR_MODEL_LEN                256                     // 车辆品牌型号50
#define DPSDK_CORE_CAR_SIZE_LEN                 64                      // 车辆尺寸50     
#define DPSDK_CORE_CAR_VIN_LEN                  64                      // 车架号50
#define DPSDK_CORE_ENG_NO_LEN                   64                      // 引擎号50
#define DPSDK_CORE_REGIST_LEN                   64                      // 车牌注册地50
#define DPSDK_CORE_REGIST_DATE_LEN              32                      // 注册日期20
#define DPSDK_CORE_CAR_PICPATH_LEN              256                     // 车辆照片路径255
#define DPSDK_CORE_CAR_PLATENO_LEN              64                      // 车牌号码50
#define DPSDK_CORE_CAR_PLATECOLOR_LEN           16                      // 车辆颜色10
#define DPSDK_CORE_CAR_PLATETYPE_LEN            16                      // 车牌类型10
#define DPSDK_CORE_CAR_OWNERNAME_LEN            256                     // 业主名称50                  
#define DPSDK_CORE_CAR_OWNERPHONE_LEN           64                      // 业主电话50                     
#define DPSDK_CORE_DEPTCODE_LEN                 128                     // 部门code
#define DPSDK_CORE_DBID_LEN                     32                      // 数据库自增长ID长度
#define DH_MAX_CORE_LANE_NUM                    8                       // 交通流量状态，最大支持8车道
#define DPSDK_PIP_SCREEN_NUM					4						// 安徽三联项目 画中画分屏个数
#define DPSDK_PIP_SCREEN_PIXEL					8192					// 安徽三联项目 NVD屏像素值
#define DPSDK_CORE_MEM_LEN						1024					// 备注信息长度
#define DPSDK_CORE_IVS_EVENT_NAME_LEN			32						// 规则事件名称长度

#define DPSDK_CORE_TVWALL_NAME_LEN				256                     // 电视墙名称长度
#define DPSDK_CORE_TVWALL_TASK_NAME_LEN         64                      // 电视墙任务名称长度
#define DPSDK_CORE_TVWALL_TASK_DES_LEN          256                     // 电视墙任务描述长度

#define DPSDK_CORE_BAY_IP_LEN					64                      // IP长度              
#define DPSDK_CORE_CAR_NUM_LENGTH				32
#define DPSDK_CORE_BAY_IMG_NUM					6
#define DPSDK_CORE_BAY_URL_LEN					1024

//康特尔定制需求
#define DPSDK_CORE_KANGTEER_GROUP_DATA			1024
#define DPSDK_CORE_KANGTEER_DATA				256

//安徽朗坤定制需求
#define DPSDK_CORE_QUERY_PIC_MAXCOUT			256			//一次查询图片数量限制
#define DPSDK_CORE_TIMESTR_LEN					64			//时间字符串长度					


#define DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN		256			//信息模板长度
//卡口布控告警新增
#define DPSDK_CORE_BAY_ORG_LEN                  256         //布控机构
#define DPSDK_CORE_BAY_SURVERY_LEN              128         //布控信息通用长度
#define DPSDK_CORE_BAY_PHONE_LEN                32          //布控告警电话通用长度
#define DPSDK_CORE_BAY_MAN_LEN                  16          //人名

#define DPSDK_CORE_CASE_CODE_LEN				64			// 案件编号
#define DPSDK_CORE_CASE_NAME_LEN				64			// 案件名称
#define DPSDK_CORE_CASE_ADDR_LEN				256			// 案件地址
#define DPSDK_CORE_CASE_MEMO_LEN				256			// 案件备注
#define DPSDK_CORE_FILE_PATH_LEN				512			// 文件目录
#define DPSDK_CORE_FILE_MEMO_LEN				512			// 文件描述
#define DPSDK_CORE_GPS_LEN						50			// GPS信息
#define DPSDK_CORE_FILE_TYPE_LEN				32			// 类型信息

#define T_IYUV									3		    ///< 视频数据，i420格式。排列顺序"Y0-Y1-...","U0-U1-..","V0-V1-..."
#define T_YV12									4			///< 视频数据，yv12格式。排列顺序"Y0-Y1-..."."V0-V1-...","U0-U1-.."

#define DPSDK_CORE_AREA_ID_MAXLEN				32
#define DPSDK_CORE_AREA_ATTR_MAXLEN				32
#define DPSDK_CORE_AREA_NAME_MAXLEN				64
#define DPSDK_CORE_AREA_WEEK_DAYS				7
#define DPSDK_CORE_DRIVER_ID_LEN				64			// 车载报警司机ID长度
#define DPSDK_CORE_AREA_DB_LEN					32			// 车载报警经纬度长度
#define DPSDK_CORE_AREA_CODE_LEN				64			// 车载报警司机ID长度
#define DPSDK_CORE_ALARMCODE_LEN				64			// 报警code长度

#define DPSDK_CORE_SCHEME_NAME_LEN				256			// 预案文件名长度
#define DPSDK_CORE_SCHEME_DESC_LEN				512			// 预案描述长度

#define DPSDK_CORE_TEMPLATE_NAME_LEN			64			// 时间模板名称长度
#define DPSDK_CORE_TEMPLATE_REMARK_LEN			256			// 时间模板说明长度
#define DPSDK_CORE_TEMPLATE_FLAG_LEN			512			// 时间模板信息长度

#define DPSDK_CORE_RFID_LABEL					32			// RFID超声波探测标签和车用电子标签长度
#define DPSDK_CORE_CHAR_LEN_32					32
#define DPSDK_CORE_CHAR_LEN_64					64
#define DPSDK_CORE_CHAR_LEN_256					256
#define DPSDK_CHAR_256							256

#define DPSDK_CORE_TAG_SUBJECT_LEN				128			// 打标主题长度
#define DPSDK_CORE_TAG_CONTENT_LEN				256			// 打标内容长度

#define DPSDK_CORE_ERROR_CONTENT_LEN			128

typedef struct S3GFlowInfo
{
	char szDevId[DPSDK_CORE_DEV_ID_LEN];					//设备id
	uint32_t		nUsedFlow;								//已使用流量
	uint32_t		nAllFlow;								//全部流量
	S3GFlowInfo()
	{
		nUsedFlow = 0;
		nAllFlow = 0;
	}
}S3G_Flow_Info_t;

typedef enum
{
	CALL_TYPE_SINGLE_CALL,			// 单呼
	CALL_TYPE_GROUP_CALL,			// 组呼
	CALL_TYPE_VT_CALL,				// 可视对讲
}dpsdk_call_type_e;


// 呼叫业务状态
typedef enum
{
	CALL_STATUS_PREPARED,			//准备
	CALL_STATUS_REQTOSCS,			//向SCS请求
	CALL_STATUS_CALLING,			//呼叫中
	CALL_STATUS_RECVING,			//接收中
	CALL_STATUS_CEASED,				//呼叫释放
}dpsdk_call_status_e;

typedef enum
{
	DPSDK_IPPROTO_UDP = 1,	    //UDP
	DPSDK_IPPROTO_TCP,			//TCP
}dpsdk_ipproto_type_e;
typedef struct tagDPSDK_CreateParam
{
	dpsdk_ipproto_type_e	eSipProto;		//用户id标识符
	char					szSCAgent[512];					// SCAgent设置，默认为DSSCClient，可设置为APPClient
}DPSDK_CreateParam_t;


/**车载设备流量信息回调函数定义
@param IN                                    nPDLLHandle              SDK句柄
@param IN                                    pRetInfo						CMS发送的3G流量信息
@param IN                                    pUserParam               用户参数
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDK3GFlowInfoCallback)( IN int32_t nPDLLHandle,
														   IN S3G_Flow_Info_t* p3GInfo, 
														   IN void* pUserParam );

/***************************************************************************************
 @ 宏定义结束
***************************************************************************************/


/***************************************************************************************
 @ 类型定义
***************************************************************************************/

// SDK类型
typedef enum
{
	DPSDK_CORE_SDK_SERVER						= 1,					 //服务模式使用
}dpsdk_sdk_type_e;

// SDK状态类型
typedef enum
{
	DPSDK_CORE_STATUS_SERVER_ONLINE				= 1,					 //服务上线通知
	DPSDK_CORE_STATUS_SERVER_OFFLINE            = 2,					 //服务下线通知
}dpsdk_status_type_e;

// 日志等级
typedef enum
{
	DPSDK_LOG_LEVEL_DEBUG						= 2,					// 调试
	DPSDK_LOG_LEVEL_INFO						= 4,					// 信息
	DPSDK_LOG_LEVEL_ERROR						= 6,					// 错误
}dpsdk_log_level_e;

// 协议版本
typedef enum
{
	DPSDK_PROTOCOL_VERSION_I					= 1,					// 一代协议
	DPSDK_PROTOCOL_VERSION_II					= 2,					// 二代协议
}dpsdk_protocol_version_e;

// 设备状态
typedef enum
{
	DPSDK_DEV_STATUS_UNKNOW						= 0,                         // 未知状态
	DPSDK_DEV_STATUS_ONLINE						= 1,					     // 在线
	DPSDK_DEV_STATUS_OFFLINE					= 2,					     // 离线

	// 废弃
	DPSDK_CORE_DEVICE_STATUS_ONLINE				= DPSDK_DEV_STATUS_ONLINE,
	DPSDK_CORE_DEVICE_STATUS_OFFLINE            = DPSDK_DEV_STATUS_OFFLINE,
}dpsdk_dev_status_e, dpsdk_device_status_type_e;

// 单元类型
typedef enum
{
	DPSDK_DEV_UNIT_UNKOWN,		                                        // 未知
	DPSDK_DEV_UNIT_ENC,			                                        // 编码
	DPSDK_DEV_UNIT_DEC,			                                        // 解码
	DPSDK_DEV_UNIT_ALARMIN,		                                        // 报警输入
	DPSDK_DEV_UNIT_ALARMOUT,	                                        // 报警输出
	DPSDK_DEV_UNIT_TVWALLIN,	                                        // TvWall输入
	DPSDK_DEV_UNIT_TVWALLOUT,	                                        // TvWall输出
	DPSDK_DEV_UNIT_DOORCTRL,	                                        // 门禁
	DPSDK_DEV_UNIT_VOICE,	                                          	// 对讲
}dpsdk_dev_unit_type_e;

// 节点类型
typedef enum
{
	DPSDK_CORE_NODE_DEP,												// 组织
	DPSDK_CORE_NODE_DEV,												// 设备
	DPSDK_CORE_NODE_CHANNEL,											// 通道
}dpsdk_node_type_e;

typedef enum
{
	OPTTYPE_UNKOWN				             	= 0,					// 
	OPTTYPE_LOGIN,										             	// 登录 
	OPTTYPE_LOGOUT,										            	// 登出
	OPTTYPE_REAL,									            		// 实时视频
	OPTTYPE_PTZ,										            	// 云台
	OPTTYPE_PLAYBACK,													// 回放
	OPTTYPE_DOWNLOAD,													// 下载
	OPTTYPE_LOCALRECORD,												// 本地录像
	OPTTYPE_QUERYRECORD,												// 查询录像
	OPTTYPE_ARM,														// 报警主机布防
	OPTTYPE_DISARM,														// 报警主机撤防
}dpsdk_log_optType_e;
// 获取节点的深度
typedef enum
{
	DPSDK_CORE_GEN_GETGROUP_OPERATION_ALL		= -1,					 // 获取子孙
	DPSDK_CORE_GEN_GETGROUP_OPERATION_SELF		= 0,					 // 获取自身
	DPSDK_CORE_GEN_GETGROUP_OPERATION_CHILD		= 1,					 // 获取子节点
}dpsdk_getgroup_operation_e;

// 节点改变通知类型
typedef enum
{
	DPSDK_CORE_CHANGE_UNDEFINE					= 0,					 // 未定义
	DPSDK_CORE_CHANGE_ADD_DEV					= 1,					 // 增加设备			
	DPSDK_CORE_CHANGE_MODIFY_DEV				= 2,					 // 修改设备
	DPSDK_CORE_CHANGE_DEL_DEV					= 3,					 // 删除设备
	DPSDK_CORE_CHANGE_ADD_ORG					= 4,					 // 增加组织
	DPSDK_CORE_CHANGE_MODIFY_ORG				= 5,					 // 修改组织 
	DPSDK_CORE_CHANGE_DELETE_ORG				= 6,					 // 删除组织 

	DPSDK_CORE_CHANGE_USER_ROLE                 =7,                      //用户角色变更
	DPSDK_CORE_CHANGE_ROLE_ORG                  =8,                      // 角色组织变更
	DPSDK_CORE_CHANGE_LOGIC_ORG                 =9,                      // 逻辑组织变更
	DPSDK_CORE_CHANGE_CHANNEL_RIGHT             =10,                     // 通道权限变更
	DPSDK_CORE_CHANGE_CODEINFO                  =11,                     // 节点<通道或设备>所属组织及排序变更
}dpsdk_change_type_e;

// 节点改变通知类型
typedef enum
{
	DPSDK_CORE_ORG_CHANGE_UNDEFINE					= 0,					 // 未定义
	DPSDK_CORE_ORG_CHANGE_ADD_DEV					= 1,					 // 增加设备
	DPSDK_CORE_ORG_CHANGE_MODIFY_DEV				= 2,					 // 修改设备
	DPSDK_CORE_ORG_CHANGE_DEL_DEV					= 3,					 // 删除设备
	DPSDK_CORE_ORG_CHANGE_ADD_ORG					= 4,					 // 增加组织
	DPSDK_CORE_ORG_CHANGE_MODIFY_ORG				= 5,					 // 修改组织 
	DPSDK_CORE_ORG_CHANGE_DELETE_ORG				= 6,					 // 删除组织 

	DPSDK_CORE_ORG_CHANGE_USER_ROLE                 =7,                      //用户角色变更
	DPSDK_CORE_ORG_CHANGE_ROLE_ORG                  =8,                      // 角色组织变更
	DPSDK_CORE_ORG_CHANGE_LOGIC_ORG                 =9,                      // 逻辑组织变更
	DPSDK_CORE_ORG_CHANGE_CHANNEL_RIGHT             =10,                     // 通道权限变更
	DPSDK_CORE_ORG_CHANGE_CODEINFO                  =11,                     // 节点<通道或设备>所属组织及排序变更
}dpsdk_org_change_type_e;



// 摄像头类型
typedef enum
{
	CAMERA_TYPE_NORMAL                          = 1,		             // 枪机
	CAMERA_TYPE_SD                              = 2,           			 // 球机
	CAMERA_TYPE_HALFSD                          = 3,                 	 // 半球
	CAMERA_TYPE_EVIDENCE						= 4,					 // 证据通道
	CAMERA_TYPE_NORMAL_HD						= 5,					 // 网络高清枪机，福建高速项目新增摄像头类型begin
	CAMERA_TYPE_SD_HD							= 6,					 // 网络高清球机
	CAMERA_TYPE_NORMAL_SIMULATION_SD			= 8,					 // 模拟标清枪机
	CAMERA_TYPE_SD_SIMULATION_SD				= 9,					 // 模拟标清球机
	CAMERA_TYPE_HALFSD_SIMULATION_SD			= 10,					 // 模拟标清半球
	CAMERA_TYPE_NORMAL_SIMULATION_HD			= 11,					 // 模拟高清枪机
	CAMERA_TYPE_SD_SIMULATION_HD				= 12,					 // 模拟高清球机
	CAMERA_TYPE_HALFSD_SIMULATION_HD			= 13,					 // 模拟高清半球
	CAMERA_TYPE_HALFSD_HD						= 14,					 // 网络高清半球，福建高速项目新增摄像头类型end
}dpsdk_camera_type_e;

// 设备厂商类型
typedef enum
{
	DPSDK_CORE_DEVICE_FACTORY_UNDEFINE			= 0,					 // 未定义
	DPSDK_CORE_DEVICE_FACTORY_DAHUA				= 1,					 // 大华			
	DPSDK_CORE_DEVICE_FACTORY_HIK				= 2,					 // 海康
	DPSDK_CORE_DEVICE_FACTORY_H264				= 16,					 // 国标
	DPSDK_CORE_DEVICE_FACTORY_H3C				= 17,					 // 华三
	DPSDK_CORE_DEVICE_FACTORY_XC				= 18,					 // 信产
	DPSDK_CORE_DEVICE_FACTORY_LIYUAN			= 19,					 // 立元
	DPSDK_CORE_DEVICE_FACTORY_BIT				= 20,					 // 比特
	DPSDK_CORE_DEVICE_FACTORY_H3TS				= 21,					 // 华三ts流
	DPSDK_CORE_DEVICE_FACTORY_TIANSHI			= 36,					 // 天视上传的海康流
}dpsdk_device_factory_type_e;

//是否检查权限
typedef enum
{
	DPSDK_CORE_CHECK_RIGHT						= 0,					// 检查
	DPSDK_CORE_NOT_CHECK_RIGHT					= 1,					// 不检查
}dpsdk_check_right_e;

// 码流类型
typedef enum
{
	DPSDK_CORE_STREAMTYPE_MAIN					= 1,					// 主码流
	DPSDK_CORE_STREAMTYPE_SUB					= 2,					// 辅码流
	DPSDK_CORE_STREAMTYPE_THIRD					= 3,					// 三码流
	DPSDK_CORE_STREAMTYPE_SIGNAL				= 5,					// 本地信号，只能用于上墙
}dpsdk_stream_type_e;

// 媒体类型
typedef enum
{
	DPSDK_CORE_MEDIATYPE_VIDEO					= 1,					 // 视频
	DPSDK_CORE_MEDIATYPE_AUDIO					= 2,					 // 音频
	DPSDK_CORE_MEDIATYPE_ALL					= 3,					 // 音频 + 视频
}dpsdk_media_type_e;

// 传输类型
typedef enum
{
	DPSDK_CORE_TRANSTYPE_UDP					= 0,					 // UDP
	DPSDK_CORE_TRANSTYPE_TCP					= 1,					 // TCP
}dpsdk_trans_type_e;

//流输出荷载类型
typedef enum
{
	DPSDK_CORE_TRACKIDTYPE_PS			= 501,							// PS包
	DPSDK_CORE_TRACKIDTYPE_ORIG	        = 601,							// 第三方原始帧
	DPSDK_CORE_TRACKIDTYPE_DH			= 701,							// 大华帧
	DPSDK_CORE_TRACKIDTYPE_DHSTD		= 801,							// 大华标准帧
	DPSDK_CORE_TRACKIDTYPE_TS			= 901,							// TS包
	DPSDK_CORE_TRACKIDTYPE_RTP			= 101,							// RTP标准流
}dpsdk_trackid_type_e;

//码流的视频分辨率类型
typedef enum
{
	DPSDK_CORE_RESOLUTION_1080P			= 1,							// 1080P
	DPSDK_CORE_RESOLUTION_130M	        = 2,							// 130M
	DPSDK_CORE_RESOLUTION_720P			= 3,							// 720P
	DPSDK_CORE_RESOLUTION_D1		    = 4,							// D1
	DPSDK_CORE_RESOLUTION_CIF			= 5,							// CIF
	DPSDK_CORE_RESOLUTION_QCIF			= 6,							// QCIF
	DPSDK_CORE_RESOLUTION_VGA			= 7,							// VGA
	DPSDK_CORE_RESOLUTION_QVGA			= 8,							// QVGA
}dpsdk_resolution_type_e;

//视频编码格式
typedef enum
{
	DPSDK_CORE_VIDEOCODEC_H264			= 1,							// h264
	DPSDK_CORE_VIDEOCODEC_MPEG4	        = 2,							// mpeg4
	DPSDK_CORE_VIDEOCODEC_JPEG			= 3,							// jpeg
}dpsdk_videocodec_type_e;

//码流转换类型
typedef enum
{
	DPSDK_CORE_SC_NONE = -1,
	DPSDK_CORE_SC_TS,      
	DPSDK_CORE_SC_PS,		
	DPSDK_CORE_SC_RTP,     
	DPSDK_CORE_SC_MP4_FILE,		
	DPSDK_CORE_SC_GDPS,    
	DPSDK_CORE_SC_GAYSPS,  
	DPSDK_CORE_SC_FLV_FILE,
	DPSDK_CORE_SC_ASF_FILE,
	DPSDK_CORE_SC_ASF_STREAM,
	DPSDK_CORE_SC_FLV_STREAM,
	DPSDK_CORE_SC_MP4_NOSEEK,
	DPSDK_CORE_SC_DAV_FILE,
	DPSDK_CORE_SC_DAV_STREAM,
	DPSDK_CORE_SC_AVI_FILE,
	DPSDK_CORE_SC_AVI_STREAM,
	DPSDK_CORE_SC_TS_NEW,
	DPSDK_CORE_SC_PS_NEW,
	DPSDK_CORE_SC_MOV,
	DPSDK_CORE_SC_MP464,
	DPSDK_CORE_SC_MOV64,
	DPSDK_CORE_SC_WAV_FILE,
	DPSDK_CORE_SC_DHPS,
	DPSDK_CORE_SC_DHPS_STREAM,
	DPSDK_CORE_SC_CDJFPS,
	DPSDK_CORE_SC_CDJFTS,
	DPSDK_CORE_SC_RAW,	//裸数据回调
}dpsdk_stream_convertor_type_e;

// 音频类型
typedef enum{
	Talk_Coding_Default                         = 0,		             //default
	Talk_Coding_PCM                             = 1,		             //PCM
	Talk_Coding_G711a,			                                         //G711a
	Talk_Coding_AMR,			                                         //AMR
	Talk_Coding_G711u,			                                         //G711u
	Talk_Coding_G726,			                                         //G726
	Talk_Coding_AAC                             = 8,                     //add by fengjian 2012.8.8
	Talk_Coding_G722                            = 101,		             //G722 海康设备使用
	Talk_Coding_G711_MU,		                                         //G711 海康使用
}dpsdk_audio_type_e;

//位数
typedef enum
{
	Talk_Audio_Bits_8                           = 8,
	Talk_Audio_Bits_16                          = 16,
}dpsdk_talk_bits_e;					

//采样率
typedef enum
{
	Talk_Audio_Sam_8K                           = 8000,
	Talk_Audio_Sam_16K                          = 16000,
	Talk_Audio_Sam_8192                         = 8192,
	Talk_Audio_Sam_48k							= 48000,
}Talk_Sample_Rate_e;			


///
typedef enum{
	Talk_Type_Device                            = 1,	                 //设备
	Talk_Type_Channel		                                             //通道
}dpsdk_talk_type_e;

// 图片类型
typedef enum
{
	DPSDK_CORE_PIC_FORMAT_BMP					= 0,					 // BMP
	DPSDK_CORE_PIC_FORMAT_JPEG					= 1,					 // JPEG
}dpsdk_pic_type_e;

// 录像源类型
typedef enum
{
	DPSDK_CORE_PB_RECSOURCE_ALL					= 1,					 // 所有
	DPSDK_CORE_PB_RECSOURCE_DEVICE				= 2,	    			 // 设备录像
	DPSDK_CORE_PB_RECSOURCE_PLATFORM			= 3,					 // 平台录像
}dpsdk_recsource_type_e;

// 录像类型
typedef enum
{
	DPSDK_CORE_PB_RECORD_UNKONWN				= 0,					 // 全部录像
	DPSDK_CORE_PB_RECORD_MANUAL					= 1,					 // 手动录像
	DPSDK_CORE_PB_RECORD_ALARM					= 2,					 // 报警录像
	DPSDK_CORE_PB_RECORD_MOTION_DETECT			= 3,					 // 移动侦测
	DPSDK_CORE_PB_RECORD_VIDEO_LOST				= 4,					 // 视频丢失
	DPSDK_CORE_PB_RECORD_VIDEO_SHELTER			= 5,					 // 视频遮挡
	DPSDK_CORE_PB_RECORD_TIMER					= 6,					 // 定时录像
	DPSDK_CORE_PB_RECORD_ALL_DAY				= 7,					 // 全天录像
	CENTER_DISK_FULL							= 36,				     // 硬盘满
	CENTER_DISK_FAULT							= 37,				 	 // 硬盘故障
}dpsdk_record_type_e;

// 录像流请求类型
typedef enum
{
	DPSDK_CORE_PB_MODE_NORMAL					= 1,					 // 回放
	DPSDK_CORE_PB_MODE_DOWNLOAD 				= 2,					 // 下载
}dpsdk_pb_mode_e;

// 录像流回放速度
typedef enum
{
	DPSDK_CORE_PB_NORMAL						= 8,						  // 1倍数
	DPSDK_CORE_PB_FAST2							= DPSDK_CORE_PB_NORMAL * 2,   // 2倍数
	DPSDK_CORE_PB_FAST4							= DPSDK_CORE_PB_NORMAL * 4,   // 4倍数
	DPSDK_CORE_PB_FAST8							= DPSDK_CORE_PB_NORMAL * 8,   // 8倍数
	DPSDK_CORE_PB_FAST16						= DPSDK_CORE_PB_NORMAL * 16,  // 16倍数
	DPSDK_CORE_PB_SLOW2							= DPSDK_CORE_PB_NORMAL / 2,   // 1/2倍数
	DPSDK_CORE_PB_SLOW4							= DPSDK_CORE_PB_NORMAL / 4,   // 1/4倍数
	DPSDK_CORE_PB_SLOW8							= DPSDK_CORE_PB_NORMAL / 8,   // 1/8倍数
	DPSDK_CORE_PB_SLOW16						= 0,						  // 1/16倍数
}dpsdk_playback_speed_e;

// 录像打标操作
typedef enum
{
	DPSDK_CORE_OP_TYPE_UNKNOW					= 0,					// 
	DPSDK_CORE_OP_TYPE_ADD,												// 新增
	DPSDK_CORE_OP_TYPE_MODIFY,											// 修改
	DPSDK_CORE_OP_TYPE_DELETE,											// 删除
}dpsdk_operator_type_e;

// 云台方向控制命令			
typedef enum
{
	DPSDK_CORE_PTZ_GO_UP						= 1,					 // 上
	DPSDK_CORE_PTZ_GO_DOWN                      = 2,					 // 下
	DPSDK_CORE_PTZ_GO_LEFT 						= 3,					 // 左
	DPSDK_CORE_PTZ_GO_RIGHT 					= 4,					 // 右
	DPSDK_CORE_PTZ_GO_LEFTUP 					= 5,					 // 左上
	DPSDK_CORE_PTZ_GO_LEFTDOWN 					= 6,					 // 左下
	DPSDK_CORE_PTZ_GO_RIGHTUP 					= 7,					 // 右上
	DPSDK_CORE_PTZ_GO_RIGHTDOWN 				= 8,					 // 右下
}dpsdk_ptz_direct_e;

// 云台图像控制命令
typedef enum
{	
	DPSDK_CORE_PTZ_ADD_ZOOM                      = 0,					 // 变倍+ 
	DPSDK_CORE_PTZ_ADD_FOCUS                     = 1,					 // 变焦+
	DPSDK_CORE_PTZ_ADD_APERTURE                  = 2,					 // 光圈+
	DPSDK_CORE_PTZ_REDUCE_ZOOM 					 = 3,					 // 变倍-
	DPSDK_CORE_PTZ_REDUCE_FOCUS 				 = 4,					 // 变焦-
	DPSDK_CORE_PTZ_REDUCE_APERTURE 				 = 5,					 // 光圈-
}dpsdk_camera_operation_e;

// 云台锁类型
typedef enum
{
	DPSDK_CORE_PTZ_CMD_LOCK						= 1,					 // 锁定当前摄像头
	DPSDK_CORE_PTZ_CMD_UNLOCK_ONE 				= 2,					 // 解锁当前摄像头
	DPSDK_CORE_PTZ_CMD_UNLOCK_ALL 				= 3,					 // 解锁被该用户锁定的所有摄像头
}dpsdk_ptz_locktype_e;

// 云台预置点操作类型
typedef enum
{
	DPSDK_CORE_PTZ_PRESET_LOCATION				= 1,					 // 预置点定位
	DPSDK_CORE_PTZ_PRESET_ADD					= 2,					 // 预置点增加
	DPSDK_CORE_PTZ_PRESET_DEL					= 3,					 // 预置点删除
}dpsdk_ptz_prepoint_cmd_e;

// 云台扩展控制命令
typedef enum 
{
	DPSDK_CORE_PTZ_START_AUTO_ROUND				= 39,					// 开始水平旋转
	DPSDK_CORE_PTZ_STOP_AUTO_ROUND				= 40,					// 停止水平旋转

	DPSDK_CORE_PTZ_SET_LEFT_SCAN_RANGE			= 41,					// 设置左边界
	DPSDK_CORE_PTZ_SET_RIGHT_SCAN_RANGE			= 42,					// 设置右边界
	DPSDK_CORE_PTZ_START_SCAN					= 43,					// 开始线扫
	DPSDK_CORE_PTZ_STOP_SCAN					= 44,					// 停止线扫

	DPSDK_CORE_PTZ_SET_MODLE_START				= 45,					// 设置巡迹开始
	DPSDK_CORE_PTZ_SET_MODLE_CANCEL				= 46,					// 设置巡迹结束
	DPSDK_CORE_PTZ_RUN_MODLE					= 47,					// 运行巡迹
	DPSDK_CORE_PTZ_STOP_MODLE					= 48,					// 停止巡迹
	DPSDK_CORE_PTZ_CLEAR_MODLE					= 49,					// 清除巡迹

	DPSDK_CORE_PTZ_UPDOWN						= 50,					// 翻转命令

	DPSDK_CORE_PTZ_OPEN_ASSISTANT_POINT			= 52,					// 辅助开关开
	DPSDK_CORE_PTZ_CLOSE_ASSISTANT_POINT		= 53,					// 辅助开关关

	DPSDK_CORE_PTZ_OPEN_IPC_MENU				= 54,					// 打开菜单
	DPSDK_CORE_PTZ_CLOSE_IPC_MENU				= 55,					// 关闭菜单
	DPSDK_CORE_PTZ_MENU_ASSURE					= 56,					// 菜单确定
	DPSDK_CORE_PTZ_MENU_CALCEL					= 57,					// 菜单取消
	DPSDK_CORE_PTZ_MENU_UP						= 58,					// 菜单上
	DPSDK_CORE_PTZ_MENU_DOWN					= 59,					// 菜单下
	DPSDK_CORE_PTZ_MENU_LEFT					= 60,					// 菜单左
	DPSDK_CORE_PTZ_MENU_RIGHT					= 61,					// 菜单右
}dpsdk_ptz_extend_cmd_e;

typedef enum{
	Talk_Protocol_Auto=0,
	Talk_Protocol_TCP,
	Talk_Protocol_UDP,
	Talk_Protocol_END,
}Talk_Protocol_Type_e;				//视频流请求协议

// 视频锁定/解锁类型
typedef enum
{
	DPSDK_CORE_VIDEO_CMD_LOCK					= 1,					// 锁定当前摄像头
	DPSDK_CORE_VIDEO_CMD_UNLOCK_ONE,									// 解锁当前摄像头
}dpsdk_video_locktype_e;

// 录像锁定/解锁类型
typedef enum
{
	DPSDK_CORE_RECORD_CMD_LOCK					= 1,					// 录像锁定
	DPSDK_CORE_RECORD_CMD_UNLOCK,										// 录像解锁
}dpsdk_record_locktype_e;

// 报警类型
typedef enum
{
	DPSDK_CORE_ALARM_TYPE_Unknown				= 0,				     // 未知
	DPSDK_CORE_ALARM_TYPE_VIDEO_LOST,									 // 视频丢失
	DPSDK_CORE_ALARM_TYPE_EXTERNAL_ALARM,								 // 外部报警
	DPSDK_CORE_ALARM_TYPE_MOTION_DETECT,								 // 移动侦测
	DPSDK_CORE_ALARM_TYPE_VIDEO_SHELTER,								 // 视频遮挡
	DPSDK_CORE_ALARM_TYPE_DISK_FULL,									 // 硬盘满
	DPSDK_CORE_ALARM_TYPE_DISK_FAULT,									 // 硬盘故障
	DPSDK_CORE_ALARM_TYPE_FIBER,										 // 光纤报警
	DPSDK_CORE_ALARM_TYPE_GPS,											 // GPS信息
	DPSDK_CORE_ALARM_TYPE_3G,											 // 3G
	DPSDK_CORE_ALARM_TYPE_STATUS_RECORD,								 // 设备录像状态
	DPSDK_CORE_ALARM_TYPE_STATUS_DEVNAME,								 // 设备名
	DPSDK_CORE_ALARM_TYPE_STATUS_DISKINFO,								 // 硬盘信息
	DPSDK_CORE_ALARM_TYPE_IPC_OFF,										 // 前端IPC断线
	DPSDK_CORE_ALARM_TYPE_DEV_DISCONNECT			= 16,					//设备断线报警

	//景德镇华润燃气项目 
	DPSDK_CORE_ALARM_POWER_INTERRUPT				= 17,					// 市电中断报警 
	DPSDK_CORE_ALARM_POWER_ENABLED					= 18,					// 市电启用报警 
	DPSDK_CORE_ALARM_INFRARED_DETECT				= 19,					// 红外探测报警 
	DPSDK_CORE_ALARM_GAS_OVER_SECTION				= 20,					// 燃气浓度超过上限 
	DPSDK_CORE_ALARM_FLOW_OVER_SECTION				= 21,					// 瞬时流量超过上限 
	DPSDK_CORE_ALARM_TEMPERATURE_OVER_SECTION		= 22,					// 温度超过上限 
	DPSDK_CORE_ALARM_TEMPERATURE_UNDER_SECTION		= 23,					// 温度低于下限 
	DPSDK_CORE_ALARM_PRESSURE_OVER_SECTION			= 24,					// 压力超过上限 
	DPSDK_CORE_ALARM_PRESSURE_UNDER_SECTION			= 25,					// 压力低于下限

	DPSDK_CORE_ALARM_STATIC_DETECTION				= 26,					// 静态检测 
	DPSDK_CORE_ALARM_REMOTE_EXTERNAL_ALARM			= 28,					// 远程外部报警

	//门禁
	DPSDK_CORE_ALARM_DOOR_BEGIN				     = 40,		    	     // 门禁设备报警起始
	DPSDK_CORE_ALARM_FORCE_CARD_OPENDOOR		 = 41,				     // 胁迫刷卡开门
	DPSDK_CORE_ALARM_VALID_PASSWORD_OPENDOOR	 = 42,				     // 合法密码开门
	DPSDK_CORE_ALARM_INVALID_PASSWORD_OPENDOOR	 = 43,				     // 非法密码开门
	DPSDK_CORE_ALARM_FORCE_PASSWORD_OPENDOOR	 = 44,				     // 胁迫密码开门
	DPSDK_CORE_ALARM_VALID_FINGERPRINT_OPENDOOR	 = 45,			         // 合法指纹开门
	DPSDK_CORE_ALARM_INVALID_FINGERPRINT_OPENDOOR	= 46,				 // 非法指纹开门
	DPSDK_CORE_ALARM_FORCE_FINGERPRINT_OPENDOOR	 = 47,				     // 胁迫指纹开门

	DPSDK_CORE_ALARM_TYPE_VALID_CARD_READ		 = 51,				     // 合法刷卡/开门
	DPSDK_CORE_ALARM_TYPE_INVALID_CARD_READ,							 // 非法刷卡/开门
	DPSDK_CORE_ALARM_TYPE_DOOR_MAGNETIC_ERROR,							 // 门磁报警
	DPSDK_CORE_ALARM_TYPE_DOOR_BREAK,									 // 破门报警和开门超时报警
	DPSDK_CORE_ALARM_TYPE_DOOR_ABNORMAL_CLOSED,							 // 门非正常关闭
	DPSDK_CORE_ALARM_TYPE_DOOR_NORMAL_CLOSED,							 // 门正常关闭
	DPSDK_CORE_ALARM_TYPE_DOOR_OPEN,									 // 门打开

	DPSDK_CORE_ALARM_DOOR_OPEN_TIME_OUT_BEG		= 60,
	DPSDK_CORE_ALARM_DOOR_OPEN_TIME_OUT_END		= 70,

	//报警主机
	ALARM_TYPE_ALARMHOST_BEGIN			= 80,
	DPSDK_CORE_ALARM_TYPE_ALARM_CONTROL_ALERT	= 81,				     // 报警主机报警
	DPSDK_CORE_ALARM_TYPE_FIRE_ALARM,									 // 火警
	DPSDK_CORE_ALARM_TYPE_ZONE_DISABLED,								 // 防区失效
	DPSDK_CORE_ALARM_TYPE_BATTERY_EMPTY,								 // 电池没电
	ALARM_TYPE_AC_OFF					= 85,					// 市电断开-设备报警
	ALARM_TYPE_ALARMHOST_END			= 90,	

	DPSDK_CORE_ALARM_FILESYSTEM				    = 100,					 // 文件系统
	DPSDK_CORE_ALARM_RAID_FAULT,										 // raid故障
	DPSDK_CORE_ALARM_RECORDCHANNELFUNCTION_ABNORMAL,					 // 录像通道功能异常
	DPSDK_CORE_SVR_HARDDISK_STATUS,										 // 硬盘状态
	DPSDK_CORE_ALARM_RECORD_REPAIR,										 // 录像补全 -P3.0

	//begin电网报警类型
	ELECTRIC_WIRE_SHOCK					= 109,					// 电网触电
	ELECTRIC_WIRE_INTERRUPT				= 110,					// 电网断电
	ELECTRIC_WIRE_SHORT_CIRCUIT			= 111,					// 电网短路
	ELECTRIC_WIRE_BREAKDOWN				= 112,					// 电网故障
	ELECTRIC_WIRE_VOLTAGE_LOW			= 113,					// 电网电压低
	//end
	ALARM_TYPE_RECORD_WRITE_FAIL		= 114,					// 录像写入失败

	//电网报警类型新增begin add by hu_wenjuan
	ELECTRIC_ALARM_BEGIN_EX                         = 115, 
	ELECTRIC_BREAK_CIRCUIT                          = 115,                                  // 电网开路 
	ELECTRIC_SENSE_ALARM                            = 116,                                  // 电网传感报警 
	ELECTRIC_ALARM_END_EX                           = 150,                                  
	//电网报警类型新增end 

	ALARM_VTT_URGENCY                   = 160,                  // VTT设备紧急按钮报警

	//-M的相关报警在这里添加
	DPSDK_CORE_ALARM_MOTOR_BEGIN					= 200,
	DPSDK_CORE_ALARM_OVERSPEED_OCCURE				= 201, 			     // 超速报警产生
	DPSDK_CORE_ALARM_OVERSPEED_DISAPPEAR,  								 // 超速报警消失
	DPSDK_CORE_ALARM_DRIVEROUT_DRIVERALLOW,								 // 驶出行区
	DPSDK_CORE_ALARM_DRIVERIN_DRIVERALLOW,								 // 驶入行区
	DPSDK_CORE_ALARM_DRIVEROUT_FORBIDDRIVE,								 // 驶出禁入区
	DPSDK_CORE_ALARM_DRIVERIN_FORBIDDRIVE,								 // 驶入禁入区
	DPSDK_CORE_ALARM_DRIVEROUT_LOADGOODS,								 // 驶出装货区
	DPSDK_CORE_ALARM_DRIVERIN_LOADGOODS,								 // 驶入装货区
	DPSDK_CORE_ALARM_DRIVEROUT_UNLOADGOODS,								 // 驶出卸货区
	DPSDK_CORE_ALARM_DRIVERIN_UNLOADGOODS,								 // 驶入卸货区
	DPSDK_CORE_ALARM_CAR_OVER_LOAD,										 // 超载
	DPSDK_CORE_ALARM_SPEED_SOON_ZERO,									 // 急刹车
	DPSDK_CORE_ALARM_3GFLOW,											 // 3G流量
	DPSDK_CORE_ALARM_AAC_POWEROFF,										 // ACC断电报警
	DPSDK_CORE_ALARM_SPEEDLIMIT_LOWERSPEED,								 // 限速报警 LowerSpeed
	DPSDK_CORE_ALARM_SPEEDLIMIT_UPPERSPEED,								 // 限速报警 UpperSpeed 
	DPSDK_CORE_ALARM_VEHICLEINFOUPLOAD_CHECKIN,							 // 车载自定义信息上传 CheckIn
	DPSDK_CORE_ALARM_VEHICLEINFOUPLOAD_CHECKOUT,						 // 车载自定义信息上传 CheckOut
	ALARM_CAR_OPEN_DOOR 				= 219,                			 // 开门报警
	ALARM_URGENCY						= 220,							 // 紧急报警
	ALARM_DEV_VOICE_EX     				= 229,    				// 设备语音请求报警
	DPSDK_CORE_ALARM_GAS_LOWLEVEL					= 236,				 // 油耗报警
	DPSDK_CORE_ALARM_MOTOR_END						= 300,

	//智能报警
	DPSDK_CORE_ALARM_IVS_ALARM_BEGIN				= 300,				 // 智能设备报警类型在dhnetsdk.h基础上+300（DMS服务中添加）
	DPSDK_CORE_ALARM_IVS_ALARM,											 // 智能设备报警
	DPSDK_CORE_ALARM_CROSSLINEDETECTION,								 // 警戒线事件
	DPSDK_CORE_ALARM_CROSSREGIONDETECTION ,								 // 警戒区事件
	DPSDK_CORE_ALARM_PASTEDETECTION,									 // 贴条事件
	DPSDK_CORE_ALARM_LEFTDETECTION,										 // 物品遗留事件
	DPSDK_CORE_ALARM_STAYDETECTION,										 // 停留事件
	DPSDK_CORE_ALARM_WANDERDETECTION,									 // 徘徊事件
	DPSDK_CORE_ALARM_PRESERVATION,										 // 物品保全事件
	DPSDK_CORE_ALARM_MOVEDETECTION,										 // 移动事件
	DPSDK_CORE_ALARM_TAILDETECTION,										 // 尾随事件
	DPSDK_CORE_ALARM_RIOTERDETECTION,									 // 聚众事件
	DPSDK_CORE_ALARM_FIREDETECTION,										 // 火警事件
	DPSDK_CORE_ALARM_SMOKEDETECTION,									 // 烟雾报警事件
	DPSDK_CORE_ALARM_FIGHTDETECTION,									 // 斗殴事件
	DPSDK_CORE_ALARM_FLOWSTAT,											 // 流量统计事件
	DPSDK_CORE_ALARM_NUMBERSTAT,										 // 数量统计事件
	DPSDK_CORE_ALARM_CAMERACOVERDDETECTION,								 // 摄像头覆盖事件
	DPSDK_CORE_ALARM_CAMERAMOVEDDETECTION,								 // 摄像头移动事件
	DPSDK_CORE_ALARM_VIDEOABNORMALDETECTION,							 // 视频异常事件
	DPSDK_CORE_ALARM_VIDEOBADDETECTION,									 // 视频损坏事件
	DPSDK_CORE_ALARM_TRAFFICCONTROL,									 // 交通管制事件
	DPSDK_CORE_ALARM_TRAFFICACCIDENT,									 // 交通事故事件
	DPSDK_CORE_ALARM_TRAFFICJUNCTION,									 // 交通路口事件
	DPSDK_CORE_ALARM_TRAFFICGATE,										 // 交通卡口事件
	DPSDK_CORE_ALARM_TRAFFICSNAPSHOT,									 // 交通抓拍事件
	DPSDK_CORE_ALARM_FACEDETECT,										 // 人脸检测事件 
	DPSDK_CORE_ALARM_TRAFFICJAM,										 // 交通拥堵事件

	DPSDK_CORE_ALARM_TRAFFIC_RUNREDLIGHT			= 0x00000100 + 300,	 // 交通违章-闯红灯事件
	DPSDK_CORE_ALARM_TRAFFIC_OVERLINE				= 0x00000101 + 300,	 // 交通违章-压车道线事件
	DPSDK_CORE_ALARM_TRAFFIC_RETROGRADE				= 0x00000102 + 300,	 // 交通违章-逆行事件
	DPSDK_CORE_ALARM_TRAFFIC_TURNLEFT				= 0x00000103 + 300,	 // 交通违章-违章左转
	DPSDK_CORE_ALARM_TRAFFIC_TURNRIGHT			    = 0x00000104 + 300,	 // 交通违章-违章右转
	DPSDK_CORE_ALARM_TRAFFIC_UTURN					= 0x00000105 + 300,	 // 交通违章-违章掉头
	DPSDK_CORE_ALARM_TRAFFIC_OVERSPEED				= 0x00000106 + 300,	 // 交通违章-超速
	DPSDK_CORE_ALARM_TRAFFIC_UNDERSPEED				= 0x00000107 + 300,	 // 交通违章-低速
	DPSDK_CORE_ALARM_TRAFFIC_PARKING				= 0x00000108 + 300,	 // 交通违章-违章停车
	DPSDK_CORE_ALARM_TRAFFIC_WRONGROUTE				= 0x00000109 + 300,	 // 交通违章-不按车道行驶
	DPSDK_CORE_ALARM_TRAFFIC_CROSSLANE				= 0x0000010A + 300,	 // 交通违章-违章变道
	DPSDK_CORE_ALARM_TRAFFIC_OVERYELLOWLINE			= 0x0000010B + 300,	 // 交通违章-压黄线
	DPSDK_CORE_ALARM_TRAFFIC_DRIVINGONSHOULDER		= 0x0000010C + 300,	 // 交通违章-路肩行驶事件  
	DPSDK_CORE_ALARM_TRAFFIC_YELLOWPLATEINLANE		= 0x0000010E + 300,	 // 交通违章-黄牌车占道事件
	DPSDK_CORE_ALARM_CROSSFENCEDETECTION			= 0x0000011F + 300,	 // 翻越围栏事件
	DPSDK_CORE_ALARM_ELECTROSPARKDETECTION			= 0X00000110 + 300,	 // 电火花事件
	DPSDK_CORE_ALARM_TRAFFIC_NOPASSING				= 0x00000111 + 300,	 // 交通违章-禁止通行事件
	DPSDK_CORE_ALARM_ABNORMALRUNDETECTION			= 0x00000112 + 300,	 // 异常奔跑事件
	DPSDK_CORE_ALARM_RETROGRADEDETECTION			= 0x00000113 + 300,	 // 人员逆行事件
	DPSDK_CORE_ALARM_INREGIONDETECTION				= 0x00000114 + 300,	 // 区域内检测事件
	DPSDK_CORE_ALARM_TAKENAWAYDETECTION				= 0x00000115 + 300,	 // 物品搬移事件
	DPSDK_CORE_ALARM_PARKINGDETECTION				= 0x00000116 + 300,	 // 非法停车事件
	DPSDK_CORE_ALARM_FACERECOGNITION				= 0x00000117 + 300,	 // 人脸识别事件
	DPSDK_CORE_ALARM_TRAFFIC_MANUALSNAP				= 0x00000118 + 300,	 // 交通手动抓拍事件
	DPSDK_CORE_ALARM_TRAFFIC_FLOWSTATE				= 0x00000119 + 300,	 // 交通流量统计事件
	DPSDK_CORE_ALARM_TRAFFIC_STAY					= 0x0000011A + 300,	 // 交通滞留事件
	DPSDK_CORE_ALARM_TRAFFIC_VEHICLEINROUTE			= 0x0000011B + 300,	 // 有车占道事件
	DPSDK_CORE_ALARM_MOTIONDETECT					= 0x0000011C + 300,	 // 视频移动侦测事件
	DPSDK_CORE_ALARM_LOCALALARM						= 0x0000011D + 300,	 // 外部报警事件
	DPSDK_CORE_ALARM_PRISONERRISEDETECTION			= 0X0000011E + 300,	 // 看守所囚犯起身事件
	DPSDK_CORE_ALARM_IVS_B_ALARM_END,									 // 以上报警都为IVS_B服务的报警类型，与SDK配合
	DPSDK_CORE_ALARM_VIDEODIAGNOSIS					= 0X00000120 + 300,	 // 视频诊断结果事件
	DPSDK_CORE_ALARM_IVS_V_ALARM                    =  DPSDK_CORE_ALARM_VIDEODIAGNOSIS,	// 
	DPSDK_CORE_ALARM_IVS_RFID_INFO					= 0x00000166 + 300,  // RFID红外线检测信息事件

	//新增智能报警start
	DPSDK_CORE_ALARM_IVS_AUDIO_ABNORMALDETECTION    = 0x00000126 + 300,	 // 声音异常检测
	DPSDK_CORE_ALARM_CLIMB_UP						= 0x00000128 + 300,	 // 攀高检测 
	DPSDK_CORE_ALARM_LEAVE_POST  					= 0x00000129 + 300,	 // 离岗检测
	//新增智能报警End

	DPSDK_CORE_ALARM_IVS_TRAFFIC_WITHOUT_SAFEBELT   = 0x00000138 + 300,  // 交通未系安全带事件
	DPSDK_CORE_ALARM_IVS_TRAFFIC_DRIVER_SMOKING     = 0x00000139 + 300,  // 驾驶员抽烟事件
	DPSDK_CORE_ALARM_IVS_TRAFFIC_DRIVER_CALLING     = 0x0000013A + 300,  // 驾驶员打电话事件

	DPSDK_CORE_ALARM_IVS_SHOPPRESENCE				= 0x00000246 + 300,  //商铺占道经营事件   882
	DPSDK_CORE_ALARM_IVS_WASTEDUMPED				= 0x00000247 + 300,  //垃圾违章倾倒事件   883

	DPSDK_CORE_ALARM_IVS_ALARM_END					= 1000,				 // 智能设备报警类型的范围为300-1000
	DPSDK_CORE_ALARM_OSD,												 // osd信息
	DPSDK_CORE_ALARM_CROSS_INFO,										 // 十字路口

	DPSDK_CORE_ALARM_CLIENT_ALARM_BEGIN				= 1100,				 // 客户端平台报警开始
	DPSDK_CORE_ALARM_CLIENT_DERELICTION,								 // 遗留检测[交通事件-抛洒物]
	DPSDK_CORE_ALARM_CLIENT_RETROGRADATION,								 // 逆行 [交通事件]
	DPSDK_CORE_ALARM_CLIENT_OVERSPEED,									 // 超速  [交通事件]
	DPSDK_CORE_ALARM_CLIENT_LACK_ALARM,									 // 欠速  [交通事件]
	DPSDK_CORE_ALARM_CLIENT_FLUX_COUNT,									 // 流量统计[交通事件]
	DPSDK_CORE_ALARM_CLIENT_PARKING,									 // 停车检测[交通事件]
	DPSDK_CORE_ALARM_CLIENT_PASSERBY,									 // 行人检测[交通事件]
	DPSDK_CORE_ALARM_CLIENT_JAM,										 // 拥堵检测[交通事件]
	DPSDK_CORE_ALARM_CLIENT_AREA_INBREAK,								 // 特殊区域入侵
	DPSDK_CORE_ALARM_CLIENT_ALARM_END				= 1200,				 // 客户端平台报警结束

	ALARM_SYSTEM_BEGIN					= 1200,					// 来自系统的报警
	ALARM_HOST_TEMPRATURER				= 1201,					// 主机温度过高
	ALARM_RAID_LOAD						= 1202,					// raid降级
	ALARM_SERVER_AUTO_MIGRATE			= 1203,					// 服务器自动迁移
	ALARM_SERVER_MANUAL_MIGRATE			= 1204,					// 服务器手动迁移
	ALARM_SERVER_STATUS_CHANGE			= 1205,					// 服务器状态变更 
	ALARM_MASTER_TO_BACKUP				= 1206,					// 双机热备主机切备机
	ALARM_BACKUP_TO_MASTER				= 1207,					// 双机热备备机切主机
	ALARM_BACKUP_ABNORMAL				= 1208,					// 双机热备备机故障
	ALARM_BACKUP_NORMAL					= 1209,					// 双机热备备机故障恢复
	ALARM_SYSTEM_END					= 1300,

	// -E 视频质量诊断 新增12种报警类型
	ALARM_VQDS_VIDEO_LOST				= 1500,					// 视频质量诊断-视频丢失
	ALARM_VQDS_HIGHBRIGHT				= 1501,					// 高亮度警告
	ALARM_VQDS_HIGHBRIGHT_RED			= 1502,					// 高亮度红色报警
	ALARM_VQDS_LOWBRIGHT				= 1503,					// 低亮度警告
	ALARM_VQDS_LOWBRIGHT_RED			= 1504,					// 低亮度红色报警
	ALARM_VQDS_CONTRAST					= 1505,					// 对比度警告
	ALARM_VQDS_CONTRAST_RED				= 1506,					// 对比度红色报警
	ALARM_VQDS_CLARITY					= 1507,					// 清晰度警告
	ALARM_VQDS_CLARITY_RED				= 1508,					// 清晰度红色报警
	ALARM_VQDS_COLOR_OFFSET				= 1509,					// 色彩偏差警告
	ALARM_VQDS_COLOR_OFFSET_RED			= 1510,					// 偏色红色报警
	ALARM_VQDS_DIAGNOSE_FAIL			= 1511,					// 视频质量诊断失败

	ALARM_ALARMHOST_MEDICAL				 = 1604,				 // 医疗报警
	ALARM_ALARMHOST_URGENCY				 = 1605,				 // 报警主机紧急报警
	ALARM_ALARMHOST_CATCH				 = 1606,				 // 挟持报警
	ALARM_ALARMHOST_MENACE_SLIENCE       = 1607,				 // 无声威胁
	ALARM_ALARMHOST_PERIMETER            = 1608,				 // 周界报警
	ALARM_ALARMHOST_DEFENCEAREA_24H		 = 1609,				 // 24小时防区报警
	ALARM_ALARMHOST_DEFENCEAREA_DELAY	 = 1610,				 // 延时防区报警
	ALARM_ALARMHOST_DEFENCEAREA_INITIME  = 1611,				 // 及时防区报警
	ALARM_ALARMHOST_BREAK				 = 1612,				 // 防拆
	ALARM_ALARMHOST_AUX_OVERLOAD         = 1613,                 // AUX过流
	ALARM_ALARMHOST_AC_POWDOWN			 = 1614,                 // 交流电掉电
	ALARM_ALARMHOST_BAT_DOWN			 = 1615,                 // 电池欠压
	ALARM_ALARMHOST_SYS_RESET			 = 1616,                 // 系统复位
	ALARM_ALARMHOST_PROGRAM_CHG          = 1617,                 // 电池掉线
	ALARM_ALARMHOST_BELL_CUT			 = 1618,                 // 警号被切断或短路
	ALARM_ALARMHOST_PHONE_ILL			 = 1619,                 // 电话切断或失效
	ALARM_ALARMHOST_MESS_FAIL			 = 1620,				 // 通讯失败
	ALARM_ALARMHOST_WIRELESS_PWDOWN		 = 1621,				 // 无线探测器欠压
	ALARM_ALARMHOST_SIGNIN_FAIL			 = 1622,				 // 登录失败
	ALARM_ALARMHOST_ERR_CODE			 = 1623,				 // 错误密码登陆
	ALARM_ALARMHOST_MANAUL_TEST			 = 1624,				 // 手动测试
	ALARM_ALARMHOST_CYCLE_TEST			 = 1625,				 // 定期测试
	ALARM_ALARMHOST_SVR_REQ				 = 1626,				 // 服务请求
	ALARM_ALARMHOST_BUF_RST				 = 1627,				 // 报警缓冲复位
	ALARM_ALARMHOST_CLR_LOG				 = 1628,				 // 清除日志
	ALARM_ALARMHOST_TIME_RST			 = 1629,				 // 日期时间复位
	ALARM_ALARMHOST_NET_FAIL			 = 1630,				 // 网络错误
	ALARM_ALARMHOST_IP_CONFLICT			 = 1631,				 // IP冲突
	ALARM_ALARMHOST_KB_BREAK			 = 1632,				 // 键盘防拆
	ALARM_ALARMHOST_KB_ILL               = 1633,				 // 键盘问题
	ALARM_ALARMHOST_SENSOR_O			 = 1634,				 // 探测器开路
	ALARM_ALARMHOST_SENSOR_C			 = 1635,				 // 探测器短路
	ALARM_ALARMHOST_SENSOR_BREAK		 = 1636,				 // 探测器防拆
	ALARM_FIRE_ALARM					 = 1637,				 // 报警主机火警

	//接警主机报警end
	ALARM_POWER_MAJORTOSPARE			= 1640,					// 主电源切备用电源
	ALARM_POWER_SPARETOMAJOR			= 1641,					// 备用电源切主电源
	ALARM_ENCODER_ALARM					= 1642,					// 编码器故障报警
	ALARM_DEVICE_REBOOT					= 1643,					// 设备重启报警
	ALARM_DISK							= 1644,					// 硬盘报警
	ALARM_NET_ABORT_WIRE				= 1645,					// 有线网络故障报警
	ALARM_NET_ABORT_WIRELESS			= 1646,					// 无线网络故障报警
	ALARM_NET_ABORT_3G					= 1647,					// 3G网络故障报警
	ALARM_MAC_CONFLICT					= 1648,					// MAC冲突
	ALARM_POWER_OFF_BACKUP				= 1649,					// 备用电源掉电
	ALARM_CHASSISINTRUDED				= 1650,					// 机箱入侵	
	ALARM_PSTN_BREAK_LINE				= 1651,					// PSTN掉线报警
	ALARM_CALL_ALARM_HOST				= 1652,					// 电话报警主机设备报警
	ALARM_CALL_ALARM_HOST_CHN			= 1653,					// 电话报警主机通道报警
	ALARM_RCEMERGENCY_CALL				= 1654,					// 紧急救助未知事件
	ALARM_RCEMERGENCY_CALL_KEYBOARD_FIRE = 1655,				// 紧急救助键盘区火警
	ALARM_RCEMERGENCY_CALL_KEYBOARD_DURESS = 1656,				// 紧急救助键盘区胁迫
	ALARM_RCEMERGENCY_CALL_KEYBOARD_ROBBER = 1657,				// 紧急救助键盘区匪警
	ALARM_RCEMERGENCY_CALL_KEYBOARD_MEDICAL = 1658,				// 紧急救助键盘区医疗
	ALARM_RCEMERGENCY_CALL_KEYBOARD_EMERGENCY = 1659,			// 紧急救助键盘区紧急
	ALARM_RCEMERGENCY_CALL_WIRELESS_EMERGENCY = 1660,			// 紧急救助遥控器紧急
	ALARM_LOCK_BREAK					= 1661,					// 撬锁
	ALARM_ACCESS_CTL_OPEN				= 1662, 				// 视频报警主机异常开门
	// 报警运营平台新增end

	//动环(PE)报警-(SCS_ALARM_SWITCH_START 取名直接来自SCS动环文档)
	//系统工程动环增加报警类型ALARM_SCS_BEGIN
	//开关量，不可控
	ALARM_SCS_SWITCH_START				= 1800,
	ALARM_SCS_INFRARED,											// 红外对射告警
	ALARM_SCS_SMOKE,											// 烟感告警
	ALARM_SCS_WATER,                							// 水浸告警
	ALARM_SCS_COMPRESSOR,           							// 压缩机故障告警
	ALARM_SCS_OVERLOAD,             							// 过载告警
	ALARM_SCS_BUS_ANOMALY,          							// 母线异常
	ALARM_SCS_LIFE,                 							// 寿命告警
	ALARM_SCS_SOUND,                							// 声音告警
	ALARM_SCS_TIME,                 							// 时钟告警
	ALARM_SCS_FLOW_LOSS,            							// 气流丢失告警
	ALARM_SCS_FUSING,               							// 熔断告警
	ALARM_SCS_BROWN_OUT,            							// 掉电告警
	ALARM_SCS_LEAKING,              							// 漏水告警
	ALARM_SCS_JAM_UP,               							// 堵塞告警
	ALARM_SCS_TIME_OUT,             							// 超时告警
	ALARM_SCS_REVERSE_ORDER,        							// 反序告警
	ALARM_SCS_NETWROK_FAILURE,      							// 组网失败告警
	ALARM_SCS_UNIT_CODE_LOSE,       							// 机组码丢失告警
	ALARM_SCS_UNIT_CODE_DISMATCH,   							// 机组码不匹配告警
	ALARM_SCS_FAULT,                							// 故障告警
	ALARM_SCS_UNKNOWN,              							// 未知告警
	ALARM_SCS_CUSTOM,               							// 自定义告警
	ALARM_SCS_NOPERMISSION,         							// 无权限告警
	ALARM_SCS_INFRARED_DOUBLE,      							// 红外双鉴告警
	ALARM_SCS_ELECTRONIC_FENCE,     							// 电子围栏告警
	ALARM_SCS_UPS_MAINS,            							// 市电正常市电异常
	ALARM_SCS_UPS_BATTERY,          							// 电池正常电池异常
	ALARM_SCS_UPS_POWER_SUPPLY,     							// UPS正常输出旁路供电
	ALARM_SCS_UPS_RUN_STATE,        							// UPS正常UPS故障
	ALARM_SCS_UPS_LINE_STYLE,       							// UPS类型为在线式UPS类  型为后备式
	ALARM_SCS_XC,                   							// 小车
	ALARM_SCS_DRQ,                  							// 断路器
	ALARM_SCS_GLDZ,                 							// 隔离刀闸
	ALARM_SCS_JDDZ,                								// 接地刀闸
	ALARM_SCS_IN_END,											// 请注意这个值，不用把他作为判断值；只标记说“开关量，不可控”结束；
	//因为接下来的“开关量，可控”没有开始标记如ALARM_SCS_DOOR_START

	//开关量，可控，请注意接下来的ALARM_SCS_DOOR_SWITCH这个不能作为BEGIN用
	ALARM_SCS_DOOR_SWITCH				= 1850,					// 门禁控制器开关告警
	ALARM_SCS_UPS_SWITCH,										// UPS开关告警,
	ALARM_SCS_DBCB_SWITCH,          							// 配电柜开关告警
	ALARM_SCS_ACDT_SWITCH,          							// 空调开关告警
	ALARM_SCS_DTPW_SWITCH,          							// 直流电源开关告警
	ALARM_SCS_LIGHT_SWITCH,         							// 灯光控制器开关告警
	ALARM_SCS_FAN_SWITCH,           							// 风扇控制器开关告警
	ALARM_SCS_PUMP_SWITCH,          							// 水泵开关告警
	ALARM_SCS_BREAKER_SWITCH,       							// 刀闸开关告警
	ALARM_SCS_RELAY_SWITCH,         							// 继电器开关告警
	ALARM_SCS_METER_SWITCH,        								// 电表开关告警
	ALARM_SCS_TRANSFORMER_SWITCH,   							// 变压器开关告警
	ALARM_SCS_SENSOR_SWITCH,        							// 传感器开关告警
	ALARM_SCS_RECTIFIER_SWITCH,     							// 整流器告警
	ALARM_SCS_INVERTER_SWITCH,      							// 逆变器告警
	ALARM_SCS_PRESSURE_SWITCH,      							// 压力开关告警
	ALARM_SCS_SHUTDOWN_SWITCH,      							// 关机告警
	ALARM_SCS_WHISTLE_SWITCH,	   								// 警笛告警
	ALARM_SCS_SWITCH_END,
	//模拟量
	ALARM_SCS_ANALOG_START				= 1880,
	ALARM_SCS_TEMPERATURE,										// 温度告警
	ALARM_SCS_HUMIDITY,             							// 湿度告警
	ALARM_SCS_CONCENTRATION,        							// 浓度告警
	ALARM_SCS_WIND,                 							// 风速告警
	ALARM_SCS_VOLUME,               							// 容量告警
	ALARM_SCS_VOLTAGE,              							// 电压告警
	ALARM_SCS_ELECTRICITY,          							// 电流告警
	ALARM_SCS_CAPACITANCE,          							// 电容告警
	ALARM_SCS_RESISTANCE,           							// 电阻告警
	ALARM_SCS_CONDUCTANCE,          							// 电导告警
	ALARM_SCS_INDUCTANCE,           							// 电感告警
	ALARM_SCS_CHARGE,               							// 电荷量告警
	ALARM_SCS_FREQUENCY,            							// 频率告警
	ALARM_SCS_LIGHT_INTENSITY,      							// 发光强度告警(坎)
	ALARM_SCS_PRESS,                							// 力告警（如牛顿，千克力）
	ALARM_SCS_PRESSURE,             							// 压强告警（帕，大气压）
	ALARM_SCS_HEAT_TRANSFER,        							// 导热告警（瓦每平米）
	ALARM_SCS_THERMAL_CONDUCTIVITY, 							// 热导告警（kcal/(m*h*℃)）
	ALARM_SCS_VOLUME_HEAT,          							// 比容热告（kcal/(kg*℃)）
	ALARM_SCS_HOT_WORK,             							// 热功告警（焦耳）
	ALARM_SCS_POWER,                							// 功率告警（瓦）
	ALARM_SCS_PERMEABILITY,         							// 渗透率告警（达西）
	ALARM_SCS_PROPERTION,										// 比例（包括电压电流变比，功率因素，负载单位为%） 
	ALARM_SCS_ENERGY,											// 电能（单位为J）
	ALARM_SCS_ANALOG_END,
	//ALARM_SCS_END,

	ALARM_IP_DEV_TALK					= 1907,					// IP设备对讲报警

	ALARM_TYPE_UNIFY_BEGIN				= 1908,					// 报警类型统一管理，不需要在EnumCenterRecType增加
	ALARM_VOICE_EXCEPTION				= 1909,					// 音频异常报警	
	ALARM_TYPE_UNIFY_END,										// 报警类型统一管理，不需要在EnumCenterRecType增加

	//EVS新增报警类型
	ALARM_NO_DISK                       = 1916,					// 无硬盘报警 
	ALARM_DOUBLE_DEV_VERSION_ABNORMAL   = 1917,					// 双控设备主板与备板之间版本信息不一致异常事件 
	ALARM_DCSSWITCH                     = 1918,					// 主备切换事件/集群切换报警 
	ALARM_DEV_RAID_FAILED               = 1919,					// 设备RAID错误报警 
	ALARM_DEV_RAID_DEGRADED             = 1920,					// 设备RAID降级报警 
	ALARM_BUF_DROP_FRAME                = 1921,					// 录像缓冲区丢帧报警

	AE_ALARM_TYPE_BEGIN					= 2000,
	ALARM_DOOR_MAGNETISM				= 2200,					// 门磁
	ALARM_PASSIVE_INFRARED				= 2201,					// 被动红外
	ALARM_GAS							= 2202,					// 气感
	ALARM_INITIATIVE_INFRARED			= 2203,					// 主动红外
	ALARM_GLASS_CRASH					= 2204,					// 玻璃破碎
	ALARM_EXIGENCY_SWITCH				= 2205,					// 紧急开关
	ALARM_SHAKE							= 2206,					// 震动
	ALARM_BOTH_JUDGE					= 2207,					// 双鉴（红外+微波）
	ALARM_THREE_TECHNIC					= 2208,					// 三技术
	ALARM_CALL_BUTTON					= 2209,      			// 呼叫按钮
	ALARM_SENSE_OTHER					= 2210,	    			// 其他
	AE_ALARM_TYPE_END					= 2400,

	//begin震动光纤报警类型
	ALARM_TYPE_VIBRATIONFIBER_BEGIN     = 2601,					// 震动光纤1
	ALARM_VIBRATIONFIBER_SNLALARM,                              // 开关量报警 
	ALARM_VIBRATIONFIBER_BOXALARM,                              // 开关盒报警 
	ALARM_VIBRATIONFIBER_INVALIDZONE,                           // 防区失效1106 
	ALARM_VIBRATIONFIBER_SIGNAL_OFF,                            // 光纤信号源停止 
	ALARM_VIBRATIONFIBER_FIBRE_BREAK,                           // 光纤断开
	ALARM_TYPE_VIBRATIONFIBER_END		= 2700,					// 震动光纤5
	//end
	//巡更报警
	ALARM_PATROL_BEGIN					 = 2701,
	ALARM_PATROL_EXCEPTION				 = 2702,				// 巡更异常报警 
	ALARM_PATROL_END					 = 2800,
	// -F预留报警类型，自定义报警
	ALARM_TYPE_USERDEFINE_BEGIN			 = 3101,
	ALARM_TYPE_USERDEFINE_END			 = 3130,

	// 报警运营平台，扩展自定义报警类型
	ALARM_TYPE_USERDEFINEEX_BEGIN		 = 3201,
	ALARM_TYPE_USERDEFINEEX_END			 = 4200,

	ALARM_NODE_ACTIVE					= 4201,					// 主从切换报警
	ALARM_ISCSI_STATUS					= 4202,					// ISCSI存储状态变更报警
	ALARM_OUTDOOR_STATIC				= 4203,

	ALARM_FALLING						= 4204,					// 跌落事件报警 
	ALARM_ITC_OUTSIDE_CARNUM			= 4205,					// 出入口外部车报警
	ALARM_POS_TRANING_MODE				= 4206,					//POS机训练模式报警
	ALARM_REFUND_OVER_QUOTA				= 4207,					//退货限额报警
	ALARM_SWING_CARD_FREQUENTLY			= 4208,					//会员卡频繁出现报警
	ALARM_SIGNLE_COST_OVER_QUOTA		= 4209,					//销售单笔超额报警

	//DSS-H可视对讲设备室内机新增传感器报警类型
	ALARM_SENSE_BEGIN					= 4299,
	ALARM_SENSE_DOOR                    = 4300,                 //门磁
	ALARM_SENSE_PASSIVEINFRA            = 4301,                 //被动红外
	ALARM_SENSE_GAS                     = 4302,                 //气感
	ALARM_SENSE_SMOKING                 = 4303,                 //烟感
	ALARM_SENSE_WATER                   = 4304,                 //水感
	ALARM_SENSE_ACTIVEFRA               = 4305,                 //主动红外
	ALARM_SENSE_GLASS                   = 4306,                 //玻璃破碎
	ALARM_SENSE_EMERGENCYSWITCH         = 4307,                 //紧急开关
	ALARM_SENSE_SHOCK                   = 4308,                 //震动
	ALARM_SENSE_DOUBLEMETHOD            = 4309,                 //双鉴(红外+微波)
	ALARM_SENSE_THREEMETHOD             = 4310,                 //三技术
	ALARM_SENSE_TEMP                    = 4311,                 //温度
	ALARM_SENSE_HUMIDITY                = 4312,                 //湿度
	ALARM_SENSE_WIND                    = 4313,                 //风速
	ALARM_SENSE_CALLBUTTON              = 4314,                 //呼叫按钮
	ALARM_SENSE_GASPRESSURE             = 4315,                 //气体压力
	ALARM_SENSE_GASCONCENTRATION        = 4316,                 //燃气浓度
	ALARM_SENSE_GASFLOW                 = 4317,                 //气体流量
	ALARM_SENSE_OIL                     = 4319,                 //油量检测，汽油、柴油等车辆用油检测
	ALARM_SENSE_MILEAGE                 = 4320,                 //里程数检测
	ALARM_SENSE_URGENCYBUTTON           = 4321,                 //紧急按钮
	ALARM_SENSE_STEAL                   = 4322,                 //盗窃
	ALARM_SENSE_PERIMETER               = 4323,                 //周界
	ALARM_SENSE_PREVENTREMOVE           = 4324,                 //防拆
	ALARM_SENSE_DOORBELL                = 4325,                 //门铃
	ALARM_SENSE_LOCK_LOCKKEY            = 4326,                 //门锁钥匙报警
	ALARM_SENSE_LOCK_LOWPOWER           = 4327,                 //门锁低电压报警
	ALARM_SENSE_LOCK_PREVENTREMOVE      = 4328,                 //门锁防拆
	ALARM_SENSE_LOCK_FORCE		        = 4329,                 //门锁胁迫报警
	ALARM_SENSE_END						= 4399,

	ALARM_STORAGE_BEGIN					= 4400,
	ALARM_IO_QUEUE_FULL					= 4401,					// 磁盘读写高负荷
	ALARM_DISK_DESTROY					= 4402,					// 磁盘异常
	ALARM_IPSAN_OFF_LINE				= 4403,					// IPSan掉线
	ALARM_NO_DISK_STORAGE				= 4404,					// 没有磁盘			
	ALARM_GET_STREAM_ERROR				= 4405,					// 取码流错误
	ALARM_STORAGE_END					= 4499,

	//DSSH出入口卡口黑名单报警类型新增
	ALARM_TRAFFIC_SUSPICIOUSCAR         = 4501,

	//大华出入口控制机报警类型
	ALARM_SLUICE_BEGIN								= 4502,
	ALARM_SLUICE_IC_CARD_STATUS_LOWCARD				= 4503,					//卡箱少卡报警
	ALARM_SLUICE_IC_CARD_STATUS_NOCARD				= 4504,					//卡箱无卡报警
	ALARM_SLUICE_IC_CARD_STATUS_FULLCARDS			= 4505,					//卡箱卡满报警
	ALARM_SLUICE_CAR_DETECTOR_STATE_OFFLINE			= 4506,					//车检器掉线报警
	ALARM_SLUICE_CAR_DETECTOR_STATE_LOOPOFFLINE		= 4507,					//地感线圈掉线报警
	ALARM_SLUICE_LED_DEV_STATE_OFFLINE				= 4508,					//LED掉线报警
	ALARM_SLUICE_SWIPING_CARD_DEV_STATE_OFFLINE		= 4509,					//面板刷卡板掉线报警
	ALARM_SLUICE_DELIVE_CARD_DEV_OFFLINE			= 4510,					//发卡刷卡板掉线报警
	ALARM_SLUICE_SPEAK_DEV_STATUS					= 4511,					//对讲事件报警
	ALARM_SLUICE_END								= 4550,

	//DSSH自助缴费机报警类型
	ALARM_SELFPAY_BEGIN								= 4551,
	ALARM_SELFPAY_NOPAPER							= 4552,//缺纸
	ALARM_SELFPAY_NOCASH50							= 4553,
	ALARM_SELFPAY_NOCASH20							= 4554,
	ALARM_SELFPAY_NOCASH10							= 4555,
	ALARM_SELFPAY_NOCASH1							= 4556,
	ALARM_SELFPAY_NOCOIN							= 4557,
	ALARM_SELFPAY_LOCKMONEY							= 4558,//卡币
	ALARM_SELFPAY_DISMANTLE							= 4559,//防拆
	ALARM_SELFPAY_UNPACK							= 4560,//开箱
	ALARM_SELFPAY_UNKONWN							= 4561,//纸币不识别
	ALARM_SELFPAY_END								= 4580,

	//客户端IP对讲报警
	ALARM_IP_DEV_BEGIN = 4700,
	ALARM_IP_DEV_CALLIN = 4701,									//分机呼叫
	ALARM_IP_DEV_CALLOUT = 4702,								//拨打
	ALARM_IP_DEV_END = 4800,

	//手机APP报警类型
	ALARM_MOBILEAPP_BEGIN									= 4900,
	ALARM_MOBILEAPP_GPS										= 4901,		//手机APP上传GPS
	ALARM_MOBILEAPP_ONE_CLICK								= 4902,		//手机APP一键报警
	ALARM_MOBILEAPP_MANUAL_ADD								= 4903,		//手机APP手动添加报警
	ALARM_MOBILEAPP_END										= 5000,

	//APS人数统计报警
	ALAMR_PEOPLE_COUNTING_BEGIN								= 5001,
	ALARM_PEOPLE_UPPER_LIMIT								= 5002,		//人数上限
	ALARM_PEOPLE_LOWER_LIMIT								= 5003,		//人数下限
	ALARM_INFLUX_UPPER_LIMIT								= 5004,		//人流量超标（进）
	ALARM_OUTFLUX_UPPER_LIMIT								= 5005,		//人流量超标（出）
	ALARM_DENSITY_UPPER_LIMIT								= 5006,		//密度报警
	ALARM_SCENE_EXCEPTION									= 5007,		//场景异常报警
	ALAMR_PEOPLE_COUNTING_END								= 5100,

	ALARM_HUMAM_NUMBER_STATISTIC							= 5104,		//人流量统计相机客流量超过阀值报警事件

	ALARM_HEATIMG_TEMPER							= 5120,		//热成像测温点温度异常报警
	ALARM_FIRE_WARNING								= 5121,		//热成像着火点报警
	ALARM_RADIOMETRY_FIREWARNING_INFO         		= 5122,     //热成像火情报警信息上报
	ALARM_RADIOMETRY_HOTSPOT_WARNING           		= 5123,     //热成像热点异常报警（高于温度阀值报警）
	ALARM_RADIOMETRY_COLDSPOT_WARNING          		= 5124,     //热成像冷点异常报警（低于温度阀值报警）
	ALARM_RADIOMETRY_BETWEENRULE_TEMP_DIFF			= 5125,     //热成像规则间温差异常报警
	ALARM_RADIOMETRY_SMOKE_DETECTION         		= 5126,     //热成像烟雾报警
	ALARM_RADIOMETRY_FACE_OVERHEATING           	= 5127,     //热成像人体发烧预警

	//客户端机顶盒设备定制报警
	ALARM_STB_BEGIN									= 5200,		
	ALARM_STB_FIRE									= 5201,		//火警
	ALARM_STB_CRIME									= 5202,		//匪警
	ALARM_STB_EMERGENCY								= 5203,		//急救中心
	ALARM_STB_OTHER									= 5204,		//其他报警
	ALARM_STB_END									= 5250,

	//-C/-P新增报警预留
	ALARM_DSSC_BEGIN								=	5300,
	ALARM_PATIENTDETECTION_TYPE_CROSS_REGION		=	ALARM_DSSC_BEGIN + 1,	// 警戒区域报警，可能是病人离开或者有其他靠近病人
	ALARM_PATIENTDETECTION_TYPE_LIGHT_OFF			=	ALARM_DSSC_BEGIN + 2,	// 病房电灯被熄灭
	ALARM_PATIENTDETECTION_TYPE_STOP_DETECTION		=	ALARM_DSSC_BEGIN + 3,	// 撤防，不再监控病人
	ALARM_PATIENTDETECTION_TYPE_START_DETECTION		=	ALARM_DSSC_BEGIN + 4,	// 开始布防
	ALARM_DSSC_END									=	5400,

	ALARM_U700_BEGIN								= 5401,
	ALARM_VTA_INSPECTION							= ALARM_U700_BEGIN + 1, // VTA报警柱巡检报警
	ALARM_VTA_OVERSPEED								= ALARM_U700_BEGIN + 2, // VTA报警柱超速报警
	ALARM_VTA_INSPECTION_SWING_CARD					= ALARM_U700_BEGIN + 3, //VTA巡检刷卡
	ALARM_VTA_PATROL_SWING_CARD						= ALARM_U700_BEGIN + 4, //VTA巡更刷卡
	ALARM_U700_END = 5500,

	ALARM_REMOTE_CAMERA_STATE						= 5501,				//卡口设备相机状态上报报警
	ALARM_SHANGHAI_JIHENG							= 5502,				//上海迹恒上报报警
	ALARM_CHANNEL_TALK								= 5506,				//通道对讲报警


	//新动环报警定义报警区间段
	ALARM_NEW_SCS_BEGIN								= 8000,
	ALARM_NEW_SCS_END								= 9999,

	DPSDK_CORE_ALARM_IVS_CITY_MOTORPARKING			= 0X0000024F + 15000, // 城市机动车违停事件 15591
	DPSDK_CORE_ALARM_IVS_MATERIALSSTAY				= 0X00000253 + 15000, // 物料堆放事件 15595
	ALARM_CORE_ALARM_IVS_FLOATINGOBJECT_DETECTION	= 0X00000257 + 15000, // 漂浮物检测事件 15599
}dpsdk_alarm_type_e;

typedef enum
{
	OP_FTP_TYPE_UNKNOW		=0,
	OP_FTP_TYPE_DOWN		=0x01,           //下载
	OP_FTP_TYPE_UP			=0x02,           //上传
	OP_FTP_TYPE_DELETE		=0x03,           //删除
}dpsdk_operator_ftp_type_e; 

// 图片监控数据回调类型
typedef enum
{
	DPSDK_CORE_PICINFO_RECIVE,										     // 收到图片信息
	DPSDK_CORE_PICDATA_RECIVE,										     // 图片数据接收
	DPSDK_CORE_PICDATA_OVER,										     // 一组图片数据结束
}dpsdk_picdata_notify_e;


// 报警发生类型
typedef enum
{
	ALARM_EVENT_OCCUR								= 1,				 // 产生
	ALARM_EVENT_DISAPPEAR,												 // 消失
}dpsdk_event_type_e;

// 报警处理类型
typedef enum
{
	ALARM_DEALWITH_PENDING							= 1,			      // 处理中
	ALARM_DEALWITH_RESOLVE							= 2,				  // 已解决
	ALARM_DEALWITH_SUGGESTTED						= 4,				  // 误报
	ALARM_DEALWITH_IGNORED							= 8,			      // 忽略	
	ALARM_DEALWITH_UNPROCESSED						= 16				  // 未解决
}dpsdk_alarm_dealwith_e;


typedef enum
{
	//DPSDK_CORE_ORG_NODE_TYPE_ALL			        = 0,				   // 查询全部（1~4）暂时不提供
	DPSDK_CORE_ORG_NODE_TYPE_GROUP			        = 1,				   // 组织
	DPSDK_CORE_ORG_NODE_TYPE_DEPARTMENT		        = 2,			       // 部门
	DPSDK_CORE_ORG_NODE_TYPE_MONITOR_AREA	        = 3,				   // 监控区域
	DPSDK_CORE_ORG_NODE_TYPE_ADM_AREA		        = 4,				   // 行政辖区

	DPSDK_CORE_ORG_NODE_TYPE_PERSION		        = 5,				   // 人员
	DPSDK_CORE_ORG_NODE_TYPE_CHNDEPREL		        = 6,				   // 通道-部门关联表 
	DPSDK_CORE_ORG_NODE_TYPE_DEPAREAREL		        = 7,				   // 部门-辖区关联表   
}dpsdk_org_node_e;

typedef enum
{
	DSST_GROUP_CHANGE_UNKNOW                        = 0,
	DSST_GROUP_CHANGE_ORG_ADDED,
	DSST_GROUP_CHANGE_ORG_CHANGED,							                // 组织节点变更通知
	DSST_GROUP_CHANGE_ORG_DELETED,
	DSST_GROUP_CHANGE_PERSON_ADDED,
	DSST_GROUP_CHANGE_PERSON_CHANGED,						                // 人员信息变更
	DSST_GROUP_CHANGE_PERSON_DELETED,
	DSST_GROUP_CHANGE_CAR_ADDED,
	DSST_GROUP_CHANGE_CAR_CHANGED,							                // 车辆信息变更
	DSST_GROUP_CHANGE_CAR_DELETED,
}dpsdk_dsst_change_type_e;

//压缩格式获取组织结构
typedef enum
{
	DPSDK_CORE_GET_DEVINFO_BY_UNCOMPRESS = 0,		// 采用非压缩方式获取设备信息
	DPSDK_CORE_GET_DEVINFO_BY_COMPRESSED = 1,		// 采用压缩方式获取设备信息
}dpsdk_get_devinfo_compress_type_e;

// 电视墙屏分割能力
typedef enum
{
	Screen_Split_1		                            = 1,
	Screen_Split_4	                            	= 4,
	Screen_Split_9		                            = 9,
	Screen_Split_16		                            = 16,
}tvwall_screen_split_caps;

//上墙模式,安徽三联项目
typedef enum
{
	DPSDK_CORE_TVWALL_GENERAL						= 0,					//普通模式
	DPSDK_CORE_TVWALL_PIP,													//画中画模式
}dpsdk_tvwall_pip_e;

//电视墙任务信息
typedef struct tagTVWallTaskInfo
{
	uint32_t    nTaskId;													//任务ID
	char		szName[DPSDK_CORE_TVWALL_TASK_NAME_LEN];					//任务名称
	char		szDes[DPSDK_CORE_TVWALL_TASK_DES_LEN];						//任务描述
}TVWall_Task_Info_t;

// 电视墙任务信息列表
typedef struct tagTvWallTaskInfoList
{
	IN	uint32_t						nCount;								// 电视墙任务数量
	OUT	TVWall_Task_Info_t*				pTvWallTaskInfo;					// 电视墙任务信息
}TvWall_Task_Info_List_t;

//Ftp操作类型
typedef enum
{
	OP_ROMOTE_FILE_TYPE_DOWN			= 01,//下载
	OP_ROMOTE_FILE_TYPE_UP				= 02,//上传
	OP_ROMOTE_FILE_TYPE_DELETE			= 03,//删除
}dpsdk_operator_remote_file_type_e;

// 实时码流类型
typedef enum
{
	DPSDK_CORE_STREAM_ALL		= 0,		// 0-全部
	DPSDK_CORE_STREAM_MAIN		= 1,		// 1-主码流
	DPSDK_CORE_STREAM_SUB,					// 2-辅码流
	DPSDK_CORE_STREAM_THIRD,				// 3-三码流
	DPSDK_CORE_STREAM_SIGNAL	= 5,		// 5-M60本地信号
}dpsdk_encdev_stream_e;

typedef enum
{
	DPSDK_MDL_UNKNOW = -1, //未知模块
	DPSDK_MDL_APP,
	DPSDK_MDL_CMS,
	DPSDK_MDL_PCS,
	DPSDK_MDL_DMS,
	DPSDK_MDL_ADS,
	DPSDK_MDL_TRAN,	//中转模块
	DPSDK_MDL_RTSP,
	DPSDK_MDL_FTP,
	DPSDK_MDL_PEC,
	DPSDK_MDL_MGR,
	DPSDK_MDL_AREA,
	DPSDK_MDL_CMS_FORSNVD,
	DPSDK_MDL_SCS,
	DPSDK_MDL_COUNT,   //模块总数
}dpsdk_mdl_type_e;	//默认族类

// JSON 传输类型
typedef enum
{
	GENERALJSON_TRAN_UNKNOW = -1,
	GENERALJSON_TRAN_REQUEST,
	GENERALJSON_TRAN_RESPONSE,
	GENERALJSON_TRAN_NOTIFY,
	GENERALJSON_TRAN_COUNT,
}generaljson_trantype_e;

//通用组织节点信息
typedef struct tagOrgInfo
{
	IN char                             szCode[DPSDK_CORE_ORG_CODE_LEN];		  // 通用节点编码
	IN char                             szName[DPSDK_CORE_ORG_NAME_LEN];		  // 通用节点名称
	IN char                             szSN[DPSDK_CORE_ORG_SN_LEN];			  // 通用节点唯一码
	IN char                             szType[DPSDK_CORE_ORG_TYPE_LEN];		  // 通用节点类型
	IN char                             szGpsX[DPSDK_CORE_ORG_GPS_LEN];			  // 通用节点经度
	IN char                             szGpsY[DPSDK_CORE_ORG_GPS_LEN];			  // 通用节点纬度
	IN char                             szMemo[DPSDK_CORE_ORG_MEMO_LEN];		  // 通用节点描述
	uint32_t	                        domainId;		                          // 域ID
	uint32_t	                        state;			                          // 状态
}Org_Info_t;

// 获取组织个数请求信息
typedef struct tagGetOrgCountInfo 
{
	IN char								szCoding[DPSDK_CORE_ORG_CODE_LEN];         // 节点code
	OUT uint32_t						nGroupCount;						       // 组织个数
}Get_Org_Count_Info_t;

// 获取组织请求信息
typedef struct tagGetOrgInfo 
{
	IN char								szCoding[DPSDK_CORE_ORG_CODE_LEN];	       // 节点code
	IN uint32_t							nOrgCount;							       // 组织个数
	OUT Org_Info_t*						pOrgInfo;							       // 组织信息，在外部创建，如果为NULL则只返回个数
}Get_Org_Info_t; 

// 登录信息
typedef struct tagLoginInfo
{
    char								szIp[DPSDK_CORE_IP_LEN];					// 服务IP,或者是域名
	uint32_t							nPort;										// 服务端口
    char								szUsername[DPSDK_CORE_USER_NAME_LEN];		// 用户名
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// 密码
	dpsdk_protocol_version_e			nProtocol;									// 协议类型
	uint32_t							iType;										// 登陆类型，1为PC客户端, 2为手机客户端
	char								szCheckBit[DPSDK_CORE_IP_LEN];				// 手机客户端登陆平台时校验码（一般为手机号）
	char								szIMEINo[DPSDK_CORE_IP_LEN];				// IMEI号
	char								szPhonetype[DPSDK_CORE_IP_LEN];				// 手机型号
	char								platformFlag[DPSDK_CORE_PASSWORD_LEN];		// 标识位：级联平台的标识位
}Login_Info_t;

// 认证登录信息
typedef struct tagLoginWithEncryptionInfo
{
	char								szIp[DPSDK_CORE_IP_LEN];					// 服务IP,或者是域名
	uint32_t							nPort;										// 服务端口
	char								szUsername[DPSDK_CORE_USER_NAME_LEN];		// 用户名
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// 密码
	dpsdk_protocol_version_e			nProtocol;									// 协议类型
	uint32_t							iType;										// 登陆类型，1为PC客户端, 2为手机客户端
	char								szCheckBit[DPSDK_CORE_IP_LEN];				// 手机客户端登陆平台时校验码（一般为手机号）
	char								szIMEINo[DPSDK_CORE_IP_LEN];				// IMEI号
	char								szPhonetype[DPSDK_CORE_IP_LEN];				// 手机型号
	char								platformFlag[DPSDK_CORE_PASSWORD_LEN];		// 标识位：级联平台的标识位
	char								szEncryptedPassword[DPSDK_CORE_CHAR_LEN_256];// 认证登录加密字符串
	char								szRealm[DPSDK_CORE_CHAR_LEN_64];			// 服务返回的域
	char								szNonce[DPSDK_CORE_CHAR_LEN_64];			// 服务返回的随机码
}LoginWithEncryption_Info_t;

// 组织信息
typedef struct tagDepInfo 
{
	char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	char								szDepName[DPSDK_CORE_DGROUP_DGPNAME_LEN];	// 节点名称
	int									nDepSort;									// 组织排序
	char								szOrgID[DPSDK_CORE_DGROUP_DGPCODE_LEN];		// 组织结点唯一ID<海南省透明厨房项目>
}Dep_Info_t; 

// 组织信息(扩展)
typedef struct tagDepInfoEx 
{
	char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	char								szDepName[DPSDK_CORE_DGROUP_DGPNAME_LEN];	// 节点名称
	char								szModifyTime[DPSDK_CORE_TIME_LEN];			// 节点修改时间
	char								szSN[DPSDK_CORE_ORG_SN_LEN];				// 唯一标识码
	char								szMemo[DPSDK_CORE_MEM_LEN];					// 备注信息 报警运营平台
	int									nDepType;									// 组织节点类型 报警运营平台
	int									nDepSort;									// 组织排序
	int									nChargebooth;								// 收费亭标志
	int									nDepExtType;								// 组织节点扩展类型
	char								szOrgID[DPSDK_CORE_DGROUP_DGPCODE_LEN];		// 组织结点唯一ID<海南省透明厨房项目>
}Dep_Info_Ex_t; 

// 设备类型，需要和web统一
typedef enum
{
	DEV_TYPE_ENC_BEGIN			= 0,		// 编码设备
	DEV_TYPE_DVR				= DEV_TYPE_ENC_BEGIN + 1,			// DVR
	DEV_TYPE_IPC				= DEV_TYPE_ENC_BEGIN + 2,			// IPC
	DEV_TYPE_NVS				= DEV_TYPE_ENC_BEGIN + 3,			// NVS
	DEV_TYPE_MCD				= DEV_TYPE_ENC_BEGIN + 4,			// MCD
	DEV_TYPE_MDVR				= DEV_TYPE_ENC_BEGIN + 5,			// MDVR
	DEV_TYPE_NVR				= DEV_TYPE_ENC_BEGIN + 6,			// NVR
	DEV_TYPE_SVR				= DEV_TYPE_ENC_BEGIN + 7,			// SVR
	DEV_TYPE_PCNVR				= DEV_TYPE_ENC_BEGIN + 8,			// PCNVR，PSS自带的一个小型服务
	DEV_TYPE_PVR				= DEV_TYPE_ENC_BEGIN + 9,			// PVR
	DEV_TYPE_EVS				= DEV_TYPE_ENC_BEGIN + 10,			// EVS
	DEV_TYPE_MPGS				= DEV_TYPE_ENC_BEGIN + 11,			// MPGS
	DEV_TYPE_SMART_IPC			= DEV_TYPE_ENC_BEGIN + 12,			// SMART_IPC
	DEV_TYPE_SMART_TINGSHEN		= DEV_TYPE_ENC_BEGIN + 13,			// 庭审主机
	DEV_TYPE_SMART_NVR			= DEV_TYPE_ENC_BEGIN + 14,			// SMART_NVR
	DEV_TYPE_PRC				= DEV_TYPE_ENC_BEGIN + 15,			// 防护舱
	DEV_TYPE_JT808				= DEV_TYPE_ENC_BEGIN + 18,			// 部标JT808
	DEV_TYPE_VTT				= DEV_TYPE_ENC_BEGIN + 21,			// VTT
	DEV_TYPE_ALARM_STUB_VTA     = DEV_TYPE_ENC_BEGIN + 25,          // VTA

	DEV_TYPE_ENC_END			= 99,

	DEV_TYPE_TVWALL_BEGIN		= 100,
	DEV_TYPE_BIGSCREEN			= DEV_TYPE_TVWALL_BEGIN + 1,		// 大屏
	DEV_TYPE_TVWALL_END			= 199,

	DEV_TYPE_DEC_BEGIN			= 200,		// 解码设备
	DEV_TYPE_NVD				= DEV_TYPE_DEC_BEGIN + 1,			// NVD
	DEV_TYPE_SNVD				= DEV_TYPE_DEC_BEGIN + 2,			// SNVD
	DEV_TYPE_UDS				= DEV_TYPE_DEC_BEGIN + 5,			// UDS
	DEV_TYPE_DEC_END			= 299,

	DEV_TYPE_MATRIX_BEGIN		= 300,		// 矩阵设备
	DEV_MATRIX_M60				= DEV_TYPE_MATRIX_BEGIN	+ 1,		// M60
	DEV_MATRIX_NVR6000			= DEV_TYPE_MATRIX_BEGIN + 2,		// NVR6000
	DEV_TYPE_MATRIX_END			= 399,

	DEV_TYPE_IVS_BEGIN			= 400,		// 智能设备
	DEV_TYPE_ISD				= DEV_TYPE_IVS_BEGIN + 1,			// ISD 智能球
	DEV_TYPE_IVS_B				= DEV_TYPE_IVS_BEGIN + 2,			// IVS-B 行为分析服务
	DEV_TYPE_IVS_V				= DEV_TYPE_IVS_BEGIN + 3,			// IVS-V 视频质量诊断服务
	DEV_TYPE_IVS_FR				= DEV_TYPE_IVS_BEGIN + 4,			// IVS-FR 人脸识别服务
	DEV_TYPE_IVS_PC				= DEV_TYPE_IVS_BEGIN + 5,			// IVS-PC 人流量统计服务
	DEV_TYPE_IVS_M				= DEV_TYPE_IVS_BEGIN + 6,			// IVS_M 主从跟踪智能盒
	DEV_TYPE_IVS_PC_BOX			= DEV_TYPE_IVS_BEGIN + 7,			// IVS-PC 智能盒 
	DEV_TYPE_IVS_B_BOX			= DEV_TYPE_IVS_BEGIN + 8,			// IVS-B 智能盒
	DEV_TYPE_IVS_M_BOX			= DEV_TYPE_IVS_BEGIN + 9,			// IVS-M 盒子
	DEV_TYPE_IVS_PRC			= DEV_TYPE_IVS_BEGIN + 10,			// 防护舱
	DEV_TYPE_IVS_END			= 499,

	DEV_TYPE_BAYONET_BEGIN		= 500,		// -C相关设备
	DEV_TYPE_CAPTURE			= DEV_TYPE_BAYONET_BEGIN + 1,		// 卡口设备
	DEV_TYPE_SPEED				= DEV_TYPE_BAYONET_BEGIN + 2,		// 测速设备
	DEV_TYPE_TRAFFIC_LIGHT		= DEV_TYPE_BAYONET_BEGIN + 3,		// 闯红灯设备
	DEV_TYPE_INCORPORATE		= DEV_TYPE_BAYONET_BEGIN + 4,		// 一体化设备
	DEV_TYPE_PLATEDISTINGUISH	= DEV_TYPE_BAYONET_BEGIN + 5,		// 车牌识别设备
	DEV_TYPE_VIOLATESNAPPIC		= DEV_TYPE_BAYONET_BEGIN + 6,		// 违停检测设备
	DEV_TYPE_PARKINGSTATUSDEV	= DEV_TYPE_BAYONET_BEGIN + 7,		// 车位检测设备
	DEV_TYPE_ENTRANCE			= DEV_TYPE_BAYONET_BEGIN + 8,		// 出入口设备
	DEV_TYPE_VIOLATESNAPBALL	= DEV_TYPE_BAYONET_BEGIN + 9,		// 违停抓拍球机
	DEV_TYPE_THIRDBAYONET		= DEV_TYPE_BAYONET_BEGIN + 10,		// 第三方卡口设备
	DEV_TYPE_ULTRASONIC			= DEV_TYPE_BAYONET_BEGIN + 11,		// 超声波车位检测器
	DEV_TYPE_FACE_CAPTURE		= DEV_TYPE_BAYONET_BEGIN + 12,		// 人脸抓拍设备
	DEV_TYPE_ITC_SMART_NVR		= DEV_TYPE_BAYONET_BEGIN + 13,		// 卡口智能NVR设备
	DEV_TYPE_BAYONET_END		= 599,

	DEV_TYPE_ALARM_BEGIN		= 600,		// 报警设备
	DEV_TYPE_ALARMHOST			= DEV_TYPE_ALARM_BEGIN + 1,			// 报警主机
	DEV_TYPE_ALARM_END			= 699,

	DEV_TYPE_DOORCTRL_BEGIN		= 700,
	DEV_TYPE_DOORCTRL_DOOR		= DEV_TYPE_DOORCTRL_BEGIN + 1,		// 门禁
	DEV_TYPE_DOORCTRL_END		= 799,

	DEV_TYPE_PE_BEGIN			= 800,
	DEV_TYPE_PE_PE				= DEV_TYPE_PE_BEGIN + 1,			// 动环
	DEV_TYPE_PE_AE6016			= DEV_TYPE_PE_BEGIN + 2,			// AE6016设备
	DEV_TYPE_PE_NVS				= DEV_TYPE_PE_BEGIN + 3,			// 带动环功能的NVS设备
	DEV_TYPE_PE_END				= 899,

	DEV_TYPE_VOICE_BEGIN		= 900,		// ip对讲
	DEV_TYPE_VOICE_MIKE			= DEV_TYPE_VOICE_BEGIN + 1,
	DEV_TYPE_VOICE_NET			= DEV_TYPE_VOICE_BEGIN + 2,
	DEV_TYPE_VOICE_END			= 999,

	DEV_TYPE_IP_BEGIN			= 1000,		// IP设备（通过网络接入的设备）
	DEV_TYPE_IP_SCNNER			= DEV_TYPE_IP_BEGIN + 1,			// 扫描枪
	DEV_TYPE_IP_SWEEP			= DEV_TYPE_IP_BEGIN + 2,			// 地磅
	DEV_TYPE_IP_POWERCONTROL	= DEV_TYPE_IP_BEGIN + 3,			// 电源控制器
	DEV_TYPE_IP_END				= 1099,

	DEV_TYPE_MULTIFUNALARM_BEGIN= 1100,		// 多功能报警主机
	DEV_TYPE_VEDIO_ALARMHOST	= DEV_TYPE_MULTIFUNALARM_BEGIN + 1,	// 视频报警主机
	DEV_TYPE_MULTIFUNALARM_END	= 1099,

	DEV_TYPE_SLUICE_BEGIN		= 1200,
	DEV_TYPE_SLUICE_DEV			= DEV_TYPE_SLUICE_BEGIN + 1,		// 出入口道闸设备
	DEV_TYPE_SLUICE_PARKING		= DEV_TYPE_SLUICE_BEGIN + 2,		// 停车场道闸设备
	DEV_TYPE_SLUICE_STOPBUFFER	= DEV_TYPE_SLUICE_BEGIN + 3,		// 视频档车器
	DEV_TYPE_SLUICE_END			= 1299,

	DEV_TYPE_ELECTRIC_BEGIN		= 1300,
	DEV_TYPE_ELECTRIC_DEV		= DEV_TYPE_ELECTRIC_BEGIN + 1,		// 电网设备
	DEV_TYPE_ELECTRIC_END		= 1399,

	DEV_TYPE_LED_BEGIN			= 1400,
	DEV_TYPE_LED_DEV			= DEV_TYPE_LED_BEGIN + 1,			// LED屏设备
	DEV_TYPE_LED_END			= 1499,

	DEV_TYPE_VIBRATIONFIBER_BEGIN	= 1500,		
	DEV_TYPE_VIBRATIONFIBER_DEV	= DEV_TYPE_VIBRATIONFIBER_BEGIN + 1,// 震动光纤设备 
	DEV_TYPE_VIBRATIONFIBER_END	= 1599,

	DEV_TYPE_PATROL_BEGIN		= 1600,		
	DEV_TYPE_PATROL_DEV			= DEV_TYPE_PATROL_BEGIN + 1,		// 巡更棒设备
	DEV_TYPE_PATROL_SPOT		= DEV_TYPE_PATROL_BEGIN + 2,		// 巡更点设备
	DEV_TYPE_PATROL_END			= 1699,

	DEV_TYPE_SENTRY_BOX_BEGIN	= 1700,		
	DEV_TYPE_SENTRY_BOX_DEV		= DEV_TYPE_SENTRY_BOX_BEGIN + 1,	// 哨位箱设备
	DEV_TYPE_SENTRY_BOX_END		= 1799,

	DEV_TYPE_COURT_BEGIN		= 1800,		
	DEV_TYPE_COURT_DEV			= DEV_TYPE_COURT_BEGIN + 1,			// 庭审设备
	DEV_TYPE_COURT_END			= 1899,

	DEV_TYPE_VIDEO_TALK_BEGIN	= 1900,
	DEV_TYPE_VIDEO_TALK_VTNC	= DEV_TYPE_VIDEO_TALK_BEGIN + 1, 
	DEV_TYPE_VIDEO_TALK_VTO		= DEV_TYPE_VIDEO_TALK_BEGIN + 2,  
	DEV_TYPE_VIDEO_TALK_VTH		= DEV_TYPE_VIDEO_TALK_BEGIN + 3,  
	DEV_TYPE_VIDEO_TALK_END		= 1999,

	DEV_TYPE_BROADCAST_BEGIN	= 2000,
	DEV_TYPE_BROADCAST_ITC_T6700R = DEV_TYPE_BROADCAST_BEGIN + 1,	// ITC_T6700R广播设备
	DEV_TYPE_BROADCAST_END		= 2099,

	DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN = 2100,
	DEV_TYPE_VIDEO_RECORD_SERVER_BNVR	= DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN + 1, // BNVR设备
	DEV_TYPE_VIDEO_RECORD_SERVER_OE	= DEV_TYPE_VIDEO_RECORD_SERVER_BEGIN + 2, // 手术设备(operation equipment)
	DEV_TYPE_VIDEO_RECORD_SERVER_END	= 2199,

}dpsdk_dev_type_e;

// 设备信息
typedef struct tagDeviceInfo 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// 设备ID
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
	char								szUser[DPSDK_CORE_USER_NAME_LEN];			// 用户名
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// 密码
	char								szIP[DPSDK_CORE_IP_LEN];					// 设备IP
	int									nPort;										// 设备端口
	dpsdk_device_factory_type_e			nFactory;									// 厂商类型
	dpsdk_dev_status_e					nStatus;									// 设备状态
	int									nEncChannelChildCount;						// 编码子通道个数
	dpsdk_dev_type_e					nType;										// 设备类型
}Device_Info_t; 

#if 1
typedef struct tagDeviceInfoEx 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// 设备ID
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
	dpsdk_device_factory_type_e			nFactory;									// 厂商类型//dsl::DStr   szManfac;					// 生产商
	int                                 szModel;					                // 模式
	char								szUser[DPSDK_CORE_USER_NAME_LEN];			// 用户名
	char								szPassword[DPSDK_CORE_PASSWORD_LEN];		// 密码
	char								szIP[DPSDK_CORE_IP_LEN];					// 设备IP
	dpsdk_dev_type_e                    nDevType;						            // 设备type
	int									nPort;										// 设备端口
	int                             	szLoginType;				                // 登陆类型
	char	                            szRegID[DPSDK_CORE_DEV_ID_LEN];				// 主动注册设备ID
	int			                        nProxyPort;					                // 代理端口
	int			                        nUnitNum;					                // 单元数目--对于矩阵设备代表卡槽数
	dpsdk_dev_status_e					nStatus;									// 设备状态
	char                                szCN[DPSDK_CORE_DEV_ID_LEN];				// 设备序列号
	char	                            szSN[DPSDK_CORE_DEV_ID_LEN];   	 		    // 互联编码SN
	uint64_t                            nRight;						                // 权限信息(只有IP对讲设备中的话筒才有)
	char                                szDevIP[DPSDK_CORE_IP_LEN];					// 设备真实IP
	int                                 nDevPort;					                // 设备真实port
	char                                dev_Maintainer[DPSDK_CORE_USER_NAME_LEN];   // 设备联系人
	char                                dev_MaintainerPh[DPSDK_CORE_USER_NAME_LEN]; // 设备联系人号码
	char                                dev_Location[DPSDK_CORE_POS_NAME_LEN];      // 设备所在位置
	char                                desc[DPSDK_CORE_OPT_NOTE_LEN];              // 设备描述 
	int									nEncChannelChildCount;						// 编码子通道个数
	int									iAlarmInChannelcount;						// 报警输入通道个数
	int									nSort;									    // 组织排序
	char								szCallNum[DPSDK_CORE_IP_LEN];				// 设备呼叫号码
}Device_Info_Ex_t; 
#endif

// 编码通道信息
typedef struct tagEncChannelInfo 
{
	dpsdk_camera_type_e	                nCameraType;		                        // 类型，参见CameraType_e
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// 通道ID:设备ID+通道号
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
	int									nSort;										// 组织排序
}Enc_Channel_Info_t; 

// 云台设备通道信息
typedef struct tagPtzChannelInfo 
{
	INOUT char                          szCameralID[DPSDK_CORE_CHL_ID_LEN];         // 设备ID
	OUT   bool                          bResult;                                        // 该通道号是否订阅成功
}Ptz_Channel_Info_t; 

// 编码通道信息 扩展
typedef struct tagEncChannelInfoEx 
{
	dpsdk_camera_type_e	                nCameraType;		                        // 类型，参见CameraType_e
	char								szId[DPSDK_CORE_LEN*4];				// 通道ID:设备ID+通道号
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
	uint64_t                            nRight;                                     // 权限信息
	int                                 nChnlType;                                  // 通道类型
	int                                 nStatus;
	char                                szChnlSN[DPSDK_CORE_LEN*4];			// 互联编码SN
    char                                szLatitude[DPSDK_CORE_LEN*4];		// 纬度
	char                                szLongitude[DPSDK_CORE_LEN*4];		// 经度
	char                                szMulticastIp[DPSDK_CORE_IP_LEN];		// 组播IP
	int                                 nMulticastPort;		// 组播端口
}Enc_Channel_Info_Ex_t;
// 分级加载组织请求信息
typedef struct tagLoadDepInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	IN dpsdk_getgroup_operation_e		nOperation;									// 获取节点的深度
}Load_Dep_Info_t; 

// 获取组织个数请求信息
typedef struct tagGetDepCountInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	OUT uint32_t						nDepCount;									// 组织个数
	OUT uint32_t						nDeviceCount;								// 设备个数
	OUT uint32_t                        nChannelCount;                              //通道个数
}Get_Dep_Count_Info_t; 

// 获取组织请求信息
typedef struct tagGetDepInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	IN uint32_t							nDepCount;									// 组织个数
	OUT Dep_Info_t*						pDepInfo;									// 组织信息，在外部创建，如果为NULL则只返回个数
	IN uint32_t							nDeviceCount;								// 设备个数
	OUT Device_Info_Ex_t*				pDeviceInfo;								// 设备信息
}Get_Dep_Info_t; 

// 获取组织请求信息
typedef struct tagGetDepInfoEx 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	INOUT uint32_t						nDepCount;									// 组织个数
	OUT Dep_Info_t*						pDepInfo;									// 组织信息，在外部创建，如果为NULL则只返回个数
	INOUT uint32_t						nDeviceCount;								// 设备个数
	OUT Device_Info_Ex_t*				pDeviceInfo;								// 设备信息
	INOUT uint32_t						nChannelCount;                              // 通道个数
	OUT Enc_Channel_Info_Ex_t*			pEncChannelnfo;								// 通道信息
}Get_Dep_Info_Ex_t;

//电子地图服务配置信息
typedef struct tagConfigEmapAddrInfo
{
	OUT char			                szIP[DPSDK_CORE_IP_LEN];		            // 电子地图服务IP地址
	OUT int								nPort;										// 电子地图服务端口号
}Config_Emap_Addr_Info_t;

// 获取编码通道请求信息
typedef struct tagGetChannelInfo 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	IN uint32_t							nEncChannelChildCount;						// 通道个数
	OUT Enc_Channel_Info_t*				pEncChannelnfo;								// 通道信息
}Get_Channel_Info_t;

// 获取编码通道请求信息
typedef struct tagGetDepChannelInfo 
{
	IN char								szCoding[DPSDK_CORE_DGROUP_DGPCODE_LEN];	// 节点code
	IN uint32_t							nEncChannelChildCount;						// 通道个数
	OUT Enc_Channel_Info_t*				pEncChannelnfo;								// 通道信息
}Get_Dep_Channel_Info_t;

// 获取通道请求信息
typedef struct tagGetChannelInfoEx 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	IN uint32_t							nEncChannelChildCount;						// 通道个数
	OUT Enc_Channel_Info_Ex_t*			pEncChannelnfo;								// 通道信息
}Get_Channel_Info_Ex_t;

// 获取设备支持码流类型
typedef struct tagGetDevStreamTypeInfo
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	IN int								nUnitNo;									// 单元序号
	OUT dpsdk_stream_type_e				nStreamType;								// 支持的码流类型
}Get_Dev_StreamType_Info_t;

// 获取码流信息
typedef struct tagGetRealStreamInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_check_right_e					nRight;										// 是否检测权限
	dpsdk_stream_type_e					nStreamType;								// 码流类型
	dpsdk_media_type_e					nMediaType;									// 媒体类型
	dpsdk_trans_type_e					nTransType;									// 传输类型
	int									nTrackID;									// 拉流TrackID，默认0
}Get_RealStream_Info_t;

// 视频帧信息
typedef struct tagFrameInfo
{
	long                                nWidth;			                            // 图像宽度，单位pixel，音频默认为0
	long                                nHeight;                                    // 图像高度，单位pixel，音频默认为0
	long                                nStamp;			                            // 时间信息，单位ms
	long                                nType;				                        // 数据类型，T_IYUV, T_YV12, Please refer to the macro definition.
	long                                nFrameRate;		                            // 图像帧位， Image frame bit when encoding.
}Frame_Info;

// 获取语音信息
typedef struct tagGetTalkStreamInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 设备ID或通道ID
	dpsdk_audio_type_e                  nAudioType;                                 // 音频类型		  
    dpsdk_talk_type_e                   nTalkType;                                  // 设备类型（通道或设备）
	dpsdk_talk_bits_e					nBitsType;								    // 位数
	Talk_Sample_Rate_e					nSampleType;								// 采样率类型
	dpsdk_trans_type_e					nTransType;									// 传输类型
}Get_TalkStream_Info_t;


// 呼叫邀请信息
typedef struct tagGetCallStreamInfo
{
	dpsdk_call_type_e					nCallType;									//呼叫类型
	char								szSendChnlId[DPSDK_CORE_CHL_ID_LEN];		//发送通道
	char								szRecvChnlId[DPSDK_CORE_CHL_ID_LEN];		//接收通道
	char								szRtpServIP[DPSDK_CORE_IP_LEN];				//TRP服务IP
	int									nRtpPort;									//TRP服务端口
	int									nCallID;									//呼叫ID
	int									nDlgID;										//会话ID
	int									nTid;										//T ID
}Get_InviteCall_Info_t;

// 
typedef struct tagAudioUserParam
{
	void*                                objectPoint;								// 音频录音获取用户参数

	tagAudioUserParam(void)
	{
		objectPoint = NULL;
	}
}AudioUserParam_t;

// 单个录像信息
typedef struct tagSingleRecordInfo
{
	uint32_t							nFileIndex;									// 文件索引
	dpsdk_recsource_type_e				nSource;									// 录像源类型
	dpsdk_record_type_e					nRecordType;								// 录像类型
	uint64_t							uBeginTime;									// 起始时间
	uint64_t							uEndTime;									// 结束时间
	uint64_t							uLength;									// 文件大小
}Single_Record_Info_t;

// 录像信息
typedef struct tagRecordInfo
{
	IN char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	IN uint32_t							nBegin;										// 录像起始
	IN uint32_t							nCount;										// 请求录像数
	OUT uint32_t						nRetCount;									// 实际返回个数
	OUT Single_Record_Info_t*			pSingleRecord;								// 录像记录信息
}Record_Info_t;

// 按文件获取录像码流信息
typedef struct tagGetRecordStreamFileInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_check_right_e					nRight;										// 是否检测权限
	dpsdk_pb_mode_e						nMode;										// 录像流请求类型
	
	uint32_t							nFileIndex;									// 文件索引
	uint64_t							uBeginTime;									// 播放起始
	uint64_t							uEndTime;									// 播放结束
}Get_RecordStream_File_Info_t;

// 按时间获取录像码流信息
typedef struct tagGetRecordStreamTimeInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_check_right_e					nRight;										// 是否检测权限
	dpsdk_pb_mode_e						nMode;										// 录像流请求类型

	dpsdk_recsource_type_e				nSource;									// 录像源类型                  
	uint64_t							uBeginTime;									// 开始时间 
	uint64_t							uEndTime;									// 结束时间
	int									nTrackID;									// 拉流TrackID，默认0
}Get_RecordStream_Time_Info_t;

// 按本地文件播放录像
typedef struct tagGetRecordLocalInfo
{
	char								szFilePath[DPSDK_CORE_FILEPATH_LEN];		// 文件路径
}Get_Record_Local_Info_t;

// 查询录像信息
typedef struct tagQueryRecordInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_check_right_e					nRight;										// 是否检测权限
	dpsdk_recsource_type_e				nSource;									// 录像源类型
	dpsdk_record_type_e					nRecordType;								// 录像类型
	uint64_t							uBeginTime;									// 起始时间
	uint64_t							uEndTime; 									// 结束时间
}Query_Record_Info_t;

// 录像打标信息
typedef struct tagTag_Info
{
	IN dpsdk_recsource_type_e			source;										// 来源
	OUT uint32_t						tagid;										// 标签ID
	IN char								cameraId[DPSDK_CORE_CHL_ID_LEN];			// 摄像头ID
	IN uint64_t							tagtime;									// tag的时间
	IN uint64_t							endtime;									// 结束时间
	IN char								subject[DPSDK_CORE_TAG_SUBJECT_LEN];		// 主题
	IN char								content[DPSDK_CORE_TAG_CONTENT_LEN];		// 内容
	IN int32_t							ownerid;									// 创建者的ID
	IN uint64_t							ownertime;									// 创建时间(修改时间)
	IN char								url[DPSDK_TAG_URL_LEN];						// 存放图片的url
}Tag_Info_t;

// 录像锁定操作信息
typedef struct tagRecordLockOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_record_locktype_e				nLockType;									// 录像锁定类型
	uint64_t							uBeginTime;									// 起始时间
	uint64_t							uEndTime; 									// 结束时间
	int32_t								nDBId;										// DB ID
	char								szReason[DPSDK_CHAR_256];					// 原因
}Record_Lock_Operation_Info_t;

// 录像锁定查询信息
typedef struct tagRecordLockQueryInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	uint64_t							uBeginTime;									// 起始时间
	uint64_t							uEndTime; 									// 结束时间
}Record_Lock_Query_Info_t;

// 按时间获取录像url
typedef struct tagGetRecordStreamUrlTimeInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_recsource_type_e				nSource;									// 录像源类型                  
	uint64_t							uBeginTime;									// 开始时间 
	uint64_t							uEndTime;									// 结束时间
	char								szUrl[DPSDK_TAG_URL_LEN];					// URL信息
	uint32_t							nSessionId;									// cms sessionid
	int									nToken;
}Get_RecordStreamUrl_Time_Info_t;

// 云台方向控制信息
typedef struct tagPtzDirectInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_ptz_direct_e					nDirect;									// 云台方向控制命令
	uint32_t							nStep;										// 步长	
	bool								bStop;										// 控制命令：停止：true；控制：false
}Ptz_Direct_Info_t;

// 云台命令操作信息
typedef struct tagPtzOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_camera_operation_e			nOperation;									// 云台命令控制操作
	uint32_t							nStep;										// 步长	
	bool								bStop;										// 控制命令：停止：true；控制：false
}Ptz_Operation_Info_t;

// 云台三维定位操作信息
typedef struct tagPtzSitInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	int32_t							pointX;										// 坐标值X
	int32_t							pointY;										// 坐标值Y
	int32_t							pointZ;										// 坐标值Z	
	int32_t                         type;                                       // 1--快速定位, 2--精确定位
}Ptz_Sit_Info_t;

// 云台锁定操作信息
typedef struct tagPtzLockInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_ptz_locktype_e				nLock;										// 锁定/解锁类型
}Ptz_Lock_Info_t;

// 云台打开命令信息 目前包括灯光 雨刷 红外
typedef struct tagPtzOpenCommandInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	bool								bOpen;										// 开启
}Ptz_Open_Command_Info_t;

//云台定位报警信息
typedef struct tagPtzSitAlarmInfo
{
	char                                szDevId[DPSDK_CORE_CHL_ID_LEN];             // 设备ID
	int                                 nChannelID;                                 // 通道号 
	int                                 nPTZPan;                                    // 云台水平运动位置，有效范围：[0,3600] 
	int                                 nPTZTilt;                                   // 云台垂直运动位置，有效范围：[-1800,1800] 
	int                                 nPTZZoom;                                   // 云台光圈变动位置，有效范围：[0,128] 
	uint8_t                             bState;                                     // 云台运动状态, 0-未知1-运动2-空闲 
	uint8_t                             bAction;                                    // 云台动作，-预置点，-线扫，-巡航，-巡迹，-水平旋转 
	uint8_t                             bFocusState;                                // 云台聚焦状态, 0-未知, 1-运动状态, 2-空闲 
	uint8_t                             bEffectiveInTimeSection;                    // 在时间段内预置点状态是否有效 	//如果当前上报的预置点是时间段内的预置点，则为，其他情况为 
	int                                 nPtzActionID;                               // 巡航ID号 
	uint32_t                            dwPresetID;                                 // 云台所在预置点编号 
	float                               fFocusPosition;                             // 聚焦位置 
	uint8_t                             bZoomState;                                 // 云台ZOOM状态，-未知，-ZOOM，-空闲 
}Ptz_Sit_Alarm_Info;

// 视频图像属性
typedef struct tagVideoColorInfo
{
	int32_t								nBrightness;								// 亮度,默认64;范围0-128
	int32_t								nContrast;									// 对比度,默认64;范围0-128
	int32_t								nSaturation;								// 饱和度,默认64;范围0-128
	int32_t								nHue;										// 色调,默认64;范围0-128
}Video_Color_Info_t;

// 获取实时流URL信息
typedef struct tagGetRealStreamUrlInfo
{
	IN char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	IN dpsdk_stream_type_e				nStreamType;								// 码流类型
	IN dpsdk_media_type_e				nMediaType;									// 媒体类型
	IN dpsdk_trans_type_e				nTransType;									// 传输类型
	OUT char							szUrl[DPSDK_TAG_URL_LEN];					// URL信息
	OUT int32_t							nToken;										// 令牌
	OUT	int32_t							nTrackId;									// 轨道ID
}Get_RealStreamUrl_Info_t;

//获取对外媒体流URL信息
typedef struct tagGetExternalRealStreamUrlInfo
{
	IN char			                    szCameraId[DPSDK_CORE_CHL_ID_LEN];		    // 通道ID
	IN dpsdk_stream_type_e	            nStreamType;					            // 码流类型
	IN dpsdk_media_type_e	            nMediaType;						            // 媒体类型
	IN dpsdk_trans_type_e	            nTransType;						            // 传输类型
	IN dpsdk_trackid_type_e             nTrackId;                                   // 轨道ID
	IN bool                             bUsedVCS;                                   // 需要VCS转码
	IN dpsdk_videocodec_type_e          nVcsVideocodec;                             // 码流转码后的视频编码格式, bUsedVCS为1有效
	IN dpsdk_resolution_type_e          nVcsResolution;                             // 码流的视频分辨率，bUsedVCS为1有效
	IN uint32_t                         nVcsfps;                                    // 码流的帧率，bUsedVCS为1有效
	IN uint32_t                         nVcsbps;                                    // 码流的码率，bUsedVCS为1有效
	OUT char			                szUrl[DPSDK_TAG_URL_LEN];		            // URL信息
}Get_ExternalRealStreamUrl_Info_t;

// 单个预置点信息
typedef struct tagPtzSinglePrepointInfo
{
	uint32_t							nCode;										// 预置点编号
	char								szName[DPSDK_CORE_POINT_NAME_LEN];			// 名字
}Ptz_Single_Prepoint_Info_t;

// 单个预置点时间信息
typedef struct tagTimePtzSinglePrepointInfo
{
	uint32_t							nCode;										// 预置点编号
	char								szName[DPSDK_CORE_POINT_NAME_LEN];			// 名字
	char					    	    szBeginTime[DPSDK_CORE_POINT_TIME_LEN];	    // 开始时间
	char					    	    szEndTime[DPSDK_CORE_POINT_TIME_LEN];	    // 结束时间
}Ptz_Single_Time_Prepoint_Info_t;


// 云台预置点信息
typedef struct tagPtzPrepointInfo
{
	IN  char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	OUT uint32_t						nCount;										// 预置点数量
	OUT Ptz_Single_Prepoint_Info_t		pPoints[DPSDK_CORE_POINT_COUNT];			// 预置点信息
}Ptz_Prepoint_Info_t;

// 时间段内云台预置点信息
typedef struct tagPtzTimePrepointInfo
{
	IN  char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	OUT uint32_t						nCount;										// 预置点数量
	OUT Ptz_Single_Time_Prepoint_Info_t	pPoints[DPSDK_CORE_POINT_COUNT];			// 预置点信息
}Ptz_Time_Prepoint_Info_t;

// 云台预置点操作信息
typedef struct tagPtzPrepointOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_ptz_prepoint_cmd_e			nCmd;										// 预置点操作命令
	Ptz_Single_Prepoint_Info_t			pPoints;									// 预置点信息
}Ptz_Prepoint_Operation_Info_t;

// 定时云台任务信息
typedef struct tagPtzTimeTaskInfotInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	char                         		szBuf[DPSDK_CORE_TASK_LEN];					// 预置点信息
}Ptz_Time_Task_Info_t;

// 带时间段信息的云台预置点操作信息
typedef struct tagPtzTimePrepointOperationInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_ptz_prepoint_cmd_e			nCmd;										// 预置点操作命令
	Ptz_Single_Time_Prepoint_Info_t		pPoints;									// 预置点信息
}Ptz_Time_Prepoint_Operation_Info_t;

// 带时间段信息的云台预置点信息
typedef struct tagPrepointTime
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	Ptz_Single_Time_Prepoint_Info_t		pPoints;									// 预置点信息
}Ptz_Prepoint_Time_t;

// 云台扩展命令信息
typedef struct tagPtzExtendCommandInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	dpsdk_ptz_extend_cmd_e				nCmd;										// 扩展命令
	int32_t								nParam;										// 参数
}Ptz_Extend_Command_Info_t;

// 球机云台参数信息
typedef struct tagPtzParamInfo
{
	int									nPositionX;							// 云台水平运动位置,有效范围：[0,3600]
	int									nPositionY;							// 云台垂直运动位置,有效范围：[-1800,1800]
	int									nPositionZoom;						// 云台光圈变动位置,有效范围：[0,128]
	double								fSpeedPositionX;					// 云台水平方向速率,归一化到-1~1			
	double								fSpeedPositionY;					// 云台垂直方向速率,归一化到-1~1
	double								fSpeedZoom;							// 云台光圈放大倍率,归一化到0~1
}Ptz_Param_t;

// 球机可视域信息
typedef struct tagChannelViewInfo
{
	int		   nDistance;						   // 可视距离, 单位:米 
	int        nAngelH;                            // 水平可视角度, 0~1800, 单位:十分之一度 
	int        nAzimuthH;                          // 水平方位角度, 0~3600, 单位:十分之一度 
	int        nInclinationH;                      // 水平倾斜角度, -900~900, 单位:十分之一度
}Channel_View_Info_t;

// 获取上报人流量信息
typedef struct tagGetPeopleCount
{
	IN  char						    szBeginTime[DPSDK_CORE_TIME_LENGTH];		// 开始时间             
	IN  char						    szEndTime[DPSDK_CORE_TIME_LENGTH];			// 结束时间
	OUT uint32_t						nEnterCount;								// 进入人数
	OUT uint32_t						nExitCount;									// 出去人数
}Get_People_Count_t;

// 单个报警方案
typedef struct tagAlarmSingleEnableInfo
{
	char								szAlarmDevId[DPSDK_CORE_DEV_ID_LEN];		// 报警设备ID
	int32_t								nVideoNo;									// 视频通道 视频相关的报警 -1接收所有通道
	int32_t								nAlarmInput;								// 报警输入通道 报警输入相关的报警 -1接收所有通道
	dpsdk_alarm_type_e					nAlarmType;									// 报警类型
}Alarm_Single_Enable_Info_t;

// 报警方案
typedef struct tagAlarmEnableInfo
{
	uint32_t							nCount;										// 报警布控个数
	Alarm_Single_Enable_Info_t*			pSources;									// 报警内容
}Alarm_Enable_Info_t;

// 单个报警方案(针对整个部门所有设备设置报警)
typedef struct tagAlarmSingleEnableByDepInfo
{
	char								szAlarmDepartmentCode[DPSDK_CORE_DEV_ID_LEN];	// 报警设备所属部门
	int32_t								nVideoNo;									    // 视频通道 视频相关的报警 -1接收所有通道
	int32_t								nAlarmInput;								    // 报警输入通道 报警输入相关的报警 -1接收所有通道
	dpsdk_alarm_type_e					nAlarmType;									    // 报警类型
}Alarm_Single_Enable_By_Dep_Info_t;

// 报警方案(针对整个部门所有设备设置报警)
typedef struct tagAlarmEnableByDepInfo
{
	uint32_t							nCount;										// 报警布控个数
	Alarm_Single_Enable_By_Dep_Info_t*	pSources;							        // 报警内容
}Alarm_Enable_By_Dep_Info_t;

// 查询报警信息
typedef struct tagAlarmQueryInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	uint64_t							uStartTime;									// 开始时间
	uint64_t							uEndTime;									// 结束时间
	dpsdk_alarm_type_e					nAlarmType;									// 报警类型
	bool								bLinkInfo;									// 返回的报警信息是否有联动录像信息，用于兼容部分老平台
	bool								bPositionInfo;								// 返回的报警信息是否有点位信息，用于兼容新版本ADS新增点位信息
}Alarm_Query_Info_t;

// 单个报警信息
typedef struct tagSingleAlarmInfo
{
	dpsdk_alarm_type_e					nAlarmType;									// 报警类型
	dpsdk_event_type_e					nEventType;									// 事件状态
	char								szDevId[DPSDK_CORE_DEV_ID_LEN];				// 报警设备ID
	uint32_t							uChannel;									// 报警通道
	uint64_t							uAlarmTime;									// 报警时间
	dpsdk_alarm_dealwith_e				nDealWith;									// 处理意见
	char								szPicUrl[DPSDK_CORE_IMG_PATH_LEN];			// 报警图片url
	char								szSwLabel[DPSDK_CORE_RFID_LABEL];			// 超声波探测标签
	char								szElecLabel[DPSDK_CORE_RFID_LABEL];			// 车用电子标签
	char								szMessage[DPSDK_CORE_ALARM_MSG_LEN];		// 附加信息
}Single_Alarm_Info_t;

// 报警信息
typedef struct tagAlarmInfo
{
	IN uint32_t							nCount;										// 请求录像数
	OUT uint32_t						nRetCount;									// 实际返回个数
	OUT Single_Alarm_Info_t*			pAlarmInfo;									// 报警信息
}Alarm_Info_t;

// 客户端报警上报信息
typedef struct tagClientAlarmInfo
{
	char								szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 报警通道ID
	dpsdk_alarm_type_e					enAlarmType;								// 报警类型
	dpsdk_event_type_e					enStatus;									// 事件状态
	uint64_t							uAlarmTime;									// 报警时间
	char								szMsg[DPSDK_CORE_ALARM_MSG_LEN];			// 报警信息
}Client_Alarm_Info_t;


// 单个电视墙信息
typedef struct tagTvWallInfo
{
	uint32_t							nTvWallId;									// 电视墙ID
	uint32_t							nState;										// 启用状态
	char								szName[DPSDK_CORE_TVWALL_NAME_LEN];			// 名称
}TvWall_Info_t;

// 电视墙列表信息
typedef struct tagTvWallListInfo
{
	IN	uint32_t						nCount;										// 电视墙数量
	OUT	TvWall_Info_t*					pTvWallInfo;								// 电视墙信息
}TvWall_List_Info_t;

// 电视墙屏信息
typedef struct tagTvWallScreenInfo
{
	uint32_t							nScreenId;									// 屏ID
	char								szName[DPSDK_CORE_TVWALL_NAME_LEN];			// 名称
	char								szDecoderId[DPSDK_CORE_DEV_ID_LEN];			// 解码器ID
	float								fLeft;										// 左边距
	float								fTop;										// 上边距
	float								fWidth;										// 宽度
	float								fHeight;									// 高度
	bool								bBind;										// 是否绑定解码器
	bool								bCombine;									// 是否融合屏
}TvWall_Screen_Info_t;

// 电视墙布局信息
typedef struct tagTvWallLayoutInfo
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nCount;										// 屏数量
	OUT	TvWall_Screen_Info_t*			pScreenInfo;								// 屏信息
}TvWall_Layout_Info_t;


// 电视墙屏分割（分割后窗口ID从0开始，从左到右，从上到下依次递增，使用者自己维护）
typedef struct tagTvWallScreenSplit
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	tvwall_screen_split_caps		enSplitNum;									// 分割数量
}TvWall_Screen_Split_t;

// 电视墙屏开窗信息
typedef struct tagTvWallScreenOpenWindow
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	float							fLeft;										// 窗口左边距
	IN	float							fTop;										// 窗口上边距
	IN	float							fWidth;										// 窗口宽度
	IN	float							fHeight;									// 窗口高度

	OUT	uint32_t						nWindowId;									// 窗口ID
	OUT	uint32_t						nZorder;									// 窗口Z序
}TvWall_Screen_Open_Window_t;

// 电视墙屏窗口移动
typedef struct tagTvWallScreenMoveWindow
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	uint32_t						nWindowId;									// 窗口ID
	IN	float							fLeft;										// 窗口左边距
	IN	float							fTop;										// 窗口上边距
	IN	float							fWidth;										// 窗口宽度
	IN	float							fHeight;									// 窗口高度
}TvWall_Screen_Move_Window_t;

// 电视墙屏关窗信息
typedef struct tagTvWallScreenCloseWindow
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	uint32_t						nWindowId;									// 窗口ID
}TvWall_Screen_Close_Window_t;

// 电视墙屏窗口置顶
typedef struct tagTvWallScreenSetTopWindow
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	uint32_t						nWindowId;									// 窗口ID
}TvWall_Screen_Set_Top_Window_t;

// 电视墙屏窗口设置视频源
typedef struct tagSetTvWallScreenWindowSource
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	uint32_t						nWindowId;									// 窗口ID
	IN	char							szCameraId[DPSDK_CORE_CHL_ID_LEN];			// 通道ID
	IN	dpsdk_stream_type_e				enStreamType;								// 码流类型
	IN	uint64_t						nStayTime;									// 停留时间
}Set_TvWall_Screen_Window_Source_t;

// 电视墙屏窗口关闭视频源
typedef struct tagTvWallScreenCloseSource
{
	IN	uint32_t						nTvWallId;									// 电视墙ID
	IN	uint32_t						nScreenId;									// 屏ID
	IN	uint32_t						nWindowId;									// 窗口ID(若窗口ID=-1则表示关闭该屏中所有窗口的视频源)
}TvWall_Screen_Close_Source_t;

//安徽三联项目单个屏是否为画中画屏
typedef struct tagPicInPicInfo
{
	int							        nScreenID;								    //屏ID
	float						        fLeftPercent;								//左坐标 0~1之间的值
	float						        fTopPercent;								//上坐标 0~1之间的值
	float						        fRightPercent;								//右坐标 0~1之间的值 右>左
	float						        fBottomPercent;								//下坐标 0~1之间的值 下>上
	int							        nBigChnNum;									//大窗口号 此值有取值范围为：屏1：0~15；屏2：16~19；屏3：20~23；屏4：24~27；
	int							        nSmallChnNum;								//小窗口号 此值有取值范围为：屏1：0~15；屏2：16~19；屏3：20~23；屏4：24~27；
	dpsdk_tvwall_pip_e                  enPIP;										//是否采用画中画功能               
}Pic_In_Pic_Info_t;

//安徽三联项目画中画上墙控制操作
typedef struct tagPipTvWallScreenInfo
{
	IN	uint32_t						nTvWallId;									// 电视墙ID

	IN	Pic_In_Pic_Info_t				picInPicInfo[DPSDK_PIP_SCREEN_NUM];			//画中画上墙信息
}Pip_TvWall_Screen_Info_t;

typedef struct tagTvWallSubTvInfo
{
	uint32_t							nTvWallId;
	uint32_t							nScreenId;
}TvWall_SubTv_Info_t;

// 违章报警数据结构信息
typedef struct tagTrafficAlarmInfo
{
	char			                    szCameraId[DPSDK_CORE_CHL_ID_LEN];		    // 通道ID
	char			                    nPtsIp[DPSDK_CORE_BAY_IP_LEN];				// pts内网
	char			                    nPtsIpy[DPSDK_CORE_BAY_IP_LEN];		        // pts外网
	int32_t				                nPicPort;								    // pic内网port
	int32_t				                nPicPorty;								    // pic外网port
	dpsdk_alarm_type_e	                type;								        // 违章类型
	char			                    szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];		// 车牌
	int32_t				                nLicentype;							        // 车牌颜色类型
	int32_t				                nCarColor;								    // 车身颜色
	int32_t				                nCarLogo;								    // 车标类型
	int32_t				                nWay;									    // 车道号
	char			                    szPicUrl[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_BAY_URL_LEN];	// 图片URL
	uint32_t		                    nPicGroupStoreID;						    // 图片组存储ID
	int32_t				                bNeedStore;									// 是否需存盘 0：不需存盘 1：需存盘
	int32_t				                bStored;									// 是否已存盘 0：未存盘 1：已存盘int	
	int32_t				                nAlarmLevel;								// 报警级别
	int32_t				                nAlarmTime;                                 // 报警发生时间,精度为秒，值为time(NULL)值

	//新增字段
	int32_t								nChannel;                                  // 通道
	char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];         // 设备ID
	char								szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];// 设备名称 
	char								szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN]; // 通道名称
	int32_t								nCarType;                                  // 车类型
	int32_t								nCarSpeed;                                 // 车速
	int32_t								nCarLen;                                   // 车身长度单位
	int32_t								nCardirect;                                // 行车方向
	int32_t								nMaxSpeed;                                 // 限制速度
	int32_t								nMinSpeed;                                 // 最低限制速度
	int32_t								nRtPlate[DPSDK_CORE_COORDINATE_LEN];       // 车牌坐标
	char								szMessage[DPSDK_CORE_ALARM_MSG_LEN];	   // 报警信息
}Traffic_Alarm_Info_t;

// 交通流量上报数据结构信息
typedef struct tagTrafficFlowInfo
{
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];	        // 通道编号
	char                                szDirect[DPSDK_CORE_DIRECT_LEN];            // 方向编号，见字典表
	uint16_t                            nInterval;                                  // 上报间隔，单位秒
	uint16_t                            nTrafficFlow;		                        // 交通流量（包括从设备接收到的所有数据，违章也包括在内）	
	uint64_t                            nTime;                                      // 上报时间，1970的秒数
}TrafficFlow_Info_t;

// 每个车道交通流量状态
typedef struct tagTrafficFlowLaneState
{
	uint64_t                            nDateTime;                                   // 数据上报时间 UTC时间
	uint32_t                            nDetectorID;                                 // 检测车道编号
	uint32_t                            nVolume;                                     // 交通量（辆/单位时间）小车当量
	uint32_t                            nFlowRate;                                   // 流率（辆/小时）小车当量
	float                               nAverageSpeed;                               // 平均速度（公里/小时）
	float                               fTimeOccupancy;                              // 平均时间占有率（%）
	float                               nTimeHeadway;                                // 车头时距（秒）
	float                               nLength;                                     // 平均车长（米）
	float                               nBackOfQueue;                                // 排队长度（米）
	float                               nTravelTime;                                 // 旅行时间（秒）
	float                               nDelay;                                      // 延误（秒），##
	uint32_t                            nMotoVehicles;                               // 微型车交通量（辆/单位时间）
	uint32_t                            nSmallVehicles;                              // 小车交通量（辆/单位时间）
	uint32_t                            nMediumVehicles;                             // 中车交通量（辆/单位时间）
	uint32_t                            nLargeVehicles;                              // 大车交通量（辆/单位时间）
	uint32_t                            nLongVehicles;                               // 特大车交通量（辆/单位时间）
	uint32_t                            nState;                                      // 状态值：1-流量过大,2-流量过大恢复,3-正常,4-流量过小,5-流量过小恢复
	uint32_t                            nFlow;                                       // 流量值，单位：辆
	uint32_t                            nPeriod;                                     // 流量值对应的统计时间
	uint32_t                            nDrivingDir;                                 // 行驶方向，上行下行。上行，即车辆离设备部署点越来越近 /下行，即车辆离设备部署点越来越远
	int32_t                             nDirection;                                  // 车道方向
	int32_t                             nPeriodBySeconds;                            //以秒为单位的周期
}TrafficFlow_Lane_State;


// 设备交通流量上报详细信息数据结构
typedef struct tagDevTrafficFlowInfo
{
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];          // 通道编号
	char                                szDirect[DPSDK_CORE_DIRECT_LEN];             // 方向编号，见字典表
	uint16_t                            nTrafficLaneNum;                             // 交通流量数量
	TrafficFlow_Lane_State              LaneState[DH_MAX_CORE_LANE_NUM];             // 车道交通流量状态,最多支持8个车道
}DevTrafficFlow_Info_t;

//订阅流量上报请求信息
typedef struct tagSubscribeTrafficFlowInfo
{   
	int32_t                             nChnlCount;                                  // 订阅通道的数量
	int32_t                             nInterval;                                   // 订阅通道上报间隔，单位秒
	Enc_Channel_Info_t*                 pEncChannelnfo;                              // 通道信息
	int32_t                             nSubscribeFlag;                              // 订阅标记。0:取消订阅，1：订阅
}Subscribe_Traffic_Flow_Info_t;

//订阅云台状态报警信息
typedef struct tagSubscribePtzSitAlarmInfo
{
	int32_t                             nChnlCount;                                 //订阅通道的数量
	Ptz_Channel_Info_t*                 pPtzChannelnfo;                             // 通道信息
	int32_t                             nSubscribeFlag;                             //订阅标记。0:取消订阅，1：订阅
}Subscribe_Ptz_SitAlarmInfo_t;

// 车辆违章图片信息
typedef struct tagTrafficViolationInfo
{
	char                                szRecordId[DPSDK_CORE_CAR_RECORD_ID_LEN];    // 记录ID
	char	                            szDeviceId[DPSDK_CORE_DEV_ID_LEN];		     // 设备ID
	int32_t		                        nChannel;					                 // 通道
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];     	 // 通道编号
	int32_t	                            ntype;						                 // 违章报警类型 见EnumCarRule 枚举定义	
	char	                            szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 设备名称,UTF8编码
	char	                            szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];	// 通道名称,UTF8编码	
	char	                            szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];		 // 车牌号码，UTF8编码
	int32_t		                        nCarNumType;				                 // 车牌类型
	int32_t		                        nCarNumColor;				                 // 车牌颜色
	int32_t	                    	    nCarColor;					                 // 车身颜色
	int32_t                             nCarType;					                 // 车类型
	int32_t		                        nCarLogo;					                 // 车标类型
	int32_t		                        nWay;						                 // 车道号
	int32_t		                        nCarSpeed;					                 // 车速
	int32_t		                        nCarLen;					                 // 车身长度，单位cm,不能超过4位
	int32_t		                        nCardirect;					                 // 行车方向
	int32_t		                        nMaxSpeed;					                 // 限制速度,用于超速判断
	int32_t		                        nMinSpeed;					                 // 最低限制速度,用于超速判断
	char   	                            szCapturedate[DPSDK_CORE_TIME_LEN];		     // 精确到秒,如 2013-09-25 12:04:08
	char	                            szOptNote[DPSDK_CORE_OPT_NOTE_LEN];			 // 备注信息
	int32_t                             nPicNum;                                     // 图片张数，最大支持6张
	char                                szPicName[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_FILEPATH_LEN]; // 图片文件命名，最大支持6张。如果为空，则由PTS生成。
	int32_t 	                        nRtPlate[DPSDK_CORE_COORDINATE_LEN];	     // 车牌坐标,left,top, right, bottom,不能超过4位		
	int32_t                             nDataSource;				                 // 数据来源,不能超过2位
}Traffic_Violation_Info_t;

typedef struct tagDeptAreaRelation
{
	char                                szDeptCode[DPSDK_CORE_ORG_CODE_LEN];         // 部门节点编码
	char                                szAreaCode[DPSDK_CORE_ORG_CODE_LEN];         // 辖区节点编码
}DeptArea_Relation_t;

typedef struct tagGetDeptAreaRelation
{
	IN  uint32_t						nCount;                                      // 部门辖区关系记录数
	OUT DeptArea_Relation_t*			pDeptAreaRelation;				             // 部门辖区关系，在外部创建，如果为NULL则只返回个数
}Get_DeptArea_Relation_t;

//获取部门人员请求信息

typedef struct tagPersonInfo
{    
	IN char                             szCode[DPSDK_CORE_PERSON_CODE_LEN];          // 人员编码
	IN char                             szName[DPSDK_CORE_PERSON_NAME_LEN];          // 人员姓名
	IN char                             szDeptCode[DPSDK_CORE_PERSON_DEPTCODE_LEN];  // 人员所属部门编码
	IN char                             szSN[DPSDK_CORE_PERSON_SN_LEN];              // 人员唯一编号
	IN char                             szType[DPSDK_CORE_PERSON_TYPE_LEN];          // 人员类型
	IN char                             szOffice[DPSDK_CORE_PERSON_OFFICE_LEN];      // 人员办公地点
	IN char                             szMobileNum[DPSDK_CORE_PERSON_MOBILENUM_LEN];// 人员移动电话
	IN char                             szVirtualNum[DPSDK_CORE_PERSON_VIRTUALNUM_LEN];// 人员虚拟短号
	IN char                             szState[DPSDK_CORE_PERSON_STATE_LEN];        // 人员状态
}Person_Info_t;

typedef struct tagGetPersonInfo
{
	IN char								szDeptCoding[DPSDK_CORE_PERSON_DEPTCODE_LEN];// 部门code
	IN uint32_t							nPersonCount;						         // 部门人员个数
	OUT Person_Info_t*					pPersonInfo;						         // 人员信息，在外部创建，如果为NULL则只返回个数
}Get_Person_Info_t;

//车辆信息
typedef struct tagCarInfo 
{
	char	                            szOwenerCode[DPSDK_CORE_DGROUP_DGPCODE_LEN]; // 所属组织Code
	char	                            szCode[DPSDK_CORE_CAR_CODE_LEN];	         // 车辆code
	char                                szColor[DPSDK_CORE_CAR_COLOR_LEN];           // 车辆颜色
	char                                szType[DPSDK_CORE_CAR_TYPE_LEN]; 	         // 车辆类型
	char                                szModel[DPSDK_CORE_CAR_MODEL_LEN];	         // 车辆品牌型号
	int32_t                             nApprovedSeating;	                         // 核定载人数
	char                                szSize[DPSDK_CORE_CAR_SIZE_LEN];             // 车辆尺寸 长×宽×高；单位：毫米
	char                                szVin[DPSDK_CORE_CAR_VIN_LEN];               // 车架号
	char                                szEngineNo[DPSDK_CORE_ENG_NO_LEN];           // 引擎号
	char                                szPicPath[DPSDK_CORE_CAR_PICPATH_LEN];       // 车辆照片路径 255
	char	                            szPlateNo[DPSDK_CORE_CAR_PLATENO_LEN];       // 车牌号码
	char                                szSecondPlateNo[DPSDK_CORE_CAR_PLATENO_LEN]; // 第二车牌号
	char	                            szPlateColor[DPSDK_CORE_CAR_PLATECOLOR_LEN]; // 车牌颜色
	char	                            szPlateType[DPSDK_CORE_CAR_PLATETYPE_LEN];	 // 车牌类型								                           // 车牌类型
	char                                szPlateRegistered[DPSDK_CORE_REGIST_LEN];    // 车牌注册地
	char                                szRegisterDate[DPSDK_CORE_REGIST_DATE_LEN];  // 注册日期
	char                                szOwnerName[DPSDK_CORE_CAR_OWNERNAME_LEN];   // 业主名称
	char                                szOwnerPhone[DPSDK_CORE_CAR_OWNERPHONE_LEN]; // 业主电话
	int32_t	                            nState;									     // 车辆状态
	//char	                            szGPSCode[DPSDK_CORE_CAR_GPSCODE_LEN];	 	 // GPS编号
}Car_Info_t;

//获取部门车辆请求信息
typedef struct tagGetCarInfo
{
	IN char								szDeptCoding[DPSDK_CORE_DEPTCODE_LEN];       // 部门code
	IN uint32_t							nCarCount;							         // 部门车辆个数
	OUT Car_Info_t*					    pCarInfo;							         // 车辆信息，在外部创建，如果为NULL则只返回个数
}Get_Car_Info_t;

//订阅卡口过车(或区间测速)信息请求信息
typedef struct tagSubscribeBayCarInfo
{   
	int32_t                             nChnlCount;                                  // 订阅通道的数量
	Enc_Channel_Info_t*                 pEncChannelnfo;                              // 通道信息
	int32_t                             nSubscribeFlag;                              // 订阅标记。0:取消订阅，1：订阅
}Subscribe_Bay_Car_Info_t;

//卡口过车信息
/* 
车牌颜色：
		 0 蓝 
		 1 黄 
		 2 白 
		 3 黑 
		 4 绿 
		 100 其他 

车身颜色：
		 0 白 
		 1 黑 
		 2 红 
		 3 黄 
		 4 灰 
		 5 蓝 
		 6 绿 
		 7 橙 
		 8 紫 
		 9 青 
		 10 粉 
		 11 棕 
		 100 其他 

车辆类型：
		 0 未知 
		 1 小型汽车 
		 2 大型汽车 
		 3 使馆汽车 
		 4 领馆汽车 
		 5 境外汽车 
		 6 外籍汽车 
		 7 低速汽车 
		 8 拖拉机 
		 9 挂车 
		 10 教练车 
		 11 临时行驶车 
		 12 警用汽车 
		 13 警用摩托车 
		 14 普通摩托车 
		 15 轻便摩托车 
		 16 机动车 
		 17 公交车 
		 18 摩托车 
		 19 客车 
		 20 大货车 
		 21 中货车 
		 22 轿车 
		 23 面包车 
		 24 小货车 
		 256 非机动车 
		 257 自行车 
		 258 三轮车 
		 512 行人 
		 513 军用车 

车牌类型：
		 0 未知 
		 1 蓝牌黑牌 
		 2 黄牌 
		 3 双层黄尾牌 
		 4 警牌 
		 5 武警牌 
		 6 部队号牌 
		 7 部队双层 
		 8 港澳特区号牌 
		 9 教练车号牌 
		 10 个性号牌 
		 11 农用牌 
		 12 使馆号牌 
		 13 摩托车号牌 
		 14 拖拉机号牌 
		 15 其他号牌 
		 16 公务车 
		 17 私家车 
		 18 军用 
		 19 民航号牌 
		 20 黑牌 

违章类型：
		 0  出现车辆 
		 1  超速 
		 2  超低速 
		 3  其他 
		 4  闯红灯 
		 5  不安车道行驶 
		 6  压线 
		 7  逆向行驶 
		 8  非机动车道 
		 10  机动车违反禁令标志指示 
		 30  违章左转 
		 31  违章右转 
		 32  违章掉头 
		 33  违章停车 
		 34  违章变道 
		 35  压黄线 
		 36  交通拥堵 
		 37  交通滞留 
		 38  黄牌车占道 
		 39  有车占道 
		 40  手动抓拍 
		 41  占用公交车道事件 
		 42  违章倒车事件 
		 43  闯黄灯事件 
		 44  车位有车事件 
		 45  车位无车事件 
		 46  吸烟 
		 47  打电话 
		 48  不系安全带 
		 49  遮挡号牌 
		 50  黄网格违章停车 
		 51  交通抛洒物事件 
		 52  交通行人事件 
		 53  绕行卡口 
		 54  限行 
		 55  斑马线行人优先 
		 56  受限车牌事件 
		 57  压停止线事件 
		 58  路肩行驶事件 
		 59  禁止通行事件 
		 60  车辆黑名单事件 
		 61  车牌前后对比 
		 62  超重 
		 63  行人闯红灯 
		 64  超限违章 
		 65  底盘检查 
		 99  未知 

方向代码:
		 0 东向西 
		 1 西向东 
		 2 南向北 
		 3 北向南 
		 4 东南向西北 
		 5 西北向东南 
		 6 东北向西南 
		 7 西南向东北 

图片类型：
		 0 普通 
		 1 合成 
		 2 抠图,车牌小图片 
		 3 驾驶员图片 
		 4 底盘图片 
*/
typedef struct tagBayCarInfo
{
	char                                szDeviceId[DPSDK_CORE_DEV_ID_LEN];            //设备ID
	int32_t                             nDevChnId;                                    //通道号
	char                                szChannelId[DPSDK_CORE_CHL_ID_LEN];           //通道ID
	char                                szDeviceName[DPSDK_CORE_DGROUP_DEVICENAME_LEN]; //设备名称
	char                                szDeviceChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN]; //通道名称
	char                                szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];          //车牌号
	int32_t                             nCarNumType;                                  //车牌类型
	int32_t                             nCarNumColor;                                 //车牌颜色
	int32_t                             nCarSpeed;                                    //车速
	int32_t                             nCarType;                                     //车类型
	int32_t                             nCarColor;                                    //车颜色
	int32_t                             nCarLen;                                      //车长
	int32_t                             nCarDirect;                                   //行车方向
	int32_t                             nWayId;                                       //车道号
	uint64_t							lCaptureTime;                                 //抓图时间，精确到毫秒级
	unsigned long                       lPicGroupStoreID;                             //图片组存盘ID 
	int32_t                             nIsNeedStore;                                 //图片组是否需要存盘 0：不需要 1：需要
	int32_t                             nIsStoraged;                                  //图片组是否已经存盘 0：未完成存盘 1：已成功存盘，保留，目前未使用
	char                                szCaptureOrg[DPSDK_CORE_DGROUP_DGPNAME_LEN];  //通缉机构
	char                                szOptOrg[DPSDK_CORE_DGROUP_DGPNAME_LEN];      //布控机构
	char                                szOptUser[DPSDK_CORE_PERSON_NAME_LEN];        //布控人员
	char                                szOptNote[DPSDK_CORE_OPT_NOTE_LEN];           //备注信息
	char                                szImg0Path[DPSDK_CORE_IMG_PATH_LEN];          //图片路径
	char                                szImg1Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg2Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg3Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg4Path[DPSDK_CORE_IMG_PATH_LEN];
	char                                szImg5Path[DPSDK_CORE_IMG_PATH_LEN]; 

	char								szImgPlatePath[DPSDK_CORE_IMG_PATH_LEN];		//车牌小图片坐标
	int									icarLog;										//车标类型
	int									iPlateLeft;
	int									iPlateRight;
	int									iPlateTop;
	int									iPlateBottom;
}Bay_Car_Info_t;

//卡口布控告警信息
typedef struct tagBayWantedAlarmInfo
{
	char            szCameraId[DPSDK_CORE_CHL_ID_LEN];         //通道ID
	int32_t         nChannel;                                  //通道号
	char			szDeviceId[DPSDK_CORE_DEV_ID_LEN]; 	       //设备ID（DVR+通道）
	char			szPtsIp[DPSDK_CORE_BAY_IP_LEN];	            //pts内网
	char			szPtsIpy[DPSDK_CORE_BAY_IP_LEN];	        //pts外网
	int32_t			ulPicPort;                                  //pic内网port
	int32_t			ulPicPorty;                                 //pic外网port
		
	//布控信息
	char			szSurveyId[DPSDK_CORE_DEV_ID_LEN];	        //布控ID
	char			szSurveryOrg[DPSDK_CORE_BAY_ORG_LEN];       //布控机构
	char			szArrestOrg[DPSDK_CORE_BAY_SURVERY_LEN];    //通缉机构
	char			szUserName[DPSDK_CORE_BAY_SURVERY_LEN];     //当前布控的操作员
	int32_t			nAlart;								        //报警类型
	int32_t		    nSurlevel;						            //布控等级
	int32_t			nState;								        //布控状态
	int32_t			nCartype;						            //车辆类型
	char			szCartypeName[DPSDK_CORE_BAY_SURVERY_LEN];  //车辆类型名称
	char			szCarNum[DPSDK_CORE_BAY_SURVERY_LEN];		//车牌
	int32_t		    nLicentype;							        //车牌颜色类型
	char		    szCarlicenName[DPSDK_CORE_BAY_SURVERY_LEN]; //车牌颜色名称
	int32_t			nCarnotype;							        //车牌类型
	char			szCarnotypeName[DPSDK_CORE_BAY_SURVERY_LEN];//车牌类型名称

	int32_t			nCarcolor;								    //车身颜色
	char			szCarpower[DPSDK_CORE_BAY_SURVERY_LEN];		//发动机号
	int32_t			nCarlen;								    //车长：厘米
	char			szFrameno[DPSDK_CORE_BAY_SURVERY_LEN];		//车架号
	int32_t			nBckcolor;								    //车牌底色

	int32_t			nSurType;								    //布控类型
	uint64_t		nBegindate;
	uint64_t		nEnddate;

	char			szIdentify[DPSDK_CORE_BAY_SURVERY_LEN];		//车主身份证
    char			szOwnName[DPSDK_CORE_BAY_SURVERY_LEN];		//车主姓名
	char			szOwnAddr[DPSDK_CORE_BAY_SURVERY_LEN];		//车主地址
	char			szOwnPhone[DPSDK_CORE_BAY_SURVERY_LEN];		//车主电话
	char			szDescirbe[DPSDK_CORE_BAY_SURVERY_LEN];		//描述
	char			szOrderlyPhone[DPSDK_CORE_BAY_PHONE_LEN];	//布控单位值班电话
	char			szLinkMan[DPSDK_CORE_BAY_MAN_LEN];			//布控联系人
	char			szLinkManPhone[DPSDK_CORE_BAY_PHONE_LEN];   //布控联系人电话
	char			szOriUrl[DPSDK_CORE_IMG_URL];				//车辆原始图片

	//报警信息
	char			szPicUrl[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_IMG_URL];//图片URL
	uint32_t		ulPicGroupStoreID;					        //图片组存储ID
	int32_t			bNeedStore;						            //是否需存盘 0：不需存盘 1：需存盘
	int32_t			bStored;							        //是否已存盘 0：未存盘 1：已存盘
	int32_t			nCarLogo;							        //车标类型

	int32_t			nAlarmLevel;						        //布控报警级别
	uint32_t		ulAlarmTime;							    //报警发生时间,精度为秒，值为time(NULL)值
	int32_t			nDeviceType;						        //设备类型。1编码器，2报警主机
	int32_t         nLightColor;                                //红绿灯状态，0 未知,1 绿灯,2 红灯,3 黄灯

}Bay_WantedAlarm_Info_t;


//区间测速上报信息
typedef struct tagAreaDetectInfo
{
	char                                szAreaId[DPSDK_CORE_AREA_ID_LEN];                // 区间ID 50
	char                                szAreaName[DPSDK_CORE_AREA_NAME_LEN];            // 区间名称 256
	char                                szStartDevId[DPSDK_CORE_DEV_ID_LEN];             // 起始设备ID
	uint32_t                            nStartChnNum;                                    // 起始点通道号
	char                                szStartChnId[DPSDK_CORE_CHL_ID_LEN];             // 起始点通道ID 
	char                                szStartDevName[DPSDK_CORE_DGROUP_CHNNAME_LEN];   // 起始点设备名,UTF8编码
	char                                szStartDevChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];// 起始点通道名,UTF8编码
	uint64_t                            nStartCapTime;                                   // 起始点通过时间
	uint32_t                            nStartCarSpeed;                                  // 起始点通过速度
	char                                szStartPosId[DPSDK_CORE_POS_ID_LEN];             // 起始点卡点ID
	char                                szStartPosName[DPSDK_CORE_POS_NAME_LEN];		 // 起始点卡点名
	char                                szEndDevId[DPSDK_CORE_DEV_ID_LEN];               // 终止点设备ID
	uint32_t                            nEndChnNum;                                      // 终止点通道号
	char                                szEndChnId[DPSDK_CORE_CHL_ID_LEN];               // 终止点通道ID 
	char                                szEndDevName[DPSDK_CORE_DGROUP_CHNNAME_LEN];     // 终止点设备名,UTF8编码
	char                                szEndDevChnName[DPSDK_CORE_DGROUP_CHNNAME_LEN];  // 终止点通道名,UTF8编码
	uint64_t                            nEndCapTime;                                     // 终止点通过时间
	uint32_t                            nEndCarSpeed;                                    // 终止点通过速度
	char                                szEndPosId[DPSDK_CORE_POS_ID_LEN];               // 终止点卡点ID
	char                                szEndPosName[DPSDK_CORE_POS_NAME_LEN];           // 终止点卡点名
	uint32_t                            nAreaRange;                                      // 区间距离
	uint32_t                            nMinSpeed;                                       // 路段限速下限 
	uint32_t                            nMaxSpeed;                                       // 路段限速上限 
	char                                szCarNum[DPSDK_CORE_CAR_NUM_LENGTH];             // 车牌号码，UTF8编码
	uint32_t                            nCarNumType;                                     // 车牌类型
	uint32_t                            nCarNumColor;                                    // 车牌颜色
	uint32_t                            nCarColor;                                       // 车身颜色
	uint32_t                            nCarType;                                        // 车类型
	uint32_t                            nCarLogo;                                        // 车标类型
	uint32_t                            nCarAvgSpeed;                                    // 车辆平均速度
	uint32_t                            nIsIllegalSpeed;                                 // 是否超速或低速
	uint32_t                            nPicNum;                                         // 图片张数，最大支持6张
	char                                szPicName[DPSDK_CORE_BAY_IMG_NUM][DPSDK_CORE_FILEPATH_LEN]; // 图片文件命名，最大支持6张。
	uint32_t                            nRtPlate[DPSDK_CORE_COORDINATE_LEN];             // 车牌坐标,left,top, right, bottom,不能超过4位
	char                                szCarPlatePicURL[256];                           // 车牌小图片URL
}Area_Detect_Info_t;

///< 获取组播 ip:port 
typedef struct tagCamStream
{
	char	camid[DPSDK_CORE_CHL_ID_LEN];
	long	limit;
	char	decosderIp[DPSDK_CORE_IP_LEN];
	char	channel[DPSDK_CORE_CHL_ID_LEN];
	char	param[DPSDK_CORE_CHL_ID_LEN];		// 返回参数
}CamStream_Tnfo_t;

///< 通过解码器IP与通道号获取电视墙对应窗口信息
typedef struct tagQueryTvWallInfo{
	char	devip[DPSDK_CORE_CHL_ID_LEN];		// 需要获取的解码器IP
	char	devid[DPSDK_CORE_DEV_ID_LEN];		// 设备ID
	long	port_;								// 解码设备端口号
	long	channel_;							// 需要获取的解码器通道号
	char	camid[DPSDK_CORE_DEV_ID_LEN];		// 需要绑定视频源的设备ID
	char	camgip[DPSDK_CORE_IP_LEN];			// 需要获取的解码器组播IP
	long	camport;							// 需要获取的解码器组播端口号
	long	tvwallid_;							// 电视墙编号
	long	screenid_;							// 屏幕编号
	long	wndid_;								// 窗口编号
	bool	bgood_;								// 是否获取成功
}QueryTvWall_Info_t;

//单个事件信息
typedef struct tagOneIssueInfo
{
	char szStatName[DPSDK_CORE_KANGTEER_DATA];
	char szUseClass[DPSDK_CORE_KANGTEER_DATA];
	char szContent[DPSDK_CORE_KANGTEER_DATA];
	char szIssueName[DPSDK_CORE_KANGTEER_DATA];
	char szDeviceID[DPSDK_CORE_KANGTEER_DATA];
	char szBeginTime[DPSDK_CORE_KANGTEER_DATA];
	char szEndTime[DPSDK_CORE_KANGTEER_DATA];
	char szWorkCompany[DPSDK_CORE_KANGTEER_DATA];
	char szLinkMan[DPSDK_CORE_KANGTEER_DATA];
	char szLinkMethod[DPSDK_CORE_KANGTEER_DATA];
	char szAllowJob[DPSDK_CORE_KANGTEER_DATA];
}One_Issue_Info_t;

//事件信息
typedef struct tagIssueInfo
{
	One_Issue_Info_t oneIssueInfo[DPSDK_CORE_KANGTEER_GROUP_DATA];
	int nSize;
}Issue_Info_t;

//单张图片信息
typedef struct tagOneFtpPicInfo
{
	char szDevId[DPSDK_CORE_DEV_ID_LEN];			//摄像头ID
	int  nChlNo;									//通道号
	char szCapTime[DPSDK_CORE_TIMESTR_LEN];			//抓图时间
	char szFtpPath[DPSDK_CORE_FILEPATH_LEN];		//Ftp保存图片路径
}One_Ftp_Pic_Info_t;

//图片信息
typedef struct tagFtpPicInfo
{
	One_Ftp_Pic_Info_t oneFtpPicInfo[DPSDK_CORE_QUERY_PIC_MAXCOUT];			//单张图片信息
	int nSize;																//图片张数
}Ftp_Pic_Info_t;

typedef struct OpeOSDTemplatInfo
{
	uint32_t					nTemplateId;
	uint32_t					nMsgType;												// 1:OSD信息，2：短信
	uint32_t					nOpeType;												// 1、添加 2、修改 3、删除
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// 信息内容
	char						szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];
	char						szMemo[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];
}Ope_OSD_Templat_Info_t;

typedef struct SearchHistoryOSDInfo
{
	uint32_t					nBeginTime;
	uint32_t					nEndTime;
	uint32_t					nMsgType;								// 1:OSD信息，2：短信
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];			// 设备id
}Search_History_OSDInfo_t;

typedef struct SendOSDInfo
{
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];							// 设备id
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// 信息内容
}Send_OSDInfo_t;

typedef struct SendSMSInfo
{
	int							nUserId;												// 用户id
	int64_t						nTime;													// 时间
	char						szDevId[DPSDK_CORE_DEV_ID_LEN];							// 设备id
	char						szDevName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];			// 设备名称
	char						szMessage[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];			// 信息内容
	char						szSMSNo[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];				// 信息电话号码
}Send_SMS_Info_t;

//资源信息上传信息
typedef struct tagSaveFileInfo
{
	char								szCaseCode[DPSDK_CORE_CASE_CODE_LEN];		// 案件编号
	char								szCaseName[DPSDK_CORE_CASE_NAME_LEN];		// 案件名称
	char								szStartData[DPSDK_CORE_TIME_LEN];			// 案件开始 yyyy-mm-dd hh:mi:ss
	char								szEndData[DPSDK_CORE_TIME_LEN];				// 案件结束 yyyy-mm-dd hh:mi:ss
	char								szCaseAddr[DPSDK_CORE_CASE_ADDR_LEN];		// 案件地址
	char								szCaseMemo[DPSDK_CORE_CASE_MEMO_LEN];		// 案件备注
	char								szFilePath[DPSDK_CORE_FILE_PATH_LEN];		// 文件目录
	char								szFileMemo[DPSDK_CORE_FILE_MEMO_LEN];		// 文件描述
	char								szGpsX[DPSDK_CORE_GPS_LEN];					// 上传文件经度
	char								szGpsY[DPSDK_CORE_GPS_LEN];					// 上传文件纬度
	int									nFileType;									// 文件类型 1图像 2视频 3其他
	char								szImageType[DPSDK_CORE_FILE_TYPE_LEN];		// 图片文件格式 JPEG/BMP/GIF/PNG/Other
	int									nImageWidth;								// 图片宽度 0-8192
	int									nImageHeigth;								// 图片高度 0-8192
	char								szVideoFlowType[DPSDK_CORE_FILE_TYPE_LEN];	// 码流类型 PS/TS/DHAV/Other
	char								szVideoEncode[DPSDK_CORE_FILE_TYPE_LEN];	// 编码格式 H264/JPEG4/Other

	char								szLocalPath[DPSDK_CORE_FILE_PATH_LEN];		// 本地文件路径
}Save_File_Info;

//AsyncLoadDGroupInfo传递给Thread的信息
typedef struct tagAsyncThreadInfo
{
	int   nSeq;
	int   nTimeout;
	void* pDLLDpsdk;
	void* pFun;
	void* pUserParam;
}Async_Thread_Info_t;

//视频分享结构体
struct ShareVideoInfo
{
	char	szCameraId[DPSDK_CORE_CHL_ID_LEN];		//摄像头ID
	int		nType;									//1视频，2音频，3音频＋视频
	int		nSubStream;								//码流类型。1主码流，2子码流
	int		nIsMobile;								//非零表示手机客户端请求
	uint64_t	nPlanId;							//录像计划ID
	uint64_t	nPlaybacktime;						//回放时间
};

typedef struct tagDataAnalysisInfo
{
	tagDataAnalysisInfo()
	{
		pFun = NULL;
		nProviderType = 0;
		hHandle = NULL;
		pTSStreamParseDH = NULL;
	}
	~tagDataAnalysisInfo()
	{
	}

	void* pFun;
	int nProviderType;
	void* hHandle;
	void* pTSStreamParseDH;
}Data_Analysis_Info_t;

typedef struct tagStreamConvertorInfo
{
	void* pDLLDpsdk;
	void* pFun;
	void* hSCHandle;
	int   nSeq;
	int   nMediaType;
	char  szNodeId[DPSDK_CORE_DEV_ID_LEN];
	int   paramVal;
}Stream_Convertor_Info_t;


typedef struct tagTalkParam
{
	dpsdk_talk_type_e talkType;
	dpsdk_audio_type_e audioType; 
	dpsdk_talk_bits_e audioBit;
	Talk_Sample_Rate_e sampleRate; 
	dpsdk_trans_type_e transMode;

}Talk_Param_t;

typedef enum
{	// 报警主机布防操作控制类型
	CONTROL_ERROR = 0,			// 控制类型错误
	CONTROL_DEV_ARM,			// 针对设备布防-1
	CONTROL_DEV_DISARM,			// 针对设备撤防-2
	CONTROL_DEV_ARM_HOME,		// 在家布防-3
	CONTROL_DEV_ARM_OUT,		// 外出布防-4
	CONTROL_CHL_BYPASS,			// 针对通道旁路-5
	CONTROL_CHL_DISBYPASS,		// 针对通道取消旁路-6
	CONTROL_CHL_ARM_CLEAR,		// 针对通道消警-7
}dpsdk_AlarmhostOperator_e;

typedef enum
{	// 报警主机状态类型
	ALARMHOSE_STATUS_ERROR = 0,			// 状态类型错误
	ALARMHOSE_STATUS__DEV_ARM,			// 针对设备布防-1
	ALARMHOSE_STATUS__DEV_DISARM,		// 针对设备撤防-2
	ALARMHOSE_STATUS__CHL_BYPASS,		// 针对通道旁路-3
	ALARMHOSE_STATUS__CHL_DISBYPASS,	// 针对通道取消旁路-4
	ALARMHOSE_STATUS__DEV_IN_ARM,		// 针对设备在家布防-5 add by djm 20131219
	ALARMHOSE_STATUS__DEV_OUT_ARM,		// 针对设备外出布防-6 add by djm 20131219
}dpsdk_videoalarmhost_status_type_e;

typedef enum
{
	AHOST_OPERATE_DEVICE			= 1,		// 设备 布/撤防
	AHOST_OPERATE_CHANNEL			= 2,		// 通道 布/撤防
	AHOST_OPERATE_CHANNEL_ALARMOUT	= 3,		// 报警输出通道操作
}dpsdk_netalarmhost_operator_e;

typedef enum
{
	AHOST_CMD_TYPE,
	AHOST_CMD_ENABLE = 1,						// 报警主机布防
	AHOST_CMD_DISABLE,							// 报警主机撤防
	AHOST_CMD_BYPASS,							// 报警主机旁路
	AHOST_CMD_CANCELKBLIGHT,					// 取消键盘指示灯显示
	AHOST_CMD_ALARMMODE,						// 设置报警主机取消报警是自动的还是客户端手动取消
	AHOST_CMD_CANCELALARM,						// 取消报警上报
	AHOST_CMD_ALARMOUT_ON,						// 报警主机输出通道打开
	AHOST_CMD_ALARMOUT_OFF,						// 报警主机输出通道关闭
	AHOST_CMD_DOOR_OPEN,						// 门禁通道开启
	AHOST_CMD_DOOR_CLOSE,						// 门禁通道关闭
	AHOST_CMD_DOOR_AUTO,						// 门禁通道自动
	AHOST_CMD_DOOR_ALWAYS_OPEN,					// 门禁通道常开
	AHOST_CMD_DOOR_ALWAYS_CLOSE,				// 门禁通道常关
}dpsdk_netalarmhost_cmd_e;

typedef struct tagUserInfo
{
	int		iUserId;					// 用户id
	int		iUserLevel;					// 用户等级
	bool	iUserOperFlag;				// true操作员false企业客户
	char	szCoding[128];              // 用户所在组织
	char	szCodeName[256];            // 用户所在组织名称

}DPSDK_UserInfo_t;

// 报警输入通道信息
typedef struct tagAlarmInChannelInfo 
{
	char								szId[DPSDK_CORE_DEV_ID_LEN];				// 通道ID:设备ID+通道号
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
	uint64_t                            nRight;                                     // 权限信息
	int                                 nChnlType;                                  // 通道类型
	int                                 nStatus;
}AlarmIn_Channel_Info_t; 

// 获取报警输入通道请求信息
typedef struct tagGetAlarmInChannelInfo 
{
	IN char								szDeviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	IN uint32_t							nAlarmInChannelCount;						// 通道个数
	OUT AlarmIn_Channel_Info_t*			pAlarmInChannelnfo;							// 通道信息
}Get_AlarmInChannel_Info_t;

typedef struct tagdpsdkAHostDefenceStatus
{
	char szNodeID[DPSDK_CORE_DEV_ID_LEN];		// 防区节点ID
	int  nAlarm;								// 0表示未报警 1104表示报警 1105表示火警 1106表示防
	int  nUndefendAlarm;						// 0表示没有未布防报警 83表示未布防报警（由于24小时防区会出现布防报警和未布防报警并发的情况 所以需要区分一下）
	bool bByPass;								// true=旁路, false=未旁路
	bool bDefend;								// true=布防, false=撤防

}dpsdk_AHostDefenceStatus_t;

typedef enum
{  
	AHOST_TYPE_NONE			= 0,
	AHOST_TYPE_STAY			= 1,				// 留守布防
	AHOST_TYPE_BYPASS,							// 防区旁路
}dpsdk_netalarmhost_report_type_e;

typedef struct tagPhoneSubscribeAlarm
{
	int         iUserId;				//用户ID
	char        szPhoneId[256];			//手机ID,手机推送的标志
	int         iAppId;					//应用程序编号
	char        szPush_type[64];		//手机类型
	int         iIs_subscribe;			//是否订阅; 1-订阅, 0-取消订阅
	char        szLanguage[32];			//语言
	char        szTimefmt[32];			//时间格式化

	int         iDbOper;				//db操作类型. 1-插入, 2-更新, 3-查询

}dpsdk_phone_subscribe_alarm_t;

//卡口业务类型
typedef enum
{
	BAY_MONITOR_CAR = 1,		//车辆
	BAY_MONITOR_FACE = 2,		//人脸
}dpsdk_bay_monitor_e;

typedef enum
{
	AREATYPE_UNKOWN			= 0x00,		//未知
	AREATYPE_SPEEDLIMIT		= 0x01,		//限速区
	AREATYPE_DRIVERALLOW	= 0x02,		//行驶区
	AREATYPE_FORBIDDRIVE	= 0x04,		//禁行区
	AREATYPE_LOADGOODS		= 0x08,		//出发区
	AREATYPE_UNLOADGOODS	= 0x10,		//达到区
}dpsdk_area_type_e;

typedef struct tagAreaPoint
{
	double dwLongitude;				//经度
	double dwLatidude;				//纬度
}Area_Point_t;

typedef struct tagAreatimePeriod
{
	char szBeginTime[32];				// 起始时间
	char szEndTime[32];					// 结束时间
}Area_Time_Period_t;

typedef struct tagAreatimeWeekdays
{
	int days;
	Area_Time_Period_t* arryAlarmtimePeriod;
	int nAlarmtimePeriodCount;
}Area_Time_Weekdays_t;

// 电子围栏启用时间段
typedef struct tagAreaTime
{
	int enable;												// 时间端启用使用,1表示启用，0表示不启用
	Area_Time_Weekdays_t areatimeWeekdays[DPSDK_CORE_AREA_WEEK_DAYS];	// 星期中一天的时间段
}Area_Time_t;

//电子围栏信息
typedef struct tagAreaInfo
{
	dpsdk_area_type_e nAreaType;						//围栏类型
	char strAreaAttr[DPSDK_CORE_AREA_ATTR_MAXLEN];			//围栏属性
	char strAreaName[DPSDK_CORE_AREA_NAME_MAXLEN];			//围栏名称
	int nSpeedLimit;							//限速
	int nNumMax;								//最大车辆数
	Area_Point_t* arryAreaPoints;
	int nAreaPointsCount;

	Area_Time_t	stuAlarmTime;					
}Area_Info_t;

typedef struct tagPeccancyAlarmInfo
{
	int					areaId;								// 围栏ID   3.0废弃
	int					areatype;							// 围栏类型
	int					currrentSpeed;						// 当前速度
	int					maxSpeed;						    // 限速值
	char				driverId[DPSDK_CORE_DRIVER_ID_LEN];		// 司机工号
	char				deviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	int					alarmType;							// 报警类型
	int64_t				alarmTime;							// 报警发生时间,精度为秒，值为time(NULL)值
	char				message[DPSDK_CORE_ALARM_MSG_LEN];		// 备注信息
	int					diffSpeed;							// 当前速度与限速值的差
	int					diffAlarmTime;						// 当前报警时间-上次报警时间（秒）
	char				areaCode[DPSDK_CORE_AREA_CODE_LEN];		// 围栏码
	char				dbLongitude[DPSDK_CORE_AREA_DB_LEN];		// 经度
	char				dbLatitude[DPSDK_CORE_AREA_DB_LEN];		// 纬度
	int					alarmStat;							// 报警状态
	int					channelSeq;							// 通道序号
	char				deviceName[DPSDK_CORE_DEV_ID_LEN];		// 设备名称
	char				alarmID[DPSDK_CORE_ALARMCODE_LEN];		// 报警id，guid
}Peccancy_Alarm_t;

// 预案状态
typedef enum
{
	ALARM_SCHEME_STATUS_CLOSE			= 0,				// 关闭
	ALARM_SCHEME_STATUS_OPEN,								// 打开
}dpsdk_alarmScheme_status_e;

// 预案列表信息
typedef struct tagAlarmSchemeInfo
{
	dpsdk_alarmScheme_status_e	status;									// 预案状态
	uint32_t					id;										// 预案数据库id
	char						schemeName[DPSDK_CORE_SCHEME_NAME_LEN];	// 预案名称
	uint32_t					templateId;								// 预案时间模板ID
	char						desc[DPSDK_CORE_SCHEME_DESC_LEN];		// 预案描述

}AlarmSchemeInfo_t;

// 预案文件信息
typedef struct tagAlarmSchemeFileInfo
{
	dpsdk_alarmScheme_status_e	status;									// 预案状态
	uint32_t					id;										// 预案数据库id
	char						schemeName[DPSDK_CORE_SCHEME_NAME_LEN];	// 预案名称
	uint32_t					templateId;								// 预案时间模板ID
	char						desc[DPSDK_CORE_SCHEME_DESC_LEN];		// 预案描述
	char*						data;									// 预案数据
	uint32_t					len;									// 预案数据长度

}AlarmSchemeFileInfo_t;

// 日期模板信息
typedef struct tagTimeTemplateInfo
{
	uint32_t 	id;												// 序号
	char		name[DPSDK_CORE_TEMPLATE_NAME_LEN];				// 模板名称
	char		remark[DPSDK_CORE_TEMPLATE_REMARK_LEN];			// 时间模板的说明
	char		flag[DPSDK_CORE_TEMPLATE_FLAG_LEN];				// 具体包含全天的、还是周一到周日

}TimeTemplateInfo_t;

// cms消息通知类型
typedef enum
{
	ALARM_MSGTYPE_UnKnown				= 0,				// 未知
	ALARM_MSGTYPE_TIMETEMPLATE_ADD,							// 时间模板添加
	ALARM_MSGTYPE_TIMETEMPLATE_UPDATE,						// 时间模板更新
	ALARM_MSGTYPE_TIMETEMPLATE_DELETE,						// 时间模板删除
	ALARM_MSGTYPE_ALARMSCHEME_ADD,							// 报警预案添加
	ALARM_MSGTYPE_ALARMSCHEME_UPDATE,						// 报警预案更新
	ALARM_MSGTYPE_ALARMSCHEME_DELETE,						// 报警预案删除
}dpsdk_alarm_msgType_e;

typedef struct tagAlarmSchemeChgInfo
{
	dpsdk_alarm_msgType_e	type;							// 消息类型,预案通知、时间模板通知使用
	uint64_t				id;								// 数据库id,预案通知使用
	uint64_t				nParam1;						// 修改预案通知时表示时间模板id
	uint64_t				nParam2;						// 修改预案通知时表示预案开关
	char					szMsg[2048];					// 修改预案通知时表示修改者ip;时间模板存在批量删除情况，故使用str类型标识id
}AlarmSchemeChg_t;

typedef struct tagDataChangeInfo
{
	int64_t			nParam1;
	int64_t			nParam2;
	char			szMsg1[1024*3];
	char			szMsg2[1024*3];
}DataChange_t;

typedef struct tagDPSDKParam
{
	char	szUserIdFlag[64];		//用户id标识符
}DPSDKParam_t;

typedef struct tagPerson_Count_Info
{
	int			nChannelID;									// 统计通道号
	char		szRuleName[DPSDK_CORE_IVS_EVENT_NAME_LEN];	// 规则名称
	uint32_t	nStartTime;									// 开始时间
	uint32_t	nEndTime;									// 结束时间
	uint32_t	nEnteredSubTotal;							// 进入人数小计
	uint32_t	nExitedSubtotal;							// 出去人数小计
	uint32_t	nAvgInside;									// 平均保有人数(除去零值)
	uint32_t	nMaxInside;									// 最大保有人数
}Person_Count_Info_t;

typedef struct tagSingleChnlIdInfo
{
	char	szChnlId[DPSDK_CORE_CHL_ID_LEN];
}Single_ChnlId_Info_t;

// 工地号关联通道ID信息
typedef struct tagChnlIdBySiteCodeInfo
{
	int						nSiteCode;				// 工地号
	int						nChnlIdCount;			// 通道ID数量
	Single_ChnlId_Info_t*	pSingleChnlIdInfo;		// 通道ID列表
	tagChnlIdBySiteCodeInfo()
	{
		nSiteCode = 0;
		nChnlIdCount = 0;
		pSingleChnlIdInfo = NULL;
	}
	~tagChnlIdBySiteCodeInfo()
	{
		nSiteCode = 0;
		nChnlIdCount = 0;
		if(pSingleChnlIdInfo != NULL)
		{
			delete [] pSingleChnlIdInfo;
			pSingleChnlIdInfo = NULL;
		}
	}
}ChnlIdBySiteCode_Info_t;
//Prison模块结构体定义 begin

// 刻录实时状态信息
typedef struct tagDevBurnerCDStateInfo
{
	//char								szName[DPSDK_CORE_TVWALL_NAME_LEN];
	uint32_t				m_burnerId;											// 刻录机ID, ID从0开始
	uint32_t				m_burnerState;										// 刻录机状态 0：可以刻录 1：刻录机类型不对，是一个非光盘设备 
																				// 2：未找到刻录机 3：有其它光盘在刻录 4：刻录机处于非空闲状态，即在备份、刻录或回放中
	uint32_t				m_romType;											// 盘片类型 0：大华文件系统 1：移动硬盘或U盘 2：光盘
	uint32_t				m_operateType;										// 操作类型 0：空闲 1：正在备份中 2：正在刻录中 3：正在进行光盘回放
	uint32_t				m_processState;										// 进度状态 0：停止或结束 1：开始 2：出错 3：满 4：正在初始化
	uint32_t				m_startTime;										// 开始时间
	uint32_t				m_elapseTime;										// 已刻录时间
	uint32_t				m_totalSpace;										// 光盘总容量
	uint32_t				m_remainSpace;										// 光盘剩余容量
	uint32_t				m_burned;											// 已刻录容量
	uint32_t				m_channelMask;										// 刻录的通道掩码
	uint32_t				m_emMode;											// 刻录模式0-BURN_MODE_SYNC,1-BURN_MODE_TURN,2-BURN_MODE_CYCLE
	uint32_t				m_emPack;											// 刻录流格式0-DHAV,1-BURN_PACK_PS...

}Dev_Burner_CDState_Info_t;

// 获取刻录实时状态信息请求
typedef struct tagDevBurnerCDStateRequest
{
	char				deviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	uint32_t			burnerId;									//光盘刻录机ID (id从0开始计数)

}Dev_Burner_CDState_Request_t;

// 获取刻录实时状态信息回复
typedef struct tagDevBurnerCDStateReponse
{
	Dev_Burner_CDState_Info_t  stuDevBurnerStateInfo;

}Dev_Burner_CDState_Reponse_t;

//刻录控制命令
typedef enum
{
	Cmd_StartBurn = 1,															// 开始刻录
	Cmd_PauseBurn,																// 暂停刻录
	Cmd_ContinueBurn,															// 继续刻录
	Cmd_StopBurn,																// 停止刻录
	Cmd_ChangeCD,																// 手动换盘
}Core_EnumControlBurnerCmd;

// 获取刻录实时状态信息请求
typedef struct tagControlDevBurnerRequest
{
	char						deviceId[DPSDK_CORE_DEV_ID_LEN];			// 设备ID
	Core_EnumControlBurnerCmd   cmd;										//控制命令
	int							channelMask;								//通道掩码    第1个通道为1；第2个通道是：1<<1;第3个是1<<2
	int							burnerMask;									//刻录机掩码  1表示光驱1；2光驱2；3双光驱
	//庭审相关
	int							emMode;										//刻录模式    0-BURN_MODE_SYNC,1-BURN_MODE_TURN,2-BURN_MODE_CYCLE
	int							emPack;										//刻录流格式  0-DHAV,1-BURN_PACK_PS...

}Control_Dev_Burner_Request_t;

//刻录片头
typedef struct tagDevBurnerInfoHeader
{
	char					m_deviceId[DPSDK_CORE_CHAR_LEN_32];					// 设备ID
	char					m_password[DPSDK_CORE_CHAR_LEN_64];					//  叠加密码
	char					m_caseId[DPSDK_CORE_CHAR_LEN_64];					// 1.案件编号
	char					m_trialSeq[DPSDK_CORE_CHAR_LEN_256];				// 2.案件序号/审讯序号
	char					m_caseUnderTaker[DPSDK_CORE_CHAR_LEN_256];			// 3.办案人员
	char					m_caseDep[DPSDK_CORE_CHAR_LEN_256];					// 4.办案单位	
	char					m_caseReason[DPSDK_CORE_CHAR_LEN_256];				// 5.涉嫌名称
	char					m_caseReferPerson[DPSDK_CORE_CHAR_LEN_256];			// 6.涉案人员
	char					m_caseRemark[DPSDK_CORE_CHAR_LEN_256];				// 7.案卷备注
	char					m_caseRecordName[DPSDK_CORE_CHAR_LEN_256];			// 8.录像名称
	char					m_RecordNum[DPSDK_CORE_CHAR_LEN_64];				// 9.光盘编号
	char					m_recordPerson[DPSDK_CORE_CHAR_LEN_256];			// 10.刻录人
	bool					m_dataCheckOsdEn;									// 11.光盘刻录数据校验配置/叠加使能
	bool					m_AttachFileEn;										// 12.附加文件使能
	bool					m_multiBurnerDataCheck;								// 13.多光盘一致性校验使能
	uint32_t				m_multiBurnerDataCheckSpeed;						// 14.校验速度校验速度 0 高速（头尾数据校验）,1 正常（随机数据校验）,2 低速 （全盘数据校验）,默认0
}DevBurnerInfoHeader_t;

//审讯表单属性名
typedef struct tagTrialFormAttrName
{
	char					m_caseIdAttr[DPSDK_CORE_CHAR_LEN_32];				// 案件编号
	char					m_trialSeqAttr[DPSDK_CORE_CHAR_LEN_32];			// 案件序号/审讯序号
	char					m_caseUnderTakerAttr[DPSDK_CORE_CHAR_LEN_32];		// 办案人员
	char					m_caseDepAttr[DPSDK_CORE_CHAR_LEN_32];				// 办案单位
	char					m_caseReasonAttr[DPSDK_CORE_CHAR_LEN_32];			// 涉嫌名称
	char					m_caseReferPersonAttr[DPSDK_CORE_CHAR_LEN_32];		// 涉案人员
	char					m_caseRemarkAttr[DPSDK_CORE_CHAR_LEN_32];			// 案卷备注
	char					m_caseRecordNameAttr[DPSDK_CORE_CHAR_LEN_32];		// 录像名称
	char					m_trialObjNameAttr[DPSDK_CORE_CHAR_LEN_32];			// 被审讯人姓名
	char					m_trialObjSexAttr[DPSDK_CORE_CHAR_LEN_32];			// 被审讯人性别
	char					m_trialObjIDAttr[DPSDK_CORE_CHAR_LEN_32];			// 被审讯人身份证号码
	char					m_trialObjNationAttr[DPSDK_CORE_CHAR_LEN_32];		// 民族
	char					m_trialObjBirthdayAttr[DPSDK_CORE_CHAR_LEN_32];		// 出生年月
	char					m_trialObjHomeAddrAttr[DPSDK_CORE_CHAR_LEN_32];		// 住址
	char					m_trialObjWorkUnitsAttr[DPSDK_CORE_CHAR_LEN_32];	// 工作单位
	char					m_trialObjTelephoneAttr[DPSDK_CORE_CHAR_LEN_32];	// 联系电话
	char					m_CDIDAttr[DPSDK_CORE_CHAR_LEN_32];					// 光盘编号
	char					m_recordPersonAttr[DPSDK_CORE_CHAR_LEN_32];			// 刻录人
	char					m_caseAssistantAttr[DPSDK_CORE_CHAR_LEN_32];		// 协助办案人员--卷宗信息新增，非必填项
	char					m_trialObjAgeAttr[DPSDK_CORE_CHAR_LEN_32];			// 年龄--被询问人信息-新增，非必填项
}TrialFormAttrName_t;

//单个磁盘信息
typedef struct tagSingleDiskInfo
{
	int						nDiskId;											//硬盘ID（从0开始）
	uint32_t				uVolume;											//硬盘容量
	uint32_t				uFreeSpace;											//剩余容量
	unsigned char			diskState;											//高四位的值表示硬盘类型，具体为：0 读写驱动器 1 只读驱动器 2 备份驱动器或媒体驱动器 3 冗余驱动器 4 快照驱动器；低四位的值表示硬盘的状态，0-休眠,1-活动,2-故障
	unsigned char			diskNum;											//硬盘号
	unsigned char			subareaNum;											//分区号
	unsigned char			signal;												//标识， 0本地 1 远程
}Single_Disk_Info_t;

//设备磁盘信息
typedef struct tagDiskInfo
{
	char					szDevId[DPSDK_CORE_DEV_ID_LEN];						//设备ID
	int						nDiskInfoSize;										//磁盘信息数量
	Single_Disk_Info_t*		pDiskInfoList;										//磁盘信息列表

	tagDiskInfo()
	{
		nDiskInfoSize = 0;
		pDiskInfoList = NULL;
	}

	~tagDiskInfo()
	{
		nDiskInfoSize = 0;
		if(pDiskInfoList)
		{
			delete [] pDiskInfoList;
			pDiskInfoList = NULL;
		}
	}
}Device_Disk_Info_t;

//Prison模块结构体定义 end


//Pec模块结构体定义 begin

//门禁编程命令类型,与协议定义相同
typedef enum
{
	CORE_DOOR_CMD_PROGARM,
	CORE_DOOR_CMD_OPEN			= 5,				// 开门
	CORE_DOOR_CMD_CLOSE			= 6,				// 关门
	CORE_DOOR_CMD_ALWAYS_OPEN,						// 门常开
	CORE_DOOR_CMD_ALWAYS_CLOSE,						// 门常关
	CORE_DOOR_CMD_HOLIDAY_MAG_OPEN,					// 假日管理门常开
	CORE_DOOR_CMD_HOLIDAY_MAG_CLOSE,				// 假日管理门常关
	CORE_DOOR_CMD_RESET,							// 复位
	CORE_DOOR_CMD_HOST_ALWAYS_OPEN,					// 报警主机下的门禁通道，常开
	CORE_DOOR_CMD_HOST_ALWAYS_CLOSE,				// 报警主机下的门禁通道，常关
}Core_EnumSetDoorCmd;

// 门控制请求
typedef struct tagSetDoorCmdRequest
{
	char						szCameraId[DPSDK_CORE_DEV_ID_LEN];			// 通道ID
	Core_EnumSetDoorCmd		    cmd;										//控制命令
	int64_t						start;										//通开始时间
	int64_t						end;										//结束时间

}SetDoorCmd_Request_t;

// 通道信息
typedef struct tagChannelBaseInfo 
{
	char								szName[DPSDK_CORE_DGROUP_DEVICENAME_LEN];	// 名称
}ChannelBase_Info_t;

// 视频关联回复
typedef struct tagGetLinkResourceResponce
{
	char*		pXmlData;
	uint32_t	nLen;

}GetLinkResource_Responce_t;

typedef enum
{
	Door_Close,
	Door_Open,
	Door_DisConn,
}dpsdk_door_status_e;

//Pec模块结构体定义 end

//集群对讲结构体定义

//StartCall返回的对讲参数
typedef struct tagStartCallResponse
{
	int					returnValue;							// 平台返回的错误码，0代表成功，其它失败
	int					seq;									// 用于关闭呼叫的seq
	uint32_t			sessionId;								// 语音对讲会话Id
	char				szGroupId[DPSDK_CORE_CHL_ID_LEN];		// 设备ID或通道ID
	char				strSendChnlID[DPSDK_CORE_CHL_ID_LEN];	// 发送通道ID
	char				strRecvChnlID[DPSDK_CORE_CHL_ID_LEN];	// 接收通道ID
	char				rtpServIP[DPSDK_CORE_IP_LEN];			// 远端RTP IP
	int					rtpPort;								// 远端RTP端口
	int					talkMode;								// 对讲模式 0对讲 1广播（喊话）
	int					audioType;								// 1 PCM，2 G.711，3 G.723，4 G.726，5 G.729
	int					audioBit;								// 用实际的值表示，如8位 则填值为8
	uint32_t			sampleRate;								// 采样率，如16k 则填值为16000	
	int					transMode;								// 1 tcp,2 udp;

	//SCS返回，报错时候使用
	int					cmsaudioType;							// 1 PCM，2 G.711，3 G.723，4 G.726，5 G.729
	int					cmsaudioBit;							// 用实际的值表示，如8位 则填值为8
	uint32_t			cmssampleRate;							// 采样率，如16k 则填值为16000
	int					callId;
	int					dlgId;
}StartCallParam_t;

//InviteCall返回的对讲参数
typedef struct tagInviteCallResponse
{
	int					audioType;							// 1 PCM，2 G.711，3 G.723，4 G.726，5 G.729
	int					audioBit;							// 用实际的值表示，如8位 则填值为8
	uint32_t			sampleRate;							// 采样率，如16k 则填值为16000	
	char				rtpServIP[DPSDK_CORE_IP_LEN];
	int					rtpPort;
	dpsdk_call_type_e	nCallType;							//呼叫类型，单呼还是组呼
	char				groupID[DPSDK_CORE_CHL_ID_LEN];		//呼叫者ID，组呼时为组ID，单呼时为ID#IP
	char				callerID[DPSDK_CORE_CHL_ID_LEN];	//讲话者ID
	char				sendChnlID[DPSDK_CORE_CHL_ID_LEN];	//发送通道，单呼时才会用到
	char				recvChnlID[DPSDK_CORE_CHL_ID_LEN];	//接收通道，穿网包需要带上
	int					callId;
	int					dlgId;
	int                 tid;
}InviteCallParam_t;

//音频采集参数
typedef struct tagAudioRecrodParam
{
	dpsdk_audio_type_e		audioType;								// 1 PCM，2 G.711，3 G.723，4 G.726，5 G.729
	dpsdk_talk_bits_e		audioBit;								// 用实际的值表示，如8位 则填值为8
	Talk_Sample_Rate_e		sampleRate;								// 采样率，如16k 则填值为16000
}AudioRecrodParam_t;

//集群对讲结构体定义 end

//可视对讲结构体定义 begin

//邀请对讲参数
typedef struct tagInviteVtCallParam
{
	int					audioType;						// 1 PCM，G.711，G.723，G.726，G.729
	int					audioBit;						// 用实际的值表示，如位则填值为
	uint32_t			sampleRate;						// 采样率，如k 则填值为
	char				rtpServIP[DPSDK_CORE_IP_LEN];	// 远端RTP IP
	int					rtpAPort;						// 音频端口
	int					rtpVPort;						// 视频端口
	dpsdk_call_type_e	nCallType;						// 呼叫类型，单呼还是组呼
	char				szUserId[DPSDK_CORE_CHL_ID_LEN];						// 呼叫者ID
	int					callId;
	int					dlgId;
	int                 tid;
	char				szCameraId[DPSDK_CORE_CHL_ID_LEN];// 视频通道ID
}InviteVtCallParam_t;

//响铃通知参数
typedef struct tagRingInfo
{
	char		szUserId[DPSDK_CORE_CHL_ID_LEN];				// 设备ID或通道ID
	int			callId;
	int			dlgId;
	int			tid;
}RingInfo_t;

//可视对讲状态繁忙通知参数
typedef struct tagBusyVtCall
{
	char		szUserId[DPSDK_CORE_CHL_ID_LEN];				// 设备ID或通道ID
	int			callId;
	int			dlgId;
}BusyVtCallInfo_t;

//可视对讲应答参数
typedef struct tagStartVtCallResponse
{
	int					videoPort;						// 本地视频端口
	int					audioPort;						// 本地音频端口
	char				rtpServIP[DPSDK_CORE_IP_LEN];	// 远端RTP IP
	int					rtpAPort;						// 远端RTP音频端口
	int					rtpVPort;						// 远端RTP视频端口
	int					talkMode;						// 对讲模式0对讲1广播（喊话）
	int					audioType;						// 1 PCM，G.711，G.723，G.726，G.729
	int					audioBit;						// 用实际的值表示，如位则填值为
	uint32_t			sampleRate;						// 采样率，如k 则填值为	
	int					callId;
	int					dlgId;
	char				szCameraId[DPSDK_CORE_CHL_ID_LEN];// 视频通道ID
}StartVtCallParam_t;


//集群对讲结构体定义 end

typedef enum
{
	DPSDK_LOG_INFO,  //信息
	DPSDK_LOG_DEBUG,	//调试
	DPSDK_LOG_ERROR,	//错误	
}dpsdk_log_type_e;

// 媒体流按业务分类 
typedef enum
{
	DPSDK_MEDIA_INVALID,
	DPSDK_MEDIA_REAL =1, //实时
	DPSDK_MEDIA_PLAYBACK =2,//回放
	DPSDK_MEDIA_TALK,
	DPSDK_MEDIA_BAY,
	DPSDK_MEDIA_CALL,
	DPSDK_MEDIA_BROADCAST,
	DPSDK_MEDIA_DOWNLOAD,
}dpsdk_media_func_e;

// OSD Text 对齐方式
typedef enum
{
	OSD_TEXT_ALIGN_INVALID		= 0,				// 无效的对齐方式
	OSD_TEXT_ALIGN_LEFT			= 1,				// 左对齐
	OSD_TEXT_ALIGN_XCENTER		= 2,				// X坐标中对齐
	OSD_TEXT_ALIGN_YCENTER		= 3,				// Y坐标中对齐
	OSD_TEXT_ALIGN_CENTER		= 4,				// 居中
	OSD_TEXT_ALIGN_RIGHT		= 5,				// 右对齐
	OSD_TEXT_ALIGN_TOP			= 6,				// 按照顶部对齐
	OSD_TEXT_ALIGN_BOTTOM		= 7,				// 按照底部对齐
	OSD_TEXT_ALIGN_LEFTTOP		= 8,				// 按照左上角对齐
	OSD_TEXT_ALIGN_CHANGELINE	= 9					// 换行对齐
}OSDTextAlign_e;

typedef struct OSDInfo
{
	char				szChannelId[DPSDK_CORE_DEV_ID_LEN];				//通道ID
	char				strOSDText[DPSDK_CORE_OSDTEMPLAT_CONTENT_LEN];	//osd信息，换行用'|'隔开
	int					nForeground;									// 前景色,默认0
	int					nBackground;									// 背景色，默认0
	int					nLeft;											// 显示位置，默认5402
	int					nTop;											// 默认797
	int					nRight;											// 默认5402
	int					nBottom;										// 默认797
	OSDTextAlign_e		enumAlign;										// OSD Text 对齐方式默认OSD_TEXT_ALIGN_LEFT，左对齐
	int					nRemainTime;									// osd叠加，叠加持续时间 0：为一直叠加
}OSD_Info_t;

typedef struct tagDPSDKDemuxInfo {
	int					type;			// 1:VIDEO, 2:AUDIO, 3:DATA
	int					subtype;		// I Frame, BP Frame, PCM8, MS-ADPCM etc.
	int					encode;			// MPEG4, H264, STDH264
	int					sequence;		// I帧间隔里面的序号

	// 图像大小信息
	int					width;
	int					height;

	// 帧率信息
	int					rate;

	// time information
	int					year;
	int					month;
	int					day;
	int					hour;
	int					minute;
	int					secode;
	unsigned long		timestamp;

	int					channels;
	int					bitspersample;
	int					samplespersecond;
}DPSDK_DEMUX_INFO;

//轮巡任务结构定义begain

#define TASK_MIN_STAY_TIME			15					//轮训默认最短停留时间（s）
#define TASK_MIN_LIMIT_TIME			10					//为兼容以前版本，增加轮巡最短限制时间 10s
#define TASK_MAX_WINDOW_COUNT_36	36
#define TASK_MAX_WINDOW_COUNT_64	64
#define XMLTASK_NAME_LEN			64
#define XMLPROJ_NAME_LEN			64
#define MAX_PROJ_TIME_PERIOD_NUM	10					//轮训计划默认最短时间
#define XMLTASK_DESCRP_LEN			256
#define MAX_POINT_NUM				255
#define MAX_SPLIT_SIZE				8
#define MAX_SPLIT_WND_COUNT			(MAX_SPLIT_SIZE * MAX_SPLIT_SIZE)
#define XMLTASK_FILE_NAME			"task.xml"
#define TASK_ID_INVALID				0					//轮巡任务的id是从1开始的，判断非法的任务id，应该是<=0
#define XMLTASK_WNDSCHEME_NAME		"wndscheme.xml"
#define MAX_TASKINFO_BUF_SIZE		1024*1024

typedef struct tagCustomWnd{

	tagCustomWnd(void){}
	tagCustomWnd(bool bEnable, int nCombine, int x1, int y1, int x2, int y2)
		: bEnable(bEnable)
		, nCombine(nCombine)
		, x1(x1)
		, y1(y1)
		, x2(x2)
		, y2(y2)
	{

	}

	bool operator!=(const tagCustomWnd& src)
	{
		if(bEnable != src.bEnable)return true;
		if(nCombine != src.nCombine)return true;
		if(x1 != src.x1)return true;
		if(y1 != src.y1)return true;
		if(x2 != src.x2)return true;
		if(y2 != src.y2)return true;

		return false;
	}

	tagCustomWnd& operator=(const tagCustomWnd& other)
	{
		bEnable = other.bEnable;
		nCombine = other.nCombine;
		x1 = other.x1;
		y1 = other.y1;
		x2 = other.x2;
		y2 = other.y2;

		return *this;
	}

	bool bEnable;
	int nCombine;
	int x1;
	int y1;
	int x2;
	int y2;
}SmartWnd_CustomWnd_t;

typedef struct tagSplitInfo{

	bool operator==(const tagSplitInfo& src)
	{
		if(nRow != src.nRow)return false;
		if(nCol != src.nCol)return false;
		if(nSplitCount != src.nSplitCount)return false;

		int nCount = nRow * nCol;
		for (int i = 0; i < nCount; ++i)
		{
			if (stuWnds[i] != src.stuWnds[i])
			{
				return false;
			}
		}

		return true;
	}

	tagSplitInfo& operator=(const tagSplitInfo& other)
	{
		nRow = other.nRow;
		nCol = other.nCol;
		nSplitCount = other.nSplitCount;
		for (int i = 0; i < MAX_SPLIT_WND_COUNT; i++)
		{
			stuWnds[i] = other.stuWnds[i];
		}

		return *this;
	}

	int nRow;
	int nCol;
	int nSplitCount;
	SmartWnd_CustomWnd_t stuWnds[MAX_SPLIT_WND_COUNT];
	tagSplitInfo()
	{
		nRow = 0;
		nCol = 0;
		nSplitCount = 0;
	}
	//////////////////////////////////////////////////////////////////////////
private:
	int GetCustomWnds(int* outnRow, int* outnCol, std::vector<SmartWnd_CustomWnd_t>* outCustomWnds)
	{
		if (outnRow == NULL || outnCol == NULL || outCustomWnds == NULL)
		{
			return -1;
		}

		outCustomWnds->clear();

		*outnRow = this->nRow;
		*outnCol = this->nCol;

		int nCount = (*outnRow) * (*outnCol);
		for (int i=0; i<nCount; i++)
		{
			outCustomWnds->push_back(this->stuWnds[i]);
		}

		return 0;
	}
	int SaveCustomWnds(const int& newnRow, const int& newnCol, const std::vector<SmartWnd_CustomWnd_t>& vecCustomWnds)
	{
		if ((int)vecCustomWnds.size() < newnRow * newnCol)
			return -1;

		memset(this, 0, sizeof(tagSplitInfo));
		this->nRow = newnRow;
		this->nCol = newnCol;
		this->nSplitCount = 0;
		int nCount = newnRow * newnCol;
		for (int i=0; i<nCount; i++)
		{
			this->stuWnds[i] = vecCustomWnds[i];
			if (this->stuWnds[i].bEnable)
			{
				this->nSplitCount++;
			}
		}

		return 0;
	}
public:
	void AddRow(void)
	{
		std::vector<SmartWnd_CustomWnd_t> vecCustomWnds;
		int tmpnRow;
		int tmpnCol;
		GetCustomWnds(&tmpnRow, &tmpnCol, &vecCustomWnds);

		if (tmpnRow == MAX_SPLIT_SIZE)
			return;

		int nCount = tmpnRow * tmpnCol;
		for (int i=0; i<tmpnCol; i++)
		{
			vecCustomWnds.push_back(SmartWnd_CustomWnd_t(true,nCount,i,tmpnRow,i+1,tmpnRow+1));
			nCount++;
		}
		tmpnRow++;


		SaveCustomWnds(tmpnRow, tmpnCol, vecCustomWnds);
	}

	void SubRow(void)
	{
		std::vector<SmartWnd_CustomWnd_t> vecCustomWnds;
		int tmpnRow;
		int tmpnCol;
		GetCustomWnds(&tmpnRow, &tmpnCol, &vecCustomWnds);

		if (tmpnRow == 1)
			return;

		std::vector<SmartWnd_CustomWnd_t>::iterator itWnd = vecCustomWnds.begin() + (tmpnRow - 1) * tmpnCol;
		while (itWnd != vecCustomWnds.end())
		{
			itWnd = vecCustomWnds.erase(itWnd);
		}

		tmpnRow--;
		for (int i=0; i<(int)vecCustomWnds.size(); i++)
		{
			SmartWnd_CustomWnd_t& wnd = vecCustomWnds[i];
			if (wnd.y2 > tmpnRow)
			{
				wnd.y2 = tmpnRow;
			}
		}

		SaveCustomWnds(tmpnRow, tmpnCol, vecCustomWnds);
	}
	void AddCol(void)
	{
		std::vector<SmartWnd_CustomWnd_t> vecCustomWnds;
		int tmpnRow;
		int tmpnCol;
		GetCustomWnds(&tmpnRow, &tmpnCol, &vecCustomWnds);

		if (tmpnCol == MAX_SPLIT_SIZE)
			return;

		for (int i=0; i<tmpnRow; i++)
		{
			vecCustomWnds.push_back(SmartWnd_CustomWnd_t());
		}

		// 移动窗口信息
		tmpnCol++;
		for (int i=(int)vecCustomWnds.size()-1; i>=tmpnCol-1; i--)
		{
			int y = i / tmpnCol;
			if ((i+1) % tmpnCol == 0)
			{
				vecCustomWnds[i] = SmartWnd_CustomWnd_t(true,i,tmpnCol-1,y,tmpnCol,y+1);
			}
			else
			{
				vecCustomWnds[i] = vecCustomWnds[i-y];
				vecCustomWnds[i].nCombine = i;
			}
		}

		// 重置nCombine
		for (int i=0; i<(int)vecCustomWnds.size(); i++)
		{
			for (int j=i+1; j<(int)vecCustomWnds.size(); j++)
			{
				SmartWnd_CustomWnd_t& src = vecCustomWnds[i];
				SmartWnd_CustomWnd_t& dst = vecCustomWnds[j];
				if (src.x1==dst.x1 && src.y1==dst.y1 && src.x2==dst.x2 && src.y2==dst.y2)
				{
					vecCustomWnds[j].nCombine = vecCustomWnds[i].nCombine;
				}
			}
		}

		SaveCustomWnds(tmpnRow, tmpnCol, vecCustomWnds);
	}

	void SubCol(void)
	{
		std::vector<SmartWnd_CustomWnd_t> vecCustomWnds;
		int tmpnRow;
		int tmpnCol;
		GetCustomWnds(&tmpnRow, &tmpnCol, &vecCustomWnds);

		if (tmpnCol == 1)
			return;

		// 移动窗口信息
		std::vector<SmartWnd_CustomWnd_t>::iterator itWnd = vecCustomWnds.begin() + tmpnCol-1;
		for (int i=tmpnCol-1; itWnd!=vecCustomWnds.end(); i++)
		{
			if (i >= (tmpnRow * (tmpnCol-1)))
			{
				itWnd = vecCustomWnds.erase(itWnd);
				continue;
			}

			int y = i / (tmpnCol - 1);
			vecCustomWnds[i] = vecCustomWnds[i+y];
			vecCustomWnds[i].nCombine = i;
			itWnd++;	
		}

		tmpnCol--;
		for (int i=0; i<(int)vecCustomWnds.size(); i++)
		{
			SmartWnd_CustomWnd_t& wnd = vecCustomWnds[i];
			if (wnd.x2 > tmpnCol)
			{
				wnd.x2 = tmpnCol;
			}
		}

		// 重置nCombine
		for (int i=0; i<(int)vecCustomWnds.size(); i++)
		{
			for (int j=i+1; j<(int)vecCustomWnds.size(); j++)
			{
				SmartWnd_CustomWnd_t& src = vecCustomWnds[i];
				SmartWnd_CustomWnd_t& dst = vecCustomWnds[j];
				if (src.x1==dst.x1 && src.y1==dst.y1 && src.x2==dst.x2 && src.y2==dst.y2)
				{
					vecCustomWnds[j].nCombine = vecCustomWnds[i].nCombine;
				}
			}
		}

		SaveCustomWnds(tmpnRow, tmpnCol, vecCustomWnds);
	}
	//////////////////////////////////////////////////////////////////////////
}SmartWnd_SplitInfo_t;

// typedef struct _WindowSpanTime 
// {
// 	int								iWwindowNum;		//窗口轮训中 单次轮训的窗口数
// 	int								iTimeSpan;			//窗口轮训中 该次轮训停留的时间
// }WindowSpanTime;

// typedef std::vector<WindowSpanTime> WndSpanTimeVec;
// typedef std::map<std::string, bool> IfExecWndSchemeMap;
// 
// //<任务名称, 该任务下的窗口轮训计划>
// typedef std::map<std::string, WndSpanTimeVec> WndSchemeInfoMap;

typedef struct TaskChnlInfo
{
	std::string						strCameraName;  //通道名称
	std::string						strCameraId;	//通道ID
	int								iStreamType;	//码流类型 1主码流 2辅码流
	int								iTimeSpan;		//停留时间（单位为秒，至少10秒）
	int								iPresetPos;		//预置点（默认为0，可不填）
	int								iRotateDegree;	//旋转角度（默认为0，可不填）

	TaskChnlInfo()
	{
		strCameraName = "";
		strCameraId = "";
		iStreamType = 0;
		iTimeSpan = TASK_MIN_STAY_TIME;
		iPresetPos = 0;
		iRotateDegree = 0;
	}
}TaskChnlInfo_t;

typedef struct WindowTaskInfo
{
	std::list<TaskChnlInfo_t>		chnllist;
	int								iIndex;
	WindowTaskInfo()
	{
		chnllist.clear();
		iIndex = -1;
	}
	void RecycleInfo()
	{
		chnllist.clear();
		iIndex = -1;
	}
}WindowTaskInfo_t;

typedef struct TaskInfo
{
	int								iTaskId;
	std::string						strTaskName;
	std::string						strTaskDesc;
	SmartWnd_SplitInfo_t			struSplitInfo;		//自定义窗口分割信息
	std::vector<WindowTaskInfo_t>	windowList;			//任务包含的所有窗口列表
	TaskInfo()
	{
		iTaskId = -1;
		strTaskName = "";
		strTaskDesc = "";
		windowList.clear();
	}
}TaskInfo_t;

// 单个轮巡任务信息
typedef struct tagSingleSwitchTaskInfo
{
	int								nTaskId;						// 轮巡任务ID
	char							szTaskName[XMLTASK_NAME_LEN];	// 轮巡任务名称
}Single_Switch_Task_Info_t;

// 轮巡任务列表信息
typedef struct tagSwitchTaskInfo
{
	int32_t							nCount;							// 轮巡任务数
	Single_Switch_Task_Info_t*		pSingleTaskInfo;				// 轮巡任务信息
}Switch_Task_Info_t;

// 轮巡任务通道信息
typedef struct TaskChnlInfoEx
{
	char szCameraName[DPSDK_CORE_DGROUP_CHNNAME_LEN];				// 通道名称
	char szCameraId[DPSDK_CORE_CHL_ID_LEN];							// 通道ID
	int	 iStreamType;												// 码流类型 1主码流 2辅码流
	int	 iTimeSpan;													// 停留时间（单位为秒，至少10秒）
	int	 iPresetPos;												// 预置点（默认为0，可不填）
	int	 iRotateDegree;												// 旋转角度（默认为0，可不填）
}TaskChnlInfoEx_t;

// 轮巡任务窗口信息
typedef struct WindowTaskInfoEx
{
	int								nInfoCount;						// 轮巡任务通道信息数量
	TaskChnlInfoEx_t*				pTaskChnlInfoEx;				// 轮巡任务通道信息
}WindowTaskInfoEx_t;

// 轮巡任务信息
typedef struct TaskInfoEx
{
	int								iTaskId;						// 轮巡任务ID
	char 							szTaskName[XMLTASK_NAME_LEN];	// 轮巡任务名称
	char							szTaskDesc[XMLTASK_DESCRP_LEN];	// 轮巡任务描述
	int								nWindowTaskInfoCount;			// 轮巡任务窗口信息数量
	WindowTaskInfoEx_t*				pWindowTaskInfoEx;				// 轮巡任务窗口信息
}TaskInfoEx_t;

//轮巡任务结构定义end

/***************************************************************************************
 @ 类型定义结束
***************************************************************************************/



/***************************************************************************************
 @ 回调函数定义
***************************************************************************************/

/** DPSDK 状态回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nStatus					1 服务上线 2服务断线
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKStatusCallback)( IN int32_t nPDLLHandle, 
														IN int32_t nStatus, 
														IN void*   pUserParam );

/** OSD信息模板回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									pXML              回调信息
 @param   IN									nLen					XML字符长度
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t(DPSDK_CALLTYPE *fDPSDKOSDTemplatCallback)( IN int32_t nPDLLHandle,
														  IN char* pXML,
														  IN int32_t nLen,
														  IN void* pUserParam  );

/** OSD信息模板回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									pXML              回调信息
 @param   IN									nLen					XML字符长度
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t(DPSDK_CALLTYPE *fDPSDKHistoryOSDCallback)( IN int32_t nPDLLHandle,
														  IN char* pXML,
														  IN int32_t nLen,
														  IN void* pUserParam  );

/** DPSDK 设备修改回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nChangeType				参考dpsdk_change_type_e
 @param   IN									szDeviceId              设备Id
 @param   IN									szDepCode               组织Code
 @param   IN									szNewOrgCode            新组织Code   
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKDeviceChangeCallback)( IN int32_t  nPDLLHandle, 
															  IN uint32_t nChangeType, 
															  IN const char* szDeviceId, 
															  IN const char* szDepCode, 
															  IN const char* szNewOrgCode,
															  IN void* pUserParam );

/** DPSDK 新组织设备变更回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nOrgChangeType				参考dpsdk_org_change_type_e
 @param   IN									szOrgCode				组织ID，多个ID以“|”分隔
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOrgDevChangeNewCallback)( IN int32_t  nPDLLHandle, 
															  IN uint32_t nChangeType,
															  IN const char* szOrgCode,
															  IN void* pUserParam );

/** DPSDK 设备修改回调. 
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nChangeType				参考dpsdk_dsst_change_type_e
 @param   IN									nCount                  新纪录个数
 @param   IN									pOrgInfo                修改的新纪录
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOrgChangeCallback)( IN int32_t nPDLLHandle, 
														   IN uint32_t nChangeType, 
														   IN uint32_t nCount, 
														   IN Org_Info_t* pOrgInfo,
														   IN void* pUserParam );

/** DPSDK 人员修改回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									pNodeType				参考dpsdk_dsst_change_type_e
 @param   IN									nCount                  新纪录个数
 @param   IN									pPersonInfo             修改的新纪录
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKPersonChangeCallback)( IN int32_t nPDLLHandle, 
															  IN uint32_t nChangeType, 
															  IN uint32_t nCount, 
															  IN Person_Info_t* pPersonInfo,
															  IN void* pUserParam );

/** DPSDK 车辆修改回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									pNodeType				参考dpsdk_org_node_e
 @param   IN									szOrgCode               原组织code
 @param   IN									pCarInfo                修改的新纪录
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKCarChangeCallback)( IN int32_t nPDLLHandle, 
                                                           IN uint32_t nChangeType, 
                                                           IN const char* szCode, 
														   IN Car_Info_t* pCarInfo,
														   IN void* pUserParam );


/** 媒体数据回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nSeq					对应请求时返回的Seq
 @param   IN									nMediaType				媒体类型，参考dpsdk_media_type_e
 @param	  IN									szNodeId				数据对应的通道/设备ID
 @param	  IN 									nParamVal				扩展值;mediaType为real时，为streamType;
 @param	  IN 									szData					媒体流数据
 @param   IN 									nDataLen				数据长度 
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataCallback)( IN int32_t nPDLLHandle,
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal, 
													  IN char* szData, 
													  IN int32_t nDataLen,
													  IN void* pUserParam );

/** 媒体数据回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									nSeq					对应请求时返回的Seq
 @param   IN									nMediaType				媒体类型，参考dpsdk_media_type_e
 @param	  IN									szNodeId				数据对应的通道/设备ID
 @param	  IN 									nParamVal				扩展值;mediaType为real时，为streamType;
 @param	  IN 									szData					媒体流数据
 @param   IN 									nDataLen				数据长度 
 @param   IN 									pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataByAnalysisCallback)( IN int32_t nPDLLHandle,
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal,
													  IN bool bHead,
													  IN char* szData, 
													  IN int32_t nDataLen,
													  IN void* pUserParam );


/** 报警回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									szAlarmId               报警Id
 @param   IN									nDeviceType             设备类型
 @param   IN									szCameraId              通道Id
 @param   IN									szDeviceName            设备名称
 @param   IN									szChannelName           通道名称
 @param   IN									szCoding                编码
 @param   IN									szMessage               报警信息（普通报警信息内容）
 @param   IN									nAlarmType              报警类型，参考dpsdk_alarm_type_e
 @param   IN									nEventType              报警发生类型，参考dpsdk_event_type_e
 @param   IN									nLevel                  报警等级
 @param   IN									nTime                   报警时间
 @param   IN									pAlarmData              报警数据（智能报警使用）
 @param   IN									nAlarmDataLen           报警数据长度
 @param   IN									pPicData                图片数据
 @param   IN									nPicDataLen             图片数据长度
 @param   IN									pUserParam              用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKAlarmCallback)( IN int32_t nPDLLHandle,
													   IN const char* szAlarmId, 
													   IN uint32_t nDeviceType,
													   IN const char* szCameraId,
													   IN const char* szDeviceName,
													   IN const char* szChannelName,
													   IN const char* szCoding,
													   IN const char* szMessage,
													   IN uint32_t nAlarmType,
													   IN uint32_t nEventType,
													   IN uint32_t nLevel,
													   IN int64_t nTime,
													   IN char* pAlarmData,
													   IN uint32_t nAlarmDataLen,
													   IN char* pPicData,
													   IN uint32_t nPicDataLen,
													   IN void* pUserParam);


/** 新报警回调.
 @param   IN									nPDLLHandle				SDK句柄
 @param   IN									szAlarmId               报警Id
 @param   IN									nDeviceType             设备类型
 @param   IN									szDeviceId				设备ID
 @param   IN									nChannelNo				通道号
 @param   IN									szDeviceName            设备名称
 @param   IN									szChannelName           通道名称
 @param   IN									szCoding                编码
 @param   IN									szMessage               报警信息（普通报警信息内容）
 @param   IN									nAlarmType              报警类型，参考dpsdk_alarm_type_e
 @param   IN									nEventType              报警发生类型，参考dpsdk_event_type_e
 @param   IN									nLevel                  报警等级
 @param   IN									nTime                   报警时间
 @param   IN									pAlarmData              报警数据（智能报警使用）
 @param   IN									nAlarmDataLen           报警数据长度
 @param   IN									pPicData                图片数据
 @param   IN									nPicDataLen             图片数据长度
 @param   IN									pUserParam              用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNewAlarmCallback)(int32_t nPDLLHandle,
														const char* szAlarmId, 
														uint32_t nDeviceType,
														const char* szDeviceId,
														uint32_t nChannelNo, 
														const char* szDeviceName,
														const char* szChannelName,
														const char* szCoding,
														const char* szMessage,
														uint32_t nAlarmType,
														uint32_t nEventType,
														uint32_t nLevel,
														int64_t nTime,
														char* pAlarmData,
														uint32_t nAlarmDataLen,
														char* pPicData,
														uint32_t nPicDataLen,
														void* pUserParam);

/** 设备状态回调.
 @param   IN									nPDLLHandle		        SDK句柄
 @param   IN									szDeviceId              设备ID（DVR+通道）
 @param   IN									nStatus		            参考dpsdk_device_status_type_e
 @param   IN 									pUserParam		        用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKDevStatusCallback)( int32_t nPDLLHandle, 
														   const char* szDeviceId,
														   int32_t nStatus, 
														   void* pUserParam );

/** 通道状态回调.

*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNVRChnlStatusCallback)( IN int32_t nPDLLHandle, 
															  IN const char* szChnlId,
															  IN int32_t nStatus, 
															  IN void* pUserParam );

/** 图片数据回调函数定义
 @param	  IN	                                nPDLLHandle				SDK句柄
 @param   IN	                                session					对应请求时返回的session
 @param	  IN	                                nodeId					数据对应的通道/设备ID
 @param	  IN	                                pData					图片流数据
 @param	  IN	                                dataLen					数据长度 
 @param	  IN	                                pUserParam				用户参数
 @param	  IN	                                notify_e				图片数据类型
*/
//typedef int32_t (DPSDK_CALLTYPE *fDPSDKPicDataCallback)( IN int32_t nPDLLHandle, 
//														   IN int session, 
//														   IN const char* nodeId, 
//														   IN char* pData, 
//														   IN int dataLen, 
//														   IN void* pUserParam, 
//														   IN dpsdk_picdata_notify_e enNotify);	// fixme::该枚举类型需要重新定义

/** 车辆违章上报回调函数定义
 @param	  IN	                                nPDLLHandle				 SDK句柄
 @param	  IN	                                pRetInfo				 对应请求时返回的session
 @param	  IN	                                pUserParam				 用户参数
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKTrafficAlarmCallback)( IN int32_t nPDLLHandle, 
															  IN Traffic_Alarm_Info_t* pRetInfo, 
															  IN void* pUserParam );

/** 流量上报回调函数定义
 @param	  IN	                                nPDLLHandle			     SDK句柄
 @param	  IN	                                pRetInfo				 对应请求时返回的session
 @param	  IN	                                pUserParam				 用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetTrafficFlowCallback)( IN int32_t nPDLLHandle, 
																IN TrafficFlow_Info_t* pRetInfo,
																IN void* pUserParam );

/** 车道流量状态上报回调函数定义
    @param IN                                   nPDLLHandle              SDK句柄
    @param IN                                   pRetInfo                 对应请求时返回的流量信息
    @param IN                                   pUserParam               用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetDevTrafficFlowCallback)( IN int32_t nPDLLHandle,
																   IN DevTrafficFlow_Info_t* pRetInfo, 
																   IN void* pUserParam );


 
/** 卡口过车信息上报回调函数定义
    @param IN                                    nPDLLHandle              SDK句柄
    @param IN                                    pRetInfo                 对应请求时返回的流量信息
    @param IN                                    pUserParam               用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetBayCarInfoCallback)( IN int32_t nPDLLHandle,
															   IN Bay_Car_Info_t* pRetInfo, 
															   IN void* pUserParam );

/** 卡口过车信息上报回调函数定义
    @param IN                                    nPDLLHandle              SDK句柄
    @param IN                                    pUserParam               用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
	@remark	参数定义请参考Bay_Car_Info_t
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetBayCarInfoCallbackEx)(int32_t nPDLLHandle,
																const char*	szDeviceId,
																int32_t	nDeviceIdLen,
																int32_t	nDevChnId,
																const char* szChannelId,
																int32_t nChannelIdLen,
																const char*	szDeviceName,
																int32_t	nDeviceNameLen,
																const char*	szDeviceChnName,
																int32_t	nChanNameLen,
																const char*	szCarNum,
																int32_t nCarNumLen,
																int32_t	nCarNumType,
																int32_t	nCarNumColor,
																int32_t	nCarSpeed,
																int32_t	nCarType,
																int32_t	nCarColor,
																int32_t	nCarLen,
																int32_t	nCarDirect,
																int32_t	nWayId,
																uint64_t	lCaptureTime,
																unsigned long	lPicGroupStoreID,
																int32_t	nIsNeedStore,
																int32_t	nIsStoraged,
																const char*	szCaptureOrg,
																int32_t	nCaptureOrgLen,
																const char*	szOptOrg,
																int32_t	nOptOrgLen,
																const char*	szOptUser,
																int32_t	nOptUserLen,
																const char*	szOptNote,
																int32_t	nOptNoteLen,
																const char*	szImg0Path,
																int32_t	nImg0PathLen,
																const char*	szImg1Path,
																int32_t	nImg1PathLen,
																const char*	szImg2Path,
																int32_t	nImg2PathLen,
																const char*	szImg3Path,
																int32_t	nImg3PathLen,
																const char*	szImg4Path,
																int32_t	nImg4PathLen,
																const char*	szImg5Path,
																int32_t	nImg5PathLen,
																const char*	szImgPlatePath,
																int32_t	nImgPlatePathLen,
																int32_t	icarLog,
																int32_t	iPlateLeft,
																int32_t	iPlateRight,
																int32_t	iPlateTop,
																int32_t	iPlateBottom, 
															    void* pUserParam );

/** 区间测速上报回调函数定义
    @param IN                                    nPDLLHandle              SDK句柄
    @param IN                                    pRetInfo                 对应请求时返回的流量信息
    @param IN                                    pUserParam               用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKGetAreaSpeedDetectCallback)( IN int32_t nPDLLHandle,
																	IN Area_Detect_Info_t* pRetInfo, 
																	IN void* pUserParam );

/** 事件上报回调函数定义
    @param IN                                    nPDLLHandle              SDK句柄
    @param IN                                    pIssueInfo               事件上报信息
    @param IN                                    pUserParam               用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKIssueCallback)( IN int32_t nPDLLHandle,
													  IN Issue_Info_t* pIssueInfo, 
													  IN void* pUserParam );

/** Ftp图片回调函数定义
    @param IN                                    nPDLLHandle              SDK句柄
    @param IN                                    pFtpPicInfo               事件上报信息
    @param IN                                    pUserParam               用户参数
*/
// typedef int32_t (DPSDK_CALLTYPE *fDPSDKFtpPicCallback)( IN int32_t nPDLLHandle,
// 														IN Ftp_Pic_Info_t* pFtpPicInfo, 
// 														IN void* pUserParam );

/** 云台定位报警信息回调
	@param	IN	int32_t nPDLLHandle								        SDK句柄
    @param	IN	 pRetInfo										        云台信息
	@param	IN	void* pUserParam							            用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKPtzSitAlarmInfoCallback)( IN int32_t nPDLLHandle, 
															     IN Ptz_Sit_Alarm_Info* pRetInfo,
																 IN void* pUserParam );	

/** 卡口布控告警上报回调函数定义
 @param	  IN	                                nPDLLHandle		       SDK句柄
 @param	  IN	                                pRetInfo				 对应请求时返回的session
 @param	  IN	                                pUserParam			 用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKBayWantedAlarmCallback)( IN int32_t nPDLLHandle, 
															       IN Bay_WantedAlarm_Info_t* pRetInfo, 
															       IN void* pUserParam );

/** 文件操作回调函数定义
 @param	  IN	                                 nPDLLHandle			 SDK句柄
 @param	  IN	                                 szLocalFile			 本地文件路径
 @param	  IN	                                 szRemoteFile			 远端文件路径
 @param	  IN	                                 optype					 操作类型
 @param	  IN	                                 progress				 操作进度
 @param	  IN	                                 pUserParam				 用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKOperatorRemoteFileCallback)( IN int32_t nPDLLHandle,
																    IN char* szLocalFile,
																	IN char* szRemoteFile,
																	IN dpsdk_operator_remote_file_type_e optype,														
																	IN int32_t progress,
																	IN void* pUserParam );

/** 异步加载组织结构回调.
 @param   IN									 nRet				      调用LoadDGroupInfo的返回值
 @param   IN                                     nGroupLen                若LoadDGroupInfo成功，nGroupLen为GroupInfo字符串的长度
 @remark									
*/
typedef void (DPSDK_CALLTYPE *fAsyncLoadDGroupInfoCallback)( IN int32_t nPDLLHandle,
																IN int32_t nRet,
																IN int32_t nGroupLen,
																IN void* pUserParam);

/** 异步登录回调.
 @param   IN									 nRet				      调用Login的返回值
 @remark									
*/
typedef void (DPSDK_CALLTYPE *fAsyncLoginCallback)( IN int32_t nPDLLHandle,
													IN int32_t nRet,
													IN void* pUserParam);

/** 视频分享信息回调
 @param   IN                                    nPDLLHandle               SDK句柄
 @param   IN                                    pVideoInfo                分享的视频数组
 @param   IN                                    nVideoCount               视频数量
 @param   IN                                    szMsg                     分享时附加的信息
 @param   IN                                    nSrcUserId                分享人的userId
 @param   IN                                    szSrcUserName             分享人的用户名
 @param   IN                                    pUserParam                用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKShareVideoCallback)( IN int32_t nPDLLHandle, 
													   IN ShareVideoInfo* pVideoInfo,
													   IN int32_t nVideoCount,
													   IN const char* szMsg, 
													   IN int32_t nSrcUserId,
													   IN const char* szSrcUserName,
													   IN void* pUserParam );

/** 语音对讲信息报回调函数定义
 @param	  IN	                                nPDLLHandle		    SDK句柄
 @param	  IN	                                nAudioType			音频类型
 @param	  IN	                                nAudioBit			位数
 @param	  IN	                                nSampleRate			采样率
 @param	  IN	                                nTransMode			传输类型
 @param	  IN	                                pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKTalkParamCallback)(  IN int32_t nPDLLHandle,
														 	IN int32_t nTalkType,
															IN int32_t nAudioType, 
															IN int32_t nAudioBit,
															IN int32_t nSampleRate, 
															IN int32_t nTransMode,
															IN void* pUserParam );

/** 车载设备远程抓拍回调
 @param   IN           nPDLLHandle               SDK句柄
 @param   IN           szCameraId                通道ID
 @param   IN           szFullPath                文件全路径名
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKRemoteDeviceSnapCallback) (int32_t nPDLLHandle,
																  const char* szCameraId,
																  const char* szFullPath,
																  void *pUser);

/** 异步执行实时预览视频的结果回调
 @param   IN      nPDLLHandle       SDK句柄
 @param   IN      nRealFlag         与 StartRealplayAsync返回的nRealFlag一致
 @param   IN      nSeq              作为其他函数的操作参数 如 DPSDK_StopRealplayBySeq
 @param   IN      nRet              错误码
 @param   IN      pUserParam        用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKStartRealplayCallback) (int32_t nPDLLHandle,
															   int32_t nRealFlag,
															   int32_t nSeq,
															   int32_t nRet,
															   void* pUserParam);

/** 异步执行关闭实时预览视频的结果回调
 @param   IN      nPDLLHandle       SDK句柄
 @param   IN      nSeq              作为其他函数的操作参数 如 DPSDK_StopRealplayBySeq
 @param   IN      nRet              错误码
 @param   IN      pUserParam        用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKStopRealplayCallback) (int32_t nPDLLHandle,
															   int32_t nSeq,
															   int32_t nRet,
															   void* pUserParam);

/** 异步云台方向控制的结果回调
 @param   IN      nPDLLHandle       SDK句柄
 @param   IN      nSeq              作为其他函数的操作参数 如 DPSDK_StopRealplayBySeq
 @param   IN      nRet              错误码
 @param   IN      pUserParam        用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKPtzDirectionCallback) (int32_t nPDLLHandle,
															   int32_t nPtzFlag,
															   int32_t nRet,
															   void* pUserParam);

/** 视频报警主机布撤防/旁路状态回调
 @param	  IN	                                nPDLLHandle		    SDK句柄
 @param	  IN	                                szDeviceId			设备Id
 @param	  IN	                                nChannelNO			通道号，设备操作通道号是-1
 @param	  IN	                                nStatus				状态，参考dpsdk_videoalarmhost_status_type_e
 @param	  IN	                                pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 视频报警主机在客户端登陆的时候DMS会上报状态，客户端操作会通知其他客户端。
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKVideoAlarmHostStatusCallback)(  IN int32_t nPDLLHandle,
														 	IN char*   szDeviceId,
															IN int32_t nChannelNO, 
															IN int32_t nStatus,
															IN void* pUserParam );

/** 网络报警主机布撤防/旁路状态回调
 @param	  IN	                                nPDLLHandle		    SDK句柄
 @param	  IN	                                szDeviceId			布撤防时是设备Id;旁路/取消旁路时是通道id
 @param	  IN	                                nRType				上报类型，参考dpsdk_netalarmhost_report_type_e，1布防，2旁路
 @param	  IN	                                nOperType			操作类型，参考dpsdk_netalarmhost_operator_e，1设备操作，2通道操作
 @param	  IN	                                nStatus				状态，对于防区状态1布防2撤防；对于旁路状态1旁路2取消旁路
 @param	  IN	                                pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
 网络报警主机状态要自己查询，客户端操作会通知其他客户端。
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKNetAlarmHostStatusCallback)(  IN int32_t nPDLLHandle,
														 	IN char*   szDeviceId,
															IN int32_t nRType, 
															IN int32_t nOperType,
															IN int32_t nStatus,
															IN void* pUserParam );

/** 业翔广播通道状态回调
 @param	  IN	                                nPDLLHandle		    SDK句柄
 @param	  IN	                                szCameraId			通道id
 @param	  IN	                                nRType				上报类型，参考dpsdk_broadcast_report_type_e，1500业翔广播故障消息，1501业翔广播播放状态消息
 @param	  IN	                                nTime				上报时间
 @param	  IN	                                nStatus				状态，对于业翔对讲通道故障消息 1产生 2消失；对于业翔对讲通道播放状态 1播放 2停止
 @param	  IN	                                pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE *fDPSDKBroadcastReportStatusCallback)(  IN int32_t nPDLLHandle,
														 	IN char* szCameraId,
															IN int32_t nRType, 
															IN int64_t nTime,
															IN int32_t nStatus,
															IN void* pUserParam );

/** 图片数据回调函数定义
    @param int session												对应请求时返回的session
    @param const char* nodeId										数据对应的通道/设备ID
    @param char* pData												图片流数据
    @param int dataLen												数据长度 
	@param void* pUserParam											用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
	@param dpsdk_picdata_notify_e notify_e							图片数据类型
*/
typedef int (DPSDK_CALLTYPE *fPicDataCallback)(int session, const char* nodeId, char* pData, int dataLen, void* pUserParam, dpsdk_picdata_notify_e notify_e);

/** Json传输协议回调
	@param szJson	Json字符串
*/
typedef int (DPSDK_CALLTYPE* fDPSDKGeneralJsonTransportCallback)(IN int32_t nPDLLHandle, IN const char* szJson, void* pUserParam);

/** Json传输协议回调
	@param szJson	Json字符串
*/
typedef int (DPSDK_CALLTYPE* fDPSDKGeneralJsonTransportCallbackEx)(int32_t nPDLLHandle, const char* szJson, int nJsonLen, void* pUserParam);


/** 电子围栏改变回调函数定义
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKAreaChangeCallback)(int32_t nPDLLHandle, void* pUserParam);

/** 关联关系改变回调函数定义
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKRelationChangeCallback)(int32_t nPDLLHandle, void* pUserParam);

/** 排班信息改变回调函数定义
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                LineID				线路id
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fDPSDKBusScheduleChangeCallback)(int32_t nPDLLHandle, int LineID, void* pUserParam);

/** 排班信息改变回调函数定义
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                LineID				线路id
	@param	<IN>	                                LineType			线路类型
	@param	<IN>	                                PlanId				计划id
	@param	<IN>	                                State				状态
	@param	<IN>	                                DevId				设备id
	@param	<IN>	                                Time				时间
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fDPSDKBusScheduleStateChangeCallback)(int32_t nPDLLHandle,
																   int LineID,
																   int LineType,
																   int PlanId,
																   int State,
																   char* DevId,
																   char* Time,
																   void* pUserParam);
/** 调度信息回调函数定义
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                PlanID				计划id
	@param	<IN>	                                LineName			线路名称
	@param	<IN>	                                DisPatchTime		调度时间
	@param	<IN>	                                State				状态
	@param	<IN>	                                DevName				设备名称
	@param	<IN>	                                DepartTime			时间
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fDPSDKDispitchInfoCallback)(int32_t nPDLLHandle,
														   int PlanID,
														   char* LineName,
														   int DisPatchTime,
														   int State,
														   char* DevName,
														   int DepartTime,
														   void* pUserParam);


/** 违章报警回调函数定义
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKPeccancyAlarmCallback)(int32_t nPDLLHandle, Peccancy_Alarm_t* pAlarmInfo, void* pUserParam);

/** 报警预案变更回调函数定义
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKAlarmSchemeCallback)(int32_t nPDLLHandle, AlarmSchemeChg_t* pAlarmInfo, void* pUserParam);

/** 用户信息变更回调函数定义
	@param void* pUserParam											
*/
typedef int (DPSDK_CALLTYPE *fDPSDKDataChangeCallback)(int32_t nPDLLHandle, DataChange_t* pDataChangeInfo, void* pUserParam);

/** 集群对讲发起呼叫参数回调
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                param				主动发起呼叫的对讲参数，用于本地音频采集
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fStartCallParamCallBack)(int32_t nPDLLHandle, StartCallParam_t* param, void* pUserParam);


/** 集群对讲呼叫邀请参数回调
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                param				被邀请对讲的对讲参数，用于本地音频采集
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fInviteCallParamCallBack)(int32_t nPDLLHandle, InviteCallParam_t* param, void* pUserParam);


/** 可视对讲呼叫邀请参数回调
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                param				被邀请对讲的对讲参数，用于本地音频采集
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE *fDPSDKInviteVtCallParamCallBack)(int32_t nPDLLHandle, InviteVtCallParam_t* param, void* pUserParam);

/** 响铃通知回调
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                param				响铃参数
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE * fDPSDKRingInfoCallBack)(int32_t nPDLLHandle, RingInfo_t* param, void* pUserParam);

/** 可视对讲呼叫状态繁忙通知回调
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                param				状态繁忙信息参数
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int (DPSDK_CALLTYPE * fDPSDKBusyVtCallCallBack)(int32_t nPDLLHandle, BusyVtCallInfo_t* param, void* pUserParam);

/** 语音对讲音频发送函数定义. 
    @param char * pData						媒体流数据
    @param int dataLen						数据长度 
    @param void * pUserParam				用户参数,见AudioUserParam
*/
typedef void (DPSDK_CALLTYPE  *fAudioDataCallback)( char* pData, int dataLen, void* pUserParam );

/** 门禁状态上报接收函数定义. 
    @param char * szCamearId				门禁通道ID
    @param int nStatus						数据长度 
    @param int nTime						上报时间
    @param void * pUserParam				用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef void (DPSDK_CALLTYPE  *fDPSDKPecDoorStarusCallBack)(int32_t nPDLLHandle, const char* szCamearId, dpsdk_door_status_e nStatus, int64_t nTime, void* pUserParam);


/** 设备球机通道的可视域信息回调. 
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                szCamearId			通道ID
	@param	<IN>	                                nDistance			可视距离, 单位:米 
	@param	<IN>	                                nAngelH				水平可视角度, 0~1800, 单位:十分之一度
	@param	<IN>	                                nAzimuthH			水平方位角度, 0~3600, 单位:十分之一度
	@param	<IN>	                                nInclinationH		水平倾斜角度, -900~900, 单位:十分之一度
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE  *fDPSDKChannelViewInfoCallback)(int32_t nPDLLHandle, const char* szCamearId, int nDistance, int nAngelH, int nAzimuthH, int nInclinationH, void* pUserParam);


/** 第一帧码流信息回调. 
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                nSequence			码流序列号，可用于关闭码流请求 
	@param	<IN>	                                szCamearId			通道ID
	@param	<IN>	                                nCameraIDLen		通道ID长度
	@param	<IN>	                                nPlayMode			播放类型，1实时，2回放，详细参考dpsdk_media_func_e
	@param	<IN>	                                nFactoryType		厂商标示	*- 0表示包含大华头的厂商码流，需要内部分析是哪个厂商，目前只支持大华、海康、华三
																					*- 1表示大华厂家
																					*- 2表示海康厂家
																					*- 4表示汉邦厂商
																					*- 5表示天地伟业
																					*- 6表示恒忆
																					*- 7表示黄河
																					*- 8表示朗驰
																					*- 9表示浩特
																					*- 10表示卡尔 
																					*- 11表示景阳
																					*- 12表示中维世纪，后缀名通常为801
																					*- 13表示中维世纪板卡,后缀名通常为sv4(和通用版本是2套SDK）
																					*- 14表示东方网力
																					*- 15表示恒通
																					*- 16表示立元的DB33
																					*- 17表示环视
																					*- 18表示蓝星
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE  *fMediaDataFirstFrameCallback)(int32_t nPDLLHandle, int nSequence, const char* szCamearId, int nCameraIDLen, int nPlayMode, int nFactoryType, void* pUserParam);

/** 码流超时通知回调. 
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                nSequence			码流序列号，可用于关闭码流请求 
	@param	<IN>	                                szCamearId			通道ID
	@param	<IN>	                                nCameraIDLen		通道ID长度
	@param	<IN>	                                nPlayMode			播放类型，1实时，2回放，详细参考dpsdk_media_func_e
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE  *fMediaDataDisconnectCallback)(int32_t nPDLLHandle, int nSequence, const char* szCamearId, int nCameraIDLen, int nPlayMode, void* pUserParam);

/** 流媒体断开通知回调. 
	@param	<IN>	                                nPDLLHandle		    SDK句柄
	@param	<IN>	                                nSequence			码流序列号，可用于关闭码流请求 
	@param	<IN>	                                nPlayMode			播放类型，1实时，2回放，详细参考dpsdk_media_func_e
	@param	<IN>									pUserParam			用户指针参数,由对应的DPSDK_SetxxxxCallBack传入
*/
typedef int32_t (DPSDK_CALLTYPE  *fVideoRTSPDisConnectCallback)(int32_t nPDLLHandle, int nSequence, int nPlayMode, void* pUserParam);

/**
  @brief 录像转码完成回调函数定义
  @param nPDLLHanlde	SDK句柄
  @param nPlaybackSeq	录像转码的序列号
  @param pUserParam		用户数据
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fSaveRecordFinishedCallback)( IN int32_t nPDLLHandle,
															   IN int32_t nPlaybackSeq,
															   IN void *pUserParam);

/***************************************************************************************
 @ 回调函数定义结束
***************************************************************************************/
#endif
