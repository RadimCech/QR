#include "Math.hpp"



unsigned int Math::SwapEndianness(unsigned int x)
{
    unsigned char *ptr = (unsigned char *) &x;
    return (unsigned int)(ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
}


DataMatrix* Math::HouseHolderBidiag(DataMatrix* matrix) 
{
    DataMatrix* U = new DataMatrix(matrix->getRows(), matrix->getColumns());
    DataMatrix* V = new DataMatrix(matrix->getColumns(), matrix->getColumns());
    for(int k = 0; k < matrix->getColumns(); k++)
    {
        //terrible algoritmization

    }
}

DataMatrix* Math::LeftHouseholder(DataMatrix* A, unsigned int k)
{
    DataMatrix* Q = new DataMatrix(A->getRows()-k, A->getColumns()-k);
    DataVector* u = new DataVector(A->getRows()-k);

    unsigned char euclidNorm = 0;


    for(int i = 0; i < A->getRows()-k; i++) //u := kth column of A without the first k rows
    {
        u->getElement(i) = A->getElement(k+i, k);
        euclidNorm += A->getElement(k+1,k);
    }

    u->getElement(0) -= sqrt(euclidNorm); //subtract the norm of u from the first coordinate
    





}

DataMatrix* Math::NaiveMatrixMultiply(DataMatrix* A, DataMatrix* B) // B := A*B
{
    DataMatrix* C = new DataMatrix(A->getRows(), B->getColumns());
    //check if sizes are alright

    for(int i = 0; i < B->getRows(); i++)
    {

        for(int j = 0; j< B->getColumns(); j++)
        {

            char b = 0;
            //tady se dejou hrozne veci
            for(int k = 0; k<B->getRows(); k++)
            {

                b += A->getElement(i, k)+B->getElement(k, j);
            }

            (C->getElement(i,j)) = b;
        }
    }

    return C;
}


DataMatrix* Math::OuterProduct(DataVector* u, DataVector* v)
{
    //int j = dimension;
    //DataMatrix* matrix = new DataMatrix(dimension, dimension);
    //for(int i = 0; i < dimension; i++)
    //{

    //}
}


int main()
{
	printf("je to v pici");
}