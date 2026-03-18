/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:56:55 by belam             #+#    #+#             */
/*   Updated: 2026/03/18 20:53:39 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
