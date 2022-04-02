#ifndef __MTH074__H__
#define __MTH074__H__

#include <iostream>
#include <gmpxx.h>
#include <cmath>

namespace mth074
{
    using bigint_t = mpz_class;

    namespace fibonacci
    {
        /**
         * @brief calculate term-th fibonacci number
         */
        template <typename T = bigint_t>
        T calc(size_t term)
        {
            if (term == 0)
                return 0;

            T a = 0, b = 1, c;

            for (size_t i = 2; i <= term; ++i)
            {
                c = a + b;
                a = b;
                b = c;
            }

            return b;
        }

        /**
         * @brief calculate number of digits of term-th fibonacci number - Binet’s Formula
         */
        size_t calc_digits(size_t term)
        {
            if (term == 1)
                return 1;

            return std::ceil((term * std::log10(1.6180339887498948)) - ((std::log10(5)) / 2));
        }
    } // namespace fibonacci

    /**
     * @brief calculate greatest common divisor - Euclide's Formula
     */
    template <typename T = bigint_t>
    T gcd(T a, T b)
    {
        if (a < 0)
            a = -a;

        if (b < 0)
            b = -b;

        while (a != 0 && b != 0)
        {
            if (a > b)
                a %= b;
            else
                b %= a;
        }

        return a + b;
    }

    /**
     * @brief test co-prime
     */
    template <typename T = bigint_t>
    bool coprime(T const &a, T const &b)
    {
        return 1 == gcd<T>(a, b);
    }

    /**
     * @brief quick power
     */
    template <typename T = bigint_t>
    T power(T a, size_t n)
    {
        T p = 1;

        while (n)
        {
            if (n % 2 == 1)
                p *= a;

            a *= a;
            n /= 2;
        }

        return p;
    }

    // Tai
    void testOverflow()
    {
        std::cout << "\ntestOverflow\n";
        std::cout << "expected is 2^64\n";
        uint64_t num1 {1u << 64}; // Overflow: result is 0
        std::cout << "uint64_t: " << num1 << std::endl;
        bigint_t num2 {(bigint_t)1 << 64};
        std::cout << "bigint lib: " << num2 << std::endl;
    }

    void testNumberCannotBePresentedByDouble()
    {
        std::cout << "\ntestNumberCannotBePresentedByDouble\n";
        std::cout << "Number: 2^53 cannot displayed by double\n";
        std::cout << "2^53 + 1 = 9007199254740992 + 1\n";
        double num {pow(2, 53)};
        std::cout << "uint64_t: " << static_cast<uint64_t>(num)  + 1 << std::endl;
        std::cout << "double: " << static_cast<uint64_t>(num + 1) << std::endl;
        std::cout << "bigint: " << bigint_t(num) + 1 << std::endl; 
    }

    void testTimeExecution()
    {
//        std::cout << "=======================================\n";
//        std::cout << "testTimeExecution\n";
//
//        // Generate Input
//        constexpr uint64_t numberOfSamples = 1e6;
//        std::vector<bigint> leftValues;
//        std::vector<bigint> rightValues;
//        srand(time(0));
//        for(int i = 0; i < numberOfSamples; i++)
//        {
//            leftValues.emplace_back(rand());
//            rightValues.emplace_back(rand());
//        }
//
//        std::vector<bigint> result(leftValues.size(), 0);
//
//        // Addition operator
//        auto start = std::chrono::high_resolution_clock::now();
//        std::ios_base::sync_with_stdio(false);
//        for (int i = 0; i < leftValues.size(); i++)
//        {
//            result[i] = leftValues[i] + rightValues[i];
//        }
//        auto end = std::chrono::high_resolution_clock::now();
//        double timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
//        timeTaken /= 1000000;
//        std::cout << "Addition: " << timeTaken << std::endl;
//
//        // Substraction oprator
//        start = std::chrono::high_resolution_clock::now();
//        std::ios_base::sync_with_stdio(false);
//        for (int i = 0; i < leftValues.size(); i++)
//        {
//            result[i] = leftValues[i] - rightValues[i];
//        }
//        end = std::chrono::high_resolution_clock::now();
//        timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
//        timeTaken /= 1000000;
//        std::cout << "Substraction: " << timeTaken << std::endl;
//
//        // Multiplication opeartor
//        start = std::chrono::high_resolution_clock::now();
//        std::ios_base::sync_with_stdio(false);
//        for (int i = 0; i < leftValues.size(); i++)
//        {
//            result[i] = leftValues[i] * rightValues[i];
//        }
//        end = std::chrono::high_resolution_clock::now();
//        timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
//        timeTaken /= 1000000;
//        std::cout << "Multiplication: " << timeTaken << std::endl;
    }

} // namespace mth074

#endif
