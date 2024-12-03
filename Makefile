SRC_FILES := $(filter-out src/main.c, $(wildcard src/*.c))

install:
	sudo apt-get install gdb

i: install

run: 
	gcc src/main.c $(SRC_FILES) -o main.out
	./main.out

r: run

debug:
	gcc src/main.c $(SRC_FILES) -g -o main.out
	gdb ./main.out

d: debug

runtest:
	gcc test/test.c test/utils.c $(SRC_FILES) -o test.out
	./test.out

rt: runtest
t: runtest
test:runtest

debugtest:
	gcc test/test.c test/utils.c -g -o test.out
	gdb ./test.out

dt: debugtest

clean:
	rm main.out || true 
	rm test.out || true

c: clean
