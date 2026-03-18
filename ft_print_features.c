/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_features.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:38:21 by belam             #+#    #+#             */
/*   Updated: 2026/03/18 20:00:08 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pad(unsigned int pad_count, char pad_char, int *p_bytes)
{
	unsigned int	count;

	count = 0;
	while (count < pad_count)
	{
		ft_putchar_fd(pad_char, 1);
		count++;
	}
	*p_bytes += pad_count;
}

static void	print_sign_alt(t_features *p_features, char pad_char, int *p_bytes)
{
	if (p_features->pad_char == pad_char)
	{
		*p_bytes += ft_putstr_fd_b(p_features->sign_char, 1);
		*p_bytes += ft_putstr_fd_b(p_features->alt_form_prefix, 1);
	}
}

static void	print_prec_pad(unsigned int pad_count, int *p_bytes)
{
	print_pad(pad_count, '0', p_bytes);
}

static void	print_conv(t_flags *p_flags, t_features *p_features, int *p_bytes)
{
	if (p_flags->spec == 'c')
		ft_putchar_fd(p_features->conv[0], 1);
	else
		ft_putstr_fd(p_features->conv, 1);
	*p_bytes += p_flags->conv_len;
	free(p_features->conv);
}

void	ft_print_features(t_flags *p_flags, t_features *p_features,
	int *p_bytes)
{
	print_sign_alt(p_features, '0', p_bytes);
	print_pad(p_features->pad_left_count, p_features->pad_char, p_bytes);
	print_sign_alt(p_features, ' ', p_bytes);
	print_prec_pad(p_features->prec_pad_count, p_bytes);
	print_conv(p_flags, p_features, p_bytes);
	print_pad(p_features->pad_right_count, p_features->pad_char, p_bytes);
}
