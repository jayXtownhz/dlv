#ifndef INCLUDED_DPSDK_CORE_FTP_H
#define INCLUDED_DPSDK_CORE_FTP_H

/** 根据时间段查询FTP图片信息
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    szCameraId      通道编号
 @param   IN    nBeginTime      开始时间
 @param   IN    nEndTime		结束时间
 @param   IN    nTimeout        超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_QueryFtpPic(IN int32_t nPDLLHandle,
															IN const char *szCameraId, 
															IN uint64_t nBeginTime,
															IN uint64_t nEndTime,
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);


/** 获取Ftp图片信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	ftpPicInfo		Ftp图片信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
   1、必须先查询后获取
   2、DPSDK_QueryFtpPic会返回记录个数,
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetFtpPicInfo( IN int32_t nPDLLHandle, 
															 OUT Ftp_Pic_Info_t &ftpPicInfo );

/** 删除FTP图片信息
 @param   IN    nPDLLHandle     SDK句柄
 @param   IN    szFtpPicPath	Ftp图片路径
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_DelFtpPic(IN int32_t nPDLLHandle,
														IN const char *szFtpPicPath);

/** 图片上传至Ftp
@param    IN    nPDLLHandle    SDK句柄
@param    IN    szCameraId     截图来源的那个CameraId
@param    IN    nCaptureTime   截图的时间
@param    IN    szLocalFile    本地图片的全路径
@param    IN    szFtpAddr      ftp的地址，形式如"ftp://172.7.2.249"
@param    IN    szName         ftp的登陆名
@param    IN    szPwd          ftp的登陆密码
@return   函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_UploadFtpPic(IN int32_t nPDLLHandle, 
														   IN const char* szCameraId, 
														   IN uint64_t nCaptureTime, 
														   IN const char* szLocalFile, 
														   IN const char* szFtpAddr, 
														   IN const char* szName, 
														   IN const char* szPwd,  
														   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 操作Ftp文件
@param   IN    nPDLLHandle     SDK句柄
@param   IN    szLocalFile	   要上传或下载后的本地文件名称
@param   IN    szFtpFile	   要操作的Ftp目录上的文件完整路径（以ftp:开头）
@param   IN    szName	       登陆Ftp的用户名
@param   IN    szPwd	       登陆Ftp的密码
@param   IN    opType	       操作类型，包括上传，下载，删除。
@return  函数返回错误类型，参考dpsdk_retval_e
@remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperatorFtpFile(IN int32_t nPDLLHandle,
															  IN const char* szLocalFile,
															  IN const char* szFtpFile,
															  IN const char* szName,
															  IN const char* szPwd,
															  IN dpsdk_operator_ftp_type_e opType,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );


/** 图片上传到Ftp的URL
@param    IN    nPDLLHandle    SDK句柄
@param    IN    szCameraId     截图来源的那个CameraId
@param    IN    nCaptureTime   截图的时间
@param    IN    szLocalFile    本地图片的全路径
@param    IN    szFtpAddr      ftp的地址，形式如"ftp://172.7.2.249"
@param	  OUT	szFtpUrl	   URL
@param	  IN	nUrlLen		   URL字符串长度
@return   函数返回错误类型，参考dpsdk_retval_e
@remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetUploadFtpPicUrl(IN int32_t nPDLLHandle, 
																IN const char* szCameraId, 
																IN uint64_t nCaptureTime, 
																IN const char* szLocalFile, 
																IN const char* szFtpAddr, 
																OUT char* szFtpUrl,
																IN int32_t nUrlLen,
																IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
#endif