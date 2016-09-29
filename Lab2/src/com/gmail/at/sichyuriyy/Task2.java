package com.gmail.at.sichyuriyy;

public class Task2 extends Thread {
	
	private static final String THREAD_NAME = "Task2";
	
	private int k;
	private SquareMatrix MF, MG, ML;
	
	// k = MAX(MF + MG*ML)
	public Task2(SquareMatrix MF, SquareMatrix MG, SquareMatrix ML) {
		super(THREAD_NAME);
		this.MF = MF;
		this.MG = MG;
		this.ML = ML;
	}
	
	@Override
	public void run() {
		System.out.println("Task2 start");
		k = MF.plus(MG.mult(ML)).max();
		System.out.println("Task2 end");
	}
	
	public int getResult() {
		return k;
	}

}
