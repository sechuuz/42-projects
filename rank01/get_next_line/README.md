*This project has been created as part of the 42 curriculum by sechavez.*

# get_next_line

## Description

The 'get_next_line' project has the goal of writing a C function that returns the text in the file that a file descriptor is pointing to, one line at a time, with each call of the function returning the next line.

This project introduces us to static variables, which are needed for the function to be able to find and return the next line from the file descriptor.

The bonus part for this project calls for get_next_line with the restrictions of only using one static variable, as well as being able to handle multiple file descriptors.

## Algorithm

The algorithm for my get_next_line is as follows:

1. **Read:** We read from the file descriptor into a temporary buffer, the size of which is specified by the defined BUFFER_SIZE. We keep reading from the file descriptor until we find a newline character or if we reach the end of the file.

2. **Stash:** Our static variable, which will keep track of each line from our file descriptor, is the 'stash'. With each read, we join the buffer into our stash. Once the reading is finished, we have effectively gotten a line from the file.

3. **Return:** Because our stash was formed from multiple buffers, it still has the characters included from after the newline character. Our stash is then formatted into a proper line by only including the characters before the newline, and stored in a separate array. The original stash is then prepared for the next call of get_next_line by keeping only the characters after the previous newline character, which is why the use of a static variable is important - it allows us to keep track of each line from the file even through multiple calls.

## Instructions

### Usage

To use the function in your code:

1. Include the header in your C file:
	```c
	#include "get_next_line.h"
	```
	```c
	#include "get_next_line_bonus.h"
	```

2. Compile your C file with the get_next_line files:
	```bash
	cc main.c get_next_line.c get_next_line_utils.c
	```
	```bash
	cc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
	```

## Resources

### References

* [Static Variables Guide](https://www.geeksforgeeks.org/c/static-variables-in-c/)
* [read() Man Page](https://man7.org/linux/man-pages/man2/read.2.html)
* [open() Man Page](https://man7.org/linux/man-pages/man2/open.2.html)
* [File Descriptor Wikipedia Page](https://en.wikipedia.org/wiki/File_descriptor)


### Use of AI

AI assisted me in:
* Confirming the right approach for my algorithm
* Finding bugs and edge cases