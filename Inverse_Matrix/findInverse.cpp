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

//Take matrixs a matrix, finds the minor, and makes cofactor.
//Returns the individual number that belongs for x and y.
int findCofactor(Matrix m, int x, int y)
{
    int cofactor;
    cofactor = m( ((x+1) % 3),((y+1) % 3))
    * m( ((x+2) % 3) , ((y+2) % 3) )
    - m( ((x+1) % 3), ((y+2) % 3))
    * m( ((x+2) % 3) , ((y+1) %3) );

    return cofactor;
}

Matrix createCofactor(Matrix m)
{
    Matrix dx(m.dx,m.dy);
    for(int x = 0; x < m.dx; x++)
    {
        for(int y = 0; y < m.dy; y++)
        {
            dx(x,y) = findCofactor(m,x,y);
        }
    }
    return dx;
}


int main()
{
    Matrix x(3,3);
    x(0,0) = -1;
    x(0,1) = -2;
    x(0,2) = 2;

    x(1,0) = 2;
    x(1,1) = 1;
    x(1,2) = 1;

    x(2,0) = 3;
    x(2,1) = 4;
    x(2,2) = 5;
    //takeInput(x); //Automated input
    cout << "Matrix x\n" << x << endl;

    //STEP 1 & 2 Find the minors and Cofactor matrix.
    Matrix coFactor = createCofactor(x);
    cout << "CoFactor\n" << coFactor << endl;

    //STEP 3 Find determinant

    return 0;
}
