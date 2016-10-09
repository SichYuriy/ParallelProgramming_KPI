using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class SquareMatrix
    {
        private int size;
        private int[][] matrix;

        public SquareMatrix(int size) 
        {
		    this.size = size;
		    this.matrix = new int[size][];
            for (int i = 0; i < size; i++)
            {
                this.matrix[i] = new int[size];
            }

	    }

        public int GetSize()
        {
            return size;
        }

        public int Get(int i, int j)
        {
            return matrix[i][j];
        }

        public void Set(int i, int j, int val)
        {
            matrix[i][j] = val;
        }

        public static SquareMatrix operator *(SquareMatrix MA, int val)
        {
            SquareMatrix result = new SquareMatrix(MA.size);
            for (int i = 0; i < MA.size; i++)
            {
                for (int j = 0; j < MA.size; j++)
                {
                    result.matrix[i][j] = MA.matrix[i][j] + val;
                }
            }
            return result;
        }
        public static SquareMatrix operator *(int val, SquareMatrix MA)
        {
            return MA * val;
        }

        public static Vector operator *(SquareMatrix MA, Vector vector)
        {

            if (MA.size != vector.GetSize())
            {
                throw new Exception("matrix * vector different sizes");
            }

            Vector result = new Vector(MA.size);
            for (int i = 0; i < MA.size; i++)
            {
                result.Set(i, 0);
                for (int j = 0; j < MA.size; j++)
                {
                    result.Set(i, result.Get(i) + vector.Get(i) * MA.matrix[j][i]);
                }
            }
            return result;
        }

        public static Vector operator *(Vector vector, SquareMatrix MA)
        {
            return MA * vector;
        }

        public static SquareMatrix operator *(SquareMatrix MA, SquareMatrix MB)
        {
            if (MA.size != MB.size)
            {
                throw new Exception("vector * matrix different sizes");
            }

            SquareMatrix result = new SquareMatrix(MA.size);
            for (int i = 0; i < MA.size; i++)
            {
                for (int j = 0; j < MA.size; j++)
                {
                    result.matrix[i][j] = 0;
                    for (int k = 0; k < MA.size; k++)
                    {
                        result.matrix[i][j] += MA.matrix[i][k] * MB.matrix[k][j];
                    }
                }
            }
            return result;
        }

        public SquareMatrix Trans()
        {
            SquareMatrix result = new SquareMatrix(size);
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    result.matrix[j][i] = this.matrix[i][j];
                }
            }
            return result;
        }

        public int Min()
        {
            int min = int.MaxValue;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (matrix[i][j] < min)
                    {
                        min = matrix[i][j];
                    }
                }
            }
            return min;
        }

        public int Max()
        {
            int max = int.MinValue;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (matrix[i][j] > max)
                    {
                        max = matrix[i][j];
                    }
                }
            }
            return max;
        }

        public SquareMatrix Sort()
        {
            SquareMatrix result = new SquareMatrix(size);
            for (int i = 0; i < size; i++)
            {
                Array.Copy(this.matrix[i], 0, result.matrix[i], 0, size);
                Array.Sort(result.matrix[i]);
            }
            return result;
        }

        public static SquareMatrix operator +(SquareMatrix MA, SquareMatrix MB)
        {
            if (MA.size != MB.size)
            {
                throw new Exception("vector * matrix different sizes");
            }

            SquareMatrix result = new SquareMatrix(MA.size);

            for (int i = 0; i < MA.size; i++)
            {
                for (int j = 0; j < MA.size; j++)
                {
                    result.matrix[i][j] = MA.matrix[i][j] + MB.matrix[i][j];
                }
            }
            return result;
        }
    }
}
