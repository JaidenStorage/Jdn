#include "Basic_IO.h"

#define MAX_STR_SIZE 100
#define NUMBER 5


/* 
	fopen_s ���
	rb  : �б�(O), ����(X), ����(X), ���Ͼ����� ����(X), ��������� ����(X), fseek�Լ� ���(O)
	r+b : �б�(O), ����(0), ����(O), ���Ͼ����� ����(X), ��������� ����(X), fseek�Լ� ���(O)
	wb  : �б�(X), ����(0), ����(O), ���Ͼ����� ����(O), ��������� ����(O), fseek�Լ� ���(O)
	w+b : �б�(O), ����(0), ����(O), ���Ͼ����� ����(O), ��������� ����(O), fseek�Լ� ���(O)
	ab  : �б�(X), ����(0), ����(X), ���Ͼ����� ����(O), ��������� ����(X), fseek�Լ� ���(X)
	a+b : �б�(O), ����(0), ����(X), ���Ͼ����� ����(O), ��������� ����(X), fseek�Լ� ���(O)
*/

/*
	fputs : ���Ͽ� ���ڿ�(�� ��)�� ����.
	fgets : ���Ϸκ��� ���ڿ�(�� ��)�� �д´�.
	fscanf : ���Ϸκ��� ������ ����(����ȭ�� �Է�)�� ���� �д´�.
	fprintf : ���Ͽ� ������ ����(����ȭ�� ���)�� ���� ����.
	fread : ���Ϸκ��� ���� �����͸� �д´�.
	fwrite : ���Ͽ� ���� �����͸� ����.
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
	//stringȯ��
	//	std::fstream File_IO;
	//	File_IO << _wstring_ << std::endl;

	//wstringȯ��
	std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)

	File_IO.open("example.txt", std::ios::out | std::ios::in |  std::ios::binary | std::ios::ate);
		// std::ios::in		�б����� ���� ����
		// std::ios::out	�������� ���� ����
		// std::ios::binary	����(Binary) ���
		// std::ios::ate	(in)������ ���� ��ġ
		// std::ios::app	(out)��� ����� ������ ���� �߰��ȴ�.
		// std::ios::trunc	(out)���� ������ �����ϸ� �����.

	if (File_IO.is_open())
	{
		File_IO << _int_ << std::endl;
		File_IO << _wstring_ << std::endl;

		File_IO << std::setprecision(NUMBER) << _float_ << std::endl;					// NUMBER ���ڰ�����ŭ ���
		File_IO << std::fixed << std::setprecision(NUMBER) << _float_ << std::endl;		// �Ҽ������� NUMBER ���ڰ�����ŭ ���, NUMBER+1�ڸ����� �ݿø�����
		File_IO << std::setfill('#') << std::setw(NUMBER) << _float_ << std::endl;		// NUMBER������ ���, ������� '#'���� ä��
	};

	File_IO.close();
}

void FileLoad_CPP()
{
	//stringȯ��
	//	std::fstream File_IO;
	//	File_IO << _wstring_ << std::endl;

	//wstringȯ��
	std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)

	File_IO.open("example.txt", std::ios::out | std::ios::in | std::ios::binary);

	if (File_IO.is_open())
	{
		File_IO >> _wstring_;
	};

	File_IO.close();
}


