#/bin/bash
#RUN
git clone -b poco-1.11.7-release https://github.com/pocoproject/poco.git
cd poco
mkdir cmake-build
cd cmake-build
cmake ..
make
sudo make install
cd ..
cd ..

