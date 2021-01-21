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
	*	fopen_s ���
	*	rb  : �б�(O), ����(X), ����(X), ���Ͼ����� ����(X), ��������� ����(X), fseek�Լ� ���(O)
	*	r+b : �б�(O), ����(0), ����(O), ���Ͼ����� ����(X), ��������� ����(X), fseek�Լ� ���(O)
	*	wb  : �б�(X), ����(0), ����(O), ���Ͼ����� ����(O), ��������� ����(O), fseek�Լ� ���(O)
	*	w+b : �б�(O), ����(0), ����(O), ���Ͼ����� ����(O), ��������� ����(O), fseek�Լ� ���(O)
	*	ab  : �б�(X), ����(0), ����(X), ���Ͼ����� ����(O), ��������� ����(X), fseek�Լ� ���(X)
	*	a+b : �б�(O), ����(0), ����(X), ���Ͼ����� ����(O), ��������� ����(X), fseek�Լ� ���(O)
	*/

	/*
	*	����� �Լ�
	*	fputs : ���Ͽ� ���ڿ�(�� ��)�� ����. 
	*	fgets : ���Ϸκ��� ���ڿ�(�� ��)�� �д´�. 
	*	fscanf : ���Ϸκ��� ������ ����(����ȭ�� �Է�)�� ���� �д´�. 
	*	fprintf : ���Ͽ� ������ ����(����ȭ�� ���)�� ���� ����. 
	*	fread : ���Ϸκ��� ���� �����͸� �д´�. 
	*	fwrite : ���Ͽ� ���� �����͸� ����. 
	*/

	// Write :: string, fopen_s, fputs
	{
		std::string filename = "Test.txt";
		fopen_s(&FILE_IO, filename.c_str(), "wb");
		{
			// ���ڿ�, �� �پ�
			std::string data = "Jaiden";
			fputs(data.c_str(), FILE_IO);

			// ������, ��ü
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
			// ���ڿ�, �� �پ�
			std::wstring data = L"Jaiden";
			fputws(data.c_str(), FILE_IO);

			// ������, ��ü
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
			// ���ڿ� ���پ�			
			char data[MAX_STR_SIZE] = "";
			while (!feof(FILE_IO))
			{
				fgets(data, sizeof(data), FILE_IO);
			}

			// ������, ��ü
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
			// �ѹ���
			wchar_t data[MAX_STR_SIZE] = L"";
			while (!feof(FILE_IO))
			{
				fgetws(data, sizeof(data), FILE_IO);
			}

			// ������, ��ü
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
	*	���
	*	std::ios::in		�б����� ���� ����
	*	std::ios::out		�������� ���� ����
	*	std::ios::binary	����(Binary) ���
	*	std::ios::ate		(in)������ ���� ��ġ
	*	std::ios::app		(out)��� ����� ������ ���� �߰��ȴ�.
	*	std::ios::trunc		(out)���� ������ �����ϸ� �����.
	*/

	// Write :: stringȯ��
	{
		std::fstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			File_IO << _int_ << std::endl;
			File_IO << _string_ << std::endl;

			File_IO << std::setprecision(NUMBER) << _float_ << std::endl;					// NUMBER ���ڰ�����ŭ ���
			File_IO << std::fixed << std::setprecision(NUMBER) << _float_ << std::endl;		// �Ҽ������� NUMBER ���ڰ�����ŭ ���, NUMBER+1�ڸ����� �ݿø�����
			File_IO << std::setfill('#') << std::setw(NUMBER) << _float_ << std::endl;		// NUMBER������ ���, ������� '#'���� ä��
		}
		File_IO.close();
	}

	// Write :: wstringȯ��
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

	// Load :: stringȯ��
	{
		std::fstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			File_IO >> _string_;
		}
		File_IO.close();
	}

	// Load :: wstringȯ��
	{
		std::wfstream File_IO;	// fstream = ofstream(ios::out) + ifstream(ios::in)
		std::string fileName = "example.txt";
		File_IO.open(fileName, std::ios::out | std::ios::in | std::ios::binary);
		if (File_IO.is_open())
		{
			File_IO >> _wstring_;
		}
		File_IO.close();
	}

}


