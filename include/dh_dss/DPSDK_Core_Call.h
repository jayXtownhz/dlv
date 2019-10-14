#ifndef INCLUDED_DPSDK_CORE_CALL_H
#define INCLUDED_DPSDK_CORE_CALL_H

//////////////////////////////////////////////////////////////////////////
// 集群对讲业务接口 开始

DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetStartCallParamCallback(int32_t nPDLLHandle,  
																		fStartCallParamCallBack pFun, 
																		void* pUser);

/** 打开呼叫
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nCallSeq		码流请求序号,可作为后续操作标识
 @param   IN	nCallType		呼叫类型 0单播；1组播；2可视对讲
 @param   IN	szGroupId		呼叫组ID
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartCall(int32_t nPDLLHandle, 
														int32_t& nCallSeq, 
														dpsdk_call_type_e nCallType,
														const char* szGroupId,
														fMediaDataCallback pFun, 
														void* pUser, 
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 关闭呼叫
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nCallSeq		码流请求序号,可作为后续操作标识
 @param   IN	szGroupId		组ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopCall(int32_t nPDLLHandle, 
													   int32_t nCallSeq, 
													   const char* szGroupId,
													   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 设置呼叫邀请参数回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_Create成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetInviteCallParamCallBack(int32_t nPDLLHandle,  
																		 fInviteCallParamCallBack pFun, 
																		 void* pUser);

/** 呼叫邀请
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nCallSeq		码流请求序号,可作为后续操作标识
 @param   IN	pGetInfo		呼叫邀请信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteCall(int32_t nPDLLHandle, 
														 int32_t& nCallSeq, 
														 Get_InviteCall_Info_t* pGetInfo, 
														 fMediaDataCallback pFun, 
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
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeCall(int32_t nPDLLHandle, 
													  int32_t nCallSeq, 
													  const char* szGroupId,
													  int32_t nTid,
													  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 变更呼叫状态
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nCallSeq		码流请求序号,可作为后续操作标识 
 @param   IN	szGroupId		呼叫组ID
 @param   IN	nCallStatus		呼叫状态
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModifyCallStatus(	int32_t nPDLLHandle, 
																int32_t nCallSeq, 
																const char* szGroupId,
																dpsdk_call_status_e nCallStatus,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取语音发送函数指针
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pCallBackFun	回调函数
 @param   OUT	pUserParam   	回调函数用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAudioSendFunCallBack(	int32_t nPDLLHandle,
																		void** pCallBackFun,
																		AudioUserParam_t** pUserParam);

/** 发送消息给scs服务
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szGroupId			呼叫组ID
 @param		IN		szStrText			发送的文本内容
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @sample
	DPSDK_SendScsMsg(m_nPDLLHandle, "test", "test", DPSDK_CORE_DEFAULT_TIMEOUT);
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendScsMsg(IN int32_t nPDLLHandle,
														 IN const char* szGroupId, 
														 IN const char* szStrText,
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取本地IP
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nLocalIP		本地IP
 @param   IN	nLen   			IP的长度，IP的最大长度46
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLocalIp(int32_t nPDLLHandle,
														 char* nLocalIP,
														 int32_t nLen);

//集群对讲业务接口 结束


//可视对讲业务接口 开始

/** 设置可视对讲呼叫邀请参数回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVtCallInviteCallback(int32_t nPDLLHandle,
																	  fDPSDKInviteVtCallParamCallBack pFun,
																	  void* pUser);

/** 设置响铃参数通知回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRingCallback(int32_t nPDLLHandle,
															  fDPSDKRingInfoCallBack pFun,
															  void* pUser);

/** 设置可视对讲繁忙状态通知回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusyVtCallCallback(int32_t nPDLLHandle,
																	fDPSDKBusyVtCallCallBack pFun,
																	void* pUser);


/** 请求可视对讲
 @param   IN	nPDLLHandle			SDK句柄
 @param   OUT	audioSessionId		音频请求序号,用于关闭对讲
 @param   OUT	videoSessionId		视频请求序号,用于关闭对讲
 @param   OUT	nStartVtCallParm	应答参数，用于本地频频采集和关闭对讲
 @param   IN	nCallType			呼叫类型 0单播；1组播；2可视对讲
 @param   IN	szUserId			呼叫者ID
 @param   IN    pFun				码流回调函数				
 @param   IN    pCBParam			码流回调用户参数
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartVtCall(int32_t nPDLLHandle, 
														  uint32_t &audioSessionId, 
														  uint32_t &videoSessionId, 
														  StartVtCallParam_t * nStartVtCallParm, 
														  dpsdk_call_type_e nCallType, 
														  const char* szUserId, 
														  fMediaDataCallback funCB, 
														  void* pCBParam, 
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 发送取消可视对讲
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szUserId			呼叫者ID
 @param   IN	audioSessionId		语音请求序列号
 @param   IN	videoSessionId		视频请求序列号
 @param   IN    nCallId				呼叫ID			
 @param   IN    m_dlgId				回话ID
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCancelVtCall(int32_t nPDLLHandle,
															   const char* szUserId,
															   uint32_t audioSessionId,
															   uint32_t videoSessionId,
															   int callId,
															   int dlgId,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 请求可视对讲成功后，停止可视对讲
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szUserId			呼叫者ID
 @param   IN	audioSessionId		语音请求序列号
 @param   IN	videoSessionId		视频请求序列号
 @param   IN    nCallId				呼叫ID			
 @param   IN    m_dlgId				回话ID
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopVtCall(int32_t nPDLLHandle,
														 const char* szUserId,
														 uint32_t audioSessionId,
														 uint32_t videoSessionId,
														 int m_callId = 0,
														 int m_dlgId = 0,
														 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 接受可视对讲邀请
 @param   IN	nPDLLHandle			SDK句柄
 @param   OUT	audioSessionId		音频请求序号,用于关闭对讲
 @param   OUT	videoSessionId		视频请求序号,用于关闭对讲
 @param   IN	nInviteVtCallParam	对讲参数，由DPSDK_SetVtCallInviteCallback获取
 @param   IN	nCallType			呼叫类型 0单播；1组播；2可视对讲
 @param   IN    pFun				码流回调函数				
 @param   IN    pCBParam			码流回调用户参数
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_InviteVtCall(int32_t nPDLLHandle,
														   uint32_t &audioSessionId,
														   uint32_t &videoSessionId,
														   InviteVtCallParam_t* nInviteVtCallParam,
														   dpsdk_call_type_e nCallType,
														   fMediaDataCallback funCB,
														   void* pCBParam,
														   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 接受邀请后，挂断可视对讲
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szUserId			呼叫者ID
 @param   IN	audioSessionId		语音请求序列号
 @param   IN	videoSessionId		视频请求序列号
 @param   IN    nTid				
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ByeVtCall(int32_t nPDLLHandle,
														const char* szUserId,
														uint32_t audioSessionId,
														uint32_t videoSessionId,
														int nTid,
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 拒绝可视对讲邀请
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szUserId			呼叫者ID
 @param   IN    nCallId				呼叫ID				
 @param   IN    nTid				
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendRejectVtCall(int32_t nPDLLHandle,
															   const char* szUserId,
															   int nCallId,
															   int dlgId,
															   int nTid,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 与可视对讲服务json交互
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	nSendjson			发送json
 @param   OUT   nRecivejson			应答json								
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_sendVtCallInfo(int32_t nPDLLHandle,
															 const char* nSendjson,
															 char* nRecivejson,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 修改可视对讲状态
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szUserId			呼叫者ID
 @param   IN	nCallStatus			呼叫状态
 @param   IN	audioSessionId		语音请求序列号
 @param   IN	videoSessionId		视频请求序列号		
 @param   IN	nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModifyVtCallStatus(int32_t nPDLLHandle,
																 const char* szUserId,
																 dpsdk_call_status_e nCallStatus,
																 uint32_t audioSessionId,
																 uint32_t videoSessionId,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

///** 获取语音发送函数指针
// @param   IN	nPDLLHandle		SDK句柄
// @param   OUT	AudioSendFun	语音发送函数指针，参见fAudioDataCallback
// @param   OUT	pUserParam   	回调函数用户参数
// @return  函数返回错误类型，参考dpsdk_retval_e
// @remark		
//*/
//DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetVtCallAudioSendFunCallBack(int32_t nPDLLHandle,
//																			void* &AudioSendFun,
//																			AudioUserParam_t* &pUserParam);

//可视对讲业务接口 开始

#endif