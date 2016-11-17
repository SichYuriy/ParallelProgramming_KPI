#include "SquareMatrix.h"
#include <iostream>

using namespace std;

void VectorInput(Vector& vector)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		cin >> vector[i];
	}
}

void VectorInput(Vector& vector, int val)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		vector[i] = val;
	}
}

void VectorOutput(Vector& vector)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void MatrixInput(SquareMatrix& matrix)
{
	for (int i = 0; i < matrix.getSize(); i++)
	for (int j = 0; j < matrix.getSize(); j++)
	{
		int a;
		cin >> a;
		matrix.set(a, i, j);
	}
}

void MatrixInput(SquareMatrix& matrix, int val)
{
	for (int i = 0; i < matrix.getSize(); i++)
	for (int j = 0; j < matrix.getSize(); j++)
	{
		matrix.set(val, i, j);
	}
}

void MatrixOutput(SquareMatrix& matrix)
{
	for (int i = 0; i < matrix.getSize(); i++)
	{
		for (int j = 0; j < matrix.getSize(); j++)
		{
			cout << matrix.get(i, j) << " ";
		}
		cout << endl;
	}
}