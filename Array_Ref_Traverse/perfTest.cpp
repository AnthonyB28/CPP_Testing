#include <iostream>
#include <windows.h>

using namespace std;

/*
Anthony Barranco
You can traverse arrays using iterators on the memory references.

ROUND 1 displays this using malloc to ensure the array is in a single
contiguous block of memory and you can traverse over it by setting
a reference OUT-OF-BOUNDS (ie the array stops at 499, you set it to 500)

It is faster when compared directly to other malloc by slivers of a nanosecond.
IE Round 1 vs Round 3
But it doesnt appear to be any faster compared to Round 2, direct initialization.
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

void round1()
{
     int fun = 0;

    //ROUND 1 - MALLOC
    StartCounter();
    int *bufferA = (int *)malloc(99999 * sizeof(int));
    for(int i = 0; i <= 99999; ++i)
    {
        bufferA[i] = i;
    }

    int *e = &bufferA[10000]; //Out of bounds memory location
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
    int bufferA2[10000];
    for(int i = 0; i <= 99999; ++i)
    {
        bufferA2[i] = i;
    }
    for(int i = 0; i <= 99999; ++i)
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
    int *bufferA3 = (int *)malloc(99999 * sizeof(int));
    for(int i = 0; i <= 99999; ++i)
    {
        bufferA3[i] = i;
    }
    for(int i = 0; i <= 99999; ++i)
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
