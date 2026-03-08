/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:34:11 by belam             #+#    #+#             */
/*   Updated: 2026/03/08 23:35:00 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// NULL handled in here because ft_strdup(NULL) causes seg fault (accessing NULL ptr)
static void	handle_s_conv(t_flags *p_flags, t_features *p_features, va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	if (str == (char *)0)
	{
		if (p_flags->exp_prec && p_flags->precision < 6)
			p_features->conv = ft_strdup("");
		else
			p_features->conv = ft_strdup("(null)");
	}
	else
	{
		if (p_flags->exp_prec)
			p_features->conv = ft_substr(str, 0, p_flags->precision);
		else
			p_features->conv = ft_strdup(str);
	}
}

static void	handle_di_conv(t_flags *p_flags, t_features *p_features, va_list args)
{		
	int	num;
	
	num = va_arg(args, int);
	if (num < 0)
	{
		p_flags->neg_num = 1;
		num = -num;
	}
	p_features->conv = ft_itoa_base(num, RADIX_D, 0);
}

static void	handle_zero_conv(t_flags *p_flags, t_features *p_features)
{
	if (!ft_strncmp(p_features->conv, "0", 10))
	{
		p_flags->is_zero = 1;
		if (p_flags->spec == 'p')
		{
			free(p_features->conv);
			p_features->conv = ft_strdup("(nil)");
		}
		else if (ft_strchr("diuxX", p_flags->spec) && p_flags->precision == 0)
		{
			free(p_features->conv);
			p_features->conv = ft_strdup("");
		}
	}
}

static void	set_conv_len(t_flags *p_flags, t_features *p_features)
{
	if (ft_strchr("spdiuxX%", p_flags->spec))
		p_flags->conv_len = ft_strlen(p_features->conv);
	else if (p_flags->spec == 'c')
		p_flags->conv_len = 1;
}

// ft_itoa_base takes num as int (32 bit), but uintptr_t is 64 bit, so it gets truncated
void	ft_handle_conv(va_list args, t_flags *p_flags, t_features *p_features)
{
	if (p_flags->spec == 'c')
	{
		p_features->conv = ft_strdup(" ");
		p_features->conv[0] = (unsigned char)va_arg(args, int);
	}
	else if (p_flags->spec == 's')
		handle_s_conv(p_flags, p_features, args);
	else if (p_flags->spec == 'p')
		p_features->conv = ft_itoa_base_64((uintptr_t)va_arg(args, void *),
		RADIX_X, 0);
	else if (p_flags->spec == 'd' || p_flags->spec == 'i')
		handle_di_conv(p_flags, p_features, args);
	else if (p_flags->spec == 'u')
		p_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_D, 0);
	else if (p_flags->spec == 'x')
		p_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_X, 0);
	else if (p_flags->spec == 'X')
		p_features->conv = ft_itoa_base(va_arg(args, unsigned int), RADIX_XX, 0);
	else if (p_flags->spec == '%')
		p_features->conv = ft_strdup("%");
	handle_zero_conv(p_flags, p_features);
	set_conv_len(p_flags, p_features);
}
