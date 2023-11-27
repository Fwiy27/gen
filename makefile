workdir=~/bench/generator

files = main.cpp \
		Classes/Random/Random.cpp \
		Classes/Name/Name.cpp \
		Classes/City/City.cpp \
		Classes/Date/Date.cpp \
		Classes/Email/Email.cpp \
		Classes/Password/Password.cpp \
		Classes/Chooser/Chooser.cpp \
		Classes/Generator/Generator.cpp
cpp:
	cd ${workdir}
	g++ --std=c++20 ${files} -o main
	# ./main
	# make clean

clean:
	cd ${workdir}
	rm main