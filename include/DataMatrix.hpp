#ifndef __DATAMATRIX_H
#define __DATAMATRIX_H

#include <vector>
#include <fstream>

class DataMatrix
{
    private:
    unsigned char* matrix;
    unsigned int rows;
    unsigned int columns;


    public:
    DataMatrix(unsigned int, unsigned int);

    unsigned char& getElement(unsigned int);
    unsigned char& getElement(unsigned int, unsigned int);


    unsigned char* getMatrix();
    unsigned int getDimension();
    unsigned int getRows();
    unsigned int getColumns();
};

#endif