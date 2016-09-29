package com.gmail.at.sichyuriyy;

public class MatrixVectorIO {
	
	public static void vectorInput(Vector vector) {
		ConsoleScanner in = ConsoleScanner.getInstance();
		System.out.println("vector:");
		for (int i = 0; i < vector.getSize(); i++) {
			vector.set(i, in.nextInt());
			
		}
		
	}
	
	public static void vectorInput(Vector vector, int val) {
		for (int i = 0; i < vector.getSize(); i++) {
			vector.set(i, val);
		}
	}
	
	public static void vectorOutput(Vector vector) {
		for (int i = 0; i < vector.getSize(); i++) {
			System.out.print(vector.get(i) + " ");
		}
		System.out.println();
	}
	
	public static void matrixInput(SquareMatrix matrix) {
		ConsoleScanner in = ConsoleScanner.getInstance();
		for (int i = 0; i < matrix.getSize(); i++) {
			for (int j = 0; j < matrix.getSize(); j++) {
				matrix.set(i, j, in.nextInt());
			}
		}
		
	}
	
	public static void matrixInput(SquareMatrix matrix, int val) {
		for (int i = 0; i < matrix.getSize(); i++) {
			for (int j = 0; j < matrix.getSize(); j++) {
				matrix.set(i, j, val);
			}
		}
	}
	
	public static void matrixOutput(SquareMatrix matrix) {
		for (int i = 0; i < matrix.getSize(); i++) {
			for (int j = 0; j < matrix.getSize(); j++) {
				System.out.print(matrix.get(i, j) + "\t");
			}
			System.out.println();
		}
	}
	
	

}
