#ifndef INCLUDED_DPSDK_CORE_TALK_H
#define INCLUDED_DPSDK_CORE_TALK_H

/** 语音对讲失败后参数回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKTalkParamCallback(IN int32_t nPDLLHandle,
																		IN fDPSDKTalkParamCallback fun, 
																		IN void* pUser);


/** 开始广播（打开广播语音）
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nBroadcastSeq	码流请求序号,可作为后续操作标识 
 @param   IN	szJson			码流请求信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartBroadcast( int32_t nPDLLHandle, 
																  int32_t* nBroadcastSeq, 
																  const char* szJson,
																  fMediaDataCallback pFun, 
																  void* pUser, 
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭广播
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szJson			请求信息 
 @param   IN	nBroadcastSeq	码流请求序号
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseBroadcastStream( int32_t nPDLLHandle, 
															        const char* szJson, 
																	int32_t nBroadcastSeq,
															        int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 获取语音码流
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nTalkSeq		码流请求序号,可作为后续操作标识 
 @param   IN	pGetInfo		码流请求信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTalkStream( IN int32_t nPDLLHandle, 
														     OUT int32_t& nTalkSeq, 
														     IN Get_TalkStream_Info_t* pGetInfo, 
														     IN fMediaDataCallback pFun, 
														     IN void* pUser, 
														     IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 按请求序列停止语音码流的获取
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nRealSeq		码流请求序号,可作为后续操作标识 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTalkStreamBySeq( IN int32_t nPDLLHandle, 
															        IN int32_t nRealSeq, 
															        IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 按CameralId停止语音码流获取.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		通道编号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTalkStreamByCameralId( IN int32_t nPDLLHandle, 
															              IN const char* szCameraId,
															              IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取语音采集回调信息
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pCallBackFun	回调函数
 @param   OUT	pUserParam   	回调函数用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSdkAudioCallbackInfo(IN int32_t nPDLLHandle,
															          OUT void* &pCallBackFun,
																      OUT AudioUserParam_t* &pUserParam);



#endif