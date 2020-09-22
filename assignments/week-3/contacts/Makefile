all : test-add test-remove test-update test-find test-size

contacts.o : contacts.cc
	g++ -std=c++11 -c -o contacts.o contacts.cc

test-add : tests/add.cc contacts.o
	g++ -std=c++11 -o tests/add.out tests/add.cc contacts.o

test-remove : tests/remove.cc contacts.o
	g++ -std=c++11 -o tests/remove.out tests/remove.cc contacts.o

test-update : tests/update.cc contacts.o
	g++ -std=c++11 -o tests/update.out tests/update.cc contacts.o

test-find : tests/find.cc contacts.o
	g++ -std=c++11 -o tests/find.out tests/find.cc contacts.o

test-size : tests/size.cc contacts.o
	g++ -std=c++11 -o tests/size.out tests/size.cc contacts.o

clean :
	rm *.o tests/*.out
