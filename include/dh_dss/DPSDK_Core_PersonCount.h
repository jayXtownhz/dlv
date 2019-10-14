#ifndef INCLUDED_DPSDK_CORE_PERSONCOUNT_H
#define INCLUDED_DPSDK_CORE_PERSONCOUNT_H


/** 查询统计总数.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		通道ID
 @param   OUT	nQuerySeq		码流请求序号,可作为后续操作标识 
 @param   OUT	totalCount		统计总数
 @param   IN	nStartTime		开始时间 
 @param   IN    nEndTime		结束时间				
 @param   IN    nGranularity	查询粒度，0:分钟,1:小时,2:日,3:周,4:月,5:季,6:年;
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPersonCount(int32_t nPDLLHandle, 
															   const char* szCameraId, 
															   uint32_t& nQuerySeq, 
															   uint32_t& totalCount,
															   uint32_t nStartTime, 
															   uint32_t nEndTime, 
															   int nGranularity,
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 分页查询统计结果.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		通道ID
 @param   IN	nQuerySeq		码流请求序号,可作为后续操作标识 
 @param   IN	nIndex			此次查询的开始值
 @param   IN    nCount			此次查询的数量		
 @param   OUT	nPersonInfo		详细的人数统计信息，new一个nCount大小的数组
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryPersonCountBypage(int32_t nPDLLHandle, 
																	 const char* szCameraId, 
																	 uint32_t nQuerySeq, 
																	 uint32_t nIndex, 
																	 uint32_t nCount, 
																	 Person_Count_Info_t* nPersonInfo,
																	 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 结束查询.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szCameraId		通道ID
 @param   IN	nQuerySeq		码流请求序号,可作为后续操作标识 			
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopQueryPersonCount(int32_t nPDLLHandle, 
																   const char* szCameraId, 
																   uint32_t nQuerySeq,
																   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

#endif