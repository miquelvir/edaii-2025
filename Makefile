SRC_FILES := $(filter-out src/main.c, $(wildcard src/*.c))
TEST_FILES := $(wildcard test/*.c)

install:
	sudo apt-get install gdb
	
run: 
	gcc src/main.c $(SRC_FILES)
	./a.out

debug:
	gcc src/main.c $(SRC_FILES) -g
	gdb ./a.out

runtest:
	gcc $(SRC_FILES) $(TEST_FILES)
	./a.out

debugtest:
	gcc $(SRC_FILES) $(TEST_FILES) -g
	gdb ./a.out
