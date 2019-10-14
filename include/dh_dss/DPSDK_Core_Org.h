#ifndef INCLUDED_DPSDK_ORG_H
#define INCLUDED_DPSDK_ORG_H

/** 加载组织设备信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	nGroupLen       组织结构信息长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadDGroupInfo( IN int32_t nPDLLHandle, 
															  OUT int32_t& nGroupLen, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 获取组织下子组织和子设备的个数.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		获取组织个数请求信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupCount( IN int32_t nPDLLHandle, 
															  INOUT Get_Dep_Count_Info_t* pGetInfo );
/** 获取组织下子组织和子设备的信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		子组织子设备信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pDepInfo、pDeviceInfo需要在外面创建好
 2、pDepInfo、pDeviceInfo的大小与DPSDK_GetDGroupCount返回需要一致
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupInfo( IN int32_t nPDLLHandle, 
															 INOUT Get_Dep_Info_t* pGetInfo );

/** 获取组织下子组织、子设备、子通道的信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   INOUT	pGetInfo		子组织子设备通道信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、pDepInfo、pDeviceInfo需要在外面创建好
 2、pDepInfo、pDeviceInfo的大小与DPSDK_GetDGroupCount返回需要一致
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupInfoEx( IN int32_t nPDLLHandle, 
															 INOUT Get_Dep_Info_Ex_t* pGetInfo );

/** 设置缓存组织树文件路径.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	szFilePath		文件路径,android默认为"/sdcard"
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、szFilePath android默认为"/sdcard"
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetSaveGroupFilePath( IN int32_t nPDLLHandle, 
																	IN const char* szFilePath );

/** 异步加载组织设备信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pFun            操作完成后调用此回调函数
 @param   IN    pUserParam      回传至pFun中的参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
          DPSDK_AsyncLoadDGroupInfo在加载组织后，会立即返回，在线程中等待加载完成，完成后调用回调pFun.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncLoadDGroupInfo( IN int32_t nPDLLHandle, 
															  IN fAsyncLoadDGroupInfoCallback pFun,
															  IN void* pUserParam,
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 异步加载组织设备信息，并返回操作序列号
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    nGroupSeq       操作序列号
 @param   IN	pFun            操作完成后调用此回调函数
 @param   IN    pUserParam      回传至pFun中的参数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark.
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_AsyncLoadDGroupInfoWithSeq( IN int32_t nPDLLHandle,
																  OUT int32_t& nGroupSeq,
																  IN fAsyncLoadDGroupInfoCallback pFun,
																  IN void* pUserParam,
																  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取组织结构时，设置是否采用压缩格式获取.
 @param   IN	nPDLLHandle			SDK句柄
 @param   IN	nCompressType		是否采用压缩格式
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark									
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD	DPSDK_SetCompressType( IN int32_t nPDLLHandle, 
																IN dpsdk_get_devinfo_compress_type_e nCompressType);


/** 分级加载组织设备信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN	pGetInfo		分级获取的节点信息 
 @param   OUT	nGroupLen       组织结构信息长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadDGroupInfoLayered( IN int32_t nPDLLHandle, 
																	 IN Load_Dep_Info_t* pGetInfo, 
																	 OUT int32_t& nGroupLen, 
																	 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取组织设备信息串.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	szGroupBuf		组织结构缓存,需要外部创建缓存，大小为nGroupLen+1
 @param   IN	nGroupLen       组织结构信息长度
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、szGroupBuf需要在外面创建好
 2、szGroupBuf的大小与nGroupLen需要一致或者大于nGroupLen
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupStr( IN int32_t nPDLLHandle, 
															OUT char* szGroupBuf, 
															IN int32_t nGroupLen, 
															IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取分级加载的组织设备信息串.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	szGroupBuf		组织结构缓存,需要外部创建缓存，大小为nGroupLen+1
 @param   IN	nGroupLen       组织结构信息长度
 @param   IN	szCoding		节点code
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
 1、szGroupBuf需要在外面创建好
 2、szGroupBuf的大小与nGroupLen需要一致或者大于nGroupLen
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupLayeredStr( IN int32_t nPDLLHandle, 
																   OUT char* szGroupBuf, 
																   IN int32_t nGroupLen,
																   IN const char* szCoding, 
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取根节点信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pGetInfo		根节点信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetDGroupRootInfo(IN int32_t nPDLLHandle,
																OUT Dep_Info_t* pGetInfo );
/** 加载特定类型组织信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    type            通用节点类型
 @param   OUT	nOrgCount       返回组织信息的数量
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_LoadOrgInfoByType( IN int32_t nPDLLHandle, 
																 IN dpsdk_org_node_e type,
																 OUT int32_t& nOrgCount,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取组织下子组织个数.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    type            节点类型
 @param   INOUT	pGetInfo        获取组织个数请求信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOrgCountByType( IN int32_t nPDLLHandle, 
																 IN dpsdk_org_node_e type,
																 INOUT Get_Org_Count_Info_t* pGetInfo );

/** 获取组织下子组织和子设备的信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   IN    type            组织类型
 @param   INOUT	pGetInfo       获取组织请求信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOrgInfoByType( IN int32_t nPDLLHandle, 
																IN dpsdk_org_node_e type,
																INOUT Get_Org_Info_t* pGetInfo);

/** 清除子组织和子设备信息.
 @param   IN	nPDLLHandle		SDK句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearDGroupInfo( IN int32_t nPDLLHandle );

/** 根据国标编码获取通道ID.
 @param   IN	nPDLLHandle		SDK句柄
 @param	  IN	szChnlSn		国标编码
 @param	  OUT	szChnlId		通道ID
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark		
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetChnlIdBySn( IN int32_t nPDLLHandle,
															 IN const char* szChnlSn,
															 OUT char* szChnlId );
//////////////////////////////////////////////////////////////////////////
//逻辑组织树start

/** 是否有业务树
 @param   IN	nPDLLHandle		SDK句柄
 @return  函数返回true表示含有业务树，否则表示没有业务树
 @remark
*/
DPSDK_DLL_API bool DPSDK_CALL_METHOD DPSDK_HasLogicOrg(IN int32_t nPDLLHandle);

/** 获取业务树根节点信息.
 @param   IN	nPDLLHandle		SDK句柄
 @param   OUT	pDepInfoEx		业务树根节点信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicRootDepInfo(IN int32_t nPDLLHandle,
																OUT Dep_Info_Ex_t* pDepInfoEx );

/** 获取业务树指定节点下 节点/通道/设备的数目
 @param   IN	nPDLLHandle						SDK句柄
 @param   IN    szDepCoding						节点Coding
 @param   IN    nNodeType						组织/通道/设备
 @param   OUT   pnDepNodeNum					节点下 节点/通道/设备的数目
 @return  函数返回错误类型，参考dpsdk_retval_e 
 @remark 
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicDepNodeNum(IN int32_t nPDLLHandle,
																  IN char* szDepCoding, 
																  IN dpsdk_node_type_e nNodeType, 
																  OUT int32_t* pnDepNodeNum);

/** 获取业务树指定节点下 节点信息
 @param   IN	nPDLLHandle						SDK句柄
 @param   IN    szDepCoding						节点Coding
 @param   IN    nIndex							序号
 @param   OUT   pDepInfoEx						组织节点信息
 @return  函数返回错误类型，参考dpsdk_retval_e 
 @remark    
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicSubDepInfoByIndex(IN int32_t nPDLLHandle, 
																		IN char* szDepCoding, 
																		IN int32_t nIndex, 
																		OUT Dep_Info_Ex_t* pDepInfoEx);

/** 获取业务树指定节点下 设备或者通道ID
 @param   IN	nPDLLHandle						SDK句柄
 @param   IN    szDepCoding						节点Coding
 @param   IN    nIndex							序号
 @param   IN	bChnl							=true 为通道，否则是设备
 @param   OUT	szCodeID						节点ID
 @return  函数返回错误类型，参考dpsdk_retval_e 
 @remark     
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetLogicID(IN int32_t nPDLLHandle, 
														  IN char* szDepCoding, 
														  IN int nIndex, 
														  IN bool bChnl, 
														  OUT char* szCodeID);


//逻辑组织树end

#endif