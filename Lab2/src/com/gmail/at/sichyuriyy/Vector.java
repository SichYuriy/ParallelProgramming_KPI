package com.gmail.at.sichyuriyy;

import java.util.Arrays;

public class Vector {

	private int size;
	private int[] vector;

	public Vector(int size) {
		this.size = size;
		this.vector = new int[size];
	}

	public int get(int index) {
		return vector[index];
	}

	public void set(int index, int val) {
		vector[index] = val;
	}

	public int getSize() {
		return size;
	}

	public Vector mult(int val) {
		Vector result = new Vector(size);
		for (int i = 0; i < size; i++) {
			result.set(i, this.vector[i] * val);
		}
		return result;
	}

	public Vector mult(SquareMatrix matrix) {
		Vector result = new Vector(size);
		if (this.size != matrix.getSize()) {
			throw new RuntimeException("vector * matrix different sizes");
		}
		for (int i = 0; i < size; i++) {
			result.vector[i] = 0;
			for (int j = 0; j < size; j++) {
				result.vector[i] += this.vector[i] * matrix.get(j, i);
			}
		}
		return result;
	}

	public int mult(Vector vector) {
		int result = 0;
		if (this.size != vector.getSize()) {
			throw new RuntimeException("vector * vector different sizes");
		}
		for (int i = 0; i < size; i++) {
			result += this.vector[i] * vector.vector[i];
		}

		return result;
	}

	public Vector sort() {
		Vector result = new Vector(size);
		System.arraycopy(this.vector, 0, result.vector, 0, size);
		Arrays.sort(result.vector);
		return result;
	}

	public int min() {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < size; i++) {
			if (vector[i] < min) {
				min = vector[i];
			}
		}
		return min;
	}

	public int max() {
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < size; i++) {
			if (vector[i] > max) {
				max = vector[i];
			}
		}
		return max;
	}

	public Vector plus(Vector vector) {
		if (this.size != vector.getSize()) {
			throw new RuntimeException("vector + vector different sizes");
		}
		Vector result = new Vector(size);

		for (int i = 0; i < size; i++) {
			result.set(i, this.get(i) + vector.get(i));
		}

		return result;
	}

}
