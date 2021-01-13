#include "Basic_C++.h"

void _Bin_Oct_Dec_Hex()
{
	unsigned char bin = 0b0101'0101;	// 2진법 표기법
	unsigned char oct = 0125;			// 8진법 표기법
	unsigned char Dec = 85;				// 10진법 표기법
	unsigned char Hex = 0x55;			// 16진법 표기법
}

void _text()
{
	// char		: 1byte
	// w_char	: 2byte
	// t_char	: multi-byte일때 char, Unicode일때 w_char

	// LPSTR	= long pointer string				= char *
	// LPCSTR	= long pointer constant stsring		= const char *
	// LPWSTR	= long pointer wide string			= w_char*
	// LPCWSTR	= long pointer constant wide string = const w_char*
	// LPCTSTR	= long pointer constant t_string	= const t_char *

	// char		char_[]		= "Hello World!";
	// wchar_t	wchar_t_[]	= L"Hello World!";
	// TCHAR	TCHAR_[]	= _T("Hello World!");
}


void _Char()
{
	// Number <-> Text
	{
		sprintf_s(pchar_, sizeof(pchar_), "%d", int_);		// int -> char*
		sprintf_s(pchar_, sizeof(pchar_), "%f", float_);	// float -> char*

		int_ = atoi(pchar_);		// char* -> int
		double_ = atof(pchar_);		// char* -> float
	}

	// Text <-> Text
	{
		CString_ = pchar_;						// char* -> CString

		string_ = pchar_;						// char* -> string
		cchar_ = string_.c_str();				// string -> const char*
	}

	size_t strlen(const char* s);		// 문자열 길이
	char* strcpy(char* dest, const char* src);				// 문자열 복사
	char* strncpy(char* dest, const char* src, size_t n);	// 문자열 복사
	char* strcat(char* dest, const char* src);				// 문자열 덧붙이기
	char* strncat(char* dest, const char* src, size_t n);	// 문자열 덧붙이기
	int strcmp(const char* s1, const char* s2);				// 문자열 비교함수, 같으면 0 반환
	int strncmp(const char* s1, const char* s2, size_t n);	// 문자열 비교함수, 같으면 0 반환
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

