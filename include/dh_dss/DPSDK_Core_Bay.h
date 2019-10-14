#ifndef INCLUDED_DPSDK_CORE_BAY_H
#define INCLUDED_DPSDK_CORE_BAY_H

//////////////////////////////////////////////////////////////////////////
// 卡口业务接口 开始

/** 设置违章报警回调
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKTrafficAlarmCallback( IN int32_t nPDLLHandle,
																			IN fDPSDKTrafficAlarmCallback fun,
																			IN void* pUser);

/** 车辆违章图片信息写入
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pGetInfo		详细违章信息,参考Traffic_Violation_Info_t
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteTrafficViolationInfo(IN int32_t nPDLLHandle,
																		INOUT Traffic_Violation_Info_t* pGetInfo,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 车辆违章图片信息查询
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pGetInfo		详细违章信息,参考Traffic_Violation_Info_t
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTrafficViolationInfo(IN int32_t nPDLLHandle,
																	  INOUT Traffic_Violation_Info_t* pGetInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 设置流量上报回调.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetTrafficFlowCallback(IN int32_t nPDLLHandle,
					   													     IN fDPSDKGetTrafficFlowCallback fun,
																			 IN void* pUser);
/** 设置车道流量状态上报回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetDevTrafficFlowCallback(IN int32_t nPDLLHandle,
																				IN fDPSDKGetDevTrafficFlowCallback fun,
																				IN void* pUser);

/** 订阅流量上报.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pGetInfo		订阅设备流量上报请求信息，参考Subscribe_Traffic_Flow_Info_t
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeTrafficFlow( IN int32_t nPDLLHandle,
																	IN Subscribe_Traffic_Flow_Info_t* pGetInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 设置卡口过车信息（不带图片）上报回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  设置回调函数以后再订阅DPSDK_SubscribeBayCarInfo
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetBayCarInfoCallback(IN int32_t nPDLLHandle,
																			IN fDPSDKGetBayCarInfoCallback fun,
																			IN void* pUser);

/** 设置卡口过车信息（不带图片）上报回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  设置回调函数以后再订阅DPSDK_SubscribeBayCarInfo
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetBayCarInfoCallbackEx(IN int32_t nPDLLHandle,
																			IN fDPSDKGetBayCarInfoCallbackEx fun,
																			IN void* pUser);


/** 订阅卡口过车信息上报.
 @param   IN    nPDLLHandle   SDK句柄
 @param   IN    pGetInfo      订阅卡口过车信息上报请求信息，参考Subscribe_Bay_Car_Info_t
                              注意: 如果订阅通道数nChnlCount为0(pEncChannelnfo要置NULL)，
                              表示所有通道的过车数据都上报.
							  只有订阅以后picSDK的回调才能起作用。DPSDK_SetDPSDKGetBayCarInfoCallback才能回调给上层
 @param   IN    nTimeout        超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeBayCarInfo( IN int32_t nPDLLHandle,
																   IN Subscribe_Bay_Car_Info_t* pGetInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
 
/** 订阅区间测速上报.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    nSubscribeFlag  订阅标记:1订阅；0；取消订阅
 @param   IN    nTimeout        超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribeAreaSpeedDetectInfo( IN int32_t nPDLLHandle,
																		    IN int32_t nSubscribeFlag,
																            IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** 设置区间测速上报回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKGetAreaSpeedDetectCallback(IN int32_t nPDLLHandle,
																				 IN fDPSDKGetAreaSpeedDetectCallback fun, 
																				 IN void* pUser);

/** 设置卡口布控告警上报回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKBayWantedAlarmCallback(IN int32_t nPDLLHandle,
																			 IN fDPSDKBayWantedAlarmCallback fun, 
																			 IN void* pUser);


/**
	@brief 获取指定摄像机视频流的（组播）地址和端口
	@param IN	camId				摄像机id
	@param IN	CamStream_Tnfo_t*	需要查询的信息
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCamStreamInfo(IN int32_t nPDLLHandle,INOUT CamStream_Tnfo_t* lpinfo);

/**
	@brief 通过解码器IP与通道号,查找对应电视墙信息，并与屏窗口绑定
	@param IN tagQueryTvWallInfo*	需要查询的信息
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD BindTvWallInfo(IN int32_t nPDLLHandle,INOUT QueryTvWall_Info_t* lpinfo);

/** 图片监控
@param  IN		nPDLLHandle     SDK句柄
@param	IN		cameraId		通道ID
@param	IN		funCB			图片数据回调函数指针
@param	IN		pCBParam		用户参数
@param	IN		eBayType		业务类型
@param	OUT		iSessionId		返回的会话Id DPSDK_StopPicMonitor接口需要
@return							异步顺序码,用于事件回调时,与应答事件匹配
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPicMonitor(int32_t nPDLLHandle, 
															  const char* cameraId, 
															  fPicDataCallback funCB, 
															  void* pCBParam, 
															  dpsdk_bay_monitor_e eBayType, 
															  int32_t iSessionId);

/** 停止图片监控
@param  IN		nPDLLHandle     SDK句柄
@param	IN		sessionId		会话Id
@return							异步顺序码,用于事件回调时,与应答事件匹配
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPicMonitor(int32_t nPDLLHandle, 
															 uint32_t sessionId);


// 卡口业务接口 结束


#endif