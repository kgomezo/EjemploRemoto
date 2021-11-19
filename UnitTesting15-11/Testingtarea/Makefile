all: nthprime.x
test: test_prime.x
	./$<

nthprime.x: nthprime_main.cpp nthprime.cpp nthprime.h
	c++ $< nthprime.cpp -o $@

test_prime.x: nthprime_testing.cpp nthprime.cpp nthprime.h
	c++ $< nthprime.cpp -o $@

clean:
	rm -f *.x a.out *.x.* *~
