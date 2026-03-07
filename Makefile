# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/03/06 17:25:34 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs # s = symbol table/index stored at the start within .a itself,
RM = rm -f 

# cannot use $(wildcard *.c), forbidden although moulinette won't check
SRC = ft_printf.c ft_itoa_base.c ft_itoa_base_64.c ft_putchar_fd_b.c \
	ft_putstr_fd_b.c ft_atoi_end.c ft_max.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
HEADERS = ft_printf.h $(LIBFT_DIR)/libft.h
INCLUDE_DIR = $(LIBFT_DIR)

############ TARGETS ################
# if dependency doesn't exist or is outdated, dependency will be checked and built
# recursively (only what's needed)
# default target = first target in makefile
all: $(NAME)	

$(NAME): $(LIBFT_A) $(OBJ)
	cp $< $@
	$(AR) $(NAME) $(OBJ)

# dependencies for libft is checked within its own makefile
$(LIBFT_A):
	make -C $(LIBFT_DIR)

# $< : automatic variable representing first dependency
# $@ : automatic variable representing target
# $^ : expands to all dependencies
# %:% : pattern rule for building individual files (%=the same name)
# header is only prerequisite, not included in compilation line,
# compiler finds header file from current directory OR -Iinclude/ folder
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# clean .o files from both ./ and ./libft
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

# clean all .o files and .a files
fclean: clean
	$(RM) $(LIBFT_A)
	$(RM) $(NAME)

re: fclean all

# to indicate targets that are not actual files, prevent clashes filenames that are
# same as phony targets
.PHONY: all clean fclean re
