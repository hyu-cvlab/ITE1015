main : a.o b.o main.o
	g++ -o main a.o b.o main.o
a.o : a.cc
	g++ -c -o a.o a.cc

b.o : b.cc
	g++ -c -o b.o b.cc

main.o : main.cc
	g++ -c -o main.o main.cc

clean :
	rm *.o main

