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

	_int_ = static_cast<int>(_float_);	// ����ȯ
	_int_ = int(_float_);				// ����ȯ
}

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
	//pchar_ = CString_;					// CString -> char* CString�� �⺻������ TCHAR�̰�, �����ڵ忡�� wchar_t�� �����ϱ� ������ ����

	// string <-> const char*
	_string_ = _pchar_;						// char* -> string
	_cpchar_ = _string_.c_str();			// string -> const char*

	// fuction
	{
		size_t size = strlen(_src_cpchar_);										// ���ڿ� ����					// \0������ ����, sizeof�� ���� �ٸ�
		strcpy_s(_dst_pchar_, sizeof(_dst_pchar_), _src_cpchar_);				// ���ڿ� ����					// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		strncpy_s(_dst_pchar_, sizeof(_dst_pchar_), _src_cpchar_, _length_);	// ���ڿ� �������̸�ŭ ����		// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		strcat_s(_dst_pchar_, sizeof(_src_cpchar_), _src_cpchar_);				// ���ڿ� �����̱�				// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		strncat_s(_dst_pchar_, sizeof(_src_cpchar_), _src_cpchar_, _length_);	// ���ڿ� �������̸�ŭ �����̱�	// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		strcmp(_src1_cpchar_, _src2_cpchar_);									// ���ڿ� ���Լ�, ������ 0
		strncmp(_src1_cpchar_, _src2_cpchar_, _length_);						// ���ڿ� length��ŭ ��, ������ 0
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
		size_t size = wcslen(_dst_wchar_t_);										// ���ڿ� ����					// \0������ ����, sizeof�� ���� �ٸ�
		wcscpy_s(_dst_wchar_t_, sizeof(_dst_wchar_t_), _src_wchar_t_);				// ���ڿ� ����					// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		wcsncpy_s(_dst_wchar_t_, sizeof(_dst_wchar_t_), _src_wchar_t_, _length_);	// ���ڿ� �������̸�ŭ ����		// sizeof(dst) > sizeof(src) �����ʼ�Ȯ��, src�� �� Ŀ�� �����ϴ� ����
		wcscat_s(_dst_wchar_t_, sizeof(_src_wchar_t_), _src_wchar_t_);				// ���ڿ� �����̱�				// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		wcsncat_s(_dst_wchar_t_, sizeof(_src_wchar_t_), _src_wchar_t_, _length_);	// ���ڿ� �������̸�ŭ �����̱�	// sizeof(dst) > ���ڿ�����(dst) + ���ڿ�����(src) ���� Ȯ��
		wcscmp(_src1_wchar_t_, _src2_wchar_t_);										// ���ڿ� ���Լ�, ������ 0
		wcsncmp(_src1_wchar_t_, _src2_wchar_t_, _length_);							// ���ڿ� length��ŭ ��, ������ 0
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
		//   .GetLength			������ ���ڿ��� ���̸� ����
		//   .IsEmpty			���ڿ� ���۰� ����� ������ TRUE, �׷��� ������ FALSE
		//   .Empty				���ڿ��������Ͽ� ���۸� ���
		//   .GetAt				���ڿ��� Ư�� ��ġ�� ���ڰ��� ����
		//   .SetAt				���ڿ��� Ư�� ��ġ�� ���ο� ���ڸ� ����
		//   .Compare			���ڿ��� ��, ������ 0, �׷��� ������ 0 �� �ƴ� ���� ����
		//   .Mid, Left, Right	���ڿ� �߰�, ����, �������� Ư�� ��ġ ���ڿ��� CString ���� ����
		//   .MakeUpper			���ڿ��� ��� �빮�ڷ� �ٲ�
		//   .MakeLower			���ڿ��� ��� �ҹ��ڷ� �ٲ�
		//   .Format			sprintf ���·� ���ڿ��� ���� �ֱ�
		//   .Find				���ڿ����� Ư�� ����(��)�� ã��

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

	std::vector<int> vector_(100, 0);	// ���� 100��, 0���� �ʱ�ȭ
	
	vector_.resize(10, 0);
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
		// .resize(n, x)		vector_�� ���� n���� �ø�, ����� x���� �ʱ�ȭ
		// .rbegin()			vector_�� �������� ù ��° ���Ҹ� ����Ű�� �ݺ���
		// .rend()				vector_�� �������� ������ ���Ҹ� ����Ű�� �ݺ���
		// .swap(v1)			vector_�� v1�� �ٲ�
}


void _srand()
{
	// #include <stdlib.h>	-> srand
	// #include <time.h>	-> time

	// �õ�ǥ�� �ð����� ��ü
	srand(unsigned(time(NULL)));
	int _rand_ = rand();

}


void _memory()
{
	// stack : ���� {} �߰�ȣ �������� �Ҵ�Ǵ� �޸�
	// heap : ���α׷��Ӱ� ���� �Ҵ�, ���� - malloc(<->free),calloc(<->free),new(<->delete) ��

	int _src_[5] = { 1,2,3,4,5 };
	int _count_ = sizeof(_src_) / sizeof(int);
	int _size_ = sizeof(_src_);	// _size_ = _count_ * sizeof(int)

	// malloc �����Ҵ�
	{
		int* _dst_ = (int*)malloc(_size_);	// ���� ������ ä���� �����Ҵ�
		memcpy(_dst_, _src_, _size_);		// �޸�ī��
		free(_dst_);
	}

	// calloc �����Ҵ�
	{
		int* _dst_ = (int*)calloc(_count_, sizeof(int));	// 0���� ä���� �����Ҵ�
		memcpy(_dst_, _src_, _size_);						// �޸�ī��
		free(_dst_);
	}

	// new �����Ҵ�
	{
		int* _dst_ = new int[_count_];
		memcpy(_dst_, _src_, _size_);
		delete _dst_;
	}

	// memset : �Ҵ�� ������ �� ����
	{
		int _val_ = 5;

		int* _dst_ = new int[_count_];
		memset(_dst_, _val_, _count_);	// dst�� val���� count��ŭ ä��
		delete _dst_;
	}

}


class _class
{
	// public(�ܺ�) >> protected(����+�ڽ�) >> private(����)

public:

protected:

private:

}