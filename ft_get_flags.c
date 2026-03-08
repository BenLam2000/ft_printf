/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:32:25 by belam             #+#    #+#             */
/*   Updated: 2026/03/08 23:33:35 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ptr passed is pointing at %-0d
//                            ^ 
// handles repeating valid flags and in any sequence, ex: "%00#-5d"
static void	handle_flags(const char **format_str, t_flags *p_flags)
{
	while (ft_strchr("-0# +", **format_str))
	{
		if (**format_str == '-')
			p_flags->align_left = 1;
		else if (**format_str == '0')
			p_flags->pad_zero = 1;
		else if (**format_str == '#')
			p_flags->alt_form = 1;
		else if (**format_str == ' ')
			p_flags->sign_space = 1;
		else if (**format_str == '+')
			p_flags->sign_plus = 1;
		(*format_str)++;
	}
}

// ft_atoi only returns int, but have to traverse manually after that, so integrate
// traversing into ft_atoi_end, modifying the char * directly
static void	handle_width(const char **format_str, t_flags *p_flags, va_list args)
{
	int	width;
	
	if (ft_isdigit(**format_str))
		p_flags->width = ft_atoi_end(format_str);
	else if (**format_str == '*')
	{	
		width = va_arg(args, int);
		if (width < 0)
		{
			width = -width;
			p_flags->align_left = 1;
		}
		p_flags->width = width;
		(*format_str)++;
	}
}

static void	handle_precision(const char **format_str, t_flags *p_flags, va_list args)
{	
	int	prec;

	if (**format_str == '.')
	{
		p_flags->exp_prec = 1;
		(*format_str)++;
		if (ft_isdigit(**format_str))
		{
			prec = ft_atoi_end(format_str);
			if (prec > 0)
				p_flags->precision = prec;
		}
		else if (**format_str == '*')
		{
			prec = va_arg(args, int);
			if (prec < 0)
				p_flags->exp_prec = 0;
			else
				p_flags->precision = prec;
			(*format_str)++;
		}
	}
	p_flags->spec = **format_str;
	if (ft_strchr("pdiuxX", p_flags->spec) && !p_flags->exp_prec)
		p_flags->precision = 1;
}

void	ft_get_flags(const char **format_str, t_flags *p_flags,
	t_features *p_features, va_list args)
{
	(*format_str)++;
	handle_flags(format_str, p_flags);
	handle_width(format_str, p_flags, args);
	handle_precision(format_str, p_flags, args);
	ft_handle_conv(args, p_flags, p_features);
	(*format_str)++;
}
