using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class ConsoleScanner
    {

        private static ConsoleScanner consoleScanner;

        private static List<int> arr;
        private static int tempIndex;
        private static bool endOfLine = true;

        public static ConsoleScanner GetInstance()
        {
            if (consoleScanner == null)
            {
                consoleScanner = new ConsoleScanner();
            }
            return consoleScanner;
        }

        private ConsoleScanner()
        {
            arr = new List<int>();
        }

        public int NextInt()
        {
            if (endOfLine)
            {
                tempIndex = 0;
                arr.Clear();
                while (arr.Count == 0)
                {
                    string str = Console.ReadLine();
                    string[] inputs = str.Split(' ');
                    for (int i = 0; i < inputs.Length; i++)
                    {
                        int val;
                        if (int.TryParse(inputs[i], out val))
                        {
                            arr.Add(val);
                        }
                    }
                }
            }
            int result = arr[tempIndex++];
            if (tempIndex == arr.Count)
            {
                endOfLine = true;
            }

            return result;
        }

    }

    
}
