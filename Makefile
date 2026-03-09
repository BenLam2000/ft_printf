# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/03/09 00:01:59 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
NAME		=	libftprintf.a
CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
AR 			=	ar -crs # s = symbol table/index stored at the start within .a itself,
RM 			=	rm -f 

SRC 		=	ft_printf.c ft_get_flags.c ft_handle_conv.c ft_flags_to_features.c\
				ft_print_features.c ft_itoa_base.c ft_itoa_base_64.c ft_putstr_fd_b.c\
				ft_atoi_end.c ft_max.c
OBJ 		= 	$(SRC:.c=.o)
LIBFT_DIR 	= 	./libft
LIBFT_A 	= 	$(LIBFT_DIR)/libft.a
HEADERS 	= 	ft_printf.h $(LIBFT_DIR)/libft.h
INCLUDE_DIR = 	$(LIBFT_DIR)

############# RULES ##################
all			: 	$(NAME)

bonus		: 	all

$(NAME)		: 	$(LIBFT_A) $(OBJ)
				cp $< $@
				$(AR) $(NAME) $(OBJ)

# dependencies for libft is checked within its own makefile
$(LIBFT_A)	:
				make -C $(LIBFT_DIR)

%.o			:	%.c $(HEADERS)
				$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# clean .o files from both ./ and ./libft
clean		:
				make -C $(LIBFT_DIR) clean
				$(RM) $(OBJ)

# clean all .o files and .a files
fclean		: 	clean
				$(RM) $(LIBFT_A)
				$(RM) $(NAME)

re			: 	fclean all

.PHONY		:	all clean fclean re
