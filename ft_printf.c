/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/03/09 16:14:43 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO:
// refactor to meet norm
// input type is not same as specifier
// number of arguments not matching format string
// restructure folder to have src, incl, obj...
// README
// .gitignore all unused files for submission + 
//  make a standard reusable .gitignore template

// future: variadic function that can be reusable to build things like atoi
//  and format_is_valid, for any number of sets of characters,
//  each with a set count or unlimited/optional

// DONE:
// check for correct format before conversion to prevent segmentation fault
// handle invalid specifiers/flags
// flags in any order or combination
// return value
// ft_atoi_end
// . flag
// makefile
// tester file
// check for NULL input or ""
// change structs to typedefs
// move ft_itoa_base and 64 into root dir, remove declaration from 
//  libft/libft.h & libft/Makefile and add to ft_printf.h and Makefile
// replace const strings with macros (radix)
// readd NULL malloc checking in ft_itoa_base and 64

/////////////////////////////////////

// '/0' incl. in strchr check, so ft_strchr(any string, '\0') == true
static int	format_is_valid(const char *format_str)
{
	while (ft_strchr("-0# +", *format_str) && *format_str)
		format_str++;
	if (ft_isdigit(*format_str))
	{
		while (ft_isdigit(*format_str))
			format_str++;
	}
	else if (*format_str == '*')
		format_str++;
	if (*format_str == '.')
	{
		format_str++;
		if (ft_isdigit(*format_str))
		{
			while (ft_isdigit(*format_str))
				format_str++;
		}
		else if (*format_str == '*')
			format_str++;
	}
	if (ft_strchr(SPECS, *format_str) && *format_str)
		return (1);
	return (0);
}

static void	set_defaults(t_flags *p_flags, t_features *p_features)
{
	*p_flags = (t_flags){0};
	*p_features = (t_features){
		.pad_char = ' ',
		.pad_left_count = 0,
		.pad_right_count = 0,
		.prec_pad_count = 0,
		.sign_char = "",
		.alt_form_prefix = "",
		.conv = ""
	};
}

int	ft_printf(const char *format_str, ...)
{
	va_list		args;
	int			bytes_written;
	t_flags		flags;
	t_features	features;

	va_start(args, format_str);
	bytes_written = 0;
	while (*format_str)
	{
		if (*format_str == '%' && format_is_valid(format_str + 1))
		{
			set_defaults(&flags, &features);
			ft_get_flags(&format_str, &flags, &features, args);
			ft_flags_to_features(&flags, &features);
			ft_print_features(&flags, &features, &bytes_written);
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
