run:
	g++ knapsack.cpp -g -Wall
	./a.out < knapsack.in

testfile:
	g++ knapsack.cpp -g -Wall 
	./a.out < testinput > testout.ans 

test: clean testfile
	g++ tester.cpp -o test -g 
	./test

clean:
	rm -f test a.out
