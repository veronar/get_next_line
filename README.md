# **Get_Next_Line**

WeThinkCode_ Core project  
Reading a line on a fd is way too tedious

### **Description**
The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

## Objective
This project will not only allow us to add a very convenient function to our collection, but it will also allow us to learn a highly interesting new concept in C programming: static variables.  
We will also gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.  
Our respect of the Norm will improve the rigor of our programming. Our approach to coding will change when we discover that the initial state of a variable in a function can vary depending on the call of that very function.  

Allowed functions:
- read
- malloc
- free

## Installation

Clone the get_next_line repo and change to the repo directory:

```
git clone https://github.com/veronar/get_next_line
cd ./get_next_line/get_next_line/
```

### Compilation

In order to use get_next_line in folder `./test_main` run the `Makefile` with the following command:

```
make
```

This will create an executable called `gnl` which will read from the `test.txt`.  
The main can be edited to open any other files & read from it accordingly.

If edits are made to get_next_line, it will need to be recompiled  
To recompile run the following command:

```
make re
```

Get_next_line is a function that is added to LibFT (1st WeThinkCode_ Core project), added to the libft.h header file and used as a part of LibFT.

## Usage

To use get_next_line `#include "get_next_line.h"` will need to be added to the list of included libraries & will need to be in the correct directory.
