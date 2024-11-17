#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2 іт/Source.cpp" // Змініть на шлях до вашого файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int k = 3, n = 4, Low = 7, High = 65;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            Create(a, k, n, Low, High);

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            for (int i = 0; i < k; i++) delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestSumMaxOddColumns)
        {
            const int k = 3, n = 4;
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            // Ініціалізація тестових даних
            a[0][0] = 10; a[0][1] = 20; a[0][2] = 15; a[0][3] = 25;
            a[1][0] = 30; a[1][1] = 5;  a[1][2] = 35; a[1][3] = 40;
            a[2][0] = 50; a[2][1] = 45; a[2][2] = 55; a[2][3] = 60;

            int expectedSum = 50 + 55; // Максимальні елементи у непарних стовпцях (0, 2) = 50 і 55
            int actualSum = SumMaxOddColumns(a, k, n);
            Assert::AreEqual(expectedSum, actualSum);

            for (int i = 0; i < k; i++) delete[] a[i];
            delete[] a;
        }
    };
}
