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
