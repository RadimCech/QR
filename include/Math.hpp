#ifndef __Math_H
#define __Math_H

#include <cmath>
#include "DataMatrix.hpp"
#include "DataVector.hpp"

class Math
{

    public:
    static unsigned int SwapEndianness(unsigned int);

    static DataMatrix* HouseHolderBidiag(DataMatrix* ); //QR decomposition using householder reflectinos
    static DataMatrix* LeftHouseholder(DataMatrix* , unsigned int );
    static DataMatrix* NaiveMatrixMultiply(DataMatrix*, DataMatrix*);
    static DataMatrix* OuterProduct(DataVector*, DataVector*);

};




#endif
