#ifndef INCLUDED_DPSDK_CORE_ALARMBUSINESS_H
#define INCLUDED_DPSDK_CORE_ALARMBUSINESS_H

/** 根据设备ID获取报警输入通道信息
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pstruUserInfo	用户信息结构体
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
 1、pAlarmInChannelnfo需要在外面创建好
 2、pAlarmInChannelnfo的个数与DPSDK_GetDGroupInfo返回时有报警主机设备id和报警输入通道个数
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAlarmInChannelInfo( IN int32_t nPDLLHandle, 
																	INOUT Get_AlarmInChannel_Info_t* pstruUserInfo);

/** 查询网络报警主机状态
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDeviceId		设备id
 @param   IN	nChannelcount	通道个数
 @param   OUT	pDefence		通道信息结构体
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pDefence需要在外面创建好，根据通道个数new
 2、没有单独设备的布撤防状态，需要根据通道的状态判断
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryNetAlarmHostStatus( IN int32_t nPDLLHandle, 
																	   IN const char* szDeviceId,
																	   IN int32_t nChannelcount,
																	   OUT dpsdk_AHostDefenceStatus_t* pDefence,
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 查询网络报警主机状态包含的通道个数
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDeviceId		设备id
 @param   OUT	pChannelcount	通道个数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pDefence需要在外面创建好，根据通道个数new
 2、没有单独设备的布撤防状态，需要根据通道的状态判断
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryNetAlarmHostChannelCount(int32_t nPDLLHandle, 
																			const char* szDeviceId,
																			int32_t* pChannelcount,
																			int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取网络报警主机所有状态
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nChannelcount	通道个数
 @param   OUT	pDefence		通道信息结构体
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、先调用DPSDK_QueryNetAlarmHostChannelCount获取通道个数nChannelcount
 2、然后new一个nChannelcount大小的结构体数组dpsdk_AHostDefenceStatus_t指针pDefence
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetNetAlarmHostStatus(int32_t nPDLLHandle,
																	int32_t nChannelcount,
																	dpsdk_AHostDefenceStatus_t* pDefence);

/** 设置视频报警主机布撤防/旁路状态回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、登陆平台的时候平台先回调设备布撤防状态，接着回调通道旁路状态
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVideoAlarmHostStatusCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKVideoAlarmHostStatusCallback fun, 
																			  IN void* pUser);

/** 设置网络报警主机布撤防/旁路状态回调.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、有其他客户端修改了网络报警主机状态以后，回调通知
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetNetAlarmHostStatusCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKNetAlarmHostStatusCallback fun, 
																			  IN void* pUser);

/** 报警订阅设置-报警运营平台.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    userParam       用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PhoneSubscribeAlarm(IN int32_t nPDLLHandle,
																  INOUT dpsdk_phone_subscribe_alarm_t& userParam, 
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 视频报警主机：设备布撤防/通道旁路/消除通道报警.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    szDeviceId      设备id
 @param   IN    channelId       通道号，-1表示对设备操作
 @param   IN    controlType     操作类型, 参考dpsdk_AlarmhostOperator_e
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、视频报警主机类型为:1101
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlVideoAlarmHost(IN int32_t nPDLLHandle,
																	IN const char *szDeviceId, 
																	IN int32_t channelId, 
																	IN int32_t controlType,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 网络报警主机：设备布撤防/通道旁路/消除通道报警.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    szId			设备id/通道id
 @param   IN    opttype			设备/通道操作,参考dpsdk_netalarmhost_operator_e
 @param   IN    controlType     操作类型, 参考dpsdk_netalarmhost_cmd_e
 @param   IN    iStart			开始时间,默认为0
 @param   IN    iEnd			结束时间,默认为0
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
 1、网络报警主机类型为:601
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlNetAlarmHostCmd(IN int32_t nPDLLHandle,
																	 IN const char* szId, 
																	 IN int32_t opttype, 
																	 IN int32_t controlType, 
																	 IN int64_t iStart, 
																	 IN int64_t iEnd, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


#endif