using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class Vector
    {
        private int size;
        private int[] vector;

        public Vector(int size)
        {
            this.size = size;
            this.vector = new int[size];
        }

        public int Get(int index)
        {
            return vector[index];
        }

        public void Set(int index, int val)
        {
            vector[index] = val;
        }

        public int GetSize()
        {
            return size;
        }

        public static Vector operator *(Vector va, int val)
        {
            Vector result = new Vector(va.size);
            for (int i = 0; i < va.size; i++)
            {
                result.Set(i, va.vector[i] * val);
            }
            return result;
        }

        public static Vector operator *(int val, Vector va)
        {
            return va * val;
        }

        public static int operator *(Vector va, Vector vb)
        {
            int result = 0;
            if (va.size != vb.GetSize())
            {
                throw new Exception("vector * vector different sizes");
            }
            for (int i = 0; i < va.size; i++)
            {
                result += va.vector[i] * vb.vector[i];
            }

            return result;
        }

        public Vector Sort()
        {
            Vector result = new Vector(size);
            Array.Copy(this.vector, 0, result.vector, 0, size);
            Array.Sort(result.vector);
            return result;
        }

        public int Min()
        {

            int min = int.MaxValue;
            for (int i = 0; i < size; i++)
            {
                if (vector[i] < min)
                {
                    min = vector[i];
                }
            }
            return min;
        }

        public int Max()
        {
            int max = int.MinValue;
            for (int i = 0; i < size; i++)
            {
                if (vector[i] > max)
                {
                    max = vector[i];
                }
            }
            return max;
        }

        public static Vector operator +(Vector va, Vector vb)
        {
            if (va.size != vb.GetSize())
            {
                throw new Exception("vector + vector different sizes");
            }
            Vector result = new Vector(va.size);

            for (int i = 0; i < va.size; i++)
            {
                result.Set(i, va.Get(i) + vb.Get(i));
            }

            return result;
        }
    }
}
