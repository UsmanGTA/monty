# MONTY - C - Stacks, Queues - LIFO, FIFO
![Header Image](https://www.geeksultd.com/wp-content/uploads/2020/05/Monty-Stacks-Queues.jpg)
## Synopsis
This project is a part of a Holberton Curriculum building upon previous concepts of stacks, queues and linked lists.

## Built by
- Tristan Thrasher - tristan.thrasher-1[at]ou.edu
- Usman Abdul Jabbar - usmangta[at]gmail.com - UsmanJabbar.com

## Files
- 0-main.c - Contains all of the driver code necessary to run the interpreter.
- 1-logic.c - Contains all the logic pertaining to the opcodes, / push / pall / nop / .
- 2-logic-continued.c - Contains all the logic pertaining the opcodes, / pop / add / swap / pint / .
- 3-advanced.c - Contails all the logic pertaining the opcodes, / sub / div / mul / mod / .
- 4-advanced-continued.c - Contains all the logic pertaining the opcodes, / pchar / pstr / .
- 5-helper.c - Contains all of the custom functions, mostly related to cleanup.
- monty.h - Contains all of the headers, declarations, and structs.
- README.md - A file that reads itself. Completely clueless.

## A Brief Overview
### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Usage: monty file
- where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, its not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
- where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
- where is the line number where the instruction appears.
- Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
- it executed properly every line of the file
- it finds an error in the file
- an error occured

If you cant malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, )

This project allows us to dive deeper into stacks and queues where stacks are built with the help of linked lists. Furthermore, this project also tries to build on previous concepts such as memory management, LIFO, FIFO and manipulating such stacks.

The core of the project lies in the push function that allows users to build the stack (LIFO). Further down the line, new functions had to integrated to affirm the all the previous concepts.
