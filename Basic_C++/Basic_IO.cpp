#include "Basic_IO.h"

#define MAX_STR_SIZE 100
#define NUMBER 5




void File_IO_Korean()
{
	//#include <locale>
	setlocale(LC_ALL, "Korean");
	std::locale::global(std::locale("Korean"));
}


void File_IO_C()
{
	FILE* FILE_IO;

	/*
	*	fopen_s 모드
	*	rb  : 읽기(O), 쓰기(X), 갱신(X), 파일없을시 생성(X), 파일존재시 삭제(X), fseek함수 사용(O)
	*	r+b : 읽기(O), 쓰기(0), 갱신(O), 파일없을시 생성(X), 파일존재시 삭제(X), fseek함수 사용(O)
	*	wb  : 읽기(X), 쓰기(0), 갱신(O), 파일없을시 생성(O), 파일존재시 삭제(O), fseek함수 사용(O)
	*	w+b : 읽기(O), 쓰기(0), 갱신(O), 파일없을시 생성(O), 파일존재시 삭제(O), fseek함수 사용(O)
	*	ab  : 읽기(X), 쓰기(0), 갱신(X), 파일없을시 생성(O), 파일존재시 삭제(X), fseek함수 사용(X)
	*	a+b : 읽기(O), 쓰기(0), 갱신(X), 파일없을시 생성(O), 파일존재시 삭제(X), fseek함수 사용(O)
	*/

	/*
	*	입출력 함수
	*	fputs : 파일에 문자열(한 행)을 쓴다. 
	*	fgets : 파일로부터 문자열(한 행)을 읽는다. 
	*	fscanf : 파일로부터 정해진 형식(형식화된 입력)에 따라 읽는다. 
	*	fprintf : 파일에 정해진 형식(형식화된 출력)에 따라 쓴다. 
	*	fread : 파일로부터 이진 데이터를 읽는다. 
	*	fwrite : 파일에 이진 데이터를 쓴다. 
	*/

	// Write :: string, fopen_s, fputs
	{
		std::string filename = "Test.txt";
		fopen_s(&FILE_IO, filename.c_str(), "wb");
		{
			// 문자열, 한 줄씩
			std::string data = "Jaiden";
			fputs(data.c_str(), FILE_IO);

			// 데이터, 전체
			char Data[MAX_STR_SIZE] = "Sample";
			fwrite(Data, sizeof(char), sizeof(Data), FILE_IO);
		}
		fclose(FILE_IO);
	}

	// Write :: wstring, _wfopen_s, fputws
	{
		std::wstring filename = L"Test.txt";
		_wfopen_s(&FILE_IO, filename.c_str(), L"wb");
		{
			// 문자열, 한 줄씩
			std::wstring data = L"Jaiden";
			fputws(data.c_str(), FILE_IO);

			// 데이터, 전체
			wchar_t Data[MAX_STR_SIZE] = L"Sample";
			fwrite(Data, sizeof(wchar_t), sizeof(Data), FILE_IO);
		}
		fclose(FILE_IO);
	}

	// Load :: string, fopen_s, fgets
	{
		std::string filename = "Test.txt";
		fopen_s(&FILE_IO, filename.c_str(), "rb");
		{
			// 문자열 한줄씩			
			char data[MAX_STR_SIZE] = "";
			while (!feof(FILE_IO))
			{
				fgets(data, sizeof(data), FILE_IO);
			}

			// 데이터, 전체
			char Data[MAX_STR_SIZE] = "";
			fread(Data, sizeof(char), sizeof(Data), FILE_IO);
		}
		fclose(FILE_IO);
	}

	// Load :: wstring, _wfopen_s, fgetws
	{
		std::wstring filename = L"Test.txt";
		_wfopen_s(&FILE_IO, filename.c_str(), L"rb");
		{
			// 한문장
			wchar_t data[MAX_STR_SIZE] = L"";
			while (!feof(FILE_IO))
			{
				fgetws(data, sizeof(data), FILE_IO);
			}

			// 데이터, 전체
			wchar_t Data[MAX_STR_SIZE] = L"Sample";
			fread(Data, sizeof(wchar_t), sizeof(Data), FILE_IO);
		}
		fclose(FILE_IO);
	}

}

void File_IO_CPP()
{
	// #include <fstream>
	// #include <iomanip>

	/*
	*	모드
	*	std::ios::in		읽기위한 파일 열기
	*	std::ios::out		쓰기위한 파일 열기
	*	std::ios::binary	이진(Binary) 모드
	*	std::ios::ate		(in)파일의 끝에 위치
	*	std::ios::app		(out)모든 출력은 파일의 끝에 추가된다.
	*	std::ios::trunc		(out)만약 파일이 존재하면 지운다.
	*/

	// Write :: string환경
	{
		std::fstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			File_IO << _int_ << std::endl;
			File_IO << _string_ << std::endl;

			File_IO << std::setprecision(NUMBER) << _float_ << std::endl;					// NUMBER 숫자갯수만큼 출력
			File_IO << std::fixed << std::setprecision(NUMBER) << _float_ << std::endl;		// 소수점이하 NUMBER 숫자갯수만큼 출력, NUMBER+1자리에서 반올림주의
			File_IO << std::setfill('#') << std::setw(NUMBER) << _float_ << std::endl;		// NUMBER공간에 출력, 빈공간은 '#'으로 채움
		}
		File_IO.close();
	}

	// Write :: wstring환경
	{
		std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::ate | std::ios::binary );
		if (File_IO.is_open())
		{
			File_IO << _wstring_ << std::endl;
		}
		File_IO.close();
	}

	// Load :: string환경
	{
		std::fstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			while (File_IO.eof()==false)
			{
				File_IO >> _string_;
				//_string_ = File_IO.get();
			}

			while (getline(File_IO, _string_))
			{
				// 추가동작
			}
		}
		File_IO.close();
	}

	// Load :: wstring환경
	{
		std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			while (File_IO.eof() == false)
			{
				File_IO >> _wstring_;
				//_wstring_ = File_IO.get();
			}

			while (getline(File_IO, _wstring_))
			{
				// 추가동작
			}

		}
		File_IO.close();
	}

	// Load :: ssstream
	{
		//#include <sstream>

		std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);

		std::stringstream _stringStream_;
		_stringStream_ << File_IO.rdbuf();

		File_IO.close();

		while (!_stringStream_.eof())
		{
			_stringStream_ >> _string_;
		}

	}

}

void File_IO_Basic()
{
	//#include <filesystem>
	namespace _Filesystem_ = std::experimental::filesystem;

	// 현재경로
	_Filesystem_::path _path_ = _Filesystem_::current_path();
	std::string _path_string_ = _path_.string();

	// 폴더존재여부
	if (_Filesystem_::exists("c:\\jdn"))

	// 폴더 내 파일 전체탐색
	for (auto& p : _Filesystem_::directory_iterator("c:\\jdn"))
	{
		p.path();
	}

	// 폴더생성
	_Filesystem_::create_directories("c:\\jdn");
	// 폴더복사
	_Filesystem_::copy("c:\\jdn1", "c:\\jdn2");
	// 폴더삭제
	_Filesystem_::remove("c:\\jdn1");
	// 파일사이즈
	int _size_ = _Filesystem_::file_size("c:\\jdn1");


}
