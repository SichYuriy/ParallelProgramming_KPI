using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Lab3
{
    class Program
    {
        // Func1
        // d = MAX(B + C) + MIN(A + B * (MA*ME))

        private static int d;
        private static Vector A, B, C, D;
        private static SquareMatrix MA, ME;

        public static void Task1()
        {
            Console.WriteLine("Task1 start");
            d = (B + C).Max() + (A + B * (MA * ME)).Min();
            Console.WriteLine("Task1 end");
        }


        // Func2
        // k = MAX(MF + MG*ML)
        private static int k;
        private static SquareMatrix MF, MG, ML;

        public static void Task2()
        {
            Console.WriteLine("Task2 start");
            k = (MF + MG * ML).Max();
            Console.WriteLine("Task2 end");
        }

        // Func3
        // S = (MO * MP) * (R + T)
        private static Vector S;
        private static Vector R, T;
        private static SquareMatrix MO, MP;

        public static void Task3()
        {
            Console.WriteLine("Task3 start");
            S = (MO * MP) * (R + T);
            Console.WriteLine("Task3 end");
        }

        static void Main(string[] args)
        {
            int inputMode;
		    int size;

		    ConsoleScanner sc = ConsoleScanner.GetInstance();

		    Console.WriteLine("input size if vectors and matrices");
		    size = sc.NextInt();
		
		    InitializeVectorsAndMatrices(size);
		
		    Console.WriteLine("Chose inputMode");
		    Console.WriteLine("1 - keyboard, 2 - number");

		    inputMode = sc.NextInt();
		

		    if (inputMode == 1) {
			    InputDataFromKeyBoard();
		    } else {
			    FillDataWithOneVal();
		    }


            ThreadStart task1Start = new ThreadStart(Task1);
            ThreadStart task2Start = new ThreadStart(Task2);
            ThreadStart task3Start = new ThreadStart(Task3);

            Thread task1 = new Thread(task1Start);
            Thread task2 = new Thread(task2Start);
            Thread task3 = new Thread(task3Start);

            task1.Priority = ThreadPriority.Lowest;
            task2.Priority = ThreadPriority.Normal;
            task3.Priority = ThreadPriority.Highest;


            task1.Start();
            task2.Start();
            task3.Start();

            task1.Join();
            task2.Join();
            task3.Join();

            Console.WriteLine("Task1 results: " + d);
            Console.WriteLine("Task2 results: " + k);
            Console.WriteLine("Task3 results: ");
            //MatrixVectorIO.VectorOutput(S);

            Console.ReadKey();

        }

        public static void InitializeVectorsAndMatrices(int size)
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

        public static void InputDataFromKeyBoard() {
		    Console.WriteLine("d = MAX(B + C) + MIN(A + B * (MA*ME))");
            Console.WriteLine("A:");
		    MatrixVectorIO.VectorInput(A);
            Console.WriteLine("B:");
            MatrixVectorIO.VectorInput(B);
            Console.WriteLine("C:");
            MatrixVectorIO.VectorInput(C);
            Console.WriteLine("MA:");
		    MatrixVectorIO.MatrixInput(MA);
            Console.WriteLine("ME:");
            MatrixVectorIO.MatrixInput(ME);

            Console.WriteLine("k = MAX(MF + MG*ML)");
            Console.WriteLine("MF:");
            MatrixVectorIO.MatrixInput(MF);
            Console.WriteLine("MG:");
            MatrixVectorIO.MatrixInput(MG);
            Console.WriteLine("ML:");
            MatrixVectorIO.MatrixInput(ML);

            Console.WriteLine("S = (MO * MP) * (R + T)");
            Console.WriteLine("R:");
            MatrixVectorIO.VectorInput(R);
            Console.WriteLine("T:");
            MatrixVectorIO.VectorInput(T);
            Console.WriteLine("MO:");
            MatrixVectorIO.MatrixInput(MO);
            Console.WriteLine("MP:");
            MatrixVectorIO.MatrixInput(MP);
	    }

        public static void FillDataWithOneVal() {
            ConsoleScanner sc = ConsoleScanner.GetInstance();
            Console.WriteLine("input val to fill the data");
		
		    int val =  sc.NextInt();

            MatrixVectorIO.VectorInput(A, val);
            MatrixVectorIO.VectorInput(B, val);
            MatrixVectorIO.VectorInput(C, val);
            MatrixVectorIO.MatrixInput(MA, val);
            MatrixVectorIO.MatrixInput(ME, val);

            MatrixVectorIO.MatrixInput(MF, val);
            MatrixVectorIO.MatrixInput(MG, val);
            MatrixVectorIO.MatrixInput(ML, val);

            MatrixVectorIO.VectorInput(R, val);
            MatrixVectorIO.VectorInput(T, val);
            MatrixVectorIO.MatrixInput(MO, val);
            MatrixVectorIO.MatrixInput(MP, val);
	    }
    }
}
