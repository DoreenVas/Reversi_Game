
a.out: compileAll
	g++ *.o -o client.out
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
