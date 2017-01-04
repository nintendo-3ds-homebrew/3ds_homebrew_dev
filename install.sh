#!bin/sh

chmod +x ./devkitARMupdate.pl
echo "chmod +x ./devkitARMupdate.pl [\033[32mOK\033[0m]"

echo "=========================================================================\n"

grep "export DEVKITPRO=~/devkitPro" ~/.zshrc
retval=$?

if [ "$retval" != 0 ]
	then echo "export DEVKITPRO=~/devkitPro" >> ~/.zshrc
fi

grep "export DEVKITARM=\$DEVKITPRO/devkitARM" ~/.zshrc
retval=$?

if [ "$retval" != 0 ]
	then echo "export DEVKITARM=\$DEVKITPRO/devkitARM" >> ~/.zshrc
fi

source ~/.zshrc 
echo "\n========================================================================="
printf "DEVKITPRO and DEVKITARM set in environment [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

perl ./devkitARMupdate.pl
echo "\n========================================================================="
printf "./devkitARMupdate.pl [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

rm -fr ~/devkitPro/libctru/
rm -fr /tmp/ctrulib
git clone https://github.com/smealum/ctrulib.git /tmp/ctrulib
mv /tmp/ctrulib/libctru ~/devkitPro/
make install -C ~/devkitPro/libctru/
echo "\n========================================================================="
printf "libctru updated [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

rm -fr ~/devkitPro/citro3d
git clone https://github.com/fincs/citro3d.git ~/devkitPro/citro3d
make install -C ~/devkitPro/citro3d/
echo "\n========================================================================="
printf "citro3d installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

rm -fr ~/devkitPro/sf2dlib
git clone https://github.com/xerpi/sf2dlib.git ~/devkitPro/sf2dlib
make install -C ~/devkitPro/sf2dlib/libsf2d/
echo "\n========================================================================="
printf "sf2dlib installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

#rm -fr ~/devkitPro/3ds_portlibs
#git clone https://github.com/xerpi/3ds_portlibs.git ~/devkitPro/3ds_portlibs
#make all -C ~/devkitPro/3ds_portlibs
#echo "========================================================================="
#printf "Portlibs installed [\033[32mOK\033[0m]\n"
#echo "=========================================================================\n"

rm -fr ~/devkitPro/sfillib
git clone https://github.com/xerpi/sfillib.git ~/devkitPro/sfillib
make install -C ~/devkitPro/sfillib/libsfil/
echo "\n========================================================================="
printf "sfillib installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"

rm -fr ~/devkitPro/sftdlib
git clone https://github.com/xerpi/sftdlib.git ~/devkitPro/sftdlib
make install -C ~/devkitPro/sftdlib/libsftd/
echo "\n========================================================================="
printf "sftdlib installed [\033[32mOK\033[0m]\n"
echo "=========================================================================\n"
