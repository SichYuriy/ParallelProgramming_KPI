#define _SCL_SECURE_NO_WARNINGS
#include "SquareMatrix.h"
#include <algorithm>


SquareMatrix::SquareMatrix(int size)
{
	this->size = size;
	this->matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		this->matrix[i] = new int[size];
	}

}

SquareMatrix::~SquareMatrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

int SquareMatrix::get(int i, int j)
{
	return matrix[i][j];
}

void SquareMatrix::set(int val, int i, int j)
{
	matrix[i][j] = val;
}

int SquareMatrix::getSize()
{
	return size;
}

SquareMatrix* SquareMatrix::operator*(int val)
{
	SquareMatrix* result = new SquareMatrix(size);
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		result->matrix[i][j] = this->matrix[i][j] * val;
	return result;
}

Vector* SquareMatrix::operator*(Vector& va)
{
	Vector *result = new Vector(size);
	for (int i = 0; i < size; i++)
	{
		(*result)[i] = 0;
		for (int j = 0; j < size; j++)
		{
			(*result)[i] += va[i] * this->matrix[j][i];
		}
	}
	return result;
}

SquareMatrix* SquareMatrix::operator*(SquareMatrix& ma)
{
	SquareMatrix* result = new SquareMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result->matrix[i][j] = 0;
			for (int k = 0; k < size; k++)
			{
				result->matrix[i][j] += this->matrix[i][k] * ma.matrix[k][j];
			}
		}
	}

	return result;
}

SquareMatrix* SquareMatrix::trans()
{
	SquareMatrix *result = new SquareMatrix(size);
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		result->matrix[j][i] = this->matrix[i][j];
	return result;
}

int SquareMatrix::min_val()
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (matrix[i][j] < min)
			min = matrix[i][j];
	}
	return min;
}

int SquareMatrix::max_val()
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (matrix[i][j] > max)
			max = matrix[i][j];
	}
	return max;
}


SquareMatrix* SquareMatrix::sort()
{
	SquareMatrix* result = new SquareMatrix(size);
	for (int i = 0; i < size; i++)
	{
		std::copy(this->matrix[i], this->matrix[i] + size, result->matrix[i]);
		std::sort(result->matrix[i], result->matrix[i] + size);
	}
	return result;
}

SquareMatrix* SquareMatrix::operator+(SquareMatrix& ma)
{
	SquareMatrix* result = new SquareMatrix(size);
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		result->matrix[i][j] = this->matrix[i][j] + ma.matrix[i][j];
	return result;
}