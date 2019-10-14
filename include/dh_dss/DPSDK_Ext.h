#ifndef INCLUDED_DPSDK_EXT_H
#define INCLUDED_DPSDK_EXT_H

#include "DPSDK_Core_Define.h"

typedef enum
{
	IVS_RULE_VISIBLE	= 1,			// 规则
	IVS_OBJ_VISIBLE		= 2,			// 目标框
	IVS_LOCUS_VISIBLE	= 3,			// 轨迹
}IvsInfoVisible;

/***************************************************************************************
 @ 回调函数定义
***************************************************************************************/

/** 媒体数据回调.
 @param nPDLLHandle				SDK句柄
 @param nSeq					对应请求时返回的Seq
 @param nMediaType				媒体类型，参考dpsdk_media_type_e
 @param	szNodeId				数据对应的通道/设备ID
 @param	nParamVal				扩展值;mediaType为real时，为streamType;
 @param szUserParams			用户参数
 @remark									
*/
typedef int32_t (DPSDK_CALLTYPE *fMediaDataComplete)( IN int32_t nPDLLHandle, 
													  IN int32_t nSeq, 
													  IN int32_t nMediaType, 
													  IN const char* szNodeId, 
													  IN int32_t nParamVal, 
													  IN void* pUserParam );

/**
  @brief 解码回调
  @param nPDLLHanlde	SDK句柄
  @param nSeq			码流请求序号
  @param pBuf			解码后的音视频数据
  @param nLen			数据长度
  @param pFrameInfo		pFrameInfo 帧信息,详见FRAME_INFO结构体
  @param pUserParam		用户数据
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fMediaDataYUV)( IN int32_t nPDLLHandle,
												IN int32_t nSeq, 
												IN const char* pBuf, 
												IN int32_t nLen,
												IN Frame_Info* pFrameInfo,
												IN void* pUserParam);

/**
  @brief 语音对讲的音频数据回调
  @param nPDLLHanlde	SDK句柄
  @param nSession		对讲会话ID
  @param nMediaType		媒体类型，参考dpsdk_media_type_e
  @param szNodeId		数据对应的通道/设备ID
  @param nParamVal		扩展值;mediaType为real时，为streamType;
  @param szData			解码后的音视频数据
  @param nDataLen		数据长度
  @param pUserParam		用户数据
  @remark
 */
typedef int ( DPSDK_CALLTYPE *fTalkDataCallback )( IN int32_t nPDLLHandle,
												  IN int32_t nSession, 
												  IN int32_t nMediaType, 
												  IN const char* szNodeId,
												  IN int32_t nParamVal, 
												  IN char*	szData, 
												  IN int32_t nDataLen, 
												  IN void* szUserParam);

/**
  @brief 下载录像文件完成回调函数定义
  @param nPDLLHanlde	SDK句柄
  @param nDownloadSeq	下载录像的序列号
  @param pUserParam		用户数据
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadFinishedCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
															 IN void *pUserParam);

/**
  @brief 下载录像文件进度回调函数定义
  @param nPDLLHanlde	SDK句柄
  @param nDownloadSeq	下载录像的序列号
  @param nPos           进度，范围0--100
  @param pUserParam		用户数据
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadProgressCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
                                                             IN int32_t nPos,
															 IN void *pUserParam);

/**
  @brief 下载录像文件网络异常回调函数定义
  @param nPDLLHanlde	SDK句柄
  @param nDownloadSeq	下载录像的序列号
  @param pUserParam		用户数据
  @remark
 */
typedef int32_t (DPSDK_CALLTYPE *fDownloadNetErrorCallback)( IN int32_t nPDLLHandle,
															 IN int32_t nDownloadSeq,
															 IN void *pUserParam);

/**
  @brief 外部使用的码流回调函数定义
  @param nPDLLHanlde	SDK句柄
  @param nSeq       	播放序列号
  @param StreamType     码流类型,0系统头，1数据流
  @param Data           码流数据
  @param DataLen        码流数据长度
  @param DecoderTag     解码标签，“hik”、“dahua”等
  @param UserData		用户数据
  @remark
 */
typedef void (DPSDK_CALLTYPE *fStreamCallback)(IN int32_t nPDLLHanlde,
											   IN int32_t nSeq, 
											   IN int StreamType, 
											   IN const char *Data, 
											   IN int DataLen, 
											   IN const char *DecoderTag, 
											   IN void *UserData);

/**
  @brief 渲染回调函数,获得当前表面的device context,你可以在这个DC上画图(或文字),就好像在窗口的客户区DC上绘图
  @param nPDLLHanlde	SDK句柄
  @param nSeq			码流请求序号
  @param hDc			当前表面的device context
  @param pUser			用户数据
  @remark
 */
typedef void (DPSDK_CALLTYPE* fDrawFunCallback)(IN int32_t nPDLLHanlde, 
												IN int32_t nSeq, 
												IN void *hDc,
												IN void *pUser);

/**
  @brief 回放进度回调定义
  @param nPDLLHanlde	SDK句柄
  @param nSeq			码流请求序号
  @param nPlayedTime	已播放的时间，单位s
  @parm  nStatus        状态值，0下载中，1正常结束，2异常结束
  @param pUser			用户数据
  @remark
 */
typedef void (DPSDK_CALLTYPE* fPlaybackPosTimerCallback)(IN int32_t nPDLLHanlde, 
														 IN int32_t nSeq, 
														 IN long nPlayedTime, 
														 IN long nStatus, 
														 IN void* pUser);

/**
  @brief 码流源数据分析完的数据回调
  @param nPort			播放seq
  @param pBuf			数据指针
  @param nSize			数据长度
  @param pParam			帧信息  指向DPSDK_DEMUX_INFO这个结构体
  @param nReserved		保留
  @param nUser			用户自定义参数
  @remark只对大华码流有效
*/
 typedef void (DPSDK_CALLTYPE* fDPSDKDemuxDecCallback)(long nSeq, char * pBuf,	long nSize, void * pParam, void* pReserved, void* pUserData);

/***************************************************************************************
 @ 回调函数定义结束
***************************************************************************************/


/***************************************************************************************
 @ 接口定义
***************************************************************************************/

/** 初始化扩展库.
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_InitExt( void );

/** 反初始化扩展库.
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_InitExt成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_UnitExt( void );


/** 播放实况码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplay( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN void* hDestWnd, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetIVSAlarmInfo(IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq,
															  IN int32_t nAlarmType,
															  IN const char* szAlarmInfo, 
															  IN int32_t nDataLen);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetIvsShowFlag(IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq,
															  IN IvsInfoVisible nType,
															  IN int32_t nFlag);
//打开零通道多画面拼接实时视频
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayPreview( IN int32_t nPDLLHandle, 
																   OUT int32_t& nRealSeq, 
																   IN Get_RealStream_Info_t* pGetInfo, 
																   IN int nStartChIndex,
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayAsync(IN int32_t nPDLLHandle, 
																 OUT int32_t& nRealFlag,
																 IN Get_RealStream_Info_t* pGetInfo, 
																 IN void* hDestWnd);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRealPlayResultCallback(fDPSDKStartRealplayCallback fun, void *pUser);

/** 删除轮巡任务.
 @param   IN		nPDLLHandle		SDK句柄
 @param   IN		iTaskId			轮巡任务ID
 @param	  IN		nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelSwitch(IN int32_t nPDLLHandle, 
												        IN const unsigned int iTaskId, 
												        IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**启动轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄 
 @param   IN	pTaskInfoEx		任务信息 
 @param	  IN	hDestWndList	显示窗口句柄列表
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartTaskEx( IN int32_t nPDLLHandle, 
														   IN TaskInfoEx_t* pTaskInfoEx, 
														   IN void** hDestWndList, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**停止轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄  
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark*/		
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTask( IN int32_t nPDLLHandle,IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**启动轮巡任务.(适用于单窗口的轮巡任务)
 @param   IN	nPDLLHandle		SDK句柄 
 @param   IN	iTaskId			任务ID 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartTaskByTaskId( IN int32_t nPDLLHandle,
																 IN const int iTaskId,
																 IN void* hDestWnd,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**停止轮巡任务.(适用于单窗口轮巡任务)
 @param   IN	nPDLLHandle		SDK句柄  
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTaskByWndHandle( IN int32_t nPDLLHandle, IN void* hWndHandle, IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 切换播放的窗口.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param	  IN	hDstWnd		    目的窗口句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ChangePlayWndBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nRealSeq, 
																 IN void* hDstWnd );

/**设置解码后YUV回调
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nRealSeq		码流请求序号
@param   IN pFun            YUV回调
@param   IN pUser           用户参数
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDecCallback( IN int32_t nPDLLHandle, 
															  IN int32_t nRealSeq, 
															  IN fMediaDataYUV pFun,
															  IN void* pUser);

/** 播放实况码流附带码流回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayWithCallback( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN void* hDestWnd,
															 IN fStreamCallback fun,
															 IN void* pUser,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 播放实况码流附带是否打开YUV回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @param   IN    bDecCallback    是否打开YUV回调
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRealplayEx( IN int32_t nPDLLHandle, 
															OUT int32_t& nRealSeq, 
															IN Get_RealStream_Info_t* pGetInfo, 
															IN void* hDestWnd, 
															IN bool  bDecCallback,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按请求序号关闭码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,作为后续操作标识 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRealplayBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nRealSeq, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRealplayBySeqAsync( IN int32_t nPDLLHandle, 
																IN int32_t nRealSeq);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetStopRealPlayResultCallback(fDPSDKStopRealplayCallback fun, void *pUser);

/** 开始广播
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nTalkSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartBroadcastExt( int32_t nPDLLHandle, 
															  int32_t* nTalkSeq, 
															  const char* szJson, 
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 开始广播
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nTalkSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopBroadcast( int32_t nPDLLHandle, 
															  int32_t nTalkSeq, 
															  const char* szJson, 
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 开始语音对讲
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nTalkSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartTalk( IN int32_t nPDLLHandle, 
														 OUT int32_t& nTalkSeq, 
														 IN Get_TalkStream_Info_t* pGetInfo, 
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 按请求序号停止语音对讲.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nTalkSeq		码流请求序号,作为后续操作标识 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalkBySeq( IN int32_t nPDLLHandle, 
															 IN int32_t nTalkSeq, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按CameraId停止语音对讲
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		设备或通道编号
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  关闭所有的已经打开的CameraId	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalkByCameraId( IN int32_t nPDLLHandle, 
																  IN const char* szCameraId, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


//集群对讲

/** 开始呼叫
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nCallSeq		码流请求序号,作为后续操作标识 
 @param   IN	nCallType		呼叫类型 0单播；1组播；2可视对讲
 @param   IN	szGroupId		呼叫组ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartCallExt( int32_t nPDLLHandle, 
														    int32_t& nCallSeq, 
															dpsdk_call_type_e nCallType,
															const char* szGroupId, 
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 关闭呼叫
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nCallSeq		码流请求序号,可作为后续操作标识
 @param   IN	szGroupId		组ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopCallExt(int32_t nPDLLHandle, 
														  int32_t nCallSeq, 
														  const char* szGroupId,
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 呼叫邀请
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nCallSeq		码流请求序号,可作为后续操作标识
 @param   IN	pGetInfo		呼叫邀请信息 
 @param   IN    RecordParam		本地音频采集参数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteCallExt(int32_t nPDLLHandle, 
															int32_t& nCallSeq, 
															Get_InviteCall_Info_t* pGetInfo,
															AudioRecrodParam_t* RecordParam,
															void* pUser,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 呼叫被挂断，释放链接
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nCallSeq		码流请求序号,可作为后续操作标识 
 @param   IN	szGroupId		呼叫组ID
 @param   IN	nTid			T ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeCallExt(int32_t nPDLLHandle, 
														 int32_t nCallSeq, 
														 const char* szGroupId,
														 int32_t nTid,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 打开/关闭本地麦克风.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识
 @param   IN	bOpen		    true打开语音，false关闭语音
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioRecord(int32_t nPDLLHandle, 
															  int32_t nSeq,
															  bool bOpen);

/** 打开/关闭本地麦克风.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识
 @param   IN	bOpen		    true打开语音，false关闭语音
 @param   IN	nAudioType		    true打开语音，false关闭语音
 @param   IN	nBitsPerSample		    true打开语音，false关闭语音
 @param   IN	nSamplesPerSec		    true打开语音，false关闭语音
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioRecordExt(int32_t nPDLLHandle, 
															  int32_t nSeq,
															  bool bOpen,long nAudioType, long nBitsPerSample, long nSamplesPerSec);

/** 请求可视对讲
 @param   IN	nPDLLHandle			SDK句柄
 @param   OUT	audioSessionId		音频请求序号,用于关闭对讲
 @param   OUT	videoSessionId		视频请求序号,用于关闭对讲
 @param   OUT	nStartVtCallParm	应答参数，用于本地频频采集和关闭对讲
 @param   IN	nCallType			呼叫类型 0单播；1组播；2可视对讲
 @param   IN	szUserId			呼叫者ID
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartVtCallExt(int32_t nPDLLHandle, 
															 uint32_t &audioSessionId, 
															 uint32_t &videoSessionId, 
															 StartVtCallParam_t * pStartVtCallParm, 
															 dpsdk_call_type_e nCallType, 
															 const char* szUserId, 
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 接受可视对讲邀请
 @param   IN	nPDLLHandle			SDK句柄
 @param   OUT	audioSessionId		音频请求序号,用于关闭对讲
 @param   OUT	videoSessionId		视频请求序号,用于关闭对讲
 @param   IN	nInviteVtCallParam	对讲参数，由DPSDK_SetVtCallInviteCallback获取
 @param   IN	nCallType			呼叫类型 0单播；1组播；2可视对讲
 @param	  IN	hDestWnd			显示窗口句柄
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteVtCallExt(int32_t nPDLLHandle,
															  uint32_t &audioSessionId,
															  uint32_t &videoSessionId,
															  InviteVtCallParam_t* pInviteVtCallParam,
															  dpsdk_call_type_e nCallType,
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearVtCallSession(int32_t nPDLLHandle,
																 uint32_t audioSessionId);

/** 设置回放（本地录像回放、平台/设备录像回放）码流结束回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pFun			回调函数
 @param	  IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataCompleteCallback( IN int32_t nPDLLHandle, 
																			IN fMediaDataComplete pFun, 
																			IN void* pUser );

/** 打开/关闭视频语音.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	bOpen		    true打开语音，false关闭语音
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudio( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN bool bOpen);

/** 以共享方式打开/关闭声音，只管播放本路声音而不去关闭其他路的声音.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	bOpen		    true打开语音，false关闭语音
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenAudioShare(int32_t nPDLLHandle, 
															 int32_t nSeq,
															 bool bOpen);

/** 获取音量
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   OUT	nVol		    音量大小,范围[0,0xFFFF]
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetVolume( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 OUT int32_t &nVol);

/** 调节音量
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	nVol		    音量大小,范围[0,0xFFFF]
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVolume( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN int32_t nVol);

/** 按文件请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByFile( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_File_Info_t* pRecordInfo, 
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按文件回放录像，同时附带码流回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByFileWithCallback( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_File_Info_t* pRecordInfo, 
																   IN void* hDestWnd,
																   IN fStreamCallback fun,
																   IN void* pUser,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 按时间请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByTime( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																   IN void* hDestWnd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 根据码流类型按时间请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param   IN	nStreamType		码流类型
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @param	  IN	nTranMode		传输模式，1:TCP 0:UDP
 @param   IN	bBack			是否倒放
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByStreamType( IN int32_t nPDLLHandle, 
																		OUT int32_t& nPlaybackSeq, 
																		IN Get_RecordStream_Time_Info_t* pRecordInfo,
																		IN dpsdk_stream_type_e nStreamType,
																		IN void* hDestWnd, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT,
																		IN int32_t nTranMode = 1,
																		IN bool bBack = false);

/** 根据码流类型按时间请求录像流，同时附带码流回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param   IN	nStreamType		码流类型
 @param	  IN	hDestWnd		显示窗口句柄
 @param	  IN	fun				码流回调函数
 @param   IN	pUser			回调用户数据
 @param   IN	nTimeout		超时时长，单位毫秒
 @param	  IN	nTranMode		传输模式，1:TCP 0:UDP
 @param   IN	bBack			是否倒放
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByStreamTypeWithCallback( IN int32_t nPDLLHandle, 
																		OUT int32_t& nPlaybackSeq, 
																		IN Get_RecordStream_Time_Info_t* pRecordInfo,
																		IN dpsdk_stream_type_e nStreamType,
																		IN void* hDestWnd,
																		IN fStreamCallback fun,
																		IN void* pUser,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT,
																		IN int32_t nTranMode = 1,
																		IN bool bBack = false);

/** 按时间请求录像流且带码流回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param	  IN	hDestWnd		显示窗口句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByTimeWithCallback( IN int32_t nPDLLHandle, 
																   OUT int32_t& nPlaybackSeq, 
																   IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																   IN void* hDestWnd,
																   IN fStreamCallback fun,
																   IN void* pUser,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按本地文件请求录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param	  IN	hDestWnd		显示窗口句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByLocal( IN int32_t nPDLLHandle, 
																    OUT int32_t& nPlaybackSeq, 
																	IN Get_Record_Local_Info_t* pRecordInfo, 
																	IN void* hDestWnd );

/** 按本地文件请求录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param	  IN	hDestWnd		显示窗口句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
          只支持大华设备
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlaybackByLocalWithCallback( IN int32_t nPDLLHandle, 
																    OUT int32_t& nPlaybackSeq, 
																	IN Get_Record_Local_Info_t* pRecordInfo, 
																	IN void* hDestWnd,
																	IN fStreamCallback fun,
																	IN void* pUser);


/** 暂停录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PausePlaybackBySeq( IN int32_t nPDLLHandle, 
																  IN int32_t nPlaybackSeq, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 定位录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN    seekBegin       定位起始值.文件模式时,是定位处的文件大小值;时间模式时,是定位处的时间值;
 @param   In    seekEnd         定位结束值.文件模式时,无意义;时间模式时,是期待的结束时间.
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
          seekBegin在文件模式下的计算方式可以是:(文件大小值)/100*(定位处相对文件的百分比)
		  适用于远程录像回放，且只支持大华设备
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekPlaybackBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nPlaybackSeq, 
																 IN uint64_t seekBegin,
																 IN uint64_t seekEnd, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 定位本地录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nPos        	位置百分比，0-100 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekLocalPlaybackBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nPos,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 恢复录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumePlaybackBySeq( IN int32_t nPDLLHandle, 
																   IN int32_t nPlaybackSeq, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置录像速率.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN    nSpeed,         录像流回放速度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPlaybackSpeed( IN int32_t nPDLLHandle, 
																IN int32_t nPlaybackSeq, 
																IN dpsdk_playback_speed_e nSpeed, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置倒放录像速率.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN    nSpeed,         录像流回放速度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBackwardPlaybackSpeed( IN int32_t nPDLLHandle, 
																		IN int32_t nPlaybackSeq, 
																		IN dpsdk_playback_speed_e nSpeed, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlaybackBySeq( IN int32_t nPDLLHandle, 
																 IN int32_t nPlaybackSeq, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按通道关闭录像.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId   	通道编号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlaybackByCameraId( IN int32_t nPDLLHandle, 
																	  IN const char* szCameraId, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** 关闭录像.同步等待服务应答（需要DSS平台支持，否则接口会超时）
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopPlaybackBySeq( IN int32_t nPDLLHandle, 
																		IN int32_t nPlaybackSeq, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按通道关闭录像.同步等待服务应答（需要DSS平台支持，否则接口会超时）
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId   	通道编号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopPlaybackByCameraId( IN int32_t nPDLLHandle, 
																			IN const char* szCameraId, 
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取当前回放码流播放时间.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nFramTime	    返回的时间值
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFrameTime( IN int32_t nPDLLHandle,
															IN int32_t nPlaybackSeq,
															OUT uint64_t& nFramTime );
/** 获取本地录像当前播放进度.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nPos	        播放进度
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPlayPos( IN int32_t nPDLLHandle,
														  IN int32_t nPlaybackSeq,
														  OUT int32_t& nPos );
/** 抓图.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	nPicType		图片类型
 @param   IN	szFilename		文件名
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PicCapture( IN int32_t nPDLLHandle, 
														  IN int32_t nSeq, 
														  IN dpsdk_pic_type_e nPicType, 
														  IN const char* szFilename );

/** 实时录制视频
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	nDataType		*- 0 表示原始视频流;  *- 1 表示转换成AVI格式, 只对大华码流有效  *- 2 表示转换成ASF格式, 只对大华码流有效
 @param   IN	szFilename		文件名
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecord( IN int32_t nPDLLHandle, 
														   IN int32_t nSeq,  
														   IN char* szFilename,
														   IN int32_t nDataType = 0 );

/** 实时录制视频录像为FLV格式
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	szFilename		文件名
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordToFLV( IN int32_t nPDLLHandle, 
														        IN int32_t nSeq,  
														        IN char* szFilename );

/** 实时录制视频可定制录像文件格式
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	nFileType		录像文件格式
 @param   IN	szFilename		文件名

 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordEx( IN int32_t nPDLLHandle, 
														     IN int32_t nSeq,  
														     IN char* szFilename,
														     IN int32_t nFileType);

/** 停止实时录制视频
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecord( IN int32_t nPDLLHandle, 
														  IN int32_t nSeq);

/** 停止实时录制视频
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordToFLV( IN int32_t nPDLLHandle, 
														       IN int32_t nSeq);

/** 停止实时录制视频
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordEx( IN int32_t nPDLLHandle, 
														    IN int32_t nSeq);


/** 设置OSd文本信息
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	szOsdInfo		Osd信息，不得超过15个字节,一个汉字占用两个字节
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetOsdTxt( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 IN char* szOsdInfo);

/** 设置OSd文本信息,同时可以设置字体，颜色，大小，处于窗口的位置
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	szOsdInfo		Osd信息，不得超过15个字节,一个汉字占用两个字节
 @param   IN	nWindowHeight;	窗口高度，单位像素
 @param   IN	nWindowWeight;	窗口宽度，单位像素
 @param   IN	fFaceName;		字体样式“宋体”“黑体”“微软雅黑”等
 @param   IN	fHeight;		字体高度 1~100，占用窗口高度的百分比
 @param   IN	fWeight;		字体宽度 1~100，占用窗口宽度的百分比
 @param   IN	left;			字体最左边位置 1~100，占用窗口宽度的百分比
 @param   IN	top;			字体最上方位置 1~100，占用窗口高度的百分比
 @param   IN	fColor;			字体颜色0黑色，255(0x0000FF)红色，16777215(0xFFFFFF)白色
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetOsdTxtEx(int32_t nPDLLHandle, 
														  int32_t nSeq,
														  const char* szOsdInfo,
														  int nWindowHeight,
														  int nWindowWeight,
														  const char* fFaceName,
														  int fHeight,
														  int fWeight,
														  int left,
														  int top,
														  unsigned long fColor);

/**清除osd信息
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CleanUpOsdInfo( IN int32_t nPDLLHandle, 
														      IN int32_t nSeq);

/** 获取视频属性
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   OUT	videoColorInfo	视频属性
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetColor( IN int32_t nPDLLHandle, 
														IN int32_t nSeq,
														OUT Video_Color_Info_t &videoColorInfo);

/** 调整视频属性
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @param   IN	videoColorInfo	视频属性
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AdjustColor( IN int32_t nPDLLHandle, 
														   IN int32_t nSeq,
														   IN Video_Color_Info_t videoColorInfo);

/**单帧回放
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PlayOneByOne( IN int32_t nPDLLHandle, 
															IN int32_t nSeq);

/**单帧后退
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PlayOneByOneBack( IN int32_t nPDLLHandle, 
																IN int32_t nSeq);

/**恢复正常播放
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号 
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Play( IN int32_t nPDLLHandle, 
													IN int32_t nSeq);

/** 停止对讲
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    nTalkSeq	    对讲请求序号
 @param   IN    szCameraId      设备ID
 @param   IN    nTalkType       对讲类型
 @param   IN    nTimeout        超时时长，单位毫秒 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopTalk( IN int32_t  nPDLLHandle, 
													    IN int32_t  nTalkSeq,
													    IN const    char * szDeviceId,
													    IN int32_t  nTalkType,
													    IN int32_t  nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 根据通道ID录像
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId   	通道ID 
 @param   IN	szFileName      文件名
 @param   OUT   nSeq            录像请求序列号	
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordByCameraId(IN int32_t nPDLLHandle, 
																	IN const char* szCameraId, 
																	IN const char* szFileName, 
																	OUT int32_t &nSeq,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 停止根据通道ID录像
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq		录像请求序号,
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordCameraIdBySeq(IN int32_t nPDLLHandle, 
																	  IN int32_t nSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**绘图回调
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nSeq   			请求序号
 @param   IN    DrawFun         回调函数定义
 @param   IN    pUser           回调函数参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_RegisterDrawFun(IN int32_t nPDLLHandle, 
															  IN int32_t nSeq,
															  IN fDrawFunCallback fDrawFun,
															  void *pUser);

/**设置录像文件完成回调。注：必须先设置回调
@param   IN	nPDLLHandle		SDK句柄
@param   IN	fDownloadFinishedCallback	回调函数
@param   IN	pUser		                用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadFinishedCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadFinishedCallback cb, 
																		  IN void *pUser);

/**设置录像文件进度回调。注：必须先设置回调
@param   IN	nPDLLHandle		SDK句柄
@param   IN	fDownloadProgressCallback	回调函数
@param   IN	pUser		                用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadProgressCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadProgressCallback cb, 
																		  IN void *pUser);

/**设置录像文件下载网络错误回调。注：必须先设置回调
@param   IN	nPDLLHandle		SDK句柄
@param   IN	fDownloadNetErrorCallback	回调函数
@param   IN	pUser		                用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadNetErrorCallback(IN int32_t nPDLLHandle, 
																		  IN fDownloadNetErrorCallback cb, 
																		  IN void *pUser);

/**按文件索引号下载录像文件
@param   IN	  nPDLLHandle		SDK句柄
@param   OUT  nDownloadSeq	下载标志序列号
@param   IN	  szCameraId	通道ID
@param   IN	  pSingleRecord	录像文件信息，GetRecordInfo 的输出值
@param   IN	  szFileName	录像保存文件名
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByFile( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN Single_Record_Info_t* pSingleRecord,
																   IN const char *szFileName,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**按文件索引号下载录像文件
@param   IN	  nPDLLHandle		SDK句柄
@param   OUT  nDownloadSeq	下载标志序列号
@param   IN	  szCameraId	通道ID
@param   IN	  pSingleRecord	录像文件信息，GetRecordInfo 的输出值
@param   IN	  szFileName	录像保存文件名
@param   IN   nFileType     录像保存文件类型，支持FLV，MP4
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByFileEx( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN Single_Record_Info_t* pSingleRecord,
																   IN const char *szFileName,
																   IN int32_t nFileType,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**停止录像下载
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecord( IN int32_t nPDLLHandle, 
																 IN int32_t nDownloadSeq );

/**停止录像下载,同步等待服务应答（需要DSS平台支持，否则接口会超时）
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecord( IN int32_t nPDLLHandle, 
																		IN int32_t nDownloadSeq,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT  );

/**停止录像下载
@param   IN	nPDLLHandle		SDK句柄
@param   IN	szFileName	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																 IN const char* szFileName );

/**停止录像下载，同步等待服务应答（需要DSS平台支持，否则接口会超时）
@param   IN	nPDLLHandle		SDK句柄
@param   IN	szFileName	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																					IN const char* szFileName,
																					IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**停止录像下载,返回录像数量
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@param   OUT nPartitionNum  生成的录像的数量
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDownloadRecordAndGetFileNum( IN int32_t nPDLLHandle, 
																 IN int32_t nDownloadSeq,
																 OUT int32_t& nPartitionNum);

/**停止录像下载,返回录像数量，同步等待服务应答（需要DSS平台支持，否则接口会超时）
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@param   OUT nPartitionNum  生成的录像的数量
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroStopDownloadRecordAndGetFileNum( IN int32_t nPDLLHandle, 
																					  IN int32_t nDownloadSeq,
																					  OUT int32_t& nPartitionNum,
																					  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**获取录像下载位置
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@param   OUT	nPos	    位置点 0--100
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDownloadPos(IN int32_t nPDLLHandle, 
															 IN int32_t nDownloadSeq, 
															 OUT int32_t &nPos);

/**按时间下载录像
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@param   IN	  szCameraId	通道ID
@param   IN	  nSourceType	录像源类型
@param   IN	  uBeginTime	开始时间
@param   IN	  uEndTime	    结束时间
@param   IN	  szFileName	录像保存文件名
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByTime( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN dpsdk_recsource_type_e nSourceType,
																   IN uint64_t uBeginTime,
																   IN uint64_t uEndTime,
																   IN const char *szFileName,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**按时间下载录像
@param   IN	 nPDLLHandle	SDK句柄
@param   IN	 nDownloadSeq	索引号
@param   IN	  szCameraId	通道ID
@param   IN	  nSourceType	录像源类型
@param   IN	  uBeginTime	开始时间
@param   IN	  uEndTime	    结束时间
@param   IN	  szFileName	录像保存文件名
@param   IN   nFileType     录像保存文件类型，支持FLV和MP4
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DownloadRecordByTimeEx( IN int32_t nPDLLHandle, 
																   OUT int32_t& nDownloadSeq, 
																   IN const char *szCameraId,
																   IN dpsdk_recsource_type_e nSourceType,
																   IN uint64_t uBeginTime,
																   IN uint64_t uEndTime,
																   IN const char *szFileName,
																   IN int32_t nFileType,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**暂停下载录像
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseDownloadRecord( IN int32_t nPDLLHandle, 
																	 IN int32_t nDownloadSeq, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**暂停下载录像
@param   IN	nPDLLHandle		SDK句柄
@param   IN	szFileName	    文件名
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																  IN const char* szFileName, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**继续下载录像
@param   IN	nPDLLHandle		SDK句柄
@param   IN	nDownloadSeq	索引号
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeDownloadRecord( IN int32_t nPDLLHandle, 
																	 IN int32_t nDownloadSeq, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**继续下载录像
@param   IN	nPDLLHandle		SDK句柄
@param   IN	szFileName  	文件名
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeDownloadRecordByFileName( IN int32_t nPDLLHandle, 
																   IN const char* szFileName, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**
获取文件的总时长，单位：秒数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nTotalTime	通道ID
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFileTotalTime(IN int32_t nPDLLHandle, 
															   IN int32_t nSeq, 
															   OUT int32_t &nTotalTime);

/**
获取文件的当前播放点，单位：秒数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nPlayedTime	已播放时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFilePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																OUT int32_t &nPlayedTime);

/**
获取远程录像的当前播放点，单位：秒数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nPlayedTime	已播放时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRemotePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																OUT int32_t &nPlayedTime);

/**
设置文件的当前播放点， 单位：秒数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nPlayedTime	设置的播放时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetFilePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																IN int32_t nPlayedTime);

/**
设置远程的当前播放点， 单位：秒数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nPlayedTime	设置的播放时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRemotePlayedTime(IN int32_t nPDLLHandle, 
																IN int32_t nSeq, 
																IN int32_t nPlayedTime);

/**
分析并根据不同厂商，写入对应厂商可播放的原始码流
@param   INOUT  hHandle   	解码用指针，第一次设为NULL传入，之后多次写数据时沿用
@param   INOUT  nProviderType	播放序列号，第一次设为0传入，之后多次写数据时沿用
@param   IN   fp            文件指针
@param   IN   szData        要写入的数据
@param   IN   nDataLen      数据长度
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteDataByAnalysis(INOUT void*& hHandle,
																  INOUT int32_t& nProviderType,
																  IN void* fp,
																  IN char* szData,
																  IN int32_t nDataLen);

/**
设置对应某个nSeq的播放的同时返回码流的回调函数
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  fun       	回调函数
@parm    IN   pUser         用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKStreamCBPFBySeq(IN int32_t nPDLLHandle,
																	  IN int32_t nSeq,
																	  IN fStreamCallback fun,
																	  IN void* pUser);

/**
设置对应某个nSeq的返回下载数据回调
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  fun       	回调函数
@param   IN   pUser         用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKDownloadDataCallbackBySeq(IN int32_t nPDLLHandle,
																			    IN int32_t nSeq,
																			    IN fStreamCallback fun,
																			    IN void* pUser);

/**
设置定时对所有回放进度进行回调
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  fun        	回调函数
@param   IN	  pUser     	用户参数
@param   IN   nInterval     时间间隔
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPlaybackPosCallback(IN int32_t nPDLLHandle,
																	 IN fPlaybackPosTimerCallback fun,
																	 IN void* pUser,
																	 IN int32_t nInterval = 3000);

/**
设置某个音频声道打开或关闭
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nChannel  	声道序号
@param   IN   bOpen         是否打开
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetAudioChannel(IN int32_t nPDLLHanle,
															  IN int32_t nSeq,
															  IN int32_t nChannel,
															  IN bool bOpen);

/**
获取声道状态
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nChannel   	声道序号
@param   IN   bOpen         是否打开
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioChannelState(IN int32_t nPDLLHanle,
															       IN int32_t nSeq,
															       IN int32_t nChannel,
															       OUT bool& bOpen);

/**
获取声道数量
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  nChannelNum	声道数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioChannels(IN int32_t nPDLLHanle,
															   IN int32_t nSeq,
															   OUT int32_t& nChannelNum);

/**
文件剪切
只对大华文件有效
@param   IN	  sSrcFile	    源文件
@param   IN	  sDestFile     目标文件
@param   IN	  nBeginTime	开始时间
@param   IN   nEndTime      结束时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_FileCut( IN const char *sSrcFile,
													   IN const char *sDestFile,
													   IN long nBeginTime,
													   IN long nEndTime );

/**
设置下载文件分多文件保存，格式为 文件名_(i).后缀(i=1,2,3,...)
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  szFileNameWithOutExt	文件路径名，不包括后缀
@param   IN   szExt         后缀名,以“.”开头，如“.dav”
@param   IN   nFileLimit    每个文件的大小，单位B
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDownloadPartition( IN int32_t nPDLLHandle, 
																    IN int32_t nSeq, 
																	IN const char *szFileNameWithOutExt, 
																	IN const char *szExt, 
																	IN int32_t nFileLimit );

/**
获取是否为本地播放
@param   IN	  nPDLLHandle	SDK句柄
@param   IN	  nSeq        	播放序列号
@param   IN	  bLocalPlay	是否为本地播放
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_IsLocalPlay( IN int32_t nPDLLHandle, IN int32_t nSeq, OUT bool& bLocalPlay );


/**
清理某个实例所有正在使用的资源，包括打开的视频、正在下载的录像、打开的语音等
@param   IN	  nPDLLHandle	SDK句柄
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTasksByDLLHandle( IN int32_t nPDLLHandle);

/** 获取实况YUV码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回到用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealYUVStream( IN int32_t nPDLLHandle, 
																OUT int32_t& nRealSeq, 
																IN Get_RealStream_Info_t* pGetInfo, 
																IN fMediaDataYUV pFun, 
																IN void* pUser, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭实况YUV码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRealYUVStreamBySeq( IN int32_t nPDLLHandle,
																		IN int32_t nRealSeq,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 开始平台录像，持续一段时间后自动停止
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   IN    nDuration       持续时间，单位毫秒
@param   IN    streamType      实时码流类型
@param   IN    nTimeout        超时时长，单位毫秒
@return  函数返回错误类型，参考dpsdk_retval_e
@remark  
         若在这段时间内，又调用本接口，且nPDLLHandle值一致，那么持续时间延长至(最后一次调用的时间点 + 最后一次调用的nDuration)。
*/
/*DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlatformReocrdForAPeriod(IN int32_t nPDLLHandle,
																			IN const char *szCameraId,
																			IN int32_t nDuration,
																			IN dpsdk_encdev_stream_e streamType = DPSDK_CORE_STREAM_MAIN,
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );*/

/** 根据Seq从下载信息中获取下载文件名
@param   IN    nPDLLHandle     SDK句柄
@param   IN    nSeq            下载序号
@param   OUT   szFileName      文件名
@param   IN    nBufSize        szFileName的缓冲区大小
@return  函数返回错误类型，参考dpsdk_retval_e
@remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFileNameFormDownloadInfoBySeq(IN int32_t nPDLLHandle,
																			   IN int32_t nSeq,
																			   OUT char* szFileName,
																			   IN int32_t nBufSize);

/** 获取分辨率
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   OUT	nW				图片宽度
 @param   OUT	nH				图片高度
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPictureSize( IN int32_t nPDLLHandle, 
														 IN int32_t nSeq,
														 OUT long* pnW,
														 OUT long* pnH);

/** 获取实时码率
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   OUT	pBitRate		实时码率
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  只对大华码流有效
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealFrameBitRate( IN int32_t nPDLLHandle, 
																  IN int32_t nSeq,
																  OUT double *pBitRate);

/** 局部放大显示
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param		IN	nRegionNum		显示区域序号,0~(MAX_DISPLAY_WND-1),如果为0,则将设置的区域显示在主窗口中.
 @param		IN	pSrcRect		局部显示区域
 @param		IN	hDestWnd		显示窗口句柄
 @param		IN	bEnable			打开(设置)或关闭显示区域
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	只对大华码流有效
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDisplayRegion(	int32_t nPDLLHandle, 
																int32_t nSeq,
																int32_t nRegionNum, 
																int32_t nX,
																int32_t nY,
																int32_t nWidth,
																int32_t nHeight,
																void* hDestWnd, 
																bool bEnable);
/** 设置码流第一帧数据回调
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	pFun			第一帧数据回调函数指针
 @param		IN	UserParam		用户参数.
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	实时，回放都会回调通知，收到通知，表示vaxplayer播放库初始化成功
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataFirstFrameCallback(fMediaDataFirstFrameCallback pFun, void* UserParam);

/** 设置码流断流回调
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	pFun			码流断开回调函数指针
 @param		IN	UserParam		用户参数.
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	实时，回放都会回调通知，收到通知，表示vaxplayer播放库初始化成功
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataDisconnectCallback(fMediaDataDisconnectCallback pFun, void* UserParam);

/** 设置码流断流超时时间
 @param		IN	nIntervalTime	码流断开定时器时间间隔(单位毫秒)，默认30*1000
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	实时，回放都会回调通知，收到通知，表示vaxplayer播放库初始化成功
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetMediaDataDisconnectTimer(uint32_t nIntervalTime);


/** 异步云台方向控制
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	nPtzFlag		云台方向控制标记
 @param		IN	pDirectInfo		云台方向控制信息 	
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncPtzDirection(IN int32_t nPDLLHandle, 
																IN int32_t& nPtzFlag,
																IN Ptz_Direct_Info_t* pDirectInfo);

/** 设置异步云台操作结果回调
 @param		IN	pFun			云台方向控制回调函数指针
 @param		IN	UserParam		用户参数.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPtzDirectionResultCallback(fDPSDKPtzDirectionCallback fun, void *pUser);

/** 获取本地录像文件开始时间和结束时间.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szFileName		文件名 
 @param	  OUT	uBeginTime		录像开始时间
 @param	  OUT	uBeginTime		录像结束时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPlaybackTimeByLocal( IN int32_t nPDLLHandle, 
																	IN const char* szFilename,
																	OUT uint64_t& uBeginTime,
																	OUT uint64_t& uEndTime,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置码流源数据分析完的数据回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pFun			回调函数
 @param	  IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKDemuxDecCallback( IN int32_t nPDLLHandle, 
																		IN fDPSDKDemuxDecCallback pFun, 
																		IN void* pUser );

/** 通过智能报警图片获取智能规则线名称.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szFilename		回调函数
 @param	  IN	nAlarmType		智能报警类型
 @param	  OUT	szIvsRuleName	智能规则线名称
 @param	  IN	nNameLen		智能规则线名称长度
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsRuleName(IN int32_t nPDLLHandle, 
															 IN const char* szFilename,
															 IN int32_t nAlarmType, 
															 OUT char* szIvsRuleName,
															 IN int32_t nNameLen);

//////////////////////////////////////////////////////////////////////////
// 以下接口废弃
DPSDK_DLL_DEPRECATED int32_t DPSDK_CALL_METHOD DPSDK_SnapPictureByCameraId(IN int32_t nPDLLHandle, 
																		   IN const char* szCameraId, 
																		   IN dpsdk_pic_type_e nPicType, 
																		   IN const char* szFileName, 
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif
