
#include "DataVector.hpp"

DataVector::DataVector(unsigned int i)
{
    vector = new double[i]();
    dimension = i;
}

DataVector::~DataVector()
{
    delete vector;
}

void DataVector::print()
{
	for(int i = 0; i<dimension; i++)
	{
		
        printf("%5.2f ", this->getElement(i));
	}
    printf("\n");
}


double& DataVector::getElement(unsigned int i)
{
    return vector[i];
}

double* DataVector::getVector()
{
    return vector;
}

unsigned int DataVector::getDimension()
{
    return dimension;
}

void DataVector::scalarMultiply(double a)
{
	for(int i = 0; i < dimension; i++)
	{
		vector[i] *= a;
	}
}

