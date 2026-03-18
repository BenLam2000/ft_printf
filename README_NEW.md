*This project has been created as part of the 42 curriculum by belam.*

# Description
The goal of this project is to learn how formatted output works by recoding the printf function from <stdio.h>. The main learning outcome from a technical aspect is learning how to implement variadic functions (functions with a variable number of arguments).


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

### Run the executable
1. Run `./ft_printf.out`:
Expected outputs:
```
Number:|        42|
Number:|+0000042|
```





Technical Choices:
how the code works (high-level overview), different stages
why I split into stages
data strcutures used (struct)



how build works
how to run it (how to compile/make and how to use the library)
how did you do testing, show link to subject file
what did you learn from this project?
nuances that I discovered along the way
- printf: invalid format does not work on first level function call, but does work in nested function calls
- testing escape sequences does not work in terminal, because that is run using program after compile, test cases (including escape sequences) should be in source file and compiled, arguments on terminal treated as literals
reasoning behind why extra functions were built
- ft_itoa_base_64: pointer is 64 bit, but ft_itoa_base takes input as integer, will be truncated, hence use long
future improvements

Resources
- man 3 pintf
AI use
- only in Makefile for tester, stuck with some syntax


# Makefile
1. `make -C libft re` clean all .o and .a files and build libft.a from scratch
2. `cc -Wall -Wextra -Werror -c *.c -o *.o` compile all source files into object files without linking (with headers included)
3. Method 1 (FAIL)  
   `ar -crs libftprintf.a *.o ./libft/libft.a`  
   `ar -t libftprintf.a` would show that it generated the library containing .o files and libft.a  
   `cc -Wall -Wextra -Werror main.c libftprintf2.a` compile a new source file with the library will produce errors as the linker cannot retrieve the .o files from nested archives:
   
   ```
    ft_printf.c:(.text+0x2e): undefined reference to `ft_strchr'
    /usr/bin/ld: ft_printf.c:(.text+0x56): undefined reference to `ft_isdigit'
    /usr/bin/ld: ft_printf.c:(.text+0x82): undefined reference to `ft_isdigit'
    /usr/bin/ld: ft_printf.c:(.text+0xa1): undefined reference to `ft_strchr'
   ```
   Method 2 (UNTESTED)  
   Extract .o files from libft.a, copy them to root directory, then archive them with .o files for ft_printf. [Reference Link](https://stackoverflow.com/a/23557928)

   Method 3 (SUCCESS)  
   The linker only works if the .o files are at the root of the archive, not within nested archives.  
  `cp ./libft/libft.a ./libftprintf.a` Copy/move libft archive to root and rename  
  `ar -crs libftprintf.a *.o` Since the archive already exists, the `-c` flag will prevent duplicate .a and `-r` flag will insert .o files directly into the archive  
  `ar -t libftprintf.a` will display all .o files from libft and ft_printf  

# Future Improvements
- using binary to store flag states
- using array of function pointers to handle different conversion specifiers and flags


https://unix.stackexchange.com/questions/84227/limits-on-the-number-of-file-descriptors
