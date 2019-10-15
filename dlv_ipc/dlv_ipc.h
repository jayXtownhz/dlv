/**
 * @file	dlv_ipc.h
 * @author	jayxu
 * @date	2019-8-01
 * @brief	本文件中定义了 DLV_IPC_LOGIN，DLV_THREAD_PARAM 及程序常量.
 * @version	1.0
 */

#ifndef	DLV_IPC_INCLUDE_H
#define	DLV_IPC_INCLUDE_H

# ifdef	__cplusplus
extern "C" {
# endif

#define DLV_MAX_THREAD       20		/**< 单个console支持的线程数，一个消息队列一个线程 */
#define DLV_MAX_IPC          20     /**< 单线程中最多IPC数量 */
#define DLV_MAX_WAITEVENT    60000  /**< 下载视频时，最大阻塞时间60秒 */
#define DLV_EMPTY_WAIT		 3000   /**< redis队列空闲，线程休眠时间默认3秒 */
 
/**
 * IPC登录信息结构体
 */
typedef struct tagDLV_IPC_LOGIN
{
	__int64              lLoginHandle;    /**< IPC登录句柄 */
	char 				 szIpAddr[32];    /**< IP地址 */
	char 				 szUser[32];      /**< 登录用户 */
	char 				 szPwd[32];       /**< 登录密码 */
	int                  nPort;           /**< 端口号, 默认37777 */
	int                  nChan;			  /**< 录像通道, 默认0 */
	bool				 bDisconn;        /**< IPC是否掉线 */
	char                 szRegion[32];	  /**< IPC所在行政区域编码 */
	char                 szDevCode[32];   /**< IPC对应门口机编码 */
} DLV_IPC_LOGIN;

/**
 * 线程传输结构体
 */
typedef struct tagDLV_THREAD_PARAM
{
	char                 szRedisIpAddr[32];        /**< redis服务ip地址 */
	char                 szRedisPwd[32];           /**< redis服务验证密码 */
	int                  nRedisDB;                 /**< redis服务选择的数据库编号(0~15) */
	int                  nQueue;                   /**< redis服务消息队列 */
	char                 szFilePath[64];           /**< 录像视频存储的根目录路径(d:\video) */
} DLV_THREAD_PARAM;

typedef struct tagDLV_DATACB
{
	FILE*                file;					   /**< 大华数据回调函数文件句柄, 默认NULL */
	int                  fileFlushFlag;            /**< 文件句柄刷新标志, 默认1 */
} DLV_DATACB;

# ifdef	__cplusplus
}
# endif

#endif