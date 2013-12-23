#include <iostream>
#include <windows.h>

using namespace std;

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

void round1()
{
     int fun = 0;

    //ROUND 1 - MALLOC
    StartCounter();
    int *bufferA = (int *)malloc(499 * sizeof(int));
    for(int i = 0; i <= 499; ++i)
    {
        bufferA[i] = i;
    }

    int *e = &bufferA[500]; //Out of bounds memory location
    for( int *x = bufferA; x != e; ++x)
    {
        fun += *x; //Traverse and operate on the array using reference
    }
    cout << "R1: " << GetCounter() << endl;
    free(bufferA);
}

void round2()
{
    int fun = 0;
    //ROUND 2 - Direct
    StartCounter();
    int bufferA2[500];
    for(int i = 0; i <= 499; ++i)
    {
        bufferA2[i] = i;
    }
    for(int i = 0; i <= 499; ++i)
    {
        fun += bufferA2[i];
    }
    cout << "R2: " << GetCounter() << endl;
}

void round3()
{
    int fun = 0;
     //ROUND 3 - Direct MALLOC
    StartCounter();
    int *bufferA3 = (int *)malloc(499 * sizeof(int));
    for(int i = 0; i <= 499; ++i)
    {
        bufferA3[i] = i;
    }
    for(int i = 0; i <= 499; ++i)
    {
        fun += bufferA3[i];
    }
    cout <<  "R3: " << GetCounter() << endl;
    free(bufferA3);
}

int main()
{

    round1();
    round2();
    round3();
    return 0;
}
