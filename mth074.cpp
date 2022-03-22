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

    { // co-prime
        std::cout << mth074::coprime(5210644015679228794060694325390955853335898483908056458352183851018372555735221_mpz,
                                     531137992816767098689588206552468627329593117727031923199444138200403559860852242739162502265229285668889329486246501015346579337652707239409519978766587351943831270835393219031728127_mpz)
                  << std::endl;
    }

    { // quick power
        std::cout << mth074::power(mth074::fibonacci::calc(100'000), 10) << std::endl;
    }

    { // calculate greatest common divisor between very big fibonacci numbers
        std::cout << mth074::gcd(mth074::fibonacci::calc(100'000), mth074::fibonacci::calc(200'0000)) << std::endl;
    }

    return 0;
}