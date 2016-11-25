#include "MatrixVectorIO.h"
#include <iostream>
#include <mpi.h>

using namespace std;

void inputDataFromKeyBoard();
void fillDataWithOneVal();
void initializeVectorsAndMAtrices(int size);

// Func1
// d = MAX(B + C) + MIN(A + B * (MA*ME))

/*
void task1()
{
	cout << "Task1 start\n";
	d = ((*B) + (*C))->max_val() + ((*MA) * (*ME))->min_val();
	cout << "Task1 end\n";
	
}

// Func2
// k = MAX(MF + MG*ML)
int k;
SquareMatrix *MF, *MG, *ML;
void task2()
{
	cout << "Task2 start\n";
	k = ((*MF) + *((*MG) * (*ML)))->max_val();
	cout << "Task2 end\n";
	
}

// Func3
// S = (MO * MP) * (R + T)

Vector *S;
Vector *R, *T;
SquareMatrix *MO, *MP;

void task3()
{
	cout << "Task3 start\n";
	S = (*((*MO) * (*MP)))*(*((*R) + (*T)));
	cout << "Task3 end\n";
	
}
*/

int main(int argc, char *argv[]){
	
	int ierr, procid, numprocs;

	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &procid);
	//ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	int d;
	Vector *A, *B, *C;
	SquareMatrix *MA, *ME;

	int k;
	SquareMatrix *MF, *MG, *ML;

	Vector *S;
	Vector *R, *T;
	SquareMatrix *MO, *MP;
	

	int size = 100;

	int val = 5;
	
	if (procid == 0)
	{
		A = new Vector(size);
		B = new Vector(size);
		C = new Vector(size);
		MA = new SquareMatrix(size);
		ME = new SquareMatrix(size);

		VectorInput(*A, val);
		VectorInput(*B, val);
		VectorInput(*C, val);
		MatrixInput(*MA, val);
		MatrixInput(*ME, val);

		cout << "Task1 start\n";
		d = ((*B) + (*C))->max_val() + ((*MA) * (*ME))->min_val();
		cout << "Task1 end\n";
	}

	if (procid == 1) {

		MF = new SquareMatrix(size);
		MG = new SquareMatrix(size);
		ML = new SquareMatrix(size);

		MatrixInput(*MF, val);
		MatrixInput(*MG, val);
		MatrixInput(*ML, val);
		cout << "Task2 start\n";
		k = ((*MF) + *((*MG) * (*ML)))->max_val();
		cout << "Task2 end\n";
	}

	if (procid == 2) {
		R = new Vector(size);
		T = new Vector(size);
		MO = new SquareMatrix(size);
		MP = new SquareMatrix(size);

		VectorInput(*R, val);
		VectorInput(*T, val);
		MatrixInput(*MO, val);
		MatrixInput(*MP, val);


		cout << "Task3 start\n";
		S = (*((*MO) * (*MP)))*(*((*R) + (*T)));
		cout << "Task3 end\n";

	}
	cout << "end pf proc" << procid << endl;
	MPI_Barrier(MPI_COMM_WORLD);
	if (procid == 0) {
		cout << "Results " << endl;
		cout << "Task1:" << d << endl;

	}
	MPI_Barrier(MPI_COMM_WORLD);
	if (procid == 1) {

		cout << "Task2:" << k << endl;

	}
	MPI_Barrier(MPI_COMM_WORLD);
	if (procid == 2) {

		cout << "Task3:" << endl;

	}
	
	
	

	system("pause");
	ierr = MPI_Finalize();
	
	
}

/*
	
*/

/*
void initializeVectorsAndMAtrices(int size)
{
	
	if (procid == 0) {
	A = new Vector(size);
	B = new Vector(size);
	C = new Vector(size);
	MA = new SquareMatrix(size);
	ME = new SquareMatrix(size);

	VectorInput(*A, val);
	VectorInput(*B, val);
	VectorInput(*C, val);
	MatrixInput(*MA, val);
	MatrixInput(*ME, val);

	cout << "Task1 start\n";
	d = ((*B) + (*C))->max_val() + ((*MA) * (*ME))->min_val();
	cout << "Task1 end\n";
	}
	if (procid == 1) {
	MF = new SquareMatrix(size);
	MG = new SquareMatrix(size);
	ML = new SquareMatrix(size);

	MatrixInput(*MF, val);
	MatrixInput(*MG, val);
	MatrixInput(*ML, val);

	cout << "Task2 start\n";
	k = ((*MF) + *((*MG) * (*ML)))->max_val();
	cout << "Task2 end\n";
	}
	if (procid == 2) {
	R = new Vector(size);
	T = new Vector(size);
	MO = new SquareMatrix(size);
	MP = new SquareMatrix(size);

	VectorInput(*R, val);
	VectorInput(*T, val);
	MatrixInput(*MO, val);
	MatrixInput(*MP, val);

	cout << "Task3 start\n";
	S = (*((*MO) * (*MP)))*(*((*R) + (*T)));
	cout << "Task3 end\n";
	}
	

	

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
	//cin >> val;
	val = 2;

	

	

	
}

*/