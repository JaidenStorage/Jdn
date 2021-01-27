#include <ctime>
#include <atltime.h>

void sec()
{
	// #include <ctime>

	time_t start = time(NULL);
	time_t finish = time(NULL);

	time(&start);
	/*
		동작
	*/
	time(&finish);

	// 결과
	double result = difftime(finish, start);

}

void ms()
{
	//#include <atltime.h>

	CTime Start, Finish;

	Start = CTime::GetTickCount();
	/*
	동작
	*/
	Finish = CTime::GetTickCount();

	CTime Result = Finish - Start;


}

		 