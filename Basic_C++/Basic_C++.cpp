#include "Basic_C++.h"

void _type()
{
	bool	_bool_;		// 1 byte
	char	_char_;		// 1 byte
	short	_short_;	// 2 byte
	int		_int_;		// 4 byte
	long	_long_;		// 4 byte
	float	_float_;	// 4 byte
	double	_double_;	// 8 byte

	INT8	_INT8_;		// 1 byte = 8bit
	INT16	_INT16_;	// 2 byte = 16bit
	INT32	_INT32_;	// 4 byte = 32bit
	INT64	_INT64_;	// 8 byte = 64bit

	_int_ = static_cast<int>(_float_);	// 형변환
	_int_ = int(_float_);				// 형변환
}

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
	char sample[] = "Hello World!";
	char sample[100] = "Hello World!";

	// int <-> char*
	sprintf_s(_pchar_, sizeof(_pchar_), "%d", _int_);	// int -> char*
	_int_ = atoi(_pchar_);								// char* -> int

	// float <-> char*
	sprintf_s(_pchar_, sizeof(_pchar_), "%f", _float_);	// float -> char*
	_double_ = atof(_pchar_);							// char* -> float

	// CString <-> char*
	_CString_ = _pchar_;					// char* -> CString
	//pchar_ = CString_;					// CString -> char* CString이 기본적으로 TCHAR이고, 유니코드에서 wchar_t로 동작하기 때문에 위험

	// string <-> const char*
	_string_ = _pchar_;						// char* -> string
	_cpchar_ = _string_.c_str();			// string -> const char*

	// fuction
	{
		size_t size = strlen(_src_cpchar_);										// 문자열 길이					// \0까지의 길이, sizeof랑 값이 다름
		strcpy_s(_dst_pchar_, sizeof(_dst_pchar_), _src_cpchar_);				// 문자열 복사					// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		strncpy_s(_dst_pchar_, sizeof(_dst_pchar_), _src_cpchar_, _length_);	// 문자열 지정길이만큼 복사		// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		strcat_s(_dst_pchar_, sizeof(_src_cpchar_), _src_cpchar_);				// 문자열 덧붙이기				// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		strncat_s(_dst_pchar_, sizeof(_src_cpchar_), _src_cpchar_, _length_);	// 문자열 지정길이만큼 덧붙이기	// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		strcmp(_src1_cpchar_, _src2_cpchar_);									// 문자열 비교함수, 같으면 0
		strncmp(_src1_cpchar_, _src2_cpchar_, _length_);						// 문자열 length만큼 비교, 같으면 0
	}
}


void _wchar_t()
{
	wchar_t sample[] = L"Hello World!";
	wchar_t sample[100] = L"Hello World!";

	// int <-> wchar_t*
	swprintf_s(_pwchar_t_, sizeof(_pwchar_t_), L"%d", _int_);		// int -> wchar_t*
	_int_ = _wtoi(_pwchar_t_);										// wchar_t* -> int

	// float <-> wchar_t*
	swprintf_s(_pwchar_t_, sizeof(_pwchar_t_), L"%f", _float_);		// float -> wchar_t*
	_float_ = _wtof(_pwchar_t_);									// wchar_t* -> float

	// CString <-> const wchar_t*
	_CString_ = _cpwchar_t_;			// const wchar_t* -> CString
	_cpwchar_t_ = _CString_;			// CString -> const wchar_t*

	// wstring <-> const wchar_t*
	_cpwchar_t_ = _wstring_.c_str();	// const wchar_t* -> wstring
	_wstring_ = _cpwchar_t_;			// wstring -> const wchar_t*

	// fuction
	{
		size_t size = wcslen(_dst_wchar_t_);										// 문자열 길이					// \0까지의 길이, sizeof랑 값이 다름
		wcscpy_s(_dst_wchar_t_, sizeof(_dst_wchar_t_), _src_wchar_t_);				// 문자열 복사					// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		wcsncpy_s(_dst_wchar_t_, sizeof(_dst_wchar_t_), _src_wchar_t_, _length_);	// 문자열 지정길이만큼 복사		// sizeof(dst) > sizeof(src) 조건필수확인, src가 더 커도 동작하니 주의
		wcscat_s(_dst_wchar_t_, sizeof(_src_wchar_t_), _src_wchar_t_);				// 문자열 덧붙이기				// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		wcsncat_s(_dst_wchar_t_, sizeof(_src_wchar_t_), _src_wchar_t_, _length_);	// 문자열 지정길이만큼 덧붙이기	// sizeof(dst) > 문자열길이(dst) + 문자열길이(src) 조건 확인
		wcscmp(_src1_wchar_t_, _src2_wchar_t_);										// 문자열 비교함수, 같으면 0
		wcsncmp(_src1_wchar_t_, _src2_wchar_t_, _length_);							// 문자열 length만큼 비교, 같으면 0
	}
}


void _string()
{
	// #include <string>
	std::string sample("Hello");
	std::string sample = sample + "!";

	// int <-> string
	_string_ = std::to_string(_int_);		// int -> string
	_int_ = std::stof(_string_);			// string -> int

	// float <-> string
	_string_ = std::to_string(_float_);		// float -> string
	_float_ = std::stof(_string_);			// string -> float

	// const char* < -> string
	_cpchar_ = _string_.c_str();			// string -> const char*
	_string_ = _pchar_;						// char* -> string

	// wstring <-> string
	_string_.assign(_wstring_.begin(), _wstring_.end());	// wstring -> string
	_string_ = CT2CA(_wstring_.c_str());	// wstring -> string 
	_wstring_.assign(_string_.begin(), _string_.end());		// string -> wstring
	_wstring_ = CA2CT(_string_.c_str());	// string -> wstring

	// CString <-> string
	_CString_ = _string_.c_str();			// string -> CString
	_CString_ = CA2CT(_string_.c_str());	// string -> CString
	_string_ = CT2CA(_CString_);			// CString -> string
	_string_ = CT2CA(_CString_.operator LPCWSTR());	// CString -> string

}


void _wstring()
{
	// #include <string>
	std::wstring sample(L"Hello");
	std::wstring sample = sample + L"!";

	// int <-> wstring
	_wstring_ = std::to_wstring(_int_);			// int -> string
	_int_ = stoi(_wstring_);					// string -> int

	// float <-> string
	_wstring_ = std::to_wstring(_float_);		// float -> string
	_float_ = stof(_wstring_);					// string -> float

	// const wchar_t* <-> wstring
	_cpwchar_t_ = _wstring_.c_str();			// const wchar_t* -> wstring
	_wstring_ = _cpwchar_t_;					// wstring -> const wchar_t*

	// string <-> wstring

	_string_.assign(_wstring_.begin(), _wstring_.end());	// wstring -> string
	_string_ = CT2CA(_wstring_.c_str());	// wstring -> string 
	_wstring_.assign(_string_.begin(), _string_.end());		// string -> wstring
	_wstring_ = CA2CT(_string_.c_str());	// string -> wstring

	// CString <-> wstring
	_CString_ = _wstring_.c_str();			// wstring -> CString
	_wstring_ = _CString_;					// CString -> wstring
	_wstring_ = _CString_.operator LPCWSTR();	// CString -> wstring
}


void _CString()
{
	//#include <afxstr.h>

	_CString_.Delete(0, _CString_.GetLength());
		//   .GetLength			설정된 문자열의 길이를 리턴
		//   .IsEmpty			문자열 버퍼가 비워져 있으면 TRUE, 그렇지 않으면 FALSE
		//   .Empty				문자열을삭제하여 버퍼를 비움
		//   .GetAt				문자열의 특정 위치의 문자값을 얻음
		//   .SetAt				문자열의 특정 위치에 새로운 문자를 삽입
		//   .Compare			문자열을 비교, 같으면 0, 그렇지 않으면 0 이 아닌 값을 리턴
		//   .Mid, Left, Right	문자열 중간, 좌측, 우측부터 특정 위치 문자열을 CString 으로 추출
		//   .MakeUpper			문자열을 모두 대문자로 바꿈
		//   .MakeLower			문자열을 모두 소문자로 바꿈
		//   .Format			sprintf 형태로 문자열에 문자 넣기
		//   .Find				문자열에서 특정 문자(열)를 찾기

	// int <-> CString
	_int_ = _ttoi(_CString_);						// CString -> int
	_CString_.Format(_T("%02d"), _int_);			// int -> CString

	// float <-> CString
	_float_ = _ttof(_CString_);						// CString -> float
	_CString_.Format(_T("%02f"), _float_);			// float -> CString

	// const char* -> CString
	_CString_ = _cpchar_;							// char* -> CString

	// const wchar_t* <-> CString
	_cpwchar_t_ = _CString_;						// CString -> const wchar_t*
	_CString_ = _cpwchar_t_;						// const wchar_t* -> CString

	// TCHAR <-> CString
	_pTCHAR_ = (TCHAR*)(LPCTSTR)_CString_;			// CString -> TCHAR*
	_CString_ = (LPCTSTR)_pTCHAR_;					// TCHAR -> CString

	// string <-> CString
	_string_ = CT2CA(_CString_);					// CString -> string
	_string_ = CT2CA(_CString_.operator LPCWSTR());	// CString -> string 
	_CString_ = _string_.c_str();					// string -> CString
	_CString_ = CA2CT(_string_.c_str());	// string -> CString

	// wstring <-> CString
	_wstring_ = _CString_;							// CString -> wstring
	_wstring_ = _CString_.operator LPCWSTR();		// CString -> wstring
	_CString_ = _wstring_.c_str();					// wstring -> CString
}


void _vector()
{
	// #include <vector>

	std::vector<int> vector_(100, 0);	// 원소 100개, 0으로 초기화
	
	vector_.resize(10, 0);
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
		// .resize(n, x)		vector_의 원소 n개로 늘림, 빈공간 x으로 초기화
		// .rbegin()			vector_의 역순에서 첫 번째 원소를 가리키는 반복자
		// .rend()				vector_의 역순에서 마지막 원소를 가리키는 반복자
		// .swap(v1)			vector_와 v1을 바꿈
}


void _srand()
{
	// #include <stdlib.h>	-> srand
	// #include <time.h>	-> time

	// 시드표를 시간으로 교체
	srand(unsigned(time(NULL)));
	int _rand_ = rand();

}


void _memory()
{
	// data : 
	// stack : 내부 {} 중괄호 영역에서 할당되는 메모리
	// heap : 프로그래머가 직접 할당, 해제 - malloc(<->free),calloc(<->free),new(<->delete) 등

	int _src_[5] = { 1,2,3,4,5 };
	int _count_ = sizeof(_src_) / sizeof(int);
	int _size_ = sizeof(_src_);	// _size_ = _count_ * sizeof(int)

	// malloc 동적할당
	{
		int* _dst_ = (int*)malloc(_size_);	// 랜덤 값으로 채워진 공간할당
		memcpy(_dst_, _src_, _size_);		// 메모리카피
		free(_dst_);
	}

	// calloc 동적할당
	{
		int* _dst_ = (int*)calloc(_count_, sizeof(int));	// 0으로 채워진 공간할당
		memcpy(_dst_, _src_, _size_);						// 메모리카피
		free(_dst_);
	}

	// new 동적할당
	{
		int* _dst_ = new int[_count_];
		memcpy(_dst_, _src_, _size_);
		delete _dst_;
	}

	// memset : 할당된 공간에 값 설정
	{
		int _val_ = 5;

		int* _dst_ = new int[_count_];
		memset(_dst_, _val_, _count_);	// dst에 val으로 count만큼 채움
		delete _dst_;
	}

}


class _class
{
	// public(외부) >> protected(내부+자식) >> private(내부)

public:

protected:

private:

}