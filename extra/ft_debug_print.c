/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:40:11 by belam             #+#    #+#             */
/*   Updated: 2026/03/08 23:41:10 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_t_flags(t_flags *p_flags)
{
	printf("align_left:%d,\npad_zero:%d,\nalt_form:%d,\nsign_space:%d,\nsign_plus:%d,\nwidth:%d,\nprecision:%d,\nneg_num:%d,\nconv_len:%d,\nspec:%c,\n", p_flags->align_left, p_flags->pad_zero, p_flags->alt_form, p_flags->sign_space, p_flags->sign_plus, p_flags->width, p_flags->precision, p_flags->neg_num, p_flags->conv_len, p_flags->spec);
}

static void print_t_features(t_features *p_features)
{
	printf("pad_char:%c,\npad_left_count:%u,\npad_right_count:%u,\nprec_pad_count:%u,\nsign_char:%s,\nalt_form_prefix:%s,\nconv:%s\n", p_features->pad_char, p_features->pad_left_count, p_features->pad_right_count, p_features->prec_pad_count, p_features->sign_char, p_features->alt_form_prefix, p_features->conv);
}

void	ft_debug_print(const char *format_str, t_flags *p_flags, 
	t_features *p_features, const char *msg)
{
	printf("%s", msg);
	print_t_flags(p_flags);
	print_t_features(p_features);
	printf("%s\n", format_str);
}

/*
// for o,x,X: regardless of which base is set as input 0x, 0b, 0, decimal, compiler will autotranslate and stores as binary in RAM
// cases: %z (invalid specifier)
int	main(int argc, char *argv[])
{
	//struct s_features features = {.pad_char = ' ', .pad_left_count = 0, .pad_right_count = 3, .sign_char = "", .width = -5};
	//print_features(&features, conv);
	if (argc == 4)
	{
		int a = 2;
		int b;
		if (argv[3][0] == 'c')
			b = ft_printf(argv[1], argv[2][0]);
		else if (argv[3][0] == 's')
			b = ft_printf(argv[1], argv[2]);
		else if (argv[3][0] == 'p')
			b = ft_printf(argv[1], (void *)&a);
		else if (argv[3][0] == 'x' || argv[3][0] == 'X')
			b = ft_printf(argv[1], atoi(argv[2]));
		else if (argv[3][0] == 'd' || argv[3][0] == 'i' || argv[3][0] == 'u')
			b = ft_printf(argv[1], atoi(argv[2]));
		printf("\nbytes printed:%d\n", b);
	}
	else if (argc == 2)
	{
		printf("%d" , format_is_valid(argv[1]));
	}
	return (0);
}*/
