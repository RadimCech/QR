#include "DataMatrix.hpp"

DataMatrix::DataMatrix(unsigned int m, unsigned int n) //rows,columns
{
	rows = m;
	columns = n;
	matrix = (unsigned char*)malloc(m*n*10);

}

unsigned char& DataMatrix::getElement(unsigned int i) //ith row, jth column
{
	return matrix[i];
}

unsigned char& DataMatrix::getElement(unsigned int i, unsigned int j) //ith row, jth column
{
	return matrix[i+j*rows];
}

unsigned char* DataMatrix::getMatrix()
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

