### MTH074 Project - investigate C++ big integer library

## [The GNU Multiple Precision Arithmetic Library](https://gmplib.org/)

### [Compile and Install GMP library](https://gmplib.org/manual/Installing-GMP)

### Manual Installation ###
cd ~
wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
tar -xf gmp-6.2.1.tar.lz
cd gmp-6.2.1
./configure --enable-cxx
make
make check
make install

### Installation via apt
sudo apt-get install libgmp3-dev

### [Compile and Execute project](https://github.com/letrungthanh/mth074#readme)
cd ~
git clone https://github.com/letrungthanh/mth074.git
cd mth074
mkdir build
cd build
cmake ../
cmake --build .
./mth074
