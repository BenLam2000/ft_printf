/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:47:28 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:47:32 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: ft_putchar_fd
// test cases:
// n = 0 -> auto taken care
// n = INT_MIN, when flip will overflow, hence convert to long
void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;
	long	div;
	long	rem;

	if (n < 0)
		ft_putchar_fd('-', fd);
	n_long = (long)n;
	if (n_long < 0)
		n_long = -n_long;
	div = n_long / 10;
	if (div > 0)
		ft_putnbr_fd((int)div, fd);
	rem = n_long % 10;
	ft_putchar_fd('0' + (unsigned char)rem, fd);
}
