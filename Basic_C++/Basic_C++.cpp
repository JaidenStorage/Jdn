#include "Basic_C++.h"


void _Bin_Oct_Dec_Hex()
{
	unsigned char Bin = 0b0101'0101;	// 2���� ǥ���
	unsigned char Oct = 0125;			// 8���� ǥ���
	unsigned char Dec = 85;				// 10���� ǥ���
	unsigned char Hex = 0x55;			// 16���� ǥ���
}


void _text()
{
	// char		: 1byte
	// w_char	: 2byte
	// TCHAR	: multi-byte�϶� char, Unicode�϶� w_char

	// LPSTR	= long pointer string				= char *
	// LPCSTR	= long pointer constant string		= const char *
	// LPWSTR	= long pointer wide string			= w_char*
	// LPCWSTR	= long pointer constant wide string = const w_char*
	// LPCTSTR	= long pointer constant t_string	= const t_char *

	// char		char_[]		= "Hello World!";
	// wchar_t	wchar_t_[]	= L"Hello World!";
	// TCHAR	TCHAR_[]	= _T("Hello World!");

	// string	: char ���̽� �����̳�
	// wstring	: wchar_t ���̽�

	// CStringA	: char ���̽�
	// CStringW	: wchar_t ���̽�
	// CString	: TCAHR ���̽�
}


void _Char()
{
	char		char_[] = "Hello World!";

	// int <-> char*
	sprintf_s(pchar_, sizeof(pchar_), "%d", int_);		// int -> char*
	int_ = atoi(pchar_);								// char* -> int

	// float <-> char*
	sprintf_s(pchar_, sizeof(pchar_), "%f", float_);	// float -> char*
	double_ = atof(pchar_);								// char* -> float

	// CString <-> char*
	CString_ = pchar_;						// char* -> CString
	//pchar_ = CString_;					// CString -> char*�� ��� CString�� �⺻������ TCHAR�̰�, �����ڵ忡�� wchar_t�� �����ϱ� ������ ���輺�� �ִ�.

	// string <-> char*
	string_ = pchar_;						// char* -> string
	cchar_ = string_.c_str();				// string -> const char*


	// fuction
	{
		const char* src;
		const char* src_;
		char* dst;
		size_t length;

		size_t size = strlen(dst);					// ���ڿ� ����					// \0������ ����, sizeof�� ���� �ٸ�
		strcpy_s(dst, sizeof(dst), src);			// ���ڿ� ����					// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		strncpy_s(dst, sizeof(dst), src, length);	// ���ڿ� �������̸�ŭ ����		// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		strcat_s(dst, sizeof(src), src);			// ���ڿ� �����̱�				// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		strncat_s(dst, sizeof(src), src, length);	// ���ڿ� �������̸�ŭ �����̱�	// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		strcmp(src, src_);							// ���ڿ� ���Լ�, ������ 0		
		strncmp(src, src_, length);					// ���ڿ� length��ŭ ��, ������ 0 
	}
}

void _wchar_t()
{
	// int <-> wchar_t*
	swprintf_s(pwchar_t_, sizeof(pwchar_t_), L"%d", int_);		// int -> wchar_t*
	int_ = _wtoi(pwchar_t_);		// wchar_t* -> int

	// float <-> wchar_t*
	swprintf_s(pwchar_t_, sizeof(pwchar_t_), L"%f", float_);	// float -> wchar_t*
	float_ = _wtof(pwchar_t_);		// wchar_t* -> float

	// CString <-> const wchar_t*
	CString_ = cwchar_t_;			// const wchar_t* -> CString
	cwchar_t_ = CString_;			// CString -> const wchar_t*
	
	// wstring <-> const wchar_t*
	wstring_ = cwchar_t_;			// const wchar_t* -> wstring
	wstring_ = cwchar_t_;			// wstring -> const wchar_t* 

	// fuction
	{
		const wchar_t* src;
		const wchar_t* src_;
		wchar_t* dst;
		size_t length;

		size_t size = wcslen(dst);					// ���ڿ� ����					// \0������ ����, sizeof�� ���� �ٸ�
		wcscpy_s(dst, sizeof(dst), src);			// ���ڿ� ����					// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		wcsncpy_s(dst, sizeof(dst), src, length);	// ���ڿ� �������̸�ŭ ����		// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		wcscat_s(dst, sizeof(src), src);			// ���ڿ� �����̱�				// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		wcsncat_s(dst, sizeof(src), src, length);	// ���ڿ� �������̸�ŭ �����̱�	// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		wcscmp(src, src_);							// ���ڿ� ���Լ�, ������ 0		
		wcsncmp(src, src_, length);					// ���ڿ� length��ŭ ��, ������ 0 
	}

}


void _string()
{
	// #include <string>

	std::string A("Hello");
	std::string B = A + "!";

	// Number <-> Text
	{
		// int
		string_ = std::to_string(int_);		// int -> string
		int_ = atoi(string_.c_str());		// string -> int
		
		//float
		string_ = std::to_string(float_);	// float -> string
		float_ = atof(string_.c_str());		// string -> float
	}

	// Text <-> Text
	{
		// char
		cchar_ = string_.c_str();				// string -> const char*
		string_ = pchar_;						// char* -> string

		// CString
		CString_ = string_.c_str();				// string -> CString
		string_ = CT2CA(CString_);				// CString -> string
	}
}


void _CString()
{
	//#include <afxstr.h>
	
	CString_.Delete(0, CString_.GetLength());
		//  .GetLength			������ ���ڿ��� ���̸� ����
		//  .IsEmpty			���ڿ� ���۰� ����� ������ TRUE, �׷��� ������ FALSE
		//  .Empty				���ڿ��������Ͽ� ���۸� ���
		//  .GetAt				���ڿ��� Ư�� ��ġ�� ���ڰ��� ����
		//  .SetAt				���ڿ��� Ư�� ��ġ�� ���ο� ���ڸ� ����
		//  .Compare			���ڿ��� ��, ������ 0, �׷��� ������ 0 �� �ƴ� ���� ����
		//  .Mid, Left, Right	���ڿ� �߰�, ����, �������� Ư�� ��ġ ���ڿ��� CString ���� ����
		//  .MakeUpper			���ڿ��� ��� �빮�ڷ� �ٲ�
		//  .MakeLower			���ڿ��� ��� �ҹ��ڷ� �ٲ�
		//  .Format				sprintf ���·� ���ڿ��� ���� �ֱ�
		//  .Find				���ڿ����� Ư�� ����(��)�� ã��

	// Number <-> Text
	{
		// int
		int_ = _ttoi(CString_);						// CString -> int
		CString_.Format(_T("%02d"),int_);			// int -> CString

		// float
		float_ = _ttof(CString_);					// CString -> float
		CString_.Format(_T("%02f"), float_);		// float -> CString
	}
	
	// Text <-> Text
	{
		// TCHAR
		pTCHAR_ = (TCHAR*)(LPCTSTR)CString_;			// CString -> TCHAR
		CString_ = (LPCTSTR)pTCHAR_;					// TCHAR -> CString

		// char
		CString_ = cchar_;							// char* -> CString
	}
}




void _vector()
{
	// #include <vector>

	std::vector<int> vector_(100,0);	// ���� 100��, 0���� �ʱ�ȭ

	vector_.resize(10,0);		//		���� 10���� �ø�, ����� 0���� �ʱ�ȭ
		// .assign(n, x)		x ������ n ���� ���Ҹ� �Ҵ�
		// .at(n)				n ��° ���Ҹ� ����
		// .front()				vector_�� ù ��° ���Ҹ� ����
		// .back()				vector_�� ������ ���Ҹ� ����
		// .begin()				vector_�� ù ��° ���Ҹ� ����Ű�� �ݺ���
		// .end()				vector_�� ������ ���Ҹ� ����Ű�� �ݺ���
		// .clear()				vector_�� ��� ���Ҹ� ����
		// .erase(n)			vector_�� n ��° ���Ҹ� ����
		// .erase(n, i)			vector_�� n ��°���� i ��° �̸��� ���Ҹ� ����
		// .empty()				vector_�� ���Ұ� ����ִ��� Ȯ��
		// .capacity()			vector_�� �Ҵ�� ������ ũ��
		// .size()				vector_�� ������ ����
		// .insert(a, x)		vector_�� ����Ű�� ��ġ�� x ���� ����
		// .insert(a, n, x)		vector_�� ����Ű�� ��ġ�� x ���� n �� ����
		// .pop_back()			vector_�� ������ ���Ҹ� ����
		// .push_back(x)		vector_�� ������ ������ x ���� ����
		// .rbegin()			vector_�� �������� ù ��° ���Ҹ� ����Ű�� �ݺ���
		// .rend()				vector_�� �������� ������ ���Ҹ� ����Ű�� �ݺ���
		// .swap(v1)			vector_�� v1�� �ٲ�
}

