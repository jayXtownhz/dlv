#ifndef INCLUDED_DPSDK_CORE_PTZ_H
#define INCLUDED_DPSDK_CORE_PTZ_H

/** 订阅云台报警信息
 @param	  IN	nPDLLHandle				SDK句柄
 @param   IN	szCameraId		        通道编号
 @param	  IN	nSubscribeFlag			订阅标记。0:取消订阅，1：订阅
 @param   IN	nTimeout				超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SubscribePtzSitAlarm( IN int32_t nPDLLHandle,
																   	IN char* szCameralID,   
																	IN int32_t nSubscribeFlag,
																	OUT int32_t& nResult,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 云台方向控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pDirectInfo		云台方向控制信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzDirection( IN int32_t nPDLLHandle, 
															IN Ptz_Direct_Info_t* pDirectInfo, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台镜头控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pOperationInfo	云台镜头控制信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzCameraOperation( IN int32_t nPDLLHandle, 
																  IN Ptz_Operation_Info_t* pOperationInfo, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 云台三维定位.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pSitInfo		云台三维定位信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzSit( IN int32_t nPDLLHandle, 
													  IN Ptz_Sit_Info_t* pSitInfo, 
													  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询云台三维信息
@param	 IN	   nPDLLHandle	SDK句柄
@param   INOUT pSitInfo		云台三维定位信息 
@param   IN	   nTimeout		超时时长，单位毫秒
@return  函数返回错误类型，参考dpsdk_retval_e
@remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPtzSitInfo( IN int32_t nPDLLHandle, 
															   IN OUT Ptz_Sit_Info_t* pSitInfo, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台锁定控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pLockInfo	    云台锁定控制信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzLockCamera( IN int32_t nPDLLHandle, 
															 IN Ptz_Lock_Info_t* pLockInfo, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台灯光控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szCameraId		通道ID 
 @param   IN	bOpen			开启标识
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzLightControl( IN int32_t nPDLLHandle, 
															   IN Ptz_Open_Command_Info_t* Cmd, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台雨刷控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szCameraId		通道ID 
 @param   IN	bOpen			开启标识
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzRainBrushControl( IN int32_t nPDLLHandle, 
																   IN Ptz_Open_Command_Info_t* Cmd, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台红外控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szCameraId		通道ID 
 @param   IN	bOpen			开启标识
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzInfraredControl( IN int32_t nPDLLHandle, 
																  IN Ptz_Open_Command_Info_t* Cmd, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台查询预置点信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pPrepoint		预置点信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPrePoint( IN int32_t nPDLLHandle, 
															 INOUT Ptz_Prepoint_Info_t* pPrepoint, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询带有有效时间段的云台预置点信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pPrepoint		预置点信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTimePrePoint( IN int32_t nPDLLHandle, 
																 INOUT Ptz_Time_Prepoint_Info_t* pPrepoint, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台预置点操作.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pOperation		预置点操作信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzPrePointOperation( IN int32_t nPDLLHandle, 
																	IN Ptz_Prepoint_Operation_Info_t* pOperation, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 设置云台定时任务配置
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pTask		      定时云台任务信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPtzTimeTask( IN int32_t nPDLLHandle, 
															  IN Ptz_Time_Task_Info_t* pTask, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 获取云台定时任务配置.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pTask		      定时云台任务信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPtzTimeTask( IN int32_t nPDLLHandle, 
																INOUT Ptz_Time_Task_Info_t* pTask, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置预置点的有效时间段.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	pOperation		预置点操作信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPrePointTime( IN int32_t nPDLLHandle, 
															   IN Ptz_Prepoint_Time_t* pOperation, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 云台扩展命令.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pExtCmd			扩展命令信息 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PtzExtendCommand( IN int32_t nPDLLHandle, 
																IN Ptz_Extend_Command_Info_t* pExtCmd, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置云台定位报警信息回调
@param   IN    nPDLLHandle		SDK句柄
@param   IN    fun				回调函数
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPtzSitAlarmInfoCallback(int32_t nPDLLHandle, 
																			  fDPSDKPtzSitAlarmInfoCallback fun,  
																			  void* pUser );
/** 设置球机云台参数
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szCameraId		通道ID
@param   IN    fun				回调函数
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPtzParam(int32_t nPDLLHandle,
														  const char* szCameraId,
														  Ptz_Param_t* pOperation,
														  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 查询球机可视域信息
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szCameraId		通道ID
@param   OUT   pOperation		可视域信息
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryChannelViewInfo(int32_t nPDLLHandle,
																	const char* szCameraId,
																	Channel_View_Info_t* nChannelViewInfo,
																	int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 设置硬盘录像机下所有球机的可视域信息回调函数
@param   IN    nPDLLHandle		SDK句柄
@param   IN    fun				可视域信息回调函数指针
@param   OUT   pUser			用户自定义指针
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetChannelViewInfoCallback(int32_t nPDLLHandle,
																		 fDPSDKChannelViewInfoCallback fun,
																		 void* pUser );


/** 查询硬盘录像机下所有通道的可视域信息
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szDeviceId		设备ID
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryDeviceViewInfo(int32_t nPDLLHandle,
																   const char* szDeviceId,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 摄像头码流叠加OSD信息
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szChannelId		通道ID
@param   IN    struOSDInfo		OSD信息结构体
@param   IN    enumAlign		字体对其方式
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetOSDInfo(int32_t nPDLLHandle, OSD_Info_t* struOSDInfo, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szChannelId		通道ID
@param   IN	   nTimeout			超时时长，单位毫秒
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ConnectDmsByChnlId(int32_t nPDLLHandle,
																 const char* szChannelId,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
#endif