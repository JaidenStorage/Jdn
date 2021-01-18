#include "Basic_IO.h"

#define MAX_STR_SIZE 100

/* 
	fopen_s 모드
	rb  : 읽기(O), 쓰기(X), 갱신(X), 파일없을시 생성(X), 파일존재시 삭제(X), fseek함수 사용(O)
	r+b : 읽기(O), 쓰기(0), 갱신(O), 파일없을시 생성(X), 파일존재시 삭제(X), fseek함수 사용(O)
	wb  : 읽기(X), 쓰기(0), 갱신(O), 파일없을시 생성(O), 파일존재시 삭제(O), fseek함수 사용(O)
	w+b : 읽기(O), 쓰기(0), 갱신(O), 파일없을시 생성(O), 파일존재시 삭제(O), fseek함수 사용(O)
	ab  : 읽기(X), 쓰기(0), 갱신(X), 파일없을시 생성(O), 파일존재시 삭제(X), fseek함수 사용(X)
	a+b : 읽기(O), 쓰기(0), 갱신(X), 파일없을시 생성(O), 파일존재시 삭제(X), fseek함수 사용(O)
*/

/*
	fputs : 파일에 문자열(한 행)을 쓴다.
	fgets : 파일로부터 문자열(한 행)을 읽는다.
	fscanf : 파일로부터 정해진 형식(형식화된 입력)에 따라 읽는다.
	fprintf : 파일에 정해진 형식(형식화된 출력)에 따라 쓴다.
	fread : 파일로부터 이진 데이터를 읽는다.
	fwrite : 파일에 이진 데이터를 쓴다.
*/


void FileWrite_C()
{
	FILE* FILE_IO;

	// string, fopen_s, fputs
	{
		std::string filename = "Test.txt";
		std::string data = "Jaiden";

		fopen_s(&FILE_IO, filename.c_str(), "wb");
		fputs(data.c_str(), FILE_IO);
		fclose(FILE_IO);
	}

	// wstring, _wfopen_s, fputws
	{
		std::wstring filename = L"Test.txt";
		std::wstring data = L"Jaiden";

		_wfopen_s(&FILE_IO, filename.c_str(), L"wb");
		fputws(data.c_str(), FILE_IO);
		fclose(FILE_IO);
	}
}

void FileLoad_C()
{
	FILE* FILE_IO;

	// string, fopen_s, fgets
	{
		std::string filename = "Test.txt";
		char data[MAX_STR_SIZE] = "";

		fopen_s(&FILE_IO, filename.c_str(), "rb");
		
		while (!feof(FILE_IO))
		{
			fgets(data, sizeof(data), FILE_IO);
		}

		fclose(FILE_IO);
	}

	// wstring, _wfopen_s, fgetws
	{
		std::wstring filename = L"Test.txt";
		wchar_t data[MAX_STR_SIZE] = L"";

		_wfopen_s(&FILE_IO, filename.c_str(), L"rb");

		while (!feof(FILE_IO))
		{
			fgetws(data, sizeof(data), FILE_IO);
		}

		fclose(FILE_IO);
	}
}

void FileWrite_CPP()
{
	std::fstream File_IO;	// fstream = ofstream + ifstream

	//File_IO.open("example.txt", std::ios::binary | std::ios::ate);

	//fout << "file output stream test" << std::endl;
	//https://blog.naver.com/jhonbeetbox/222122559876
	//https://blog.naver.com/jade3011/222143409421
}

void FileLoad_CPP()
{

}


