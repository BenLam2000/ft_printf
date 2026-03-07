/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:19:32 by belam             #+#    #+#             */
/*   Updated: 2026/03/07 19:28:50 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

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
	int	exp_prec;
	int	neg_num;
	int conv_len;
	int	spec;
	int is_zero;
	//int	invalid_spec;
};

int	ft_printf(const char *, ...);

// libft extra functions
char	*ft_itoa_base(int num, char *radix, int sign);
char	*ft_itoa_base_64(long num, char *radix, int sign);
ssize_t	ft_putchar_fd_b(char c, int fd);
ssize_t	ft_putstr_fd_b(char *s, int fd);
int		ft_atoi_end(const char **nptr);
int		ft_max(int num1, int num2);

#endif 
