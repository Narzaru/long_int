fprog:
	gcc *.c -g3 -fsanitize=address -o main.out
	./main.out

clean:
	rm -rf *.out
	rm -rf *.s

prof: clean
	gcc -pg -Wall -Wextra -g3 -fsanitize=address *.c -o main.out
	./main.out
	gprof ./main.out