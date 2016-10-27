#define _SCL_SECURE_NO_WARNINGS
#include "Vector.h"
#include <algorithm>

Vector::Vector(int size) 
{
	this->size = size;
	this->vector = new int[size];
}

Vector::~Vector() 
{
	delete[]vector;
}

int& Vector::operator[](int index) 
{
	return vector[index];
}

int Vector::getSize()
{
	return this->size;
}

Vector* Vector::operator*(int val) 
{
	Vector *result = new Vector(this->size);
	for (int i = 0; i < this->size; ++i)
	{
		(*result)[i] = this->vector[i] * val;
	}
	return result;
}

int Vector::operator*(Vector& vectorA) 
{
	int result = 0;
	for (int i = 0; i < size; i++) 
	{
		result += this->vector[i] * vectorA[i];
	}
	return result;
}

Vector* Vector::sort() 
{
	Vector *result = new Vector(size);
	std::copy(this->vector, this->vector + size, result->vector);
	std::sort(result->vector, result->vector + size);
	return result;
}

int Vector::min_val()
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (vector[i] < min)
		{
			min = vector[i];
		}
	}
	return min;
}

int Vector::max_val()
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (vector[i] > max)
		{
			max = vector[i];
		}
	}
	return max;
}

Vector* Vector::operator+(Vector& v)
{
	Vector *result = new Vector(size);
	for (int i = 0; i < size; i++)
	{
		(*result)[i] = this->vector[i] + v[i];
	}
	return result;
}