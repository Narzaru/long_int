fprog:
	gcc *.c -g3 -fsanitize=address -o main.out
	./main.out

clean:
	rm -rf *.out