using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class MatrixVectorIO
    {

        public static void VectorInput(Vector vector)
        {
            ConsoleScanner sc = ConsoleScanner.GetInstance();
            for (int i = 0; i < vector.GetSize(); i++)
            {
                vector.Set(i, sc.NextInt());
            }
        }

        public static void VectorInput(Vector vector, int val)
        {
            for (int i = 0; i < vector.GetSize(); i++)
            {
                vector.Set(i, val);
            }
        }

        public static void VectorOutput(Vector vector)
        {
            for (int i = 0; i < vector.GetSize(); i++)
            {
                Console.Write(vector.Get(i) + " ");
            }
        }

        public static void MatrixInput(SquareMatrix matrix)
        {
            ConsoleScanner sc = ConsoleScanner.GetInstance();
            for (int i = 0; i < matrix.GetSize(); i++)
            {
                for (int j = 0; j < matrix.GetSize(); j++)
                {
                    matrix.Set(i, j, sc.NextInt());
                }
            }
        }

        public static void MatrixInput(SquareMatrix matrix, int val)
        {
            for (int i = 0; i < matrix.GetSize(); i++)
            {
                for (int j = 0; j < matrix.GetSize(); j++)
                {
                    matrix.Set(i, j, val);
                }
            }
        }

        public static void MatrixOutput(SquareMatrix matrix)
        {
            for (int i = 0; i < matrix.GetSize(); i++)
            {
                for (int j = 0; j < matrix.GetSize(); j++)
                {
                    Console.Write(matrix.Get(i, j) + "\t");
                }
                Console.WriteLine();
            }
        }

    }
}
