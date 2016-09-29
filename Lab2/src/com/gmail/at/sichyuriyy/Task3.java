package com.gmail.at.sichyuriyy;

public class Task3 implements Runnable {

	private Vector S;
	private SquareMatrix MO, MP;
	private Vector R, T;
	
	// S = (MO * MP) * (R + T)
	public Task3(SquareMatrix MO, SquareMatrix MP,
			Vector R, Vector T) {
		this.MO = MO;
		this.MP = MP;
		this.R = R;
		this.T = T;
	}

	@Override
	public void run() {
		System.out.println("Task3 start");
		S = MO.mult(MP).mult(R.plus(T));
		System.out.println("Task3 end");
	}
	
	public Vector getResult() {
		return S;
	}

}
