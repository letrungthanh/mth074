#include <iostream>

#include "mth074.h"

int main(int argc, char *argv[])
{
    { // basic arithmetic
        std::cout << -1_mpz << std::endl;
        std::cout << +1_mpz << std::endl;
        std::cout << 1_mpz + 2_mpz << std::endl;
        std::cout << 2_mpz - 1_mpz << std::endl;
        std::cout << 2_mpz * 3_mpz << std::endl;
        std::cout << 7_mpz / 2_mpz << std::endl;
        std::cout << 7_mpz % 2_mpz << std::endl;
    }

    { // calculate very big fibonacci number
        std::cout << mth074::fibonacci::calc_digits(100'000) << std::endl;
        std::cout << mth074::fibonacci::calc(100'000) << std::endl;
    }

    { // calculate greatest common divisor between very big fibonacci numbers
        std::cout << mth074::gcd(mth074::fibonacci::calc(100'000), mth074::fibonacci::calc(200'0000)) << std::endl;
    }

    return 0;
}