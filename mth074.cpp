#include <iostream>

#include "mth074.h"

int main(int argc, char *argv[])
{
    std::cout << mth074::fibonacci::calc_digits(100'000) << std::endl;
    std::cout << mth074::fibonacci::calc(100'000) << std::endl;

    return 0;
}