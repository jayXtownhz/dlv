#ifndef INCLUDED_DPSDK_CORE_ALARM_H
#define INCLUDED_DPSDK_CORE_ALARM_H


/** 设置报警状态回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_Create成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKAlarmCallback( IN int32_t nPDLLHandle, 
																	 IN fDPSDKAlarmCallback fun, 
																	 IN void* pUser );

/** 设置新报警状态回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_Create成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKNewAlarmCallback( IN int32_t nPDLLHandle, 
																	 IN fDPSDKNewAlarmCallback fun, 
																	 IN void* pUser );

/** 报警布控.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pSourceInfo		报警方案 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、布控时需要明白不同的报警类型对应不同的参数
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_EnableAlarm( IN int32_t nPDLLHandle, 
														   IN Alarm_Enable_Info_t* pSourceInfo, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 报警布控(针对某个部门下的所有设备)
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pSourceInfo		报警方案 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、布控时需要明白不同的报警类型对应不同的参数
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_EnableAlarmByDepartment( IN int32_t nPDLLHandle, 
														               IN Alarm_Enable_By_Dep_Info_t* pSourceInfo, 
														               IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 报警撤控.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DisableAlarm( IN int32_t nPDLLHandle, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 查询报警个数.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN    pQuery          查询信息
 @param	  OUT	nCount			报警个数返回 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryAlarmCount( IN int32_t nPDLLHandle, 
															   IN Alarm_Query_Info_t* pQuery, 
															   OUT int32_t& nCount, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询报警信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN    pQuery          查询信息
 @param	  		pInfo			报警信息 
 @param	  IN	nFirstNum		从第几个开始获取 
 @param	  IN	nQueryCount		获取多少个 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、支持分批获取
 2、此接口推荐和DPSDK_QueryAlarmCount一起使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryAlarmInfo( IN int32_t nPDLLHandle, 
															  IN Alarm_Query_Info_t* pQuery, 
															  INOUT Alarm_Info_t* pInfo, 
															  IN int32_t nFirstNum, 
															  IN int32_t nQueryCount, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 查询报警图片信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN    optype          操作类型
 @param	  IN	szCameraId		通道ID 
 @param	  IN	szIvsURL		图片URL 
 @param	  IN	szSavePath		保存路径 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、支持分批获取
 2、此接口推荐和DPSDK_QueryAlarmCount一起使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsbAlarmPicture( int32_t nPDLLHandle,
																   dpsdk_operator_ftp_type_e optype, 
																   const char* szCameraId,
																   const char* szIvsURL, 
																   const char* szSavePath,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** 发送报警到服务.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN    Client_Alarm_Info_t		报警信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendAlarmToServer( IN int32_t nPDLLHandle, 
																 IN Client_Alarm_Info_t* pAlarmInfo,
															     IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 获取日期模板数量
 @param   IN    nPDLLHandle		SDK句柄
 @param   OUT   pCount			日期模板数量
 @param   IN	nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCustomTimeTemplateCount(IN int32_t nPDLLHandle,
																		 IN uint32_t* pCount,
																		 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	获取自定义日期模板.
@param		IN		nPDLLHandle			SDK句柄
@param		IN		id					时间模板id(如果传入0，则获取所有时间模板)
@param		OUT		pTimeTemplate		日期模板信息
@param		IN		nTimeout			超时时间
@param		IN		nTimeout			超时时间
@return									函数返回错误类型，参考dpsdk_retval_e
@remark  
1、如果想要获取所有模板，必须先查询后获取
2、DPSDK_GetCustomTimeTemplateCount会返回记录个数,pTimeTemplate根据记录个数在外面申请相应内存
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCustomTimeTemplate(IN int32_t nPDLLHandle,
																	IN int32_t id,
																	OUT TimeTemplateInfo_t* pTimeTemplate,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	获取单个报警预案文件长度.
@param		IN		nPDLLHandle			SDK句柄
@param		IN		id					预案数据库id
@param		OUT		pLen				预案文件数据长度
@param		IN		nTimeout			超时时间
@return									函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSchemeFileDataLen(IN int32_t nPDLLHandle,
																   IN int32_t id,
																   OUT int32_t* pLen,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/**	获取单个报警预案.
@param		IN		nPDLLHandle			SDK句柄
@param		IN		id					预案数据库id
@param		OUT		pTimeTemplate		预案信息
@param		IN		nTimeout			超时时间
@return									函数返回错误类型，参考dpsdk_retval_e
@remark  
1. pTimeTemplate内存需要在外面分配;
2. 调用此函数前必须先调用DPSDK_GetSchemeFileDataLen获取预案文件长度，根据此长度分配data内存,data内存也需要在外面分配.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSchemeFile(IN int32_t nPDLLHandle,
															IN int32_t id,
															OUT AlarmSchemeFileInfo_t* pTimeTemplate,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 删除报警预案.
@param		IN		nPDLLHandle			SDK句柄
@param		IN		id					预案数据库id
@param		IN		nTimeout			超时时间
@return									函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelSchemeFile(IN int32_t nPDLLHandle,
															IN uint32_t id, 
															IN bool bNotifyAll=false,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据报警预案进行布控
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szSchemeFile	报警预案xml 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_EnableAlarmBySchemeFile( IN int32_t nPDLLHandle, 
														               IN const char* szSchemeFile, 
																	   IN uint32_t nSchemeFileLen, 
														               IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 通知预案失效.
@param		IN		nPDLLHandle			SDK句柄
@param		IN		schemeID			预案ID
@param		IN		notifyType			变更类型： (7)所有信息（时间段索引、报警源、动作）,(1)时间段索引,(2)报警源,(4)动作或其他组合.
@param		IN		nTimeout			超时时间
@return									函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_NotifySchemeInvalidate(IN int32_t nPDLLHandle,
																	 IN int64_t schemeID, 
																	 IN uint32_t notifyType,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 设置报警预案变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetAlarmSchemeCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKAlarmSchemeCallback fun,
																			  IN void * pUser);
/** 获取报警预案数量
 @param   IN    nPDLLHandle		SDK句柄
 @param   OUT   pCount			报警预案数量
 @param   IN	nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmSchemeCount(IN int32_t nPDLLHandle,
																  OUT uint32_t* pCount,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取报警预案列表
 @param		IN		nPDLLHandle			SDK句柄
 @param		OUT		pAlarmSchemeList	报警预案
 @param		IN		nCount				报警预案数量
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmSchemeList(IN int32_t nPDLLHandle,
																 OUT AlarmSchemeInfo_t* pAlarmSchemeList,
																 IN uint32_t nCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 保存报警预案
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		pAlarmScheme		报警预案
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveAlarmScheme(IN int32_t nPDLLHandle,
															  IN const AlarmSchemeInfo_t* pAlarmScheme,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 保存报警预案文件
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		id					预案数据库id
 @param		IN		schemeName			预案名称
 @param		IN		status				预案开关
 @param		IN		templateId			时间模板id
 @param		IN		desc				预案描述
 @param		IN		data				预案内容
 @param		IN		len					预案内容长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveSchemeFile(IN int32_t nPDLLHandle,
															 IN uint32_t id,
															 IN const char* schemeName,
															 IN dpsdk_alarmScheme_status_e status, 
															 IN uint32_t templateId, 
															 IN const char* desc, 
															 IN const char* data, 
															 IN uint32_t len,
															 IN bool bNotifyAll = false,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 大图抽取人脸图片
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN      szCameraId						人脸识别设备的指定通道ID
 @param		IN      requestFlag						用户自定义的请求标记，无特殊限制
 @param		IN		picData							图片数据
 @param		IN		nFileLength						图片文件大小
 @param		IN		nPicWidth						图片宽度
 @param		IN		nPicHeight						图片高度
 @param		OUT		faceDataLength					返回的人脸数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ExtractFacePicDataLength(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 char* picData, 
															 uint32_t nFileLength, 
															 uint32_t nPicWidth, 
															 uint32_t nPicHeight,
															 long* faceDataLength,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 大图抽取人脸图片
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN      szCameraId						人脸识别设备的指定通道ID
 @param		IN      requestFlag						用户自定义的请求标记，无特殊限制
 @param		IN		picData							图片数据
 @param		IN		nFileLength						图片文件大小
 @param		IN		nPicWidth						图片宽度
 @param		IN		nPicHeight						图片高度
 @param		OUT		faceData						返回的人脸数据
 @param		IN		faceDataLength					返回的人脸数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ExtractFacePicData(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 char* picData, 
															 uint32_t nFileLength, 
															 uint32_t nPicWidth, 
															 uint32_t nPicHeight,
															 char*	faceData,
															 long faceDataLength,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询条件，获取人脸库中匹配的数量
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		const char* szCameraId						    人脸识别设备的指定通道ID
 @param		IN		long requestFlag								用户自定义的请求标记，无特殊限制
 @param		IN		const char* data								查询条件
 @param		IN		uint32_t len									查询条件的数据长度
 @param		OUT		int32_t count									匹配总数
 @param		OUT		uint32_t querySession							查询会话
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceCount(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 long requestFlag, 
															 const char* data, 
															 uint32_t len,
															 int32_t* count,
															 uint32_t* querySession,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询人脸库后获取到的Session，获取指定区间的匹配数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						    人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nStartIndex							起始数据索引
 @param		IN		nQueryNum							数据条数
 @param		OUT		dataLength							返回的数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceDataLength(int32_t nPDLLHandle,
															const char* szCameraId, 
															uint32_t nQuerySession, 
															uint32_t nStartIndex, 
															uint32_t nQueryNum,	
															uint32_t* dataLength,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询人脸库后获取到的Session，获取指定区间的匹配数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						    人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nStartIndex							起始数据索引
 @param		IN		nQueryNum							数据条数
 @param		OUT		personData							返回的具体数据
 @param		IN		dataLength							返回的数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFaceData(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 uint32_t nQuerySession, 
															 uint32_t nStartIndex, 
															 uint32_t nQueryNum,
															 char*	personData,		
															 uint32_t dataLength,
															 char* szPicServerIp,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 人脸注册数据操作
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId							人脸识别设备的指定通道ID
 @param		IN		requestFlag							用户自定义的请求标记，无特殊限制
 @param		IN		operateType,						操作类型（添加/修改及删除）
 @param		IN		data								操作的数据
 @param		IN		len									数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperateFaceLib(int32_t nPDLLHandle,
															const char* szCameraId, 
															long requestFlag, 
															uint32_t operateType, 
															const char* data, 
															uint32_t len,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 断开指定的人脸库查询Session
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId							人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopFaceQuery(int32_t nPDLLHandle,
															 const char* szCameraId, 
															 uint32_t nQuerySession,
															 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询条件，获取人脸识别报警的匹配数量
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						人脸识别设备的指定通道ID
 @param		IN		requestFlag						用户自定义的请求标记，无特殊限制
 @param		IN		nStartTime						报警时间的开始区间
 @param		IN		nEndTime						报警时间的结束区间
 @param		IN		szAddress						报警地点
 @param		IN		nAlarmType						报警类型（黑白名单报警）
 @param		OUT		count							匹配总数
 @param		OUT		querySession					查询会话
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmCount(int32_t nPDLLHandle,
															const char* szCameraId, 
															long requestFlag, 
															int64_t nStartTime, 
															int64_t nEndTime, 
															const char* szAddress, 
															uint32_t nAlarmType,
															int* count,
															uint32_t* querySession,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询人脸识别报警获取到的Session，获取指定区间的匹配数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						    人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nStartIndex							起始数据索引
 @param		IN		nQueryNum							数据条数
 @param		OUT		dataLength							返回的数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmDataLength(int32_t nPDLLHandle,
																 const char* szCameraId, 
																 uint32_t nQuerySession, 
																 uint32_t nStartIndex, 
																 uint32_t nQueryNum,
																 uint32_t* dataLength,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 根据查询人脸识别报警获取到的Session，获取指定区间的匹配数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						    人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nStartIndex							起始数据索引
 @param		IN		nQueryNum							数据条数
 @param		OUT		personData							返回的具体数据
 @param		IN		dataLength							返回的数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryIvsfAlarmData(int32_t nPDLLHandle,
																  const char* szCameraId, 
																  uint32_t nQuerySession, 
																  uint32_t nStartIndex, 
																  uint32_t nQueryNum,
																  char*	personData,
																  uint32_t dataLength,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 断开指定的人脸识别报警查询Session
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId							人脸识别设备的指定通道ID
 @param		IN		nQuerySession						查询匹配数目时获取到的Session
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopIvsfAlarmQuery(int32_t nPDLLHandle,
															const char* szCameraId, 
															uint32_t nQuerySession,
															int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取单条人脸识别报警的所有图片数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						人脸识别设备的指定通道ID
 @param		IN		requestFlag						用户自定义的请求标记，无特殊限制
 @param		IN		data							单条人脸识别报警的所有图片信息
 @param		IN		len								图片信息长度
 @param		OUT		picFullDataLength				数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsfAlarmPicLength(int32_t nPDLLHandle,
															  const char* szCameraId, 
															  long requestFlag, 
															  const char* data, 
															  uint32_t len,
															  long* picFullDataLength,
															  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取单条人脸识别报警的所有图片数据
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId						人脸识别设备的指定通道ID
 @param		IN		requestFlag						用户自定义的请求标记，无特殊限制
 @param		IN		data							单条人脸识别报警的所有图片信息
 @param		IN		len								图片信息长度
 @param		OUT		picFullData						返回的完整图片数据(多个图片及其描述)
 @param		IN		picFullDataLength				数据长度
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetIvsfAlarmPic(int32_t nPDLLHandle,
																 const char* szCameraId, 
																 long requestFlag, 
																 const char* data, 
																 uint32_t len,
																 char* picFullData,
																 long picFullDataLength,
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 查询RFID报警信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN    pQuery          查询信息
 @param	  		pInfo			RFID报警信息 
 @param	  IN	nFirstNum		从第几个开始获取 
 @param	  IN	nQueryCount		获取多少个 
 @param   IN    pSwLabel		超声波探测标签
 @param   IN    pElecLabel		车用电子标签
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、支持分批获取
 2、此接口推荐和DPSDK_QueryAlarmCount一起使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRFIDAlarmInfo( IN int32_t nPDLLHandle, 
																	IN Alarm_Query_Info_t* pQuery, 
																	INOUT Alarm_Info_t* pInfo, 
																	IN int32_t nFirstNum, 
																	IN int32_t nQueryCount,
																	IN const char* pSwLabel = NULL,
																	IN const char* pElecLabel = NULL,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 报警上报过滤
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraIdList		通道ID列表，多个通道ID用','分隔
 @param		IN		pAlarmTypeArray		报警类型列表
 @param		IN		nAlarmCount			报警类型数量
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_FilterAlarm(IN int32_t nPDLLHandle, 
														  IN const char* szCameraIdList, 
														  IN dpsdk_alarm_type_e* pAlarmTypeArray, 
														  IN int32_t nAlarmCount);

/** 去除报警上报过滤
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraIdList		通道ID列表，多个通道ID用','分隔
 @param		IN		pAlarmTypeArray		报警类型列表
 @param		IN		nAlarmCount			报警类型数量
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_NoFilterAlarm(IN int32_t nPDLLHandle, 
															IN const char* szCameraIdList, 
															IN dpsdk_alarm_type_e* pAlarmTypeArray, 
															IN int32_t nAlarmCount);

/** 清除设备报警消息
 @param		IN		nPDLLHandle			SDK句柄
 @param		IN		szCameraId			通道ID
 @param		IN		nAlarmType			报警类型
 @param		IN		nTimeout			超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearDevAlarm( IN int32_t nPDLLHandle,
															 IN const char* szCameraId,
															 IN uint32_t nAlarmType,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif