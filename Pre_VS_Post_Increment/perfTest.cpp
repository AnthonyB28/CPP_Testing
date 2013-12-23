#include <iostream>
#include <windows.h>

using namespace std;

/*
Anthony Barranco
Pre-increments are faster and use less memory than post increments.
This is because pre increments dont need to copy and store the original value.
The effect of this is only noticeable when using large values with for loops.

However, it may be more apparent when doing increment operations on large values
in general.
*/

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main()
{
    long fun;

    StartCounter();
    for(int i = 0; i < 1000000000; i++)
    {
        fun += i;
    }
    cout << "Post: " << GetCounter() << endl;

    fun = 0;
    StartCounter();
    for(int i = 0; i < 999999999; ++i)
    {
        fun+= i;
    }

    cout << "Pre: " << GetCounter() << endl;


    fun = 100000000;
    long foo;
    StartCounter();
    for(int i = 0; i < 50000; i++)
    {
        foo = fun++;
    }

    cout << "Post: " << GetCounter() << endl;

    fun = 100000000;
    StartCounter();
        for(int i = 0; i < 50000; i++)
    {
            foo = ++fun;

    }
    cout << "Post: " << GetCounter() << endl;
    return 0;
}
