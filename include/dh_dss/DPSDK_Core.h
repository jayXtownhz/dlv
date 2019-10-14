#ifndef INCLUDED_DPSDK_CORE_H
#define INCLUDED_DPSDK_CORE_H

#include "DPSDK_Core_Define.h"
#include "DPSDK_Core_Alarm.h"
#include "DPSDK_Core_AlarmBusiness.h"
#include "DPSDK_Core_Bay.h"
#include "DPSDK_Core_FTP.h"
#include "DPSDK_Core_Org.h"
#include "DPSDK_Core_Playback.h"
#include "DPSDK_Core_PTZ.h"
#include "DPSDK_Core_RealStream.h"
#include "DPSDK_Core_Talk.h"
#include "DPSDK_Core_TvWall.h"
#include "DPSDK_Core_Vehicle.h"
#include "DPSDK_Core_PersonCount.h"
#include "DPSDK_Core_Prison.h"
#include "DPSDK_Core_Pec.h"
#include "DPSDK_Core_Call.h"
/***************************************************************************************
 @ 接口定义
***************************************************************************************/

/** 创建SDK句柄.
 @param   IN	nType			SDK类型
 @param   OUT	nPDLLHandle		返回SDK句柄，后续操作需要以此作为参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_Create( IN dpsdk_sdk_type_e nType, 
													  OUT int32_t& nPDLLHandle );

/** 删除SDK句柄.
 @param   IN	nPDLLHandle		SDK句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_Create成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_Destroy( IN int32_t nPDLLHandle );

/** 设置日志.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nLevel			日志等级
 @param   IN	szFilename		文件名称
 @param   IN	bScreen			是否输出到屏幕
 @param   IN	bDebugger		是否输出到调试器
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetLog( IN int32_t nPDLLHandle, 
													  IN dpsdk_log_level_e nLevel, 
													  IN const char* szFilename, 
													  IN bool bScreen, 
													  IN bool bDebugger );

/** 开始监视程序，如果程序崩溃生成dump文件
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szFilename		文件名称
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_StartMonitor( IN int32_t nPDLLHandle,  
													        IN const char* szFilename );

/** 设置DPSDK参数.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	DPSDKParam_t	参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetParam( int32_t nPDLLHandle, 
													    DPSDKParam_t* pDPSDKParam = NULL );

/** 设置平台服务在线状态回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKStatusCallback( IN int32_t nPDLLHandle, 
																	  IN fDPSDKStatusCallback fun, 
																	  IN void* pUser );

/** 设置DPSDK组织（部门辖区）变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKOrgChangeCallback( IN int32_t nPDLLHandle,
																		 IN fDPSDKOrgChangeCallback fun,
																		 IN void* pUser);
/** 登陆DSS平台.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pLoginInfo		用户登录信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Login( IN int32_t nPDLLHandle, 
													 IN Login_Info_t* pLoginInfo, 
													 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 单点登陆DSS平台.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pLoginInfo		用户登录信息，密码为加密后的密码
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SingleLogin( IN int32_t nPDLLHandle, 
														   IN Login_Info_t* pLoginInfo, 
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 认证登录预登录.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pLoginWithEncryptionInfo	认证登录信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_PreLoginWithEncryption( IN int32_t nPDLLHandle, 
																	  IN LoginWithEncryption_Info_t* pLoginWithEncryptionInfo, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 认证登录.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pLoginWithEncryptionInfo	认证登录信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoginWithEncryption( IN int32_t nPDLLHandle, 
																	 IN LoginWithEncryption_Info_t* pLoginWithEncryptionInfo, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 异步登陆DSS平台.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pLoginInfo		用户登录信息
 @param   IN	pFun            操作完成后调用此回调函数
 @param   IN    pUserParam      回传至pFun中的参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncLogin( IN int32_t nPDLLHandle, 
													 IN Login_Info_t* pLoginInfo, 
													 IN fAsyncLoginCallback pFun, 
													 IN void* pUserParam, 
													 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 登出DSS平台.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_Logout( IN int32_t nPDLLHandle, 
													  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 重连CMS.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ReconnectToCMS( IN int32_t nPDLLHandle, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 更改用户密码.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szOldPsw		原有密码
 @param   IN	szNewPsw		新密码
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ChangeUserPassword( IN int32_t nPDLLHandle, 
																 IN const char* szOldPsw,
																 IN const char* szNewPsw, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 设置Json协议回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetGeneralJsonTransportCallback(IN int32_t nPDLLHandle,
																			  IN fDPSDKGeneralJsonTransportCallback fun,
																			  IN void * pUser);

/** 设置Json协议回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetGeneralJsonTransportCallbackEx(IN int32_t nPDLLHandle,
																				IN fDPSDKGeneralJsonTransportCallbackEx fun,
																				IN void * pUser);

/**通过Json协议发送命令给平台cms/dms等模块,返回结果是json串通过DPSDK_SetGeneralJsonTransportCallback回调
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szJson			Json字符串,
@param   IN    mdltype			模块,
@param   IN    trantype			JSON 传输类型,
@param	 IN    nTimeout			超时时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GeneralJsonTransport(IN int32_t nPDLLHandle,
																   IN const char* szJson,
																   IN dpsdk_mdl_type_e mdltype, 
																   IN generaljson_trantype_e trantype,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

//////////////////////////////////////////////////////////////////////////
//设备相关功能start

/** 设置DPSDK设备变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKDeviceChangeCallback( IN int32_t nPDLLHandle, 
																			IN fDPSDKDeviceChangeCallback fun, 
																			IN void* pUser );

/** 设置DPSDK新组织设备变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKOrgDevChangeNewCallback( IN int32_t nPDLLHandle, 
																			  IN fDPSDKOrgDevChangeNewCallback fun, 
																			  IN void* pUser );

/** 设置DPSDK设备状态回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  1)登陆平台，加载组织结构以后平台会推送设备状态;2)设备状态变化会再次推送
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKDeviceStatusCallback( int32_t nPDLLHandle, 
																			fDPSDKDevStatusCallback fun, 
																			void* pUser );

/** 查询NVR通道状态(只能查询在线的NVR、SMART_NVR、EVS、NVR6000设备的通道状态)
@param   IN    nPDLLHandle     SDK句柄
@param   IN    deviceId	       设备的ID
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_QueryNVRChnlStatus( IN int32_t nPDLLHandle, 
																 IN const char* deviceId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置NVR通道状态回调
@param   IN	nPDLLHandle		SDK句柄
@param   IN	fun				回调函数
@param   IN	pUser			用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 通道状态变化的时候会推送
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetDPSDKNVRChnlStatusCallback( IN int32_t nPDLLHandle, 
																			 IN fDPSDKNVRChnlStatusCallback fun, 
																			 IN void* pUser );
/** 通过设备IP和端口以及通道号获取通道ID.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDevIp			设备IP
 @param   IN	nPort			设备port
 @param   IN	nChnlNum		通道号（从0开始）
 @param   OUT	szCameraId		通道编码
 @param	  IN	nUnitType		单元类型（1-编码单元，2-）
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCameraIdbyDevInfo( IN int32_t nPDLLHandle,
																	IN const char* szDevIp,
																	IN const int nPort,
																	IN const int nChnlNum,
																	OUT char* szCameraId,
																	IN dpsdk_dev_unit_type_e nUnitType = DPSDK_DEV_UNIT_ENC);
/** 获取通道类型
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szCameraId			通道ID
 @param   OUT	pUnitType			通道类型
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlType( IN int32_t nPDLLHandle, 
															IN char *szCameraId,
															OUT dpsdk_dev_unit_type_e* pUnitType);


/** 根据编码器通道Id获取编码器通道信息
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   OUT   pChannelInfo    通道信息，参见Enc_Channel_Info_Ex_t
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfoById(IN int32_t nPDLLHanle, 
																 IN const char *szCameraId, 
																 OUT Enc_Channel_Info_Ex_t *pChannelInfo);

/** 根据通道ID获取通道状态，不支持NVR通道状态获取
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   OUT   nStatus         状态值，参见dpsdk_dev_status_e
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelStatus(IN  int32_t nPDLLHanle, 
															   IN  const char *szCameraId, 
															   OUT dpsdk_dev_status_e &nStatus);

/** 根据通道ID获取设备厂商类型
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   OUT    nDeviceFactoryType     设备厂商值
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoById(IN  int32_t nPDLLHanle, 
																IN  const char *szCameraId, 
																OUT int32_t& nDeviceFactoryType);

/** 根据设备ID获取设备信息
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szDevId		   设备ID
@param   OUT   pDeviceInfoEx   设备信息
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoExById(IN  int32_t nPDLLHanle, 
																  IN  const char *szDevId, 
																  OUT Device_Info_Ex_t* pDeviceInfoEx);

/** 根据设备ID获取设备类型
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szDevId		   设备ID
@param   OUT   nDeviceType     设备类型
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceTypeByDevId(	IN  int32_t nPDLLHandle, 
																   IN  const char *szDevId, 
																   OUT dpsdk_dev_type_e& nDeviceType);

/** 根据通道ID获取设备ID.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szChanId		通道编号
 @param   OUT	szDevId			设备编号
 @return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevIdByChnId( IN int32_t nPDLLHandle, 
															   IN char* szChanId,
															   OUT char* szDevId);

/** 获取设备下编码通道的个数
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	szDeviceId			设备ID
 @param   OUT	nEncChannelCount	编码通道个数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetEncChannelCount( IN int32_t nPDLLHandle, 
																	IN const char *szDeviceId,
																	OUT int32_t& nEncChannelCount);
/** 获取设备下编码器通道的信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		子通道信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pEncChannelnfo需要在外面创建好
 2、pEncChannelnfo的大小与DPSDK_GetDGroupInfo中通道个数返回需要一致
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfo( IN int32_t nPDLLHandle, 
															  INOUT Get_Channel_Info_t* pGetInfo );

/** 获取组织下编码器通道的信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		子通道信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pEncChannelnfo需要在外面创建好
 2、pEncChannelnfo的大小与DPSDK_GetDGroupInfo中通道个数返回需要一致
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDepChannelInfo( IN int32_t nPDLLHandle, 
															  INOUT Get_Dep_Channel_Info_t* pGetInfo );

/** 获取设备下编码器通道的信息(扩展).
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		子通道信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pEncChannelnfo需要在外面创建好
 2、pEncChannelnfo的大小与DPSDK_GetDGroupInfo中通道个数返回需要一致
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChannelInfoEx( IN int32_t nPDLLHandle, 
																INOUT Get_Channel_Info_Ex_t* pGetInfo );


/** 获取设备支持的码流类型.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		获取信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevStreamType( IN int32_t nPDLLHandle, 
																INOUT Get_Dev_StreamType_Info_t* pGetInfo );

/** 获取设备列表信息长度.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nGroupLen       设备列表信息长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceListLen( IN int32_t nPDLLHandle,
															    OUT int32_t& nDevListLen, 
															    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取设备列表信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	szDevList       设备列表xml字符串
 @param   IN	nGroupLen       设备列表信息长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
     1、需要2次函数调用才能最终获取设备列表信息。
     2、先使用DPSDK_GetDeviceListLen，获取nDevListLen的值。
	 3、获取到nDevListLen的值之后，创建一个长度为（nDevListLen+1）的char数组，并作为参数szDevList传入。
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceListStr( IN int32_t nPDLLHandle,
															    OUT char *szDevList,
															    IN int32_t nDevListLen, 
															    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取多个设备详细信息长度.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDevicesId     需要查询的多个设备ID字符串数组
 @param   IN	nDevicesCount   设备ID字符串数组的长度
 @param   OUT   nDevInfoLen     需要查询的多个设备详细信息组成的xml字符串的长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevicesInfoLen( IN int32_t nPDLLHandle,
															     OUT int32_t& nDevInfoLen );

/** 获取多个设备详细信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	szDevicesInfo   需要查询的多个设备详细信息组成的xml字符串
 @param   IN	nDevInfoLen     设备详细信息组成的xml字符串的长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
     1、需要2次函数调用才能最终获取设备列表信息。
     2、先使用DPSDK_GetDevicesInfoLen获取nDevicesCount的值。
	 3、获取到nDevicesCount的值之后，创建一个长度为（nDevicesCount+1）的char数组，并作为参数szDevicesInfo传入。
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDevicesInfoStr( IN int32_t nPDLLHandle,
																 OUT char* szDevicesInfo, 
															     IN int32_t nDevInfoLen );

/** 从服务器获取设备信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDeviceId		设备ID
 @param   OUT   pDeviceInfoEx   设备信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeviceInfoFromService( IN int32_t nPDLLHandle, 
																		IN const char* szDeviceId,
																		OUT Device_Info_Ex_t* pDeviceInfoEx, 
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

//设备相关功能end
//////////////////////////////////////////////////////////////////////////

/** 获取电子地图服务配置信息
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	mapAddrInfo		电子地图服务配置信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetMapAddrInfo( IN int32_t nPDLLHandle, 
																OUT Config_Emap_Addr_Info_t& mapAddrInfo,
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 保存操作员日志
 @param   IN	nPDLLHandle		 SDK句柄
 @param   IN	szCameraId		 通道编号
 @param   IN    optTime			 操作时间
 @param   IN    optType	         操作类型
 @param   IN    optDesc		     操作描述
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveOptLog(  IN int32_t nPDLLHandle,
														   IN const char* szCameraId,
														   IN uint64_t optTime,
														   IN dpsdk_log_optType_e optType,
														   IN const char* optDesc);
/** 上传文件
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	stuFileInfo		文件信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveRemoteFile( IN int32_t nPDLLHandle, 
															  IN Save_File_Info stuFileInfo,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 文件操作结果回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
	1、需要和DPSDK_Create成对使用
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetOperatorRemoteFileCallback( IN int32_t nPDLLHandle, 
																			 IN fDPSDKOperatorRemoteFileCallback fun, 
																			 IN void* pUser );

/** 设置收到别人分享视频消息后的回调函数
@param   IN    nPDLLHandle     SDK句柄
@param   IN    fun             回调函数
@param   IN    pUser           用户参数
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetShareVideoCallback(IN int32_t nPDLLHandle,
																	IN fDPSDKShareVideoCallback fun, 
																	IN void* pUser);

/** 分享视频
@param   IN    nPDLLHandle     SDK句柄
@param   IN    pVideoInfo	   分享的视频信息结构数组
@param   IN    nVideoCount	   视频信息数组的长度
@param   IN    pUserId	       分享对象用户ID数组
@param   IN    nUserCount	   分享对象的数量
@param   IN    szMsg	       附加的信息
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ShareVideo(IN int32_t nPDLLHanle,
														 IN ShareVideoInfo* pVideoInfo,
														 IN int32_t nVideoCount,
														 IN int32_t* pUserId,
														 IN int32_t nUserCount,
														 IN const char* szMsg,
														 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 取消异步操作
@param   IN    nPDLLHandle     SDK句柄
@param   IN    nSeq     	   要取消的操作的序号值
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CancelOperationBySeq(IN int32_t nPDLLHandle,
																  IN int32_t nSeq);

/** 获取用户详情.以后有关用户的信息都在DPSDK_UserInfo_t里面增加
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pstruUserInfo	用户信息结构体
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark	
 1、登陆平台以后用户信息已经获取到
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserInfo( IN int32_t nPDLLHandle, 
															OUT DPSDK_UserInfo_t& pstruUserInfo, 
															IN int32_t nTimeout= DPSDK_CORE_DEFAULT_TIMEOUT );


/** 获取用户组织信息长度
@param  IN		nPDLLHandle     SDK句柄
@param  OUT		nLen			长度
@param	IN		nTimeout		超时时间
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserOrgInfoLen(IN int32_t nPDLLHandle, 
																OUT int32_t* pLen,
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取用户组织信息字符串
@param  IN		nPDLLHandle     SDK句柄
@param  OUT		szOrgInfo		用户组织信息
@param  IN		nLen			长度
@param	IN		nTimeout		超时时间
@return	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserOrgInfo(IN int32_t nPDLLHandle, 
															 OUT char* szUserOrgInfo,
															 IN int32_t nLen,
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取收藏夹xml长度.
 @param   IN	nPDLLHandle		SDK句柄
  @param   int	nDepInfoAllLen	收藏夹信息
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFavoriteLen(int32_t nPDLLHandle, int& nDepInfoAllLen, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取收藏夹.
 @param   IN	nPDLLHandle		SDK句柄
  @param   OUT	szDepInfoAll	收藏夹信息
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFavorite(int32_t nPDLLHandle, char* szDepInfoAll, int32_t nLen, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 保存收藏夹.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szDepInfoAll	收藏夹信息
 @param		IN		nTimeout			超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SaveFavorite(int32_t nPDLLHandle, char* szDepInfoAll, int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 用户数据变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDataChangeCallback(  int32_t nPDLLHandle, 
																	fDPSDKDataChangeCallback fun, 
																	void* pUser );

/** 开始录像并返回平台开始时间
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   OUT   startTime       平台开始录像时间
@param   IN    streamType      码流类型
@param   IN    nTimeout        超时时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StartRecordWithTimeRet(IN int32_t nPDLLHandle,
																	 IN  const char *szCameraId, 
																	 OUT long& startTime,
																	 IN dpsdk_stream_type_e streamType = DPSDK_CORE_STREAMTYPE_MAIN,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 结束录像并返回平台结束时间
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szCameraId      通道ID
@param   OUT   startTime       平台结束录像时间
@param   IN    nTimeout        超时时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_StopRecordWithTimeRet(IN int32_t nPDLLHandle,
																	IN  const char *szCameraId, 
																	OUT long& stopTime,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 通过工地号查询通道ID列表
@param   IN    nPDLLHandle     SDK句柄
@param   IN    nSiteCode       工地号
@param   OUT   nChnlIdCount    通道ID数量
@param   IN    nTimeout        超时时间
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryChnlIdBySiteCode(IN int32_t nPDLLHandle,
																	IN int32_t nSiteCode,
																	OUT int32_t& nChnlIdCount,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 通过工地号获取通道ID列表
@param   IN    nPDLLHandle     SDK句柄
@param   IN    nSiteCode       工地号
@param   OUT   pChnlIdInfo     通道信息
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
  1、必须先查询后获取
  2、DPSDK_QueryChnlIdBySiteCode会返回通道ID数量
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlIdBySiteCode(IN int32_t nPDLLHandle,
																  IN int32_t nSiteCode,
																  OUT ChnlIdBySiteCode_Info_t* pChnlIdInfo);


/** 查询服务列表，建立服务连接（不用加载组织结构也可以控制云台、接收报警、接收设备状态上报）
@param   IN    nPDLLHandle     SDK句柄
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryServerList(int32_t nPDLLHandle);


/** 全网校时开关
@param   IN    nPDLLHandle     SDK句柄
@param   IN    bOpen		   开关标志，ture开，false关
@return  函数返回错误类型，参考dpsdk_retval_e
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetSyncTimeOpen(int32_t nPDLLHandle, bool bOpen);


/** 查询电视墙列表个数.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  OUT	nCount			返回个数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTvWallList( IN int32_t nPDLLHandle, 
															   OUT uint32_t& nCount, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 查询电视墙布局信息
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	nTvWallId		电视墙ID
 @param	  OUT	nCount			返回个数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryTvWallLayout( IN int32_t nPDLLHandle, 
																 IN int32_t nTvWallId, 
																 OUT uint32_t& nCount, 
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**通过Json协议发送命令给cms.(使用通用json接口和回调接口)
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szJson			Json字符串,
形如:"{ \"DevID\": \"1000000\",\"CameraId\":\"1000000$1$0$1\", \"DevChannel\": 1,\"PicNum\": 1,\"CourtTime\": \"2014-09-17 16:00:00\"}"
@param   OUT   szJsonResult		平台返回的Json字符串,
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCammandToCMSByJson(IN int32_t nPDLLHandle,
																	 IN const char* szJson, 
																	 OUT char* szJsonResult,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/**通过Json协议发送命令给DMS.(使用通用json接口和回调接口)
@param   IN    nPDLLHandle		SDK句柄
@param   IN    szJson			Json字符串,
形如:"{ \"DevID\": \"1000000\",\"CameraId\":\"1000000$1$0$1\", \"DevChannel\": 1,\"PicNum\": 1,\"CourtTime\": \"2014-09-17 16:00:00\"}"
@param   IN    szDeviceId		设备ID,
@param   OUT   szJsonResult		平台返回的Json字符串,
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendCammandToDMSByJson(IN int32_t nPDLLHandle,
																	 IN const char* szJson,
																	 IN const char* szDeviceId,
																	 OUT char* szJsonResult,
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置事件上报回调（康特尔需求定制）.
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    fun             回调函数
 @param   IN    pUser           用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKIssueCallback(IN int32_t nPDLLHandle,
																	IN fDPSDKIssueCallback fun, 
																	IN void* pUser);
/** 获取用户Id (获取用户信息包含了id).
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nUserId			用户Id
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserID( IN int32_t nPDLLHandle, 
														 OUT uint32_t& nUserId );
/** 获取用户等级(获取用户信息包含了等级).
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nUserLevel		用户等级
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUserLevel( IN int32_t nPDLLHandle, 
															OUT uint32_t& nUserLevel );

/** 获取部门和辖区关系记录数.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT    nCount         记录数目
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDeptAreaRelationCount( IN int32_t nPDLLHandle, 
																		OUT int32_t& nCount,
																		IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** 获取部门和辖区关系记录.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT pGetInfo        获取部门辖区关系请求信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetAllDeptAreaRelation( IN int32_t nPDLLHandle, 
																	  INOUT Get_DeptArea_Relation_t* pGetInfo);

/** 加载所有人员信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	nPersonCount	所有人员数目
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadAllPersonInfo( IN int32_t nPDLLHandle, 
																 OUT int32_t& nPersonCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);
/** 获取特定部门的所有人员数.
 @param   IN	nPDLLHandle	   SDK句柄
 @param   IN szDeptCode        部门编号
 @param   IN nPersonCount      人数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPersonCountByDept( IN int32_t nPDLLHandle, 
																	IN char* szDeptCode,
																	OUT int32_t& nPersonCount);
/** 获取部门的所有人员信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT pGetInfo        人员信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetPersonInfoByDept( IN int32_t nPDLLHandle, 
															       INOUT Get_Person_Info_t * pGetInfo);
/** 设置DPSDK人员变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKPersonChangeCallback( IN int32_t nPDLLHandle,
																			IN fDPSDKPersonChangeCallback fun,
																			IN void* pUser);
/** 设置DPSDK关联关系变更回调.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	fun				回调函数
 @param   IN	pUser			用户参数
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetDPSDKRelationChangeCallback( IN int32_t nPDLLHandle,
																			  IN fDPSDKRelationChangeCallback fun,
																			  IN void* pUser);

/** 获取平台当前时间
 @param   IN    nPDLLHandle		SDK句柄
 @param   OUT	lCurTime		平台当前时间
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetCurrentPlatformTime( IN int32_t nPDLLHandle, 
																	 OUT long& lCurTime, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 京东项目在线视频播放鉴权
 @param   IN    nPDLLHandle		SDK句柄
 @param   IN	szIP			京东平台IP
 @param	  IN	nPort			京东平台端口
 @param   IN	szDvrCode		硬盘录像机编码
 @param   IN	szToken			访问令牌
 @param   OUT	bSuccess		鉴权结果
 @param   OUT	szErrMsg		错误信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CheckRealPlayAuth( IN int32_t nPDLLHandle,
																 IN const char* szIP,
																 IN int nPort,
																 IN const char* szDvrCode,
																 IN const char* szToken,
																 OUT bool& bSuccess,
																 OUT char* szErrMsg,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 京东项目预约历史视频播放鉴权
 @param   IN    nPDLLHandle		SDK句柄
 @param   IN	szIP			京东平台IP
 @param	  IN	nPort			京东平台端口
 @param   IN	szFileId		历史视频ID
 @param   IN	szToken			访问令牌
 @param   OUT	bSuccess		鉴权结果
 @param   OUT	szErrMsg		错误信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CheckPlaybackAuth( IN int32_t nPDLLHandle,
																 IN const char* szIP,
																 IN int nPort,
																 IN const char* szFileId,
																 IN const char* szToken,
																 OUT bool& bSuccess,
																 OUT char* szErrMsg,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 对外写日志接口.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	nLog			日志内容
 @param   IN	ntype			日志类型dpsdk_log_type_e
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_WriteDPSDKLog(int32_t nPDLLHandle,const char* nLog, int32_t ntype = 0);

/**	呼市药监局项目，根据通道名称获取通道ID
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szChnlName		通道名称
 @param   OUT	szChnlID		通道ID
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  需要平台上没有重复的通道名称，如果有重复的该接口只会返回第一个匹配的通道ID，调用此接口前需要先加载组织结构
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlIDByChnlName( IN int32_t nPDLLHandle,
																   IN const char* szChnlName,
																   OUT char* szChnlID );

/** 设置流媒体服务断开回调 
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	pFun			流媒体服务断开回调函数指针
 @param		IN	UserParam		用户参数.
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	实时，回放都会回调通知，收到通知，表示vaxplayer播放库初始化成功
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetVideoRTSPDisConnectCallback(int32_t nPDLLHandle, fVideoRTSPDisConnectCallback pFun, void* UserParam);

/** 连接SCS 
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	szScsIp			服务IP地址
 @param		IN	nScsPort		服务端口号.
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ConnectToSCS( IN int32_t nPDLLHandle, IN const char* szScsIp, IN int32_t nScsPort, IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 连接SCS 
 @param		IN	nPDLLHandle		SDK句柄
 @param		IN	szScsIp			服务IP地址
 @param		IN	nScsPort		服务端口号.
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ConnectToSCSWithCallNumber( IN int32_t nPDLLHandle, IN const char* szScsIp, IN int32_t nScsPort, IN const char* szCallNumber, IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取FTP信息
 @param		IN	nPDLLHandle		SDK句柄
 @param		OUT	szFtpInfo			存放FTP信息的缓冲区
 @param		IN	iSize		存放FTP信息的缓冲区大小
 @return	函数返回错误类型，参考dpsdk_retval_e
 @remark	返回的FTP信息格式如： ftp://user:passwd@172.7.8.9
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFTPInfo( IN int32_t nPDLLHandle, OUT char* szFtpInfo, IN int iSize);

/** 查询轮巡任务列表.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nSwitchTaskCount轮巡任务数量
 @param	  IN	nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QuerySwitchListEx(IN int32_t nPDLLHandle,
																OUT int32_t& nSwitchTaskCount, 
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 获取轮巡任务列表.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pSwitchTaskInfo	轮巡任务列表
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetSwitchList(IN int32_t nPDLLHandle,
															OUT Switch_Task_Info_t* pSwitchTaskInfo);

/** 查询轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    iTaskId			轮巡任务ID
 @param   OUT   pTaskInfo		轮巡任务详细信息（参考TaskInfo_t）
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD QuerySwitchInfo(IN int32_t nPDLLHandle,
														IN const unsigned int iTaskId, 
														OUT TaskInfo_t* pTaskInfo);

/** 查询轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    iTaskId			轮巡任务ID
 @param   OUT   pTaskInfo		轮巡任务详细信息（参考TaskInfo_t）
 @return  函数返回错误类型，参考dpsdk_retval_e	
 需要调用两次，第一次获取窗口数量，分配内存之后再次调用获取任务信息
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QuerySwitchInfoEx(IN int32_t nPDLLHandle, 
																IN const unsigned int iTaskId, 
																OUT TaskInfoEx_t* pTaskInfoEx);

/** 释放轮巡任务通道信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    pTaskChnlInfoEx	轮巡任务通道信息
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_FreeTaskChnlInfoEx(IN int32_t nPDLLHandle, 
																IN TaskChnlInfoEx_t* pTaskChnlInfoEx);

/** 修改轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄
 @param	  IN	iTaskId：		任务Id
 @param	  IN	nWindowCount	窗口数
 @param	  IN	struTaskInfoEx	自定窗口信息以及窗口信息列表
 @param	  IN	nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ModifySwitchEx(IN int32_t nPDLLHandle, 
															 IN const unsigned int iTaskId, 
															 IN int32_t nWindowCount, 
															 IN TaskInfoEx_t& struTaskInfoEx, 
															 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 添加轮巡任务.
 @param   IN	nPDLLHandle		SDK句柄
 @param	  OUT   iTaskId,		任务Id
 @param	  IN	nWindowCount	窗口数
 @param	  IN	struTaskInfoEx	自定窗口信息以及窗口信息队列
 @param	  IN	nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AddSwitchEx(IN int32_t nPDLLHandle, 
														  OUT unsigned int& iTaskId, 
														  IN int32_t nWindowCount, 
														  IN TaskInfoEx_t& struTaskInfoEx, 
														  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/** 删除轮巡任务.
 @param   IN		nPDLLHandle		SDK句柄
 @param   IN		iTaskId			轮巡任务ID
 @param	  IN		nTimeout		超时时间
 @return  函数返回错误类型，参考dpsdk_retval_e	
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DelSwitch(IN int32_t nPDLLHandle, 
												  IN const unsigned int iTaskId, 
												  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

//////////////////////////////////////////////////////////////////////////
//以下接口为废弃接口，但为保持兼容性，仍然保留接口
//remove interface begin
//以上接口为废弃接口，但为保持兼容性，仍然保留接口
//remove interface end
#endif
