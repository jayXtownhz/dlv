#ifndef	DLV_DSS_INCLUDE_H
#define	DLV_DSS_INCLUDE_H

# ifdef	__cplusplus
extern "C" {
# endif

#define DLV_MAX_WAITEVENT    60000  // 下载视频时，最大阻塞时间60秒
#define DLV_EMPTY_WAIT		 3000   // redis队列空闲，线程休眠时间默认3秒
#define DLV_MAX_THREAD       20     // 单个应用程序最大支持20个线程
#define DLV_MAX_IPC          20     // 单线程最大支持20个IPC

	typedef struct tagDLV_DSS_IPC
	{
		char                 szIpcIp[32];              // 7016服务器上连接IPC的ip地址
		char                 szChan[32];			   // ICP在7016上的通道号
		char                 szRegion[32];	           // IPC所在行政区域编码
		char                 szDevCode[32];            // IPC对应门口机编码
	} DLV_DSS_IPC;

	// 线程传输结构体
	typedef struct tagDLV_THREAD_PARAM
	{
		char                 szRedisIpAddr[32];        // redis服务ip地址
		char                 szRedisPwd[32];           // redis服务验证密码
		int                  nRedisDB;                 // redis服务选择的数据库编号(0~15)
		int                  nQueue;                   // redis服务消息队列
		char                 szFilePath[64];           // 录像视频存储的根目录路径(d:\video)
	} DLV_THREAD_PARAM;

	typedef struct tagDLV_DATACB
	{
		FILE*                file;					   // 大华数据回调函数文件句柄, 默认NULL
		int                  fileFlushFlag;            // 文件句柄刷新标志, 默认1
	} DLV_DATACB;

# ifdef	__cplusplus
}
# endif

#endif