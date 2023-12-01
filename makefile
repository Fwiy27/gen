files = main.cpp \
		Classes/FileParser/FileParser.cpp \
		Classes/Chooser/Chooser.cpp \
		Classes/Name/Name.cpp \
		Classes/Location/Location.cpp \
		Classes/Password/Password.cpp \
		Classes/Random/Random.cpp \
		Classes/Email/Email.cpp \
		Classes/Date/Date.cpp \
		Classes/Generator/Generator.cpp

cpp:
	make build
	make run
	make clean

build:
	g++ --std=c++20 ${files} -o main

run:
	./main

clean:
	rm main

docker:
	docker build -t gen .

# rd = Run Docker
rd:
	docker run -it --rm gen