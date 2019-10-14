#ifndef INCLUDED_DPSDK_CORE_TVWALL_H
#define INCLUDED_DPSDK_CORE_TVWALL_H



//////////////////////////////////////////////////////////////////////////
// 电视墙业务接口 开始

/** 查询电视墙列表个数.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  OUT	nCount			返回个数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallListCount(int32_t nPDLLHandle, 
															   uint32_t* nCount, 
															   int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取电视墙列表信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pInfo			电视墙列表信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallList( IN int32_t nPDLLHandle, 
															 INOUT TvWall_List_Info_t* pTvWallListInfo );

/** 查询电视墙布局信息
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	nTvWallId		电视墙ID
 @param	  OUT	nCount			返回个数
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallLayoutCount(int32_t nPDLLHandle, 
																 int32_t nTvWallId, 
																 uint32_t* nCount, 
																 int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 获取电视墙布局信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pInfo			电视墙布局信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallLayout( IN int32_t nPDLLHandle, 
															   INOUT TvWall_Layout_Info_t* pTvWallLayoutInfo );


/** 获取OSD信息模板信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @return  函数返回错误类型，参考dpsdk_retval_e
 @param   IN	nTimeout		超时时长，单位毫秒
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetOSDTemplatInfo( IN int32_t nPDLLHandle, 
															  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 修改OSD信息模板信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param    IN Ope_OSD_Templat_Info_t     操作信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @param   IN	nTimeout		超时时长，单位毫秒
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_OperateOSDTemplatInfo(IN int32_t nPDLLHandle,
																	IN Ope_OSD_Templat_Info_t* pOpeInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 查询OSD历史信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param    IN Search_History_OSDInfo_t     查询信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @param   IN	nTimeout		超时时长，单位毫秒
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SearchHistoryOSDInfo(IN int32_t nPDLLHandle,
																   IN Search_History_OSDInfo_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 发送OSD信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param    IN Send_OSDInfo_t     osd信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @param   IN	nTimeout		超时时长，单位毫秒
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendOSDInfo(IN int32_t nPDLLHandle,
																   IN Send_OSDInfo_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 发送SMS信息.
 @param	  IN	nPDLLHandle		SDK句柄
 @param    IN Send_SMS_Info_t     sms信息
 @return  函数返回错误类型，参考dpsdk_retval_e
 @param   IN	nTimeout		超时时长，单位毫秒
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SendSMSInfo(IN int32_t nPDLLHandle,
																   IN Send_SMS_Info_t* pOpeInfo,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 画中画分屏功能
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pPipTvWallInfo		画中画分屏
 @param   IN	nScreenId		屏ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetPipTvWallScreen( IN int32_t nPDLLHandle, 
																   IN Pip_TvWall_Screen_Info_t* pPipTvWallInfo,
																   IN int32_t nScreenId,
																   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 屏分割.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pSplitInfo		电视墙屏分割信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetTvWallScreenSplit( IN int32_t nPDLLHandle, 
																	IN TvWall_Screen_Split_t* pSplitInfo,
																	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );
/** 屏开窗.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pOpenWindowInfo		电视墙屏开窗信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenOpenWindow( IN int32_t nPDLLHandle, 
																	  INOUT TvWall_Screen_Open_Window_t* pOpenWindowInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 窗口移动.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  INOUT	pMoveWindowInfo		电视墙屏窗口移动信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenMoveWindow( IN int32_t nPDLLHandle, 
																	  INOUT TvWall_Screen_Move_Window_t* pMoveWindowInfo,
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 屏关窗.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pCloseWindowInfo		电视墙屏关窗信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenColseWindow( IN int32_t nPDLLHandle, 
																	   IN TvWall_Screen_Close_Window_t* pCloseWindowInfo,
																	   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 屏窗口置顶（对于开窗有效）.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pTopWindowInfo		电视墙屏窗口置顶信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_TvWallScreenSetTopWindow( IN int32_t nPDLLHandle, 
																     	IN TvWall_Screen_Set_Top_Window_t* pTopWindowInfo,
																     	IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 设置屏窗口视频源.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pWindowSourceInfo		电视墙屏窗口视频源信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_SetTvWallScreenWindowSource( IN int32_t nPDLLHandle, 
															        	   IN Set_TvWall_Screen_Window_Source_t* pWindowSourceInfo,
																           IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 关闭屏窗口视频源.
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	pCloseSourceInfo		电视墙屏窗口关闭视频源信息
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_CloseTvWallScreenWindowSource( IN int32_t nPDLLHandle, 
																	         IN TvWall_Screen_Close_Source_t* pCloseSourceInfo,
																	         IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 清空电视墙屏  
 @param   此接口存在问题，当电视墙绑定多个解码器id时，只能清除一个解码器id的屏，请使用接口DPSDK_ClearTvWallScreenByDecodeId
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	nTvWallId		电视墙ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearTvWallScreen( IN int32_t nPDLLHandle, 
																 IN int32_t nTvWallId,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/** 根据解码器ID清空电视墙屏
 @param	  IN	nPDLLHandle		SDK句柄
 @param	  IN	nTvWallId		电视墙ID
 @param	  IN	szDecodeId		解码器ID
 @param   IN	nTimeout		超时时长，单位毫秒
 @return  函数返回错误类型，参考dpsdk_retval_e
 @remark  
*/
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_ClearTvWallScreenByDecodeId(int32_t nPDLLHandle, 
																int32_t nTvWallId,
																const char* szDecodeId,
																int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT );

/* @fn    
 * @brief 获取电视墙任务列表总数
 * @param <IN>		nPDLLHandle		SDK句柄
 * @param <IN>		nTvWallId		电视墙ID
 * @param <OUT>		nCount			返回个数 
 * @param <IN>		nTimeout		超时时长，单位毫秒
 * @return 函数返回错误类型，参考dpsdk_retval_e.
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallTaskListCount( IN int32_t nPDLLHandle, 
																	  IN uint32_t nTVWallId,
																	  OUT uint32_t* nCount, 
																	  IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/* @fn    
 * @brief 获取电视墙任务列表信息
 * @param <IN>		nPDLLHandle		SDK句柄
 * @param <IN>		nTvWallId		电视墙ID
 * @param <OUT>		pTVWallTaskInfoList		电视墙任务列表信息 
 * @param <IN>		nTimeout		超时时长，单位毫秒
 * @return 函数返回错误类型，参考dpsdk_retval_e.
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallTaskList( IN int32_t nPDLLHandle, 
																 IN uint32_t nTVWallId,
																 INOUT TvWall_Task_Info_List_t* pTVWallTaskInfoList,
																 IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/* @fn    
 * @brief 获取电视墙任务信息长度
 * @param <IN>		nPDLLHandle		SDK句柄
 * @param <IN>		nTvWallId		电视墙ID
 * @param <IN>		nTaskId		    电视墙任务ID
 * @param <OUT>		pTaskInfoLen	电视墙任务信息长度 
 * @param <IN>		nTimeout		超时时长，单位毫秒
 * @return 函数返回错误类型，参考dpsdk_retval_e.
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallTaskInfoLen( IN int32_t nPDLLHandle, 
																    IN uint32_t nTVWallId, 
																    IN uint32_t nTaskId,
																    OUT uint32_t* pTaskInfoLen,
																    IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

/* @fn    
 * @brief 获取电视墙任务信息，需要先调用DPSDK_GetTvWallTaskInfoLen()
 * @param <IN>		nPDLLHandle		SDK句柄
 * @param <OUT>		szTaskInfoBuf	电视墙任务信息 
 * @param <IN>		nTaskInfoLen	电视墙任务信息长度 
 * @return 函数返回错误类型，参考dpsdk_retval_e.
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_GetTvWallTaskInfoStr( IN int32_t nPDLLHandle, 
																	OUT char* szTaskInfoBuf,
																    IN uint32_t nTaskInfoLen );

/* @fn    
 * @brief 电视墙任务上墙
 * @param <IN>		nPDLLHandle		SDK句柄
 * @param <IN>		nTvWallId		电视墙ID
 * @param <IN>		nTaskId		    电视墙任务ID
 * @param <IN>		nTimeout		超时时长，单位毫秒
 * @return 函数返回错误类型，参考dpsdk_retval_e.
 */
DPSDK_DLL_API int32_t DPSDK_CALL_METHOD DPSDK_MapTaskToTvWall( IN int32_t nPDLLHandle, 
															   IN uint32_t nTVWallId,
															   IN uint32_t nTaskId, 
															   IN int32_t nTimeout = DPSDK_CORE_DEFAULT_TIMEOUT);

// 电视墙业务接口 结束
//////////////////////////////////////////////////////////////////////////


#endif