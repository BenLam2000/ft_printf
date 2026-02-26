# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/02/25 21:34:51 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs # s = symbol table/index stored at the start within .a itself,
RM = rm -f 

# cannot use $(wildcard *.c), forbidden although moulinette won't check
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c\
	ft_itoa_base.c ft_itoa_base_64.c ft_putchar_fd_b.c ft_putstr_fd_b.c ft_atoi_end.c\
	ft_max.c
OBJ = $(SRC:.c=.o)
HEADER = libft.h

############ TARGETS ################
# if dependency doesn't exist or is outdated, dependency will be checked and built
# recursively (only what's needed)
# default target = first target in makefile
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# $< : automatic variable representing first dependency
# $@ : automatic variable representing target
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
