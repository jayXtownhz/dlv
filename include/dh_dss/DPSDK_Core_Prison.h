/**
 * Copyright (c) 2012, 浙江大华
 * All rights reserved.
 *
 * 文件名称：DPSDK_Core_Prison.h
 * 文件标识：
 * 摘　　要：监狱子模块 接口文件 
 *
 * 当前版本：1.0
 * 原作者　：whg
 * 完成日期：2015年9月18号
 * 修订记录：创建
*/

#ifndef INCLUDED_DPSDK_CORE_PRISON_H
#define INCLUDED_DPSDK_CORE_PRISON_H


//////////////////////////////////////////////////////////////////////////
// 监狱子模块接口 开始


/** 获取刻录实时状态信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pDevBurnerCDStateRequest			请求信息
 @param	  OUT	pDevBurnerCDStateResponse			回复信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevBurnerCDState(int32_t nPDLLHandle, 
																Dev_Burner_CDState_Request_t* pDevBurnerCDStateRequest, 
																Dev_Burner_CDState_Reponse_t* pDevBurnerCDStateResponse,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 刻录控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pDevBurnerCDStateRequest			请求信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ControlDevBurner(int32_t nPDLLHandle, 
																Control_Dev_Burner_Request_t* pControlDevBurnerRequest, 
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 刻录片头设置.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pInfoHeader		片头信息
 @param	  IN	pAttrName		审讯表单属性名
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDevBurnerHeader( int32_t nPDLLHandle,
																  DevBurnerInfoHeader_t* pInfoHeader, 
																  TrialFormAttrName_t* pAttrName,
																  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取设备磁盘信息数量
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDevId			设备ID
 @param   INOUT	pInfoCount		磁盘信息数量
 @param   INOUT pSequence		异步顺序码
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceDiskInfoCount( int32_t nPDLLHandle,
																	  const char* szDevId,
																	  int32_t& nInfoCount,
																	  int32_t& nSequence,
																	  int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取设备磁盘信息
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    nSequence		异步顺序码
 @param   INOUT	pDiskInfo		磁盘信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  需要先调用DPSDK_GetDeviceDiskInfoCount获取磁盘信息数量，pDiskInfo根据数量申请相应内存
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceDiskInfo( int32_t nPDLLHandle,
																 int32_t nSequence,
																 Device_Disk_Info_t* pDiskInfo);
// 监狱子模块接口 结束
//////////////////////////////////////////////////////////////////////////


#endif
