# Simple Shell 

A simple shell program for Unix-based systems, inspired by the Thompson Shell.

## Project Description 🚀

This project is an implementation of a simple Unix shell, inspired by the Thompson Shell, developed as a Milestone Project for the C code at ALX Africa Software Engineering Plus. 🌟

## Table of Contents
- [Introduction](#introduction)
- [Environment](#environment)
- [Key Features](#key-features)
- [How to Use](#how-to-use)
- [Contributors](#contributors)
- [License and Copyright](#license-and-copyright)

## Introduction

Welcome to the Simple Shell Program, an elegant and efficient Unix-like shell inspired by the Thompson Shell.

The Simple Shell Program distinguishes itself through its dedication to customization and optimization, avoiding heavy reliance on existing tools. Our extensive use of low-level C programming ensures efficiency and reliability, making our shell a valuable resource for system programmers. In essence, our project reflects our dedication to excellence and craftsmanship in the world of Unix-like shells.

## Environment

The shell program has been developed and tested on the following environment:
- Operating System: Ubuntu 20.04

## Key Features

- **Interactive Shell**: The shell provides an interactive command-line interface where users can enter commands and receive output.

- **Error Handling**: Comprehensive error handling ensures that the shell gracefully handles various scenarios, including command not found errors and other exceptions.

- **Command Execution**: The shell is capable of executing external commands by locating executables in the system's PATH.

- **Built-In Commands**: It supports built-in commands like `cd`, `exit`, `env`, `setenv`, and `unsetenv`.

- **Signal Handling**: The shell handles signals like Ctrl-C (SIGINT) to prevent unintended termination.

- **Argument Parsing**: Users can provide arguments with commands, allowing for more complex command execution.

- **Exit Status**: The shell maintains exit statuses and supports the `exit` command to exit the shell with a specified status.

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
4. Run the shell by executing the compiled binary:
```bash
$./hsh
```
Now, you're ready to begin using the `hsh` shell to execute commands and manage processes.

## Contributors

This project has been a labor of love contributed to by:

- [Nora Ekramy](https://github.com/noora-ekramy)
- [Malak Shenooda](https://github.com/malakehab2003)

We extend our heartfelt gratitude to them for their dedication and expertise.

## License and Copyright

Copyright (C) 2023 by [Nora Ekramy](https://github.com/noora-ekramy) and [Malak Shenooda](https://github.com/malakehab2003). 

All rights reserved.
