#ifndef INCLUDED_DPSDK_CORE_VEHICLE_H
#define INCLUDED_DPSDK_CORE_VEHICLE_H

/** 设置DPSDK围栏报警回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPeccancyAlarmCallback( IN int32_t nPDLLHandle,
																			 IN fDPSDKPeccancyAlarmCallback fun,
																			 IN void* pUser);

/** 设置DPSDK电子围栏变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKAreaChangeCallback( IN int32_t nPDLLHandle,
																		  IN fDPSDKAreaChangeCallback fun,
																		  IN void* pUser);


/** 远程设备抓图 仅用于车载平台
 @param   IN    nPDLLHandle		    SDK句柄
 @param   IN	szCameraId			通道ID
 @param   IN	szLocalPath			抓图路径
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_RemoteDeviceSnap(int32_t nPDLLHandle,
															   const char *szCameraId,
															   const char *szLocalPath);


/** 设置远程设备抓图回调
 @param   IN    nPDLLHandle		SDK句柄
 @param   IN    fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKRemoteDeviceSnapCallback(int32_t nPDLLHandle,
																			   fDPSDKRemoteDeviceSnapCallback fun,
																			   void *pUser);

/** 设置3G信息回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDK3GFlowInfoCallback( IN int32_t nPDLLHandle, 
																			IN fDPSDK3GFlowInfoCallback fun, 
																			IN void* pUser );
/**获取最新GPS信息XML串长度.
 @param		IN		nPDLLHandle				SDK句柄
 @param		OUT		nGpsXMLLen				GPS XML的长度
 @param		IN		nTimeout				超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatusXMLStrCount(int32_t nPDLLHandle, 
																  int* nCount,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**获取最新GPS信息.
 @param		IN		nPDLLHandle				SDK句柄
 @param		OUT		LastGpsIStatus			GPS XML数据
 @param		IN		nCount					GPS XML的长度,DPSDK_AskForLastGpsStatusXMLStrCount的输出参数值
 @param		IN		nTimeout				超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatusXMLStr(int32_t nPDLLHandle, 
																		char* LastGpsIStatus,
																		int nCount);

/**获取最新GPS信息.
 @param		<IN>		nPDLLHandle				SDK句柄
 @param		<OUT>		LastGpsIStatus			最新GPS信息
 @param		<IN>		nTimeout				超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForLastGpsStatus(int32_t nPDLLHandle, 
																  char* LastGpsIStatus,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/**获取用户权限下的线路信息.
 @param		<IN>		nPDLLHandle			SDK句柄
 @param		<OUT>		szJsonLineInfo		平台返回的线路信息(Json字符串)
 @param		<IN>		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOwnLineInfo(int32_t nPDLLHandle, 
															 char* szJsonLineInfo,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);



/**获取排班信息.
 @param		<IN>		nPDLLHandle			SDK句柄
 @param		<IN>		BeginTime			开始时间
 @param		<IN>		EndTime				结束时间
 @param		<IN>		InListLineId[]		线路id
 @param		<IN>		LineNum				线路数量
 @param		<OUT>		szJsonBusSchedule	平台返回的排班信息(Json字符串)
 @param		<IN>		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetBusScheduleInfo(int32_t nPDLLHandle,
																 const char* BeginTime,
																 const char* EndTime, 
																 const int InListLineId[], 
																 const int LineNum,
																 char* szJsonBusSchedule,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**设置排班信息修改回调.
 @param		<IN>		nPDLLHandle			SDK句柄
 @param		<IN>		fun					回调函数
  @param	<IN>		pUser				用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusScheduleChangeCallback(int32_t nPDLLHandle,
																			fDPSDKBusScheduleChangeCallback fun,
																			void* pUser);

/**设置排班状态修改回调.
 @param		<IN>		nPDLLHandle			SDK句柄
 @param		<IN>		fun					回调函数
 @param		<IN>		pUser				用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBusScheduleStateChangeCallback(int32_t nPDLLHandle,
																				fDPSDKBusScheduleStateChangeCallback fun,
																				void* pUser);
/**设置调度信息通知回调.
 @param		<IN>		nPDLLHandle			SDK句柄
 @param		<IN>		fun					回调函数
 @param		<IN>		pUser				用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDispitchInfoCallback(int32_t nPDLLHandle,
																	  fDPSDKDispitchInfoCallback fun,
																	  void* pUser);

/**获取最新站点信息.
 @param		<IN>		nPDLLHandle				SDK句柄
 @param		<IN>		LineId					线路id
 @param		<OUT>		szJsonLastStationInfo	平台返回的最新站点信息(Json字符串)
 @param		<IN>		nTimeout				超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLastStationsInfo(int32_t nPDLLHandle,
																  const int LineId, 
																  char* szJsonLastStationInfo,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 增加电子围栏
@param  IN		nPDLLHandle     SDK句柄
@param	IN		pAreaInfo		电子围栏信息
@param	IN		arryDevId		设备ID的数组
@param	IN		nDevIdCount		设备ID的数组的长度
@param	OUT		strAreaId		围栏ID
@param	IN		nAreaIdLen		围栏ID的字符串大小
@return
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AddAreaInfo(IN int32_t nPDLLHandle, 
														  IN Area_Info_t* pAreaInfo,
														  IN char arryDevId[][DPSDK_CORE_DEV_ID_LEN],
														  IN int32_t nDevIdCount,
														  OUT char szAreaId[],
														  IN int32_t nAreaIdLen,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 删除电子围栏
@param  IN		nPDLLHandle     SDK句柄
@param	IN		szAreaId		电子围栏Id
@return
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelAreaInfo(IN int32_t nPDLLHandle, 
														  IN const char* szAreaId,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 修改电子围栏
@param  IN		nPDLLHandle     SDK句柄
@param	IN		szAreaId		电子围栏Id
@param	IN		pAreaInfo		电子围栏信息
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModAreaInfo(IN int32_t nPDLLHandle,
														  IN const char* szAreaId,
														  IN Area_Info_t* pAreaInfo,
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 增加设备与电子围栏的关联（只修改了本地内存中的，需要Upload才上传服务）
@param  IN		nPDLLHandle     SDK句柄
@param	IN		szDevId			设备ID
@param	IN		szAreaId		电子围栏ID
@param	IN		nAreaType		电子围栏类型
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AddAreaInDev(IN int32_t nPDLLHandle, 
														   IN const char* szDevId,
														   IN const char* szAreaId,
														   IN dpsdk_area_type_e nAreaType,
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 删除设备与电子围栏的关联（只修改了本地内存中的，需要Upload才上传服务）
@param  IN		nPDLLHandle     SDK句柄
@param	IN		szDevId			设备ID
@param	IN		szAreaId		电子围栏ID
@return							
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelAreaInDev(IN int32_t nPDLLHandle, 
														   IN const char* szDevId,
														   IN const char* szAreaId,
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 上传设备与围栏关系给服务
@param  IN		nPDLLHandle     SDK句柄
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_UploadRelationChange(IN int32_t nPDLLHandle,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 将图片由字符串向二进制转换
@param  IN		nPDLLHandle     SDK句柄
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ConvertPicStrToBinary(IN int32_t nPDLLHandle,
																	IN char* pInputPic,
																	OUT char* pOutPic,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 查询设备和围栏的关系
@param  IN		nPDLLHandle     SDK句柄
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryDevAreaRelationLen(IN int32_t nPDLLHandle,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取围栏信息
@param  IN		nPDLLHandle     SDK句柄
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AskForAreaInfo(IN int32_t nPDLLHandle,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据停车区和停车道来获取对应通道ID
@param  IN		nPDLLHandle     SDK句柄
@param	IN		StopSection		停车区
@param	IN		StopWay			停车道
@param	OUT		CameraID		通道ID
@param	IN		nTimeout		操作超时时间
@return							异步顺序码,用于事件回调时,与应答事件匹配
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCameraIDbyStopSectionandWay(int32_t nPDLLHandle,
																			 const char* StopSection,
																			 const char* StopWay,
																			 char* CameraID,
																			 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据通道ID开关摄像头区域入侵分析功能
@param  IN		nPDLLHandle     SDK句柄
@param	IN		DeviceID		摄像头设备ID
@param	IN		bFlag			开关标志 true：开  false：关
@param	IN		nTimeout		操作超时时间
@return							异步顺序码,用于事件回调时,与应答事件匹配
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OpenIntrusionDetection(int32_t nPDLLHandle,
																	 const char* CameraID,
																	 bool bFlag,
																	 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

#endif