*This project has been created as part of the 42 curriculum by sechavez.*

# push_swap

## Description

The 'push_swap' project gives us the task of creating a C program that sorts a set of integer values with the shortest sequence of 'push_swap' instructions using two stacks.

The 'push_swap' instructions we have at our disposal are the following:

*	**sa (swap a)**: Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one element or none.

*	**sb (swap b)**: Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one element or none.

*	**ss** : sa and sb at the same time.

*	**pa (push a)**: Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.

*	**pb (push b)**: Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.

*	**ra (rotate a)**: Shift up all elements of stack a by 1.
		The first element becomes the last one.

*	**rb (rotate b)**: Shift up all elements of stack b by 1.
		The first element becomes the last one.

*	**rr** : ra and rb at the same time.

*	**rra (reverse rotate a)**: Shift down all elements of stack a by 1.
		The last element becomes the first one.

*	**rrb (reverse rotate b)**: Shift down all elements of stack b by 1.
		The last element becomes the first one.
		
*	**rrr** : rra and rrb at the same time.

We want our program to aim for the minimum amount of instructions, making sure each 'push_swap' operation is executed with optimization in mind. Because of this, I decided to use the 'Turk Algorithm' for sorting the integers. The 'Turk Algorithm' is a greedy algorithm and was popularized **A. Yigit Ogun**, a student from 42-Heilbronn.

After researching about other algorithms such as radix and chunk sort, I had decided to go with the 'Turk Algorithm' approach after consulting my peers about it, and also because after finding out how it worked, I thought it would be quite interesting to implement.

There is also the bonus, which tasks us with programming a replica of the 'checker_OS' programs that you can use to check if a set of operations correctly sorts a set of integers.

## Instructions

### Compilation

To compile the main 'push_swap' program, run the following command in the root directory:

`make`

To compile the 'checker' program, run the following command in the root directory:

`make bonus`

The following utilities can also be run:
* `make clean` Removes the object files.
* `make fclean` Removes all compiled files.
* `make re`	Rebuilds the push_swap program.

### Usage

To run the push_swap program, call the push_swap file that was built after compiling and then the list of integers you'd like to use. Any invalid arguments (such as duplicate integers, arguments not being integers, arguments going above/below the integer limit) will be met with an error message.

```bash
./push_swap 3 2 1 0
```

The program will output the shortest list of instructions to sort the provided list of integers. 

To run the checker program, call the push_swap file, the list of integers you'd like to use, and pipe it into calling the checker file (compiled from the bonus part) along with a copy of the list of integers you'd like to use.

```bash
ARG="3 2 1 0"; ./push_swap $ARG | ./checker $ARG
```

This program will accept a list of operations and will verify if it has been correctly sorted. **OK** will be displayed if it was sorted with the operations specified, and **KO** if not.

## Resources

### References

* [Analysis of algorithms (Wikipedia Page)](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
* [Greedy algorithm (Wikipedia Page)](https://en.wikipedia.org/wiki/Greedy_algorithm)
* [A. Yigit Ogun's 'push_swap' Article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### Use of AI

AI assisted me in:
*	Confirming the right approach for my sorting algorithm
*	Finding bugs and edge cases