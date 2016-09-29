package com.gmail.at.sichyuriyy;

public class Task1 extends Thread {

	private static final String THREAD_NAME = "Task1";
	
	private int d;
	private Vector A, B, C;
	private SquareMatrix MA, ME;

	// d = MAX(B + C) + MIN(A + B * (MA*ME))
	public Task1(Vector A, Vector B, Vector C, 
			SquareMatrix MA, SquareMatrix ME) {
		super(THREAD_NAME);
		this.A = A;
		this.B = B;
		this.C = C;
		this.MA = MA;
		this.ME = ME;
		
	}

	@Override
	public void run() {
		System.out.println("Task1 started");
		d = B.plus(C).max() + A.plus(B.mult(MA.mult(ME))).min();
		System.out.println("Task1 end");
	}
	
	public int getResult() {
		return d;
	}

}
