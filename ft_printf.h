/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:19:32 by belam             #+#    #+#             */
/*   Updated: 2026/03/09 16:24:06 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h> // uintptr_t
# include <stdarg.h> // va_arg, va_start, va_end
# include "libft.h"
# define SPECS "cspdiuxX%"
# define RADIX_D "0123456789"
# define RADIX_X "0123456789abcdef"
# define RADIX_XX "0123456789ABCDEF"

// structs
typedef struct s_flags
{
	int	align_left;
	int	pad_zero;
	int	alt_form;
	int	sign_space;
	int	sign_plus;
	int	width;
	int	precision;
	int	exp_prec;
	int	neg_num;
	int	conv_len;
	int	spec;
	int	is_zero;
}	t_flags;

typedef struct s_features
{
	char			pad_char;
	unsigned int	pad_left_count;
	unsigned int	pad_right_count;
	unsigned int	prec_pad_count;
	char			*sign_char;
	char			*alt_form_prefix;
	char			*conv;
}	t_features;

// ft_printf and helper functions
int		ft_printf(const char *format_str, ...);
void	ft_get_flags(const char **format_str, t_flags *p_flags,
			t_features *p_features, va_list args);
void	ft_handle_conv(va_list args, t_flags *p_flags, t_features *p_features);
void	ft_flags_to_features(t_flags *p_flags, t_features *p_features);
void	ft_print_features(t_flags *p_flags, t_features *p_features,
			int *p_bytes);

// libft extra functions
char	*ft_itoa_base(int num, char *radix, int sign);
char	*ft_itoa_base_64(long num, char *radix, int sign);
ssize_t	ft_putstr_fd_b(char *s, int fd);
int		ft_atoi_end(const char **nptr);
int		ft_max(int num1, int num2);

#endif 
