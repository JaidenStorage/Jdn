#include <ctime>
#include <atltime.h>

void Now_Time()
{
	CTime Now = CTime::GetCurrentTime();

	CString NowTime = Now.Format(_T("%y%m%d_%H%M%S"));
	CString Year = Now.Format(_T("%y"));
	CString Month = Now.Format(_T("%m"));
	CString	Day = Now.Format(_T("%d"));
	CString Hour = Now.Format(_T("%H"));
	CString Minute = Now.Format(_T("%M"));
	CString second = Now.Format(_T("%S"));

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

	// 결과
	double result = difftime(Finish, Start);

}

void Timer_ms()	// 분해능 16ms
{
	//#include <atltime.h>
	DWORD Start, Finish;

	Start = GetTickCount();
	/*
	동작
	*/
	Finish = GetTickCount();

	// 결과
	DWORD Result = Finish - Start;
}

void Timer_us()
{
	UINT64 SystemFrequency = NULL, StartTick = NULL, StopTick = NULL;
	DOUBLE ResultTime_sec = NULL, ResultTime_ms = NULL, ResultTime_us = NULL;

	QueryPerformanceFrequency((LARGE_INTEGER*)&SystemFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&StartTick);
	/*
	동작
	*/
	QueryPerformanceCounter((LARGE_INTEGER*)&StopTick);

	// 결과
	ResultTime_sec = static_cast<DOUBLE>(StopTick - StartTick) / static_cast<DOUBLE>(SystemFrequency);
	ResultTime_ms = static_cast<DOUBLE>(StopTick - StartTick) * pow(10, 3) / static_cast<DOUBLE>(SystemFrequency);
	ResultTime_us = static_cast<DOUBLE>(StopTick - StartTick) * pow(10, 6) / static_cast<DOUBLE>(SystemFrequency);
}

		 