![Unit Tests](https://github.com/miquelvir/edaii-2025/actions/workflows/unit-tests.yml/badge.svg)

> [!NOTE]  
> Remember to change the link above to match your GitHub username and repository name. Then, remove this comment.

# Authors

Group number: (todo, add the group number here)

- (todo, add the email of the first group member)
- (todo, add the email of the second group member)
- (todo, add the email of the third group member)

# Plagiarism Disclaimer
- You **MUST NOT** look at anyone else's solutions, including previous year students and external tutors.
- You **MUST** make your repository private.
- You **MAY** discuss the assignments with other students, but you may not look at or copy each others' code.
- You **MUST** commit frequently to the repository (at least 1 commit per exercise).
- You **MUST NOT** share your code with other students even if they ask you to.
- You **MUST** add a link next to any code you copy from external sources.
- You **MUST NOT** ask other students for their project or fragments of their code.

# Repository Contents

- [.github/workflows/unit-tests.yml](./.github/workflows/unit-tests.yml): script to run tests when pushing to GitHub (CI)
- [datasets](./datasets/): datasets of documents you can use to test your search engine
    - [wikipedia12](./datasets/wikipedia12/): a dataset of 13 documents about animals
    - [wikipedia270](./datasets/wikipedia270/): a dataset of 271 documents about different topics
    - [wikipedia540](./datasets/wikipedia540/): a dataset of 541 documents about different topics
    - [wikipedia5400](./datasets/wikipedia5400/): a dataset of 5401 documents about different topics
- [src](./src/): folder with all `.c` and `.h` files to run your program
    - [main.c](./src/main.c): entrypoint to your program
    - [sample_lib.c](./src/sample_lib.c): an example of how to write `.c` files
    - [sample_lib.h](./src/sample_lib.h): an example of how to write `.h` files
- [test](./test/): folder with all `.c` and `.h` files to unit test your program
    - [test.c](./test/test.c): test runner entrypoint
    - [sample_lib_test.c](./test/sample_lib_test.c): an example of how to write unit tests
- [Makefile](./Makefile): file defining what `make` commands are used to run the code from the CLI

# Developer Setup

## Linux

1. Install GCC
```zsh
sudo apt update
sudo apt install build-essential
sudo apt install gdb
sudo apt install valgrind
sudo apt install clang-format
gcc --version
```

2. Create your group repository from the template (instructions in the groups spreadsheet)

3. [Clone the repository using VSCode](https://code.visualstudio.com/docs/sourcecontrol/intro-to-git#_clone-a-repository-locally)
   
5. Run `make r` and make sure you see this message: `Welcome to EDA 2!`

## MacOS

1. [Install homebrew](https://brew.sh/)

1. [Install GCC](https://formulae.brew.sh/formula/gcc#default)

2. [Install GDB](https://formulae.brew.sh/formula/gdb#default)

3. [Install make](https://formulae.brew.sh/formula/make#default)

4. [Install clang-format](https://formulae.brew.sh/formula/clang-format#default)

5. Create your group repository from the template (instructions in the groups spreadsheet)

6. [Clone the repository using VSCode](https://code.visualstudio.com/docs/sourcecontrol/intro-to-git#_clone-a-repository-locally)
   
8. Run `make r` and make sure you see this message: `Welcome to EDA 2!`

## Windows

1. [Install WSL with Ubuntu](https://documentation.ubuntu.com/wsl/en/latest/guides/install-ubuntu-wsl2/) (Linux subsystem inside Windows)

2. Follow the instructions for [Linux](#linux) in a WSL terminal

> [!NOTE]  
> You could compile and run C code directly on Windows. However, the repository template only works on WSL. Thus, you might need to adapt it for it to work. We recommend using WSL instead to avoid problems.

# How to run

```zsh
make r
```

# How to run unit tests

```zsh
make t
```

# How to format the code

```zsh
make f
```

# How to use Valgrind to check for memory leaks

```zsh
make v
```

# How to run unit tests in GitHub

When you push to GitHub, your [unit tests will automatically run](.github/workflows/unit-tests.yml). Check out the results and logs in the Actions tab of your repository (in GitHub).

# How to debug

```zsh
make d
```

You can also use `make dt` to debug the unit tests.

Then, you can:
- Start the program
```zsh
run
```

- View the stack trace
```zsh
backtrace
```

- Move through the stack trace
```zsh
up
down
```
- Print a variable
```zsh
print x
```

# How to remove temporary files
```zsh
make c
```

# How to parse a document?

```c
Document *document_desserialize(char *path) {
    FILE *f = fopen(path, "r");
    assert(f != NULL);
    
    Document *document = (Document *)malloc(sizeof(Document));
    
    char buffer[262144];
    int bufferSize = 262144;
    int bufferIdx = 0;
    char ch;

    // parse id
    while ((ch = fgetc(f)) != '\n') {
        assert(bufferIdx < bufferSize);
        buffer[bufferIdx++] = ch;
    }
    assert(bufferIdx < bufferSize);
    buffer[bufferIdx++] = '\0';
    document->id = atoi(buffer);

    // parse title
    // TODO

    // parse body
    char linkBuffer[64];
    int linkBufferSize = 64;
    int linkBufferIdx = 0;
    bool parsingLink = false;
    Links *links = LinksInit();
    
    bufferIdx = 0;
    while ((ch = fgetc(f)) != EOF) {
        assert(bufferIdx < bufferSize);
        buffer[bufferIdx++] = ch;
        if (parsingLink) {
            if (ch == ')') { // end of link
                parsingLink = false;
                assert(linkBufferIdx < linkBufferSize);
                linkBuffer[linkBufferIdx++] = '\0';
                int linkId = atoi(linkBuffer);

                // TODO add to links

                linkBufferIdx = 0;
            } else if (ch != '(') { // skip first parenthesis of the link
                assert(linkBufferIdx < linkBufferSize);
                linkBuffer[linkBufferIdx++] = ch;
            } 
        } else if (ch == ']') { // found beginning of link id, e.g.: [my link text](123)
          parsingLink = true;
        }
    }
    assert(bufferIdx < bufferSize);
    buffer[bufferIdx++] = '\0';
    
    char *body = (char *)malloc(sizeof(char) * bufferIdx);
    strcpy(body, buffer);

    // TODO
}
```
