*This project has been created as part of the 42 curriculum by belam.*

# Description
The goal of this project is to learn how formatted output works by recoding the printf function from <stdio.h>. The main learning outcome from a technical aspect is learning how to implement variadic functions (functions with a variable number of arguments).


# Feature List
## Format Specifiers
This ft_printf function supports several format specifiers, those in square brackets are optional.  
`%[flags][width][.precision]specifier`

This ft_printf covers the format specifiers:
- flags (any combination): `-` , `0` , `.` , `#` , `(SPACE)` , `+`
- width: positive and negative numbers, and `*` explicit argument placeholder 
- precision: positive fixed numbers and `*` explicit argument placeholder
- conversion: `c` , `s` , `p` , `d` , `i` , `u` , `x` , `X` , `%`


# Instructions / Usage Example
### Clone the Project
1. Navigate to the directory where you wish to clone the project.
2. Run `git clone TODO ft_printf` in the terminal.

### Creating Example Tester Code
As an example, create a `main.c` test file in the root directory of the project. This file prints the integer 42 with a width of 20, and then to print it again but with a width of 8, the 0 flag and the + flag:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Number:|%10d|\n", 42);
    ft_printf("Number:|%+0*d|\n", 8, 42);
    return (0);
}
```

### Build and Compile the project
1. Run `make`. This will compile all the libft and ft_printf source files into a static library called `libftprintf.a`.
2. `cc -Wall -Wextra -Werror -Ilibft main.c libftprintf.a -o ft_printf.out`

#### Build Process
1. Makefile in root directory runs Makefile in libft, where all source and header files in libft are compiled into object files and archived into libft.a.
2. Libft.a is copied from libft/ to the project root directory and renamed libftprintf.a.
3. All source files and header files in root directory are compiled into object files and added into libftprintf.a archive.
4. libftprintf.a is ready to be linked with any tester file.


### Run the executable
1. Run `./ft_printf.out`:
Expected outputs:
```
Number:|        42|
Number:|+0000042|
```


# Technical Choices:
### Code Structure
The structure of this ft_printf is split into multiple stages for easier readability and debugging.
1. ft_get_flags(): loops through the format specifiers and gathers information on flags, width, precision and conversion specifier
2. ft_flags_to_features(): decides what are the exact items (features) for next stage to print out based on information from ft_get_flags
3. ft_print_features(): does not do any "decision making", just takes information from previous stage and prints them out in sequence to produce final output

### Data Structures
This ft_printf uses 2 structs:  
- 1 for storing information on flags status (on/off), width, precision, conversion specifier and other important items for ft_flags_to_features to process
- 1 for storing features to print  

Structs were used in this project as it serves as a neat way to consolidate many related data and can be passed by reference through functions with just a single pointer to the struct.


# Testing
Tests used in testing process [Link](https://docs.google.com/spreadsheets/d/19WstOpo51PRMms_rZeCt9k1lbD864Ocp2sTwTVwSUpE/edit?usp=sharing)


# Caveats
Some findings I discovered while coding and testing this project:
- printf: invalid format specifiers (Ex: %0.-3d) will throw compilation errors on direct function call, but does work in nested function calls
- escape sequences (Ex: \n) do not work in terminal and are treated as literals, because the compiler is the one responsible for interepreting escape sequences, and executables run in the terminal are already compiled
- ft_itoa_base_64() was built to accommodate pointer size of 64-bits, whereas ft_itoa() takes input only as an integer, which will truncate the pointer to 32-bits


# Resources
- printf format specifiers official documentation - [man 3 printf](https://linux.die.net/man/3/printf)
- understanding explicit precision - [stackoverflow](https://stackoverflow.com/questions/61590813/difference-between-d-and-d-in-c-language)

# Future Improvements
- use binary to store flag states instead of integers to improve memory efficiency
- use array of function pointers to handle different conversion specifiers and flags
- reduce complexity of code and print characters along the way

