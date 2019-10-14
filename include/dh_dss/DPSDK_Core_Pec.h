/**
 * Copyright (c) 2012, 浙江大华
 * All rights reserved.
 *
 * 文件名称：DPSDK_Core_Pec.h
 * 文件标识：
 * 摘　　要：PEC模块 接口文件 
 *
 * 当前版本：1.0
 * 原作者　：whg
 * 完成日期：2015年10月13号
 * 修订记录：创建
*/

#ifndef INCLUDED_DPSDK_CORE_PEC_H
#define INCLUDED_DPSDK_CORE_PEC_H


/** 设置门禁开关状态上报回调
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPecDoorStatusCallback(int32_t nPDLLHandle,
																	   fDPSDKPecDoorStarusCallBack pFun,
																	   void* pUser);


/** 门控制.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pRequest		请求信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDoorCmd(int32_t nPDLLHandle, 
														SetDoorCmd_Request_t* pRequest, 
														int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取绑定视频资源.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pResponce		绑定视频资源XML
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryLinkResource( int32_t nPDLLHandle,
															     uint32_t* nLen, 
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取绑定视频资源.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pResponce		绑定视频资源XML
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLinkResource( int32_t nPDLLHandle,
															   GetLinkResource_Responce_t* pResponce );

/** 西藏吉隆边防项目定制，设置业翔广播通道状态上报
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetBroadcastReportStatusCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKBroadcastReportStatusCallback fun, 
																			  IN void* pUser);

#endif
