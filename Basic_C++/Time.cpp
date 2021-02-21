#include <ctime>
#include <atltime.h>
#include <string>

void Now_Time()
{
	//#include <atltime.h>
	CString csNowTime = CTime::GetCurrentTime().Format(_T("%y%m%d_%H%M%S"));

	//#include <atltime.h>
	//#include <string>
	std::wstring wsNowTime = CTime::GetCurrentTime().Format(L"D%Y%m%dT%H%M%S").operator LPCWSTR();	//����ð�

}

void Timer_sec()
{
	// #include <ctime>
	time_t Start = time(NULL);
	time_t Finish = time(NULL);

	time(&Start);
	/*
		Finish
	*/
	time(&Finish);

	// ���
	double result = difftime(Finish, Start);

}

void Timer_ms()	// ���ش� 16ms
{
	//#include <atltime.h>
	DWORD Start, Finish;

	Start = GetTickCount();
	/*
	����
	*/
	Finish = GetTickCount();

	// ���
	DWORD Result = Finish - Start;
}

void Timer_us()
{
	UINT64 SystemFrequency = NULL, StartTick = NULL, StopTick = NULL;
	DOUBLE Result_sec = NULL, Result_ms = NULL, Result_us = NULL;

	QueryPerformanceFrequency((LARGE_INTEGER*)&SystemFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&StartTick);
	/*
	����
	*/
	QueryPerformanceCounter((LARGE_INTEGER*)&StopTick);

	// ���
	Result_sec = static_cast<DOUBLE>(StopTick - StartTick) / static_cast<DOUBLE>(SystemFrequency);
	Result_ms = static_cast<DOUBLE>(StopTick - StartTick) * pow(10, 3) / static_cast<DOUBLE>(SystemFrequency);
	Result_us = static_cast<DOUBLE>(StopTick - StartTick) * pow(10, 6) / static_cast<DOUBLE>(SystemFrequency);
}

		 