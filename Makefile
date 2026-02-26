# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/02/26 19:42:50 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs # s = symbol table/index stored at the start within .a itself,
RM = rm -f 

# cannot use $(wildcard *.c), forbidden although moulinette won't check
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = ./$(LIBFT_DIR)/libft.a
HEADER = ft_printf.h

############ TARGETS ################
# if dependency doesn't exist or is outdated, dependency will be checked and built
# recursively (only what's needed)
# default target = first target in makefile
all: $(NAME)	

$(NAME): $(LIBFT) $(OBJ)
	cp $< $@
	$(AR) $(NAME) $(OBJ)

# dependencies for libft is checked within its own makefile
$(LIBFT): 
	make -C $(LIBFT_DIR)

# $< : automatic variable representing first dependency
# $@ : automatic variable representing target
# $^ : expands to all dependencies
# %:% : pattern rule for building individual files (%=the same name)
# header is only prerequisite, not included in compilation line,
# compiler finds header file from #include in source files OR
# -I include/ folder
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# to indicate targets that are not actual files, prevent clashes filenames that are
# same as phony targets
.PHONY: all clean fclean re
