/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:19:32 by belam             #+#    #+#             */
/*   Updated: 2026/02/12 19:01:53 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#  define FT_PRINTF_H

struct s_features
{
	char			pad_char;
	unsigned int	pad_left_count;
	unsigned int	pad_right_count;
	char			*sign_char;
	char			*conv;
};

struct s_flags
{
	int	align_left;
	int	pad_zero;
	int	sign_space;
	int	sign_plus;
	int	width;
	int	neg_num;
	int conv_len;
};

# endif 
