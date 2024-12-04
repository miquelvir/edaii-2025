SRC_FILES := $(filter-out src/main.c, $(wildcard src/*.c))

r: 
	gcc src/main.c $(SRC_FILES) -o main.out
	./main.out

d:
	gcc src/main.c $(SRC_FILES) -g -o main.out
	gdb ./main.out


t:
	gcc test/test.c test/utils.c $(SRC_FILES) -o test.out
	./test.out

dt:
	gcc test/test.c test/utils.c -g -o test.out
	gdb ./test.out

c:
	rm main.out || true 
	rm test.out || true

f:
	clang-format -i **/*.c

cf:
	./check-format.sh
