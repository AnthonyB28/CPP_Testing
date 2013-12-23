#include <iostream>
#include <stdio.h>
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

int findDeterminant(Matrix m)
{
    int det = 0;
    for(int i = 0; i < 3; i++)
    {
        det = det
        +(m(0,i)
        *(m(1,((i+1)%3))
        *m(2,((i+2)%3))
        - m(1,((i+2)%3))
        *m(2,((i+1)%3))));

    }
    return det;
}

Matrix findTranspose(Matrix m)
{
    Matrix dx(m.dx,m.dy);
    for(int i = 0; i < m.dx; i++)
    {
        for(int z = 0; z < m.dy; z++)
        {
            dx(z,i) = m(i,z);
        }
    }
    return dx;
}

void solve(Matrix &x, bool d)
{
    cout << "Matrix x\n" << x << endl;
    StartCounter();
    //STEP 1 & 2 Find the minors and Cofactor matrix.
    Matrix coFactor = createCofactor(x);
        if(d){ cout << "CoFactor Matrix\n" << coFactor << endl; }

    float determinant = findDeterminant(x);
    //STEP 3 Find determinant
   if(d){  cout << "Determinant\n" << determinant << "\n" << endl;}

    //STEP 4 Find transpose of cofactor
    Matrix transpose = findTranspose(coFactor);
    if(d){ cout << "Transpose Matrix\n" << transpose << endl;}

    //STEP 5 Find the inverse, multi the transpose and the determinant
    cout << "Inverse Matrix SOLUTION\n" << (1/determinant) *transpose << endl;

    if(d){ cout << "Test Inverse\n" << x * ((1/determinant) *transpose );}
    else{cout << "Performance(ns): " << GetCounter();}
}


int main()
{
    Matrix x(3,3);
    x(0,0) = 1;
    x(0,1) = 3;
    x(0,2) = 3;

    x(1,0) = 1;
    x(1,1) = 4;
    x(1,2) = 3;

    x(2,0) = 1;
    x(2,1) = 3;
    x(2,2) = 4;
    //takeInput(x); //Automated input
    cout << "Show logs? 1 or 0" << endl;
    bool debug;
    cin >> debug;
    solve(x,debug);

    return 0;
}
