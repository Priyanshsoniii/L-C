using System;
using System.Linq;

namespace HelloWorld
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] inputValues = ReadIntegerArrayFromConsole();
            int arraySize = inputValues[0];
            int queryCount = inputValues[1];

            long[] numbersArray = ReadLongArrayFromConsole();
            long[] prefixSumArray = ComputePrefixSum(numbersArray, arraySize);

            ProcessQueries(queryCount, prefixSumArray);
        }

        private static int[] ReadIntegerArrayFromConsole()
        {
            return Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        }

        private static long[] ReadLongArrayFromConsole()
        {
            return Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        }

        private static long[] ComputePrefixSum(long[] numbersArray, int size)
        {
            long[] prefixSum = new long[size + 1];
            for (int i = 1; i <= size; i++)
            {
                prefixSum[i] = prefixSum[i - 1] + numbersArray[i - 1];
            }
            return prefixSum;
        }

        private static void ProcessQueries(int queryCount, long[] prefixSumArray)
        {
            for (int i = 0; i < queryCount; i++)
            {
                int[] range = ReadIntegerArrayFromConsole();
                int leftIndex = range[0];
                int rightIndex = range[1];
                long sumInRange = prefixSumArray[rightIndex] - prefixSumArray[leftIndex - 1];
                int elementCount = rightIndex - leftIndex + 1;
                Console.WriteLine(sumInRange / elementCount);
            }
        }
    }
}