#include <iostream>
#include <vector>
#include <cassert>
//#include <windows.h>
#include "perf.h"
#include "matrix.cpp"
using namespace std;

/*
Inverse Matrix
AX = C
A–1AX = A–1C
IX = A–1C
X = A–1C

Step 1: Find matrix of minors
Step 2: Find cofactor (checkerboard)
Step 3: Find determinant of original matrix
Step 4: Transpose cofactor in Step 2
Step 5: det(c) * transpose
*/

//Take input for each of the matrix's positions
void takeInput(Matrix &m)
{
    for(int i = 0; i < m.dx; i++)
    {
        for(int z = 0; z < m.dy; z++)
        {
            cout << "Input m(" << i << "," << z << ")" << endl;
            cin >> m(i,z);
        }
    }
}


int main()
{

    Matrix x(3,3);
    takeInput(x);
    cout << "Matrix x\n" << x;
    return 0;
}
