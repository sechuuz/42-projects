*This project has been created as part of the 42 curriculum by sechavez.*

# ft_printf

## Description

The goal of the 'ft_printf' project is to recode the 'printf' function from libc, implementing only the 'cspdiuxX%' conversions. 

The 'printf' function writes outputs to stdout according to a format given as the functions arguments.

This project serves as our introduction to 'variadic functions', functions who dont have a set amount of arguments.

Aditionally, the bonus part for this project calls for the implementation of the '-0.# +' flags that can be used.

## Algorithm and Data Structure

### Data Structure

I used a struct to hold the specifications set by the flags. This helps me store the data I need that would be applied to the output to easily be passed around to each handler function.

### Algorithm

There are three phases to my ft_printf algorithm:

1. **Parsing:** A loop iterates through the provided format character by character. It prints every character out until unless it comes across a ('%') character, which signals that a format specifier has been scanned and starts the parsing process, scanning for each character and storing the specifications for the output in a struct.

2. **Handler Dispatch:** The variadic argument is then passed to the correct handler based on its struct data. The handlers then build the main 'core' of the content that is to be printed, and then passes it to the correct formatter.

3. **Formatting:** The core is then passed to one of two central formatters, either a text formatter or a nmerical formatter, that will print out the core with the specifications from the flags.

## Instructions

### Compilation

To compile the library, run the following command in the root directory:
`make`

The following utilities can also be run:
* `make clean` Removes the object files.
* `make fclean` Removes all compiled files.
* `make re`	Rebuilds everything.

### Usage

To use the library in your code:

1. Include the header in your C file:
	```c
	#include "ft_printf.h"
	```

2. Compile your C file and link it to the library:
	```bash
	cc main.c libftprintf.a
	```

## Resources

### References

* [Variadic Functions Guide](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
* [printf Man Page](https://man7.org/linux/man-pages/man3/printf.3.html)
* [ISO/IEC 9899:201x (C11 Standard Draft)](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)

### Use of AI

AI assisted me in:
* Confirming the right approach for my algorithm
* Finding bugs and edge cases
* Structuring and using relevant terminology on my README.md

