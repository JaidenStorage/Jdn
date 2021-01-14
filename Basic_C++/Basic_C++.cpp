#include "Basic_C++.h"


void _Bin_Oct_Dec_Hex()
{
	unsigned char Bin = 0b0101'0101;	// 2진법 표기법
	unsigned char Oct = 0125;			// 8진법 표기법
	unsigned char Dec = 85;				// 10진법 표기법
	unsigned char Hex = 0x55;			// 16진법 표기법
}


void _text()
{
	// char		: 1byte
	// w_char	: 2byte
	// TCHAR	: multi-byte일때 char, Unicode일때 w_char

	// LPSTR	= long pointer string				= char *
	// LPCSTR	= long pointer constant string		= const char *
	// LPWSTR	= long pointer wide string			= w_char*
	// LPCWSTR	= long pointer constant wide string = const w_char*
	// LPCTSTR	= long pointer constant t_string	= const t_char *

	// char		char_[]		= "Hello World!";
	// wchar_t	wchar_t_[]	= L"Hello World!";
	// TCHAR	TCHAR_[]	= _T("Hello World!");

	// string	: char 베이스 컨테이너
	// wstring	: wchar_t 베이스

	// CStringA	: char 베이스
	// CStringW	: wchar_t 베이스
	// CString	: TCAHR 베이스
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
	//pchar_ = CString_;					// CString -> char*의 경우 CString이 기본적으로 TCHAR이고, 유니코드에서 wchar_t로 동작하기 때문에 위험성이 있다.

	// string <-> char*
	string_ = pchar_;						// char* -> string
	cchar_ = string_.c_str();				// string -> const char*


	// fuction
	{
		const char* src;
		const char* src_;
		char* dst;
		size_t length;

		size_t size = strlen(dst);					// 문자열 길이					// \0까지의 길이, sizeof랑 값이 다름
		strcpy_s(dst, sizeof(dst), src);			// 문자열 복사					// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		strncpy_s(dst, sizeof(dst), src, length);	// 문자열 지정길이만큼 복사		// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		strcat_s(dst, sizeof(src), src);			// 문자열 덧붙이기				// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		strncat_s(dst, sizeof(src), src, length);	// 문자열 지정길이만큼 덧붙이기	// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		strcmp(src, src_);							// 문자열 비교함수, 같으면 0		
		strncmp(src, src_, length);					// 문자열 length만큼 비교, 같으면 0 
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

		size_t size = wcslen(dst);					// 문자열 길이					// \0까지의 길이, sizeof랑 값이 다름
		wcscpy_s(dst, sizeof(dst), src);			// 문자열 복사					// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		wcsncpy_s(dst, sizeof(dst), src, length);	// 문자열 지정길이만큼 복사		// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		wcscat_s(dst, sizeof(src), src);			// 문자열 덧붙이기				// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		wcsncat_s(dst, sizeof(src), src, length);	// 문자열 지정길이만큼 덧붙이기	// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		wcscmp(src, src_);							// 문자열 비교함수, 같으면 0		
		wcsncmp(src, src_, length);					// 문자열 length만큼 비교, 같으면 0 
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
		//  .GetLength			설정된 문자열의 길이를 리턴
		//  .IsEmpty			문자열 버퍼가 비워져 있으면 TRUE, 그렇지 않으면 FALSE
		//  .Empty				문자열을삭제하여 버퍼를 비움
		//  .GetAt				문자열의 특정 위치의 문자값을 얻음
		//  .SetAt				문자열의 특정 위치에 새로운 문자를 삽입
		//  .Compare			문자열을 비교, 같으면 0, 그렇지 않으면 0 이 아닌 값을 리턴
		//  .Mid, Left, Right	문자열 중간, 좌측, 우측부터 특정 위치 문자열을 CString 으로 추출
		//  .MakeUpper			문자열을 모두 대문자로 바꿈
		//  .MakeLower			문자열을 모두 소문자로 바꿈
		//  .Format				sprintf 형태로 문자열에 문자 넣기
		//  .Find				문자열에서 특정 문자(열)를 찾기

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

	std::vector<int> vector_(100,0);	// 원소 100개, 0으로 초기화

	vector_.resize(10,0);		//		원소 10개로 늘림, 빈공간 0으로 초기화
		// .assign(n, x)		x 값으로 n 개의 원소를 할당
		// .at(n)				n 번째 원소를 참조
		// .front()				vector_의 첫 번째 원소를 참조
		// .back()				vector_의 마지막 원소를 참조
		// .begin()				vector_의 첫 번째 원소를 가리키는 반복자
		// .end()				vector_의 마지막 원소를 가리키는 반복자
		// .clear()				vector_의 모든 원소를 제거
		// .erase(n)			vector_의 n 번째 원소를 제거
		// .erase(n, i)			vector_의 n 번째부터 i 번째 미만의 원소를 제거
		// .empty()				vector_의 원소가 비어있는지 확인
		// .capacity()			vector_에 할당된 공간의 크기
		// .size()				vector_의 원소의 개수
		// .insert(a, x)		vector_가 가리키는 위치에 x 값을 삽입
		// .insert(a, n, x)		vector_가 가리키는 위치에 x 값을 n 개 삽입
		// .pop_back()			vector_의 마지막 원소를 제거
		// .push_back(x)		vector_의 마지막 공간에 x 값을 삽입
		// .rbegin()			vector_의 역순에서 첫 번째 원소를 가리키는 반복자
		// .rend()				vector_의 역순에서 마지막 원소를 가리키는 반복자
		// .swap(v1)			vector_와 v1을 바꿈
}

