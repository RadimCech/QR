#ifndef __DATAVECTOR_H
#define __DATAVECTOR_H

#include <vector>
#include <fstream>

class DataVector
{
    private:
    double* vector;
    unsigned int dimension;


    public:
    DataVector(unsigned int);
    ~DataVector();

    void print();
    double& getElement(unsigned int);
    double* getVector();
    unsigned int getDimension();

    void scalarMultiply(double);
    
};

#endif