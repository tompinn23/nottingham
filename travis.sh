wget https://cmake.org/files/v3.4/cmake-3.4.3.tar.gz
tar xvf cmake-3.4.3.tar.gz
cd cmake-3.4.3
./bootstrap
make
make install
cd ..
rm -rf cmake*
