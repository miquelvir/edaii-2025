SRC_FILES := $(filter-out src/main.c, $(wildcard src/*.c))

compile:
	gcc -Wall -Wextra -Werror src/main.c $(SRC_FILES) -o main.out
	
r:
	make compile
	./main.out

v: 
	make compile
	valgrind --leak-check=yes ./main.out

compiledebug:
	gcc src/main.c $(SRC_FILES) -g -o main.out

d:
	make compiledebug
	gdb ./main.out


compiletest:
	gcc -Wall -Wextra -Werror test/test.c test/utils.c $(SRC_FILES) -o test.out

t:
	make compiletest
	./test.out

compiletestdebug:
	gcc test/test.c test/utils.c -g -o test.out

dt:
	make compiletestdebug
	gdb ./test.out

c:
	rm main.out || true 
	rm test.out || true

f:
	clang-format -i **/*.c **/*.h

cf:
	./check-format.sh
