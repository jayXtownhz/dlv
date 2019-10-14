#ifndef INCLUDED_DPSDK_CORE_PLAYBACK_H
#define INCLUDED_DPSDK_CORE_PLAYBACK_H

/** 开启平台录像
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   IN    streamType      实时码流类型
@param   IN    nTimeout        超时时长，单位毫秒
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartPlatformReocrd(IN int32_t nPDLLHandle,
																  IN const char *szCameraId,
																  IN dpsdk_encdev_stream_e streamType = DPSDK_CORE_STREAM_MAIN,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 停止平台录像
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   IN    nTimeout        超时时长，单位毫秒
@return  函数返回错误类型，参考dpsdk_retval_e
@remark
*/ 
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopPlatformReocrd(IN int32_t nPDLLHandle,
																 IN const char *szCameraId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 查询录像.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pQueryInfo		查询信息
 @param   OUT	nRecordCount	录像记录个数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
   1、nRecordCount最大5000个记录
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecord( IN int32_t nPDLLHandle, 
														   IN Query_Record_Info_t* pQueryInfo, 
														   OUT int32_t& nRecordCount, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 通过码流类型查询录像.
 @param   IN	nPDLLHandle				SDK句柄
 @param   IN	pQueryInfo				查询信息
 @param   IN	nStreamType				码流类型
 @param   OUT	nRecordCount			录像记录个数
 @param   IN	nTimeout				超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
   1、nRecordCount最大5000个记录
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordByStreamType( IN int32_t nPDLLHandle, 
																		IN Query_Record_Info_t* pQueryInfo, 
																		IN dpsdk_stream_type_e nStreamType,
																		OUT int32_t& nRecordCount, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询当月有录像的日期.
 @param   IN	nPDLLHandle				SDK句柄
 @param   IN	cameraId				通道ID
 @param   IN	source					录像来源，可以选择DPSDK_CORE_PB_RECSOURCE_ALL
 @param   IN	recordType				录像类型，可以选择DPSDK_CORE_PB_RECORD_UNKONWN
 @param   IN	Date					日期（单位秒），可随意选择所要查询月份里的一个时间点，据1970年1月1日0时0分0秒的秒数
 @param   OUT	days					有录像的天，以逗号隔开,0代表当天没有录像，1代表有录像。上层输入参数推荐days = new char[128];
 @param   OUT	LengthofDays			days字符串的长度
 @param   IN	nTimeout				超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
   1、nRecordCount最大5000个记录
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordDaysofTheMonth(int32_t nPDLLHandle, 
																		const char* cameraId, 
																		dpsdk_recsource_type_e source, 
																		dpsdk_record_type_e recordType, 
																		uint64_t Date,
																		char* days,
																		int* LengthofDays,
																		int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取录像信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pRecords		录像信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
   1、必须先查询后获取
   2、DPSDK_QueryRecord会返回记录个数,
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordInfo( IN int32_t nPDLLHandle, 
															 INOUT Record_Info_t* pRecords );

/** 按文件请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByFile( IN int32_t nPDLLHandle, 
																	 OUT int32_t& nPlaybackSeq, 
																	 IN Get_RecordStream_File_Info_t* pRecordInfo, 
																	 IN fMediaDataCallback pFun, 
																	 IN void* pUser, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按时间请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByTime( IN int32_t nPDLLHandle, 
																	 OUT int32_t& nPlaybackSeq, 
																	 IN Get_RecordStream_Time_Info_t* pRecordInfo, 
																	 IN fMediaDataCallback pFun, 
																	 IN void* pUser, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 根据码流类型按时间请求录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息
 @param   IN	nStreamType		码流类型
 @param   IN    pFun			码流回调函数				
 @param   IN    pUser			码流回调用户参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @param   IN	nTransMode		传输模式，1:TCP 0:UDP
 @param   IN	bBack			是否倒放
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordStreamByStreamType( IN int32_t nPDLLHandle, 
																			OUT int32_t& nPlaybackSeq, 
																			IN Get_RecordStream_Time_Info_t* pRecordInfo,
									 										IN dpsdk_stream_type_e nStreamType,
																			IN fMediaDataCallback pFun, 
																			IN void* pUser, 
																			IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT,
																			IN int32_t nTransMode = 1,
																			IN bool bBack = false);

/** 暂停录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PauseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 恢复录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ResumeRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	   IN int32_t nPlaybackSeq, 
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置录像流速率.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN    nSpeed,         录像流回放速度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetRecordStreamSpeed( IN int32_t nPDLLHandle, 
																	IN int32_t nPlaybackSeq, 
																	IN dpsdk_playback_speed_e nSpeed, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 定位回放.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN    seekBegin,		定位起始值.文件模式时,是定位处的文件大小值;时间模式时,是定位处的时间值;
 @param   IN    seekEnd,		定位结束值.文件模式时,无意义;时间模式时,是期待的结束时间.
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark 
			seekBegin在文件模式下的计算方式可以是:(文件大小值)/100*(定位处相对文件的百分比)  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SeekRecordStreamBySeq(IN int32_t nPDLLHandle, 
																	IN int32_t nPlaybackSeq, 
																	IN uint64_t seekBegin, 
																	IN uint64_t seekEnd, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																	  IN int32_t nPlaybackSeq, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭录像，同步等待服务应答.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	nPlaybackSeq	回放请求序号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroCloseRecordStreamBySeq( IN int32_t nPDLLHandle, 
																			  IN int32_t nPlaybackSeq, 
																			  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按通道关闭录像流.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId   	通道编号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseRecordStreamByCameraId( IN int32_t nPDLLHandle, 
																		   IN const char* szCameraId, 
																		   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按通道关闭录像流，同步等待服务应答.
 @param	  IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId   	通道编号 
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SynchroCloseRecordStreamByCameraId( IN int32_t nPDLLHandle, 
																				IN const char* szCameraId, 
																				IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );



/** 手动启动设备录像
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szDevId			设备ID
 @param	  IN	szSN			互联编码
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartDeviceRecord( IN int32_t nPDLLHandle, 
																 IN const char* szDevId, 
																 IN const char* szSN,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 手动停止设备录像
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	szDevId			设备ID
 @param	  IN	szSN			互联编码
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopDeviceRecord( IN int32_t nPDLLHandle, 
															    IN const char* szDevId, 
															    IN const char* szSN,
															    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 京东项目定制，根据历史视频文件ID查询录像信息
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szFileId		历史视频文件ID
 @param   OUT	szCameraId		摄像头ID
 @param   OUT	begTime			开始时间
 @param   OUT	endTime			结束时间
 @param   OUT	szFilePath		历史视频文件路径
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordByFileId( IN int32_t nPDLLHandle, 
																   IN const char* szFileId,
																   OUT char* szCameraId,
																   OUT uint64_t& begTime,
																   OUT uint64_t& endTime,
																   OUT char* szFilePath,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 录像打标.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pTagInfo		录像打标信息
 @param	  IN	nOpType			打标操作，1：新增，2：修改，3：删除
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperatorTagInfo( IN int32_t nPDLLHandle, 
															   INOUT Tag_Info_t* pTagInfo,
															   IN dpsdk_operator_type_e nOpType, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按文件请求录像流，转换为指定码流保存到文件，只支持大华设备
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param   IN    scType          码流转换的目的类型
 @param   IN    pFilePath		文件保存路径
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveRecordStreamByFile( IN int32_t nPDLLHandle, 
																	  OUT int32_t& nPlaybackSeq, 
																	  IN Get_RecordStream_File_Info_t* pRecordInfo, 
																	  IN dpsdk_stream_convertor_type_e scType,
																	  IN const char* pFilePath,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 按时间请求录像流，转换为指定码流保存到文件，只支持大华设备
 @param	  IN	nPDLLHandle		SDK句柄
 @param   OUT	nPlaybackSeq	回放请求序号,作为后续操作标识  
 @param	  IN	pRecordInfo		录像信息 
 @param   IN    scType          码流转换的目的类型
 @param   IN    pFilePath		文件保存路径
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveRecordStreamByTime( IN int32_t nPDLLHandle, 
																	  OUT int32_t& nPlaybackSeq, 
																	  IN Get_RecordStream_Time_Info_t* pRecordInfo,
																	  IN dpsdk_stream_convertor_type_e scType,
																	  IN const char* pFilePath, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置录像转码完成回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKSaveRecordFinishedCallback( IN int32_t nPDLLHandle, 
																				  IN fSaveRecordFinishedCallback fun, 
																				  IN void* pUser );

/** 录像锁定/解锁操作.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pRecordLockOperationInfo	录像锁定/解锁信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_RecordLockOperation( IN int32_t nPDLLHandle, 
																   IN Record_Lock_Operation_Info_t* pRecordLockOperationInfo, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询录像锁定信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pRecordLockQueryInfo	录像锁定查询信息
 @param	  OUT	pInfoLen		录像锁定信息长度			
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryRecordLock( IN int32_t nPDLLHandle, 
															   IN Record_Lock_Query_Info_t* pRecordLockQueryInfo, 
															   OUT int32_t* pInfoLen, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取录像锁定信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pRecordLockInfo	录像锁定信息
 @param	  IN	nInfoLen		录像锁定信息长度			
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
	1、必须先查询后获取
	2、DPSDK_QueryRecordLock会返回信息长度，需要在外部分配好字符串内存
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetRecordLockInfo( IN int32_t nPDLLHandle, 
															     OUT char* pRecordLockInfo, 
															     IN int32_t nInfoLen);

/** 获取回放视频的URL路径.
 @param	  IN	nPDLLHandle		SDK句柄 
 @param	  IN	pRecordStreamUrlInfo	查询录像Url信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPlaybackByTimeUrl( IN int32_t nPDLLHandle, 
																	INOUT Get_RecordStreamUrl_Time_Info_t* pRecordStreamUrlInfo, 
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif


