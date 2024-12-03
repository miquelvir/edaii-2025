# Developer Setup

## Linux

1. Install GCC
```zsh
sudo apt update
sudo apt install build-essential
sudo apt-get install gdb
gcc --version
```

## Mac

1. [Install homebrew](https://brew.sh/)

1. [Install GCC](https://formulae.brew.sh/formula/gcc#default)

2. [Install GDB](https://formulae.brew.sh/formula/gdb#default)

3. [Install make](https://formulae.brew.sh/formula/make#default)

## Windows

1. [Install WSL with Ubuntu](https://documentation.ubuntu.com/wsl/en/latest/guides/install-ubuntu-wsl2/) (Linux subsystem inside Windows)

2. Follow the instructions for [Linux](#linux) in a WSL terminal

# How to run

```zsh
make run
```

You can also use `make r`.

# How to run unit tests

```zsh
make runtest
```

You can also use `make rt`, `make t` and `make test`.

# How to run unit tests in GitHub

When you push to GitHub, your unit tests will automatically run. Check out the results and logs in:

```
https://github.com/{username}/{repo}/actions
```

# How to debug

```zsh
make debug
```

You can also use `make d`. Also, you can use `make debugtest` or `make dt` to debug the unit tests.

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
make clean
```
