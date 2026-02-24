/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/02/24 01:33:38 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "./libft/libft.h"
#include "ft_printf.h"


// free conv
// what happens if type provided is not same as specifier?



// ptr passed is pointing at %-0d
//                            ^ 
// need to take note which flags are mutually exclusive (won't appear tgt side by side)
// TODO: # flag
// - : for any conversion
// 0 : only numbers
// + and ' ': only signed numbers
const char *check_flags_width(const char *format_str, struct s_flags *ptr_flags)
{
	while (ft_strchr("-0# +", *format_str))
	{
		if (*format_str == '-')
			ptr_flags->align_left = 1;
		else if (*format_str == '0' && ft_strchr("pdiuxX", ptr_flags->spec))
			ptr_flags->pad_zero = 1;
		else if (*format_str == '#' && ft_strchr("xX", ptr_flags->spec))
			ptr_flags->alt_form = 1;
		else if (*format_str == ' ' && ft_strchr("pdi", ptr_flags->spec))
			ptr_flags->sign_space = 1;
		else if (*format_str == '+' && ft_strchr("pdi", ptr_flags->spec))
			ptr_flags->sign_plus = 1;
		format_str++;
	}
	ptr_flags->width = ft_atoi(format_str);
	if (ptr_flags->width > 0)
	{
		while (ft_isdigit(*format_str))
			format_str++;
	}
	return(format_str);
}


// if specifier is invalid, print % until before specifier
// ex: % -2.2z -> print: % -2.2
// this function sets:
// ptr_flags->neg_num
// ptr_flags->conv_len
// ptr_features->conv

// ft_itoa_base takes num as int (32 bit), but uintptr_t is 64 bit, so it gets truncated
const char *check_conv(const char *format_str, va_list args, struct s_flags *ptr_flags, struct s_features *ptr_features)
{
	int valid_flag_width;
	int	i;
	i = 0;
	
	valid_flag_width = ft_strchr("-0# +", format_str[i]) || ft_isdigit(format_str[i]);
	while (valid_flag_width && format_str[i] != '\0')
	{
		i++;
		valid_flag_width = ft_strchr("-0# +", format_str[i]) || ft_isdigit(format_str[i]);
	}
	if (format_str[i] == '\0' || !valid_flag_width || !ft_strchr("cspdiuxX%", format_str[i]))
	{
		ptr_flags->invalid_spec = 1;
		return (format_str + i + 1);
	}
	ptr_flags->spec = (int)format_str[i];
	ptr_flags->invalid_spec = 0;
	if (ptr_flags->spec == 'c')
	{
		ptr_features->conv = ft_strdup(" ");
		ptr_features->conv[0] = (unsigned char)va_arg(args, int);
		ptr_flags->conv_len = 1;
	}
	else if (ptr_flags->spec == 's')
	{
		ptr_features->conv = ft_strdup(va_arg(args, char *));
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	else if (ptr_flags->spec == 'p')
	{
		ptr_flags->alt_form = 1;
		ptr_features->conv = ft_itoa_base_64((uintptr_t)va_arg(args, void *), "0123456789abcdef", 0);
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	else if (ptr_flags->spec == 'u')
	{
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789", 0);
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	
	else if (ptr_flags->spec == 'x')
	{
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef", 0);
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	else if (ptr_flags->spec == 'X')
	{
		ptr_features->conv = ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	else if (ptr_flags->spec == 'd' || ptr_flags->spec == 'i')
	{
		int	num;
		num = va_arg(args, int);
		if (num < 0)
		{
			ptr_flags->neg_num = 1;
			num = -num;
		}
		ptr_features->conv = ft_itoa_base(num, "0123456789", 0);
		ptr_flags->conv_len = ft_strlen(ptr_features->conv);
	}
	return (format_str + i + 1);
}

void flags_to_features(struct s_flags *ptr_flags, struct s_features *ptr_features)
{
	ptr_features->pad_char = ' '; // default
	if (ptr_flags->pad_zero && !ptr_flags->align_left)
		ptr_features->pad_char = '0'; // override

	ptr_features->sign_char = "";
	if (ptr_flags->neg_num)
		ptr_features->sign_char = "-";
	else
	{
		if (ptr_flags->sign_space)
			ptr_features->sign_char = " ";
		if (ptr_flags->sign_plus)
			ptr_features->sign_char = "+";
	}
	
	ptr_features->alt_form_prefix = "";
	if (ptr_flags->alt_form)
	{
		if (ptr_flags->spec == 'x' || ptr_flags->spec == 'p')
			ptr_features->alt_form_prefix = "0x";
		else if (ptr_flags->spec == 'X')
			ptr_features->alt_form_prefix = "0X";
	}

	ptr_features->pad_left_count = 0;
	ptr_features->pad_right_count = 0;
	if ((size_t)ptr_flags->width > ptr_flags->conv_len + ft_strlen(ptr_features->sign_char) + ft_strlen(ptr_features->alt_form_prefix))
	{
		int pad_count = ptr_flags->width - ptr_flags->conv_len - ft_strlen(ptr_features->sign_char) - ft_strlen(ptr_features->alt_form_prefix);
		if (ptr_flags->align_left)
			ptr_features->pad_right_count = pad_count;
		else
			ptr_features->pad_left_count = pad_count;
	}
}


void print_features(struct s_features *ptr_features)
{
	if (ptr_features->pad_char == '0')
	{
		ft_putstr_fd(ptr_features->sign_char, 1);	
		ft_putstr_fd(ptr_features->alt_form_prefix, 1);
	}
	if (ptr_features->pad_left_count > 0)
	{
		unsigned int	pad_count;
		pad_count = 0;
		while (pad_count < ptr_features->pad_left_count)
		{
			ft_putchar_fd(ptr_features->pad_char, 1);		
			pad_count++;
		}
	}
	if (ptr_features->pad_char == ' ')
	{
		ft_putstr_fd(ptr_features->sign_char, 1);
		ft_putstr_fd(ptr_features->alt_form_prefix, 1);
	}
	ft_putstr_fd(ptr_features->conv, 1);
	free(ptr_features->conv);
	if (ptr_features->pad_right_count > 0)
	{
		unsigned int pad_count;
		pad_count = 0;
		while (pad_count < ptr_features->pad_right_count)
		{
			ft_putchar_fd(ptr_features->pad_char, 1);		
			pad_count++;
		}
	}
}

void print_s_flags(struct s_flags *ptr_flags)
{
	printf("align_left:%d,\npad_zero:%d,\nalt_form:%d,\nsign_space:%d,\nsign_plus:%d,\nwidth:%d,\nneg_num:%d,\nconv_len:%d,\nspec:%c,\ninvalid_spec:%d\n", ptr_flags->align_left, ptr_flags->pad_zero, ptr_flags->alt_form, ptr_flags->sign_space, ptr_flags->sign_plus, ptr_flags->width, ptr_flags->neg_num, ptr_flags->conv_len, ptr_flags->spec, ptr_flags->invalid_spec);
}

void print_s_features(struct s_features *ptr_features)
{
	printf("pad_char:%c,\npad_left_count:%u,\npad_right_count:%u,\nsign_char:%s,\nalt_form_prefix:%s,\nconv:%s\n", ptr_features->pad_char, ptr_features->pad_left_count, ptr_features->pad_right_count, ptr_features->sign_char, ptr_features->alt_form_prefix, ptr_features->conv);
}

void	ft_printf(const char *format_str, ...)
{
	va_list args;
	va_start(args, format_str);
	
	struct s_flags		flags;
	struct s_features	features;
	const char	*format_str_next;

	while (*format_str != '\0')
	{
		if (*format_str == '%')
		{
			//format_str++;
			flags = (struct s_flags){0};
			format_str_next = check_conv(format_str + 1, args, &flags, &features);
			/*printf("after check conv:\n");
			print_s_flags(&flags);
			printf("%s\n", features.conv);
			printf("%s\n", format_str);*/
			
			if (!flags.invalid_spec)
			{
				check_flags_width(format_str + 1, &flags);
				/*printf("after check flags width\n");
				print_s_flags(&flags);
				printf("%s\n", format_str);*/

				flags_to_features(&flags, &features);
				/*printf("after flags to features:\n");
				print_s_flags(&flags);
				print_s_features(&features);
				printf("%s\n", format_str);*/

				//printf("final printf:\n\n");
				print_features(&features);
				//printf("\n\n");
			
				format_str = format_str_next;
			}
			else
			{
				ft_putchar_fd('%', 1);
				format_str++;
			}
		}
		else
		{
			ft_putchar_fd(*format_str, 1);
			format_str++;
		}
	}

	va_end(args);
}


// for o,x,X: regardless of which base is set as input 0x, 0b, 0, decimal, compiler will autotranslate and stores as binary in RAM
// cases: %z (invalid specifier)
int	main(int argc, char *argv[])
{
	//struct s_features features = {.pad_char = ' ', .pad_left_count = 0, .pad_right_count = 3, .sign_char = "", .width = -5};
	//print_features(&features, conv);
	if (argc > 1)
	{
		//check_flags_width(argv[1], &flags); //"-06d##"
		//printf("\n%d", atoi("   -00345"));
		//printf("%s",ft_strtrim("12345", "-"));
		int a = 2;
		//printf(format_str, arg);
		if (argv[3][0] == 'c')
			ft_printf(argv[1], argv[2][0]);
		else if (argv[3][0] == 's')
			ft_printf(argv[1], argv[2]);
		else if (argv[3][0] == 'p')
			ft_printf(argv[1], (void *)&a);
		else if (argv[3][0] == 'x' || argv[3][0] == 'X')
			ft_printf(argv[1], atoi(argv[2]));
		else if (argv[3][0] == 'd' || argv[3][0] == 'i' || argv[3][0] == 'u')
			ft_printf(argv[1], atoi(argv[2]));
	}
	return (0);
}
