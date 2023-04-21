#include "DataMatrix.hpp"

DataMatrix::DataMatrix(unsigned int m, unsigned int n) //rows,columns
{
	rows = m;
	columns = n;
	matrix = new double[m*n](); // rows storec sequentially

}

DataMatrix::~DataMatrix()
{
	delete matrix;
}


DataMatrix::DataMatrix(DataMatrix* A) //make a copy
{
	rows = A->getRows();
	columns = A->getColumns();
	matrix = new double[rows*columns];
	double* otherMatrix = A->getMatrix();
	for(int i = 0; i<rows*columns; i++)
	{
		matrix[i] = otherMatrix[i];
	}

}

void DataMatrix::print()
{
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			printf("%5.2f ", this->getElement(i,j));
		}
		printf("\n");
	}
}



double& DataMatrix::getElement(unsigned int i, unsigned int j) //ith row, jth column
{
	return matrix[i*columns + j];
}

double* DataMatrix::getMatrix()
{
	return matrix;
}

unsigned int DataMatrix::getDimension()
{
	return rows*columns;
}

unsigned int DataMatrix::getRows()
{
	return rows;
} 

unsigned int DataMatrix::getColumns()
{
	return columns;
} 

void DataMatrix::scalarMultiply(double a)
{
	for(int i = 0; i< rows*columns; i++)
	{
		matrix[i] *= a;
	}
}

