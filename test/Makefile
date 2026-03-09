# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 18:05:57 by belam             #+#    #+#              #
#    Updated: 2026/03/06 18:51:01 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =================== MODIFY THIS (DON'T ADD / AT THE END) =============================
FT_PRINTF_DIR=./..
LIBFT_DIR=./../libft
# ======================================================================================

TEST=test.sh
OUTPUT=test
LIBFTPRINTF_A=$(FT_PRINTF_DIR)/libftprintf.a

all: c s p d i u x X pc mix

c: ./test_c/$(OUTPUT)
	bash $(TEST) c

s: ./test_s/$(OUTPUT)
	bash $(TEST) s

p: ./test_p/$(OUTPUT)
	bash $(TEST) p

d: ./test_d/$(OUTPUT)
	bash $(TEST) d

i: ./test_i/$(OUTPUT)
	bash $(TEST) i

u: ./test_u/$(OUTPUT)
	bash $(TEST) u

x: ./test_x/$(OUTPUT)
	bash $(TEST) x

X: ./test_X/$(OUTPUT)
	bash $(TEST) X
	
pc: ./test_pc/$(OUTPUT)
	bash $(TEST) pc
	
mix: ./test_mix/$(OUTPUT)
	bash $(TEST) mix

./%/$(OUTPUT): ./%/test.c $(LIBFTPRINTF_A)
	cc -Wall -Wextra -Werror -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR) $< $(LIBFTPRINTF_A) -o $@

$(LIBFTPRINTF_A):
	make -C $(FT_PRINTF_DIR)	

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -f */user_test*.out
	rm -f */test*.in
	rm -f */test*.format

# clean all .o, .a, testing artifacts and output program
fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f */test
	rm -f */test*.out

re: fclean all

.PHONY: all clean fclean re c s p d i u x X pc mix
