#!/bin/zsh

sudo apt-get install build-essential libsdl2-dev

echo "\n========================================================================="
printf "libsdl2 installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

sudo apt-get install qtbase5-dev libqt5opengl5-dev

echo "\n========================================================================="
printf "qtbase5-dev and libqt5opengl5 installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

sudo apt-get install build-essential

echo "\n========================================================================="
printf "build-essential installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

sudo apt-get install cmake

echo "\n========================================================================="
printf "cmake installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

sudo apt-get install clang libc++-dev

echo "\n========================================================================="
printf "clang libc++-dev installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

echo "\033[32mmkdir ~/citra-emu\033[0m]\n"
mkdir ~/citra-emu

echo "\033[32mgit clone --recursive https://github.com/citra-emu/citra ~/citra-emu/citra\033[0m]\n"
git clone --recursive https://github.com/citra-emu/citra ~/citra-emu/citra

echo "\033[32mmkdir ~/citra-emu/citra/build\033[0m]\n"
mkdir ~/citra-emu/citra/build

echo "\033[32mcmake ~/citra-emu/citra\033[0m]\n"
cd ~/citra-emu/citra/build/
cmake ..

echo "\033[32mmake -C ~/citra-emu/citra/build/\033[0m]\n"
make

echo "\033[32msudo make install -C ~/citra-emu/citra/build/\033[0m]\n"
sudo make install
