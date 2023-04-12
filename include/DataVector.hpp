#ifndef __DATAVECTOR_H
#define __DATAVECTOR_H

#include <vector>
#include <fstream>

class DataVector
{
    private:
    unsigned char* vector;
    unsigned int dimension;


    public:
    DataVector(unsigned int);

    unsigned char& getElement(unsigned int);


    void* getVector();
    unsigned int getDimension();

    
};

#endif