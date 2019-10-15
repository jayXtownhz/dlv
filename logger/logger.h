/**
 * @file	logger.h
 * @author	jayxu
 * @date	2019-8-05
 * @brief	本文件中定义了轻量级日志输入类 CLogger 的定义.
 * @version	1.0
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <Windows.h>
#include <stdio.h>
#include <string>

#define MAX_ROWS     500       /**< 单个日志可写最大行数 */

namespace LOGGER
{
	/**
     * 日志级别的提示信息
     */
	static const std::string strFatalPrefix = "Fatal:    ";
	static const std::string strErrorPrefix = "Error:    ";
	static const std::string strWarningPrefix = "Warning:    ";
	static const std::string strInfoPrefix = "Info:    ";

	/**
     * 日志级别枚举
     */
	typedef enum EnumLogLevel
	{
		LogLevel_Stop = 0,	/**< 什么都不记录 */
		LogLevel_Fatal,		/**< 只记录严重错误 */
		LogLevel_Error,		/**< 记录严重错误，普通错误 */
		LogLevel_Warning,	/**< 记录严重错误，普通错误，警告 */
		LogLevel_Info		/**< 记录严重错误，普通错误，警告，提示信息(全部记录) */
	} EnumLogLevel;

	class CLogger
	{
	public:
		/**
         * @param nLogLevel 日志记录的等级，可空
         * @param strLogPath 日志目录，可空
		 * @param strLogName 日志名称，可空
         */
		CLogger(EnumLogLevel nLogLevel = EnumLogLevel::LogLevel_Info, const std::string strLogPath = "", const std::string strLogName = "");
		/**
		 * 析构函数
		 */
		virtual ~CLogger();
	public:
		/**
         * 写严重错误信息
		 * @param *lpcszFormat 输入严重错误信息 
         */
		void TraceFatal(const char *lpcszFormat, ...);
		/**
		 * 写错误信息
		 * @param *lpcszFormat 输入错误信息
		 */
		void TraceError(const char *lpcszFormat, ...);
		/**
		 * 写警告信息
		 * @param *lpcszFormat 输入告警信息
		 */
		void TraceWarning(const char *lpcszFormat, ...);
		/**
		 * 写提示信息
		 * @param *lpcszFormat 输入提示信息
		 */
		void TraceInfo(const char *lpcszFormat, ...);
		/**
		 * 改变写日志级别
		 * @param nLevel 当前日志级别
		 */
		void ChangeLogLevel(EnumLogLevel nLevel);
		/**
		 * 获取当前程序运行路径
		 * @return {string} 绝对路径字符串
		 */
		static std::string GetAppPathA();
		/**
		 * 格式化字符串
		 * @return {string} 转换后的字符串
		 */
		static std::string FormatString(const char *lpcszFormat, ...);
	private:
		/**
		 * 写文件操作
		 * @param strLog 需要写入文件的字符串
		 */
		void Trace(const std::string &strLog);
		/**
		 * 获取当前系统时间
		 * @return {string} 当前时间的字符串格式
		 */
		std::string GetTime();
		/**
		 * 文件全路径得到文件名
		 * @return {char*} 解析后的文件名路径
		 */
		const char *path_file(const char *path, char splitter);
	private:
		/**
		 * 写日志文件流
		 */
		FILE * m_pFileStream;
		/**
		 * 写日志级别
		 */
		EnumLogLevel m_nLogLevel;
		/**
		 * 日志目录
		 */
		std::string m_strLogPath;
		/**
		 * 日志的名称
		 */
		std::string m_strLogName;
		/**
		 * 日志文件全路径
		 */
		std::string m_strLogFilePath;
		/**
		 * 线程同步的临界区变量
		 */
		CRITICAL_SECTION m_cs;
		/**
		 * 日志行数
		 */
		int m_nLogRow;
		/**
		 * 文件句柄
		 */
		int m_fh;
		unsigned int m_uiSize;
	};
}

#endif