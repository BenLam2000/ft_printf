/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/02/26 03:37:14 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "./libft/libft.h"
#include "ft_printf.h"

// TODO:
// ft_atoi_end
// . flag
// makefile
// tester file
// input type is not same as specifier
// number of arguments not matching format string
// NULL input or ""
// change structs to typedefs
// move ft_itoa_base and 64 into root dir, remove declaration from libft/libft.h & libft/Makefile and add to ft_printf.h and Makefile
// restructure folder to have src, incl, obj...
// replace const strings with macros (radix)
// readd NULL malloc checking in ft_itoa_base and 64

// DONE:
// check for correct format before conversion to prevent segmentation fault
// handle invalid specifiers/flags
// flags in any order or combination
// return value

// '/0' terminator is included in strchr check, so ft_strchr(anything, '\0') == true
int	format_is_valid(const char *format_str)
{
	while (ft_strchr("-0# +", *format_str) && *format_str)
		format_str++;
	while (ft_isdigit(*format_str))
		format_str++;
	if (*format_str == '.')
		format_str++;
	while (ft_isdigit(*format_str))
		format_str++;
	if (ft_strchr("cspdiuxX%", *format_str) && *format_str)
		return (1);
	return (0);
}


// ptr passed is pointing at %-0d
//                            ^ 
// need to take note which flags are mutually exclusive (won't appear tgt side by side)
// - : for any conversion
// 0 : only numbers
// + and ' ': only signed numbers
// handles repeating valid flags and in any sequence, ex: "%00#-5d"
// ft_atoi only returns int, but have to traverse manually after that, so integrate
// traversing into ft_atoi_end, modifying the char * directly
void	check_flags_width(const char **format_str, struct s_flags *ptr_flags)
{
	*ptr_flags = (struct s_flags){.precision = -1};
	while (ft_strchr("-0# +", **format_str))
	{
		if (**format_str == '-')
			ptr_flags->align_left = 1;
		else if (**format_str == '0')
			ptr_flags->pad_zero = 1;
		else if (**format_str == '#')
			ptr_flags->alt_form = 1;
		else if (**format_str == ' ')
			ptr_flags->sign_space = 1;
		else if (**format_str == '+')
			ptr_flags->sign_plus = 1;
		(*format_str)++;
	}
	if (ft_isdigit(**format_str))
		ptr_flags->width = ft_atoi_end(format_str);
	if (**format_str == '.')
	{
		ptr_flags->precision = 0;
		(*format_str)++;
	}
	if (ft_isdigit(**format_str))
		ptr_flags->precision = ft_atoi_end(format_str);
}


// if specifier is invalid, print % until before specifier
// ex: % -2.2z -> print: % -2.2
// this function sets:
// ptr_flags->neg_num
// ptr_flags->conv_len
// ptr_features->conv

// ft_itoa_base takes num as int (32 bit), but uintptr_t is 64 bit, so it gets truncated
void	check_conv(const char *format_str, va_list args, struct s_flags *ptr_flags, struct s_features *ptr_features)
{
	int num;

	ptr_flags->spec = *format_str;
	if (ptr_flags->spec == 'c')
	{
		ptr_features->conv = ft_strdup(" ");
		ptr_features->conv[0] = (unsigned char)va_arg(args, int);
	}
	else if (ptr_flags->spec == 's')
		ptr_features->conv = ft_strdup(va_arg(args, char *));
	else if (ptr_flags->spec == 'p')
		ptr_features->conv = ft_itoa_base_64((uintptr_t)va_arg(args, void *), "0123456789abcdef", 0);
	else if (ptr_flags->spec == 'u')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789", 0);
	else if (ptr_flags->spec == 'x')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef", 0);
	else if (ptr_flags->spec == 'X')
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	else if (ptr_flags->spec == 'd' || ptr_flags->spec == 'i')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			ptr_flags->neg_num = 1;
			num = -num;
		}
		ptr_features->conv = ft_itoa_base(num, "0123456789", 0);
	}
	else if (ptr_flags->spec == '%')
		ptr_features->conv = ft_strdup("%");
	ptr_flags->conv_len = ft_strlen(ptr_features->conv);
}

void	print_s_flags(struct s_flags *ptr_flags);

void	flags_to_features(struct s_flags *ptr_flags, struct s_features *ptr_features)
{
	int fill_count;

	// *ptr_features = (struct s_features){.pad_char = ' ', .sign_char = "", .alt_form_prefix = "", };
	ptr_features->pad_char = ' '; // default
	if (ptr_flags->pad_zero && !ptr_flags->align_left && \
		ft_strchr("diuxX", ptr_flags->spec) && ptr_flags->precision == -1)
		ptr_features->pad_char = '0'; // override
	ptr_features->sign_char = "";
	if (ft_strchr("pdi", ptr_flags->spec))
	{
		if (ptr_flags->neg_num)
			ptr_features->sign_char = "-";
		else
		{
			if (ptr_flags->sign_space)
				ptr_features->sign_char = " ";
			if (ptr_flags->sign_plus)
				ptr_features->sign_char = "+";
		}
	}
	ptr_features->alt_form_prefix = "";
	if ((ptr_flags->alt_form && ptr_flags->spec == 'x') || ptr_flags->spec == 'p')
		ptr_features->alt_form_prefix = "0x";
	else if (ptr_flags->alt_form && ptr_flags->spec == 'X')
		ptr_features->alt_form_prefix = "0X";
	ptr_features->pad_left_count = 0;
	ptr_features->pad_right_count = 0;
	fill_count = ft_strlen(ptr_features->sign_char) + \
	ft_strlen(ptr_features->alt_form_prefix) + ft_max(ptr_flags->conv_len, ptr_flags->precision);
	if (ptr_flags->width > fill_count && ft_strchr("cspdiuxX", ptr_flags->spec))
	{
		if (ptr_flags->align_left)
			ptr_features->pad_right_count = ptr_flags->width - fill_count;
		else
			ptr_features->pad_left_count = ptr_flags->width - fill_count;
	}
	if (ptr_flags->precision > ptr_flags->conv_len && ft_strchr("pdiuxX", ptr_flags->spec))
		ptr_features->prec_pad_count = ptr_flags->precision - ptr_flags->conv_len;
}


void	print_features(struct s_features *ptr_features, int *ptr_bytes_written)
{
	unsigned int	count;
	
	if (ptr_features->pad_char == '0')
	{
		*ptr_bytes_written += ft_putstr_fd_b(ptr_features->sign_char, 1);
		*ptr_bytes_written += ft_putstr_fd_b(ptr_features->alt_form_prefix, 1);
	}
	count = 0;
	while (count < ptr_features->pad_left_count)
	{
		*ptr_bytes_written += ft_putchar_fd_b(ptr_features->pad_char, 1);		
		count++;
	}
	if (ptr_features->pad_char == ' ')
	{
		*ptr_bytes_written += ft_putstr_fd_b(ptr_features->sign_char, 1);
		*ptr_bytes_written += ft_putstr_fd_b(ptr_features->alt_form_prefix, 1);
	}
	count = 0;
	while (count < ptr_features->prec_pad_count)
	{
		*ptr_bytes_written += ft_putchar_fd_b('0', 1);
		count++;
	}
	*ptr_bytes_written += ft_putstr_fd_b(ptr_features->conv, 1);
	free(ptr_features->conv);
	count = 0;
	while (count < ptr_features->pad_right_count)
	{
		*ptr_bytes_written += ft_putchar_fd_b(ptr_features->pad_char, 1);		
		count++;
	}
}

void print_s_flags(struct s_flags *ptr_flags)
{
	printf("align_left:%d,\npad_zero:%d,\nalt_form:%d,\nsign_space:%d,\nsign_plus:%d,\nwidth:%d,\nprecision:%d,\nneg_num:%d,\nspec:%c,\n", ptr_flags->align_left, ptr_flags->pad_zero, ptr_flags->alt_form, ptr_flags->sign_space, ptr_flags->sign_plus, ptr_flags->width, ptr_flags->precision, ptr_flags->neg_num, ptr_flags->spec);
}

void print_s_features(struct s_features *ptr_features)
{
	printf("pad_char:%c,\npad_left_count:%u,\npad_right_count:%u,\nprec_pad_count:%u,\nsign_char:%s,\nalt_form_prefix:%s,\nconv:%s\n", ptr_features->pad_char, ptr_features->pad_left_count, ptr_features->pad_right_count, ptr_features->prec_pad_count, ptr_features->sign_char, ptr_features->alt_form_prefix, ptr_features->conv);
}

int ft_printf(const char *format_str, ...)
{
	va_list args;
	struct s_flags		flags;
	struct s_features	features;
	int 				bytes_written;

	bytes_written = 0;
	va_start(args, format_str);	
	while (*format_str != '\0')
	{
		if (*format_str == '%' && format_is_valid(format_str + 1))
		{
			format_str++;
			//printf("\n%s\n", format_str);
			check_flags_width(&format_str, &flags);
			/*printf("\nafter check flags width\n");
			print_s_flags(&flags);
			printf("here");
			printf("%s\n", format_str);*/

		
			check_conv(format_str, args, &flags, &features);
			format_str++;
			/*printf("\nafter check conv:\n");
			print_s_flags(&flags);
			printf("%s\n", features.conv);
			printf("%s\n", format_str);*/

			flags_to_features(&flags, &features);
			/*printf("\nafter flags to features:\n");
			print_s_flags(&flags);
			print_s_features(&features);
			printf("%s\n", format_str);*/

			//printf("\nfinal printf:\n\n");
			print_features(&features, &bytes_written);
			//printf("\n\n");
		}
		else
		{
			ft_putchar_fd(*format_str, 1);
			bytes_written++;
			format_str++;
		}
	}
	va_end(args);
	return (bytes_written);
}


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
}
