package com.gmail.at.sichyuriyy;

import static com.gmail.at.sichyuriyy.MatrixVectorIO.*;

public class Main {

	// Func1
	// d = MAX(B + C) + MIN(A + B * (MA*ME))
	private static int d;
	private static Vector A, B, C;
	private static SquareMatrix MA, ME;

	// Func2
	// k = MAX(MF + MG*ML)
	private static int k;
	private static SquareMatrix MF, MG, ML;

	// Func3
	// S = (MO * MP) * (R + T)
	private static Vector S;
	private static Vector R, T;
	private static SquareMatrix MO, MP;

	public static void main(String[] args) {

		int inputMode;
		int size;

		ConsoleScanner in = ConsoleScanner.getInstance();

		System.out.println("input size if vectors and matrices");
		size = in.nextInt();
		
		initializeVectorsAndMatrices(size);
		
		System.out.println("Chose inputMode");
		System.out.println("1 - keyboard, 2 - number");

		inputMode = in.nextInt();
		

		if (inputMode == 1) {
			inputDataFromKeyBoard();
		} else {
			fillDataWithOneVal();
		}
		
		Task1 task1 = new Task1(A, B, C, MA, ME);
		Task2 task2 = new Task2(MF, MG, ML);
		Task3 task3Run = new Task3(MO, MP, R, T);
		Thread task3 = new Thread(task3Run, "Task3");
		
		task1.setPriority(Thread.MIN_PRIORITY);
		task2.setPriority(Thread.MAX_PRIORITY);
		task3.setPriority(Thread.NORM_PRIORITY);
		
		
		task1.start();
		task2.start();
		task3.start();
		
		try {
			task1.join();
			d = task1.getResult();
			task2.join();
			k = task2.getResult();
			task3.join();
			S = task3Run.getResult();
			
			System.out.println("Task1 result: " + d);
			System.out.println("Task2 result: " + k);
			System.out.println("Task3 result:");
			vectorOutput(S);
			
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		

	}
	
	public static void initializeVectorsAndMatrices(int size) {
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
	
	public static void inputDataFromKeyBoard() {
		System.out.println("d = MAX(B + C) + MIN(A + B * (MA*ME))");
		System.out.println("A:");
		vectorInput(A);
		System.out.println("B:");
		vectorInput(B);
		System.out.println("C:");
		vectorInput(C);
		System.out.println("MA:");
		matrixInput(MA);
		System.out.println("ME:");
		matrixInput(ME);
		
		System.out.println("k = MAX(MF + MG*ML)");
		System.out.println("MF:");
		matrixInput(MF);
		System.out.println("MG:");
		matrixInput(MG);
		System.out.println("ML:");
		matrixInput(ML);
		
		System.out.println("S = (MO * MP) * (R + T)");
		System.out.println("R:");
		vectorInput(R);
		System.out.println("T:");
		vectorInput(T);
		System.out.println("MO:");
		matrixInput(MO);
		System.out.println("MP:");
		matrixInput(MP);
	}
	
	public static void fillDataWithOneVal() {
		ConsoleScanner in = ConsoleScanner.getInstance();
		System.out.println("input val to fill the data");
		
		int val =  in.nextInt();
		
		vectorInput(A, val);
		vectorInput(B, val);
		vectorInput(C, val);
		matrixInput(MA, val);
		matrixInput(ME, val);
		
		matrixInput(MF, val);
		matrixInput(MG, val);
		matrixInput(ML, val);
		
		vectorInput(R, val);
		vectorInput(T, val);
		matrixInput(MO, val);
		matrixInput(MP, val);
	}

}
