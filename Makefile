CXX = g++
test:test.cpp pqs
	g++ ./test.cpp -o test

clean:
	rm ./test