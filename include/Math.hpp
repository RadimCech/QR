#ifndef __MATH_H
#define __MATH_H

#include <cmath>
#include "DataMatrix.hpp"
#include "DataVector.hpp"
#include <tuple>
#include <vector>


class Math
{

    public:
    static unsigned int SwapEndianness(unsigned int);

    //returns a vector with U,B,V, where A*V = U*B
    static std::vector<DataMatrix*> HouseHolderBidiagonalization(DataMatrix* ); //QR decomposition using householder reflectinos
    static DataMatrix* LeftHouseholder(DataMatrix* , int );
    static DataMatrix* RightHouseholder(DataMatrix* , int );

    static DataMatrix* MultiplyByLeftHouseholder(DataMatrix*, DataMatrix*, char = 'g');
    static DataMatrix* MultiplyByRightHouseholder(DataMatrix*, DataMatrix*, char = 'g');
    
    static DataMatrix* NaiveMatrixMultiply(DataMatrix*, DataMatrix*);
    static DataMatrix* OuterProduct(DataVector*);

    static double GetNorm(DataVector*);
    static double GetNorm2(DataVector*);
    static void Normalize(DataVector*);
};
#endif
