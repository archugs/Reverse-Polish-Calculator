all : calculator

calculator : calculator.o stack.o
	g++ calculator.o stack.o -o calculator

calculator.o : calculator.cpp
	g++ -c calculator.cpp

stack.o : stack.cpp
	 g++ -c stack.cpp

clean :
	rm -rf *o calculator
