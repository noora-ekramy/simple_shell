# Simple Shell 

![Example Image](sea shell compi 0 (1).png)
A simple shell program for Unix-based systems, inspired by the Thompson Shell.

## Project Description 🚀

This project is an implementation of a simple Unix shell, inspired by the Thompson Shell, developed as a Milestone Project for the C code at ALX Africa Software Engineering Plus. 🌟

## Table of Contents
- [Introduction](#introduction)
- [Environment](#environment)
- [Allowed Functions](#allowed-functions)
- [Key Features](#key-features)
- [How to Use](#how-to-use)
- [Contributors](#contributors)
- [License and Copyright](#license-and-copyright)


## Introduction

Welcome to the Simple Shell Program, an elegant and efficient Unix-like shell inspired by the Thompson Shell.

The Simple Shell Program distinguishes itself through its dedication to customization and optimization, avoiding heavy reliance on existing tools. Our extensive use of low-level C programming ensures efficiency and reliability, making our shell a valuable resource for system programmers. In essence, our project reflects our dedication to excellence and craftsmanship in the world of Unix-like shells.

## Environment

The shell program has been developed and tested on the following environment:

- **Operating System:** Ubuntu 20.04

## Allowed Functions

The shell program utilizes the following functions, all implemented in C:

- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- wait
- waitpid
- wait3
- wait4
- write

Additionally, the shell program implements the following functions from scratch:
- cd 
- setenv
- unsetenv
- env
- _atoi
- _putchar
- _strcat
- _strcmp
- _strcpy
- _strcspn
- _strdup
- _strlen
- _strtok
- _getline

These functions are used to implement various functionalities of the shell program and interact with the operating system.

## Key Features

- **Interactive, Non-Interactive, and File Input Modes:**
  - Interactive mode allows users to enter commands and receive real-time output.
  - Non-interactive mode reads commands from a file, executing them without a prompt.
  - File input mode is supported with the usage: `simple_shell [filename]`, one command per line.

- **Error Handling:** 
  - Comprehensive error handling gracefully manages various scenarios, including command not found errors and exceptions.

- **Command Execution:** 
  - The shell executes external commands by locating executables in the system's PATH.
  - It avoids unnecessary forking if a command doesn't exist.

- **Built-In Commands:** 
  - Supports built-in commands like `cd`, `exit`, `env`, `setenv`, and `unsetenv`.

- **Signal Handling:** 
  - Handles signals such as Ctrl-C (SIGINT) to prevent unintended termination.

- **Argument Parsing:** 
  - Allows users to provide arguments with commands for more complex executions.

- **Exit Status:** 
  - Maintains exit statuses and supports the `exit` command to exit the shell with a specified status.

- **Custom `getline` Function:** 
  - Implements a custom `getline` function for efficient input reading.
  - Uses a buffer to minimize calls to the `read` system call and employs static variables.

- **Handling the PATH:** 
  - Manages the system's PATH variable to locate and execute external commands efficiently.

These features make the shell versatile and efficient, capable of handling various use cases and providing a user-friendly interface.


## How to Use

To experience the power and flexibility of this shell, follow these steps:

1. Clone the repository to your local machine using the following command:
```bash
$ git clone https://github.com/noora-ekramy/simple_shell.git
```
2. Change your current directory to the project directory:
```bash
$ cd simple_shell
```
3. Compile the program using the provided Makefile. This will create the `hsh` binary:
```bash
$ make
```
### interactive mode
Run the shell in interactive mode by executing the compiled binary. You can do this with the command:
```bash
$./hsh
```
Now, you can enter commands and receive real-time output.

### Non-Interactive Mode (Using Pipes)
In non-interactive mode, you can use the shell to execute commands from a file or by using pipes to provide input. Follow these steps:
1. Create a text file (e.g., `commands.txt`) containing one command per line.
2. Run the shell in non-interactive mode by providing the file as input. You can do this with the command:
```bash
cat commands.txt | ./hsh
```
Alternatively, you can use pipes directly with `echo` to provide input to the shell. For example:

```bash
echo "ls -l" | ./hsh
```

The shell will execute the commands and provide output.

### File Input Mode

This mode is useful for executing a series of commands stored in a file without the need for user interaction. Follow these steps:

1. Create a text file (e.g., `script.sh`) containing one command per line.

2. Run the shell with the file as an argument. You can do this with the command:
```bash
./hsh script.sh
```
The shell will execute the commands from the file without displaying a prompt or reading from standard input.
Now, you're ready to use the `hsh` shell in interactive, non-interactive (using pipes), or file input mode to execute commands and manage processes.

## Contributors

This project has been a labor of love contributed to by:

- [Nora Ekramy](https://github.com/noora-ekramy)
- [Malak Shenooda](https://github.com/malakehab2003)

We extend our heartfelt gratitude to them for their dedication and expertise.

## License and Copyright

Copyright (C) 2023 by [Nora Ekramy](https://github.com/noora-ekramy) and [Malak Shenooda](https://github.com/malakehab2003). 

All rights reserved.
