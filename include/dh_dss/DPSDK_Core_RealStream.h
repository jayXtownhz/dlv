#ifndef INCLUDED_DPSDK_CORE_REALSTREM_H
#define INCLUDED_DPSDK_CORE_REALSTREM_H

//#include "DPSDK_Core_Define.h"

/** 获取实况码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStream( IN int32_t nPDLLHandle, 
															 OUT int32_t& nRealSeq, 
															 IN Get_RealStream_Info_t* pGetInfo, 
															 IN fMediaDataCallback pFun, 
															 IN void* pUser, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取实况码流，转换为指定码流再回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息
 @param   IN    scType          码流转换的目的类型
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamEx( IN int32_t nPDLLHandle, 
															   OUT int32_t& nRealSeq, 
															   IN Get_RealStream_Info_t* pGetInfo,
															   IN dpsdk_stream_convertor_type_e scType,
															   IN fMediaDataCallback pFun, 
															   IN void* pUser, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按请求序号关闭码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRealStreamBySeq( IN int32_t nPDLLHandle, 
																	IN int32_t nRealSeq, 
																    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取零通道多画面拼接实时码流.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamPreview( int32_t nPDLLHandle,
																   int& nRealSeq, 
																   Get_RealStream_Info_t* pGetInfo,
																   int32_t nStartChannelIndex, 
																   fMediaDataCallback pFun, 
																   void* pUser, 
																   int nTimeout );


/** 获取DSS平台对外的媒体流URL
 @param   IN	nPDLLHandle						SDK句柄
 @param   INOUT	pExternalRealStreamUrlInfo		查询实时流Url信息
 @param   IN	nTimeout						超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetExternalRealStreamUrl( IN int32_t nPDLLHandle, 
 																		 INOUT Get_ExternalRealStreamUrl_Info_t* pExternalRealStreamUrlInfo, 
 																		 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsRuleSzLen(int32_t nPDLLHandle,
														 const char* szCameraId, 
														 int32_t nRealSeq,
														 int32_t* pSzLen,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsRule(int32_t nPDLLHandle,
														 const char* szCameraId, 
														 int32_t nRealSeq,
														 char*   szIvsRule,
														 int32_t iSzLen,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

 /** 获取实时流的URL
 @param   IN	nPDLLHandle				SDK句柄
 @param   INOUT	pRealStreamUrlInfo		查询实时流Url信息
 @param   IN	nTimeout				超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRealStreamUrl( IN int32_t nPDLLHandle, 
																INOUT Get_RealStreamUrl_Info_t* pRealStreamUrlInfo, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取实况码流，转换为指定码流保存到文件，只支持大华设备
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息
 @param   IN    scType          码流转换的目的类型
 @param   IN    pFilePath		文件保存路径
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveRealStream( IN int32_t nPDLLHandle, 
															  OUT int32_t& nRealSeq, 
															  IN Get_RealStream_Info_t* pGetInfo,
															  IN dpsdk_stream_convertor_type_e scType,
															  IN const char* pFilePath, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 锁定/解锁摄像头
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		通道ID
 @param   IN    lockType        锁定/解锁类型
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LockVideo( IN int32_t nPDLLHandle, 
														 IN const char* szCameraId, 
														 IN dpsdk_video_locktype_e lockType, 
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif