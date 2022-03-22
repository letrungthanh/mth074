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

} // namespace mth074

#endif