

#include "MatrixVectorIO.h"
#include <iostream>
#include <omp.h>
#include <windows.h>
#include <process.h>
#include <stdio.h>

using namespace std;

void inputDataFromKeyBoard();
void fillDataWithOneVal();
void initializeVectorsAndMAtrices(int size);

// Func1
// d = MAX(B + C) + MIN(A + B * (MA*ME))

int d;
Vector *A, *B, *C;
SquareMatrix *MA, *ME;

DWORD WINAPI task1(__in LPVOID lpParameter)
{
	cout << "Task1 start\n";
	d = ((*B) + (*C))->max_val() + ((*MA) * (*ME))->min_val();
	cout << "Task1 end\n";
	return 0;
}

// Func2
// k = MAX(MF + MG*ML)
int k;
SquareMatrix *MF, *MG, *ML;

DWORD WINAPI task2(__in LPVOID lpParameter)
{
	cout << "Task2 start\n";
	k = ((*MF) + *((*MG) * (*ML)))->max_val();
	cout << "Task2 end\n";
	return 0;
}

// Func3
// S = (MO * MP) * (R + T)

Vector *S;
Vector *R, *T;
SquareMatrix *MO, *MP;

DWORD WINAPI task3(__in LPVOID lpParameter)
{
	cout << "Task3 start\n";
	S = (*((*MO) * (*MP)))*(*((*R) + (*T)));
	cout << "Task3 end\n";
	return 0;
}


int main(){
	int inputMode;
	int size;

	cout << "input size of vectors and matrices" << endl;
	cin >> size;
	initializeVectorsAndMAtrices(size);

	cout << "Chose inputMode" << endl;
	cout << "1 - keyboard, 2 - number" << endl;

	cin >> inputMode;

	if (inputMode == 1) 
	{
		inputDataFromKeyBoard();
	} 
	else
	{
		fillDataWithOneVal();
	}


#pragma omp parallel num_threads(3) 
	{

#pragma omp sections
		{

#pragma omp section
			{
				task1(0);
			}



#pragma omp section
			{
			task2(0);
			}	

#pragma omp section
			{
				task3(0);
			}



		}
	}



	cout << "task1 results: " << d << endl;
	cout << "task2 results: " << k << endl;
	cout << "task3 results:" << endl;
	VectorOutput(*S);


	system("pause");
}

void initializeVectorsAndMAtrices(int size)
{
	A = new Vector(size);
	B = new Vector(size);
	C = new Vector(size);
	MA = new SquareMatrix(size);
	ME = new SquareMatrix(size);

	MF = new SquareMatrix(size);
	MG = new SquareMatrix(size);
	ML = new SquareMatrix(size);

	R = new Vector(size);
	T = new Vector(size);
	MO = new SquareMatrix(size);
	MP = new SquareMatrix(size);

}

void inputDataFromKeyBoard()
{
	cout << "d = MAX(B + C) + MIN(A + B * (MA*ME))" << endl;
	cout << "A:" << endl;
	VectorInput(*A);
	cout << "B:" << endl;
	VectorInput(*B);
	cout << "C:" << endl;
	VectorInput(*C);
	cout << "MA:" << endl;
	MatrixInput(*MA);
	cout << "ME:" << endl;
	MatrixInput(*ME);

	cout << "k = MAX(MF + MG*ML)" << endl;
	cout << "MF:" << endl;
	MatrixInput(*MF);
	cout << "MG:" << endl;
	MatrixInput(*MG);
	cout << "ML:" << endl;
	MatrixInput(*ML);

	cout << "S = (MO * MP) * (R + T)" << endl;
	cout << "R:" << endl;
	VectorInput(*R);
	cout << "T:" << endl;
	VectorInput(*T);
	cout << "MO:" << endl;
	MatrixInput(*MO);
	cout << "MP:" << endl;
	//MatrixInput(*MP);

}

void fillDataWithOneVal()
{
	int val;
	cout << "input val to fill the data" << endl;
	cin >> val;

	VectorInput(*A, val);
	VectorInput(*B, val);
	VectorInput(*C, val);
	MatrixInput(*MA, val);
	MatrixInput(*ME, val);

	MatrixInput(*MF, val);
	MatrixInput(*MG, val);
	MatrixInput(*ML, val);

	VectorInput(*R, val);
	VectorInput(*T, val);
	MatrixInput(*MO, val);
	MatrixInput(*MP, val);
}

