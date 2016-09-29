package com.gmail.at.sichyuriyy;

import java.util.Arrays;

public class SquareMatrix {

	private int size;
	private int[][] matrix;

	public SquareMatrix(int size) {
		this.size = size;
		this.matrix = new int[size][size];
	}

	public int getSize() {
		return size;
	}

	public int get(int i, int j) {
		return matrix[i][j];
	}

	public void set(int i, int j, int val) {
		matrix[i][j] = val;
	}

	public SquareMatrix mult(int val) {
		SquareMatrix result = new SquareMatrix(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.matrix[i][j] = this.matrix[i][j] + val;
			}
		}
		return result;
	}

	public Vector mult(Vector vector) {

		if (this.size != vector.getSize()) {
			throw new RuntimeException("matrix * vector different sizes");
		}

		Vector result = new Vector(size);
		for (int i = 0; i < size; i++) {
			result.set(i, 0);
			for (int j = 0; j < size; j++) {
				result.set(i, result.get(i) + vector.get(i) * this.matrix[j][i]);
			}
		}
		return result;
	}
	
	public SquareMatrix mult(SquareMatrix matrix) {
		if (this.size != matrix.size) {
			throw new RuntimeException("vector * matrix different sizes");
		}
		
		SquareMatrix result = new SquareMatrix(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.matrix[i][j] = 0;
				for (int k = 0; k < size; k++) {
					result.matrix[i][j] += this.matrix[i][k] * matrix.matrix[k][j];
				}
			}
		}
		return result;
	}
	
	public SquareMatrix trans() {
		SquareMatrix result = new SquareMatrix(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.matrix[j][i] = this.matrix[i][j];
			}
		}
		return result;
	}
	
	public int min() {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (matrix[i][j] < min) {
					min = matrix[i][j];
				}
			}
		}
		return min;
	}
	
	public int max() {
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (matrix[i][j] > max) {
					max = matrix[i][j];
				}
			}
		}
		return max;
	}
	
	public SquareMatrix sort() {
		SquareMatrix result = new SquareMatrix(size);
		for (int i = 0; i < size; i++) {
			System.arraycopy(this.matrix[i], 0, result.matrix[i], 0, size);
			Arrays.sort(result.matrix[i]);
		}
		return result;
	}
	
	public SquareMatrix plus(SquareMatrix matrix) {
		if (this.size != matrix.size) {
			throw new RuntimeException("vector * matrix different sizes");
		} 
		
		SquareMatrix result = new SquareMatrix(size);
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.matrix[i][j] = this.matrix[i][j] + matrix.matrix[i][j];
			}
		}
		return result;
	}
	
	

}
