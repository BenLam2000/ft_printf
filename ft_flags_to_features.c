/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_to_features.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:35:35 by belam             #+#    #+#             */
/*   Updated: 2026/03/09 00:17:12 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_padchar_sign(t_flags *p_flags, t_features *p_features)
{
	if (p_flags->pad_zero && !p_flags->align_left
		&& (ft_strchr("diuxX", p_flags->spec) || (p_flags->spec == 'p'
				&& !p_flags->is_zero)) && !p_flags->exp_prec)
		p_features->pad_char = '0';
	if (ft_strchr("di", p_flags->spec) || (p_flags->spec == 'p'
			&& ft_strncmp(p_features->conv, "(nil)", 20)))
	{
		if (p_flags->neg_num)
			p_features->sign_char = "-";
		else
		{
			if (p_flags->sign_space)
				p_features->sign_char = " ";
			if (p_flags->sign_plus)
				p_features->sign_char = "+";
		}
	}
}

static void	handle_alt(t_flags *p_flags, t_features *p_features)
{
	if ((p_flags->alt_form && p_flags->spec == 'x' && !p_flags->is_zero)
		|| (p_flags->spec == 'p' && !p_flags->is_zero))
		p_features->alt_form_prefix = "0x";
	else if (p_flags->alt_form && p_flags->spec == 'X' && !p_flags->is_zero)
		p_features->alt_form_prefix = "0X";
}

static void	handle_padding(t_flags *p_flags, t_features *p_features)
{
	int	fill_count;

	fill_count = ft_strlen(p_features->sign_char)
		+ ft_strlen(p_features->alt_form_prefix)
		+ ft_max(p_flags->conv_len, p_flags->precision);
	if (p_flags->width > fill_count && ft_strchr("cspdiuxX", p_flags->spec))
	{
		if (p_flags->align_left)
			p_features->pad_right_count = p_flags->width - fill_count;
		else
			p_features->pad_left_count = p_flags->width - fill_count;
	}
}

static void	handle_prec(t_flags *p_flags, t_features *p_features)
{
	if (p_flags->precision > p_flags->conv_len
		&& (ft_strchr("diuxX", p_flags->spec)
			|| (p_flags->spec == 'p' && !p_flags->is_zero)))
		p_features->prec_pad_count = p_flags->precision - p_flags->conv_len;
}

void	ft_flags_to_features(t_flags *p_flags, t_features *p_features)
{
	handle_padchar_sign(p_flags, p_features);
	handle_alt(p_flags, p_features);
	handle_padding(p_flags, p_features);
	handle_prec(p_flags, p_features);
}
