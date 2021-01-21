#pragma once
#include <afxstr.h>
#include <string>
#include <vector>
#include <tchar.h>
#include <time.h>
#include <stdlib.h>



bool			_bool_;

int				_int_;
long			_long_;
float			_float_;
double			_double_;

// Char
char			_char_;
char*			_pchar_;
const char*		_cpchar_;

// wchar_t
wchar_t			_wchar_t_;
wchar_t*		_pwchar_t_;
const wchar_t*	_cpwchar_t_;

// string
std::string		_string_;
std::wstring	_wstring_;

// CString
CString			_CString_;
CStringA		_CStringA_;
CStringW		_CStringW_;

// TCHAR
TCHAR			_TCHAR_;
TCHAR*			_pTCHAR_;

// Char
const char*		_src_cpchar_;
const char*		_src1_cpchar_;
const char*		_src2_cpchar_;
char*			_dst_pchar_;
size_t			_length_;

// wchar_t
const wchar_t*	_src_wchar_t_;
const wchar_t*	_src1_wchar_t_;
const wchar_t*	_src2_wchar_t_;
wchar_t*		_dst_wchar_t_;
