/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/02/12 22:01:27 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "ft_printf.h"



void check_conv(const char *format_str, va_list args, struct s_flags *ptr_flags)
{	
	if (*format_str == 'c')
	{
		ptr_features->conv = (unsigned char)va_arg(args, int);
		format_str++;
	}
	else if (*format_str == 's')
	{
		ptr_features->conv = ft_strdup(va_arg(args, char *));
		format_str++;
	}
	else if (*format_str == 'd')
	{
		int	num = va_arg(args, int);
		if (num < 0)
			ptr_flags->neg_num = 1;
		char	*conv1 = ft_itoa(num);
		char	*conv2 = ft_strtrim(conv1, "-"); // if use nested functions, cannot free conv1
		ptr_features->conv = conv2;
		ptr_flags->conv_len = ft_strlen(conv2);
		free(conv1);
		//free(conv2); //otherwise cannot be used in print features
			
		format_str++;
	}
}



// ptr passed is pointing at %-0d
//                            ^
// need to take note which flags are mutually exclusive (won't appear tgt side by side)
const char *check_flags_width(const char *format_str, struct s_flags *ptr_flags)
{
	*ptr_flags = (struct s_flags){0};
	while (ft_strchr("-0 +", *format_str))
	{
		if (*format_str == '-')
			ptr_flags->align_left = 1;
		else if (*format_str == '0')
			ptr_flags->pad_zero = 1;
		else if (*format_str == ' ')
			ptr_flags->sign_space = 1;
		else if (*format_str == '+')
			ptr_flags->sign_plus = 1;
		format_str++;
	}

	ptr_flags->width = ft_atoi(format_str);
	if (ptr_flags->width > 0)
	{
		while (ft_isdigit(*format_str))
			format_str++;
	}

	printf("%d, %d, %d, %d, %d\n", ptr_flags->align_left, ptr_flags->pad_zero, ptr_flags->sign_space, ptr_flags->sign_plus, ptr_flags->width);
	
	return(format_str);
}


void flags_to_features(struct s_flags *ptr_flags, char *conv, struct s_features *ptr_features)
{
	ptr_features->pad_char = ' '; // default
	if (ptr_flags->pad_zero)
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

	ptr_flags->conv_len = ft_strlen(conv);
}


void print_features(struct s_features *ptr_features, char *conv)
{
	if (ptr_features->pad_left_count > 0)
	{
		unsigned int pad_count = 0;
		while (pad_count < ptr_features->pad_left_count)
		{
			ft_putchar_fd(ptr_features->pad_char, 1);		
			pad_count++;
		}
	}

	ft_putstr_fd(ptr_features->sign_char, 1);

	ft_putstr_fd(conv, 1);

	if (ptr_features->pad_right_count > 0)
	{
		unsigned int pad_count = 0;
		while (pad_count < ptr_features->pad_right_count)
		{
			ft_putchar_fd(ptr_features->pad_char, 1);		
			pad_count++;
		}
	}
}

void	ft_printf(const char *format_str, ...)
{
	va_list args;
	va_start(args, format_str);
	
	struct s_flags		flags;
	//struct s_features	features;
	
	while (*format_str != '\0')
	{
		if (*format_str == '%')
		{
			format_str++;
			format_str = check_flags_width(format_str, &flags);
			printf("%s\n", format_str);
			check_conv(format_str, args, &flags);
			//flags_to_features(&flags, conv, &features);
			//print_features();
		}
		else
		{
			ft_putchar_fd(*format_str, 1);
			format_str++;
		}
	}

	va_end(args);
}

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

		//printf(format_str, arg);
		ft_printf(argv[1], argv[2]);
	}
	return (0);
}
