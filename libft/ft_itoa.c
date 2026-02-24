/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:42:07 by belam             #+#    #+#             */
/*   Updated: 2026/02/17 20:04:35 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: malloc
static void	ft_itoa_malloc(int n, char **a_ptr, int *num_len_ptr, int *sign_ptr)
{
	long	div;	

	*num_len_ptr = 0;
	*sign_ptr = 1;
	if (n < 0)
	{
		*sign_ptr = -1;
		(*num_len_ptr)++;
	}
	div = (*sign_ptr) * (long)n;
	while (div > 0)
	{
		div = div / 10;
		(*num_len_ptr)++;
	}
	*a_ptr = (char *)malloc((*num_len_ptr) * sizeof(char) + 1);
}

static void	ft_itoa_seta(int n, char **a_ptr, int *num_len_ptr, int *sign_ptr)
{
	long	div;

	(*a_ptr)[*num_len_ptr] = '\0';
	(*num_len_ptr)--;
	div = (*sign_ptr) * (long)n;
	while (div > 0)
	{
		(*a_ptr)[(*num_len_ptr)] = '0' + div % 10;
		div = div / 10;
		(*num_len_ptr)--;
	}
	if (*sign_ptr == -1)
		(*a_ptr)[*num_len_ptr] = '-';
}

// dep malloc, ft_itoa_malloc, ft_itoa_seta
// TEST CASES:
// 1. n = INT_MIN -> if flipped to positive, will overflow, 
// so conv to long first
// 2. n = 0 -> 
// NOTE:
char	*ft_itoa(int n)
{
	char	*a;
	int		num_len;
	int		sign;

	if (n == 0)
	{
		a = (char *)malloc(2);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	ft_itoa_malloc(n, &a, &num_len, &sign);
	if (!(a))
		return ((char *)0);
	ft_itoa_seta(n, &a, &num_len, &sign);
	return (a);
}
