#pragma once

class CWideToMulti
{
public:
	// m_nLength包括末尾的'\0'
	CWideToMulti(const wchar_t* szWideChar)
	{
		m_nLength = WideCharToMultiByte(CP_ACP, 0, szWideChar, -1, NULL, 0, NULL, NULL);
		m_pszMultiChar = new char[m_nLength];
		memset(m_pszMultiChar, 0, sizeof(char) * m_nLength);
		WideCharToMultiByte(CP_ACP, 0, szWideChar, -1, m_pszMultiChar, m_nLength, NULL, NULL);
	}

	// m_nLength不包括末尾的'\0',cchWideChar是该宽字节字符串的字符数
	CWideToMulti(const wchar_t* szWideChar, int cchWideChar)
	{
		m_nLength = WideCharToMultiByte(CP_ACP, 0, szWideChar, cchWideChar, NULL, 0, NULL, NULL);
		m_pszMultiChar = new char[m_nLength + 1];
		memset(m_pszMultiChar, 0, sizeof(char) * (m_nLength + 1));
		WideCharToMultiByte(CP_ACP, 0, szWideChar, cchWideChar, m_pszMultiChar, m_nLength, NULL, NULL);
	}

	~CWideToMulti(void) { delete[] m_pszMultiChar; m_pszMultiChar = NULL; }

	const char* c_str(void) { return m_pszMultiChar; }

	unsigned long length(void) { return m_nLength; }

protected:
	char* m_pszMultiChar;
	unsigned long m_nLength;
};

class CMultiToWide
{
public:
	// m_nLength包括末尾的'\0'
	CMultiToWide(const char* szMultiChar)
	{
		m_nLength = MultiByteToWideChar(CP_ACP, 0, szMultiChar, -1, NULL, 0);
		m_pszWideChar = new wchar_t[m_nLength];
		memset(m_pszWideChar, 0, sizeof(wchar_t) * m_nLength);
		MultiByteToWideChar(CP_ACP, 0, szMultiChar, -1, m_pszWideChar, m_nLength);
	}

	// m_nLength包括末尾的'\0',cbMultiChar是多字节字符串的字节数
	CMultiToWide(const char* szMultiChar, int cbMultiChar)
	{
		m_nLength = MultiByteToWideChar(CP_ACP, 0, szMultiChar, cbMultiChar, NULL, 0);
		m_pszWideChar = new wchar_t[m_nLength + 1];
		memset(m_pszWideChar, 0, sizeof(wchar_t) * (m_nLength + 1));
		MultiByteToWideChar(CP_ACP, 0, szMultiChar, cbMultiChar, m_pszWideChar, m_nLength);
	}

	~CMultiToWide(void) { delete[] m_pszWideChar; m_pszWideChar = NULL; }

	const wchar_t* wc_str(void) { return m_pszWideChar; }

	unsigned long length(void) { return m_nLength; }

protected:
	wchar_t* m_pszWideChar;
	unsigned long m_nLength;
};


class CWideToUtf8
{
public:
	// m_nLength包括末尾的'\0'
	CWideToUtf8(const wchar_t* szWideChar)
	{
		m_nLength = WideCharToMultiByte(CP_UTF8, 0, szWideChar, -1, NULL, 0, NULL, NULL);
		m_pszMultiChar = new char[m_nLength];
		memset(m_pszMultiChar, 0, sizeof(char) * m_nLength);
		WideCharToMultiByte(CP_UTF8, 0, szWideChar, -1, m_pszMultiChar, m_nLength, NULL, NULL);
	}

	// m_nLength不包括末尾的'\0',cchWideChar是该宽字节字符串的字符数
	CWideToUtf8(const wchar_t* szWideChar, int cchWideChar)
	{
		m_nLength = WideCharToMultiByte(CP_UTF8, 0, szWideChar, cchWideChar, NULL, 0, NULL, NULL);
		m_pszMultiChar = new char[m_nLength + 1];
		memset(m_pszMultiChar, 0, sizeof(char) * (m_nLength + 1));
		WideCharToMultiByte(CP_UTF8, 0, szWideChar, cchWideChar, m_pszMultiChar, m_nLength, NULL, NULL);
	}

	~CWideToUtf8(void) { delete[] m_pszMultiChar; m_pszMultiChar = NULL; }

	const char* c_str(void) { return m_pszMultiChar; }

	unsigned long length(void) { return m_nLength; }

protected:
	char* m_pszMultiChar;
	unsigned long m_nLength;
};

class CUtf8ToWide
{
public:
	// m_nLength包括末尾的'\0'
	CUtf8ToWide(const char* szMultiChar)
	{
		m_nLength = MultiByteToWideChar(CP_UTF8, 0, szMultiChar, -1, NULL, 0);
		m_pszWideChar = new wchar_t[m_nLength];
		memset(m_pszWideChar, 0, sizeof(wchar_t) * m_nLength);
		MultiByteToWideChar(CP_UTF8, 0, szMultiChar, -1, m_pszWideChar, m_nLength);
	}

	// m_nLength包括末尾的'\0',cbMultiChar是多字节字符串的字节数
	CUtf8ToWide(const char* szMultiChar, int cbMultiChar)
	{
		m_nLength = MultiByteToWideChar(CP_UTF8, 0, szMultiChar, cbMultiChar, NULL, 0);
		m_pszWideChar = new wchar_t[m_nLength + 1];
		memset(m_pszWideChar, 0, sizeof(wchar_t) * (m_nLength + 1));
		MultiByteToWideChar(CP_UTF8, 0, szMultiChar, cbMultiChar, m_pszWideChar, m_nLength);
	}

	~CUtf8ToWide(void) { delete[] m_pszWideChar; m_pszWideChar = NULL; }

	const wchar_t* wc_str(void) { return m_pszWideChar; }

	unsigned long length(void) { return m_nLength; }

protected:
	wchar_t* m_pszWideChar;
	unsigned long m_nLength;
};
