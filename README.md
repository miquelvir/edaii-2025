# Developer Setup

## Windows

1. [Install WSL with Ubuntu](https://documentation.ubuntu.com/wsl/en/latest/guides/install-ubuntu-wsl2/) (Linux subsystem inside Windows)

2. Follow the instructions for [Linux](#linux) in a WSL terminal

## Mac

1. [Install homebrew](https://brew.sh/)

1. [Install GCC](https://formulae.brew.sh/formula/gcc#default)

2. [Install make](https://formulae.brew.sh/formula/make#default)

## Linux

1. Install GCC
```zsh
sudo apt update
sudo apt install build-essential
gcc --version
```

# How to run
```zsh
make run
```

# How to run unit tests
```zsh
make runtest
```

# How to run unit tests in GitHub

When you push to GitHub, your unit tests will automatically run. Check out the results and logs in:

```
https://github.com/{username}/{repo}/actions
```

# How to debug
```zsh
make install
make debug
```

## Start
```zsh
run
```

## Find stack trace
```zsh
backtrace
```

## Move through the stack trace
```zsh
up
down
```

## Print a variable
```zsh
print x
```


# How to remove temporary files
```zsh
make clean
```
