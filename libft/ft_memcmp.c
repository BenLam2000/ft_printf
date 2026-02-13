/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:28:22 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:28:57 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// does it matter value of int? or just > / < enough?
// edge cases:
// 1. compare 0 bytes -> return 0. handled in last line
// notes:
// any arithmetic operation in c, int promotion automatically occurs
// unsigned char is promoted to int
// result is unsigned only if you explicitly cast the result
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_byte;
	unsigned char	*s2_byte;
	size_t			i;

	s1_byte = (unsigned char *)s1;
	s2_byte = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_byte[i] != s2_byte[i])
			return (s1_byte[i] - s2_byte[i]);
		i++;
	}
	return (0);
}
