wget https://cmake.org/files/v3.4/cmake-3.4.3.tar.gz
tar xf cmake-3.4.3.tar.gz
cd cmake-3.4.3
./bootstrap
make
sudo make install
cd ..
rm -rf cmake*
