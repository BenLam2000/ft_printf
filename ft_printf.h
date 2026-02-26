/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:19:32 by belam             #+#    #+#             */
/*   Updated: 2026/02/25 20:41:35 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#  define FT_PRINTF_H

struct s_features
{
	char			pad_char;
	unsigned int	pad_left_count;
	unsigned int	pad_right_count;
	unsigned int	prec_pad_count;
	char			*sign_char;
	char			*alt_form_prefix;
	char			*conv;
};

struct s_flags
{
	int	align_left;
	int	pad_zero;
	int alt_form;
	int	sign_space;
	int	sign_plus;
	int	width;
	int precision;
	int	neg_num;
	int conv_len;
	int	spec;
	//int	invalid_spec;
};

# endif 
