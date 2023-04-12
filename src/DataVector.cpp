
#include "DataVector.hpp"

DataVector::DataVector(unsigned int i)
{
    vector = (unsigned char*) malloc(i);
    dimension = i;
}

unsigned char& DataVector::getElement(unsigned int i)
{
    return *(vector + i);
}

void* DataVector::getVector()
{
    return vector;
}

unsigned int DataVector::getDimension()
{
    return dimension;
}

