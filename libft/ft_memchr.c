/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:26:59 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:27:40 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// edge cases:
// 1. search 0 bytes (n==0) --> return NULL, handled in last line
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_byte;
	size_t			i;

	s_byte = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_byte[i] == (unsigned char) c)
			return ((void *)(s_byte + i));
		i++;
	}
	return ((void *)0);
}
