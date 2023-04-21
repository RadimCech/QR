#ifndef __DATAMATRIX_H
#define __DATAMATRIX_H

#include <cstdio>


class DataMatrix
{
    private:
    double* matrix;
    unsigned int rows;
    unsigned int columns;


    public:
    DataMatrix(unsigned int, unsigned int);
    DataMatrix(DataMatrix*);
    ~DataMatrix();
    
    double& getElement(unsigned int, unsigned int);

    void print();

    double* getMatrix();
    unsigned int getDimension();
    unsigned int getRows();
    unsigned int getColumns();

    void scalarMultiply(double);
};

#endif