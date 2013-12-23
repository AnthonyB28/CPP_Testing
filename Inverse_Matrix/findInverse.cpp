#include <iostream>
#include <vector>
//#include <windows.h>
#include "perf.h"
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


class Matrix{
public:
    Matrix(int sizeX, int sizeY);
    Matrix();
    ~Matrix();
    Matrix(const Matrix& m);
    Matrix & operator = (const Matrix& rhs);
private:
    int dx, dy; //dx x dy
    long **p; //pointer to a pointer to a long integer
    void allocArrays()
    {
        //creates the x by y array
        p = new long*[dx];
        for(int i = 0; i <dx; i++){ p[i] = new long[dy];}
    }
};

Matrix::Matrix(int sizeX, int sizeY):dx(sizeX),dy(sizeY)
{
    allocArrays();
    for(int i = 0; i <dx; i++)
        {
            for(int j = 0; j < dy; j++)
                p[i][j]=0;
        }
}

Matrix::Matrix(const Matrix& m) : dx(m.dx), dy(m.dy)
{
    allocArrays();
    for (int i=0; i<dx; ++i)
    {
        for (int j=0; j<dy; ++j)
        {
            p[i][j] = m.p[i][j];
        }
    }
}


int main()
{

    return 0;
}
