program: main.cpp timer.cpp
	g++ -O3 -o main main.cpp timer.cpp -g

run: program
	./main
