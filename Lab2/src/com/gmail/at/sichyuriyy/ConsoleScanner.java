package com.gmail.at.sichyuriyy;

import java.util.Scanner;

public class ConsoleScanner {
	
	private static ConsoleScanner consoleScanner;
	
	private Scanner in; 
	
	public static ConsoleScanner getInstance() {
		if (consoleScanner == null) {
			consoleScanner = new ConsoleScanner();
		}
		return consoleScanner;
	}
	
	private ConsoleScanner() {
		in = new Scanner(System.in);
	}
	
	
	
	public int nextInt() {
		return in.nextInt();
	}

}
