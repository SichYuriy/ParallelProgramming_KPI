#include "Vector.h"

class SquareMatrix
{
private:
	int size;
	int **matrix;

	~SquareMatrix();

public:
	
	SquareMatrix(int size);

	int get(int i, int j);

	void set(int val, int i, int j);

	int getSize();

	SquareMatrix* operator*(int val);

	Vector* operator*(Vector& v);

	SquareMatrix* operator*(SquareMatrix& ma);
	
	SquareMatrix* trans();

	int min_val();

	int max_val();

	SquareMatrix* sort();

	SquareMatrix* operator+(SquareMatrix& ma);


};