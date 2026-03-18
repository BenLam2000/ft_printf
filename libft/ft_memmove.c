/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:42:35 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 18:27:23 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memset_seq(int start, int end, unsigned char *dest_byte,\
	const unsigned char *src_byte)
{
	int	i;

	i = start;
	if (start > end)
	{
		while (i >= end)
		{
			dest_byte[i] = src_byte[i];
			i--;
		}
	}
	else
	{
		while (i <= end)
		{
			dest_byte[i] = src_byte[i];
			i++;
		}
	}
}

// if n = 0, just return dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_byte;
	unsigned char		*dest_byte;

	src_byte = (const unsigned char *) src;
	dest_byte = (unsigned char *) dest;
	if (n == 0)
		return (dest);
	if (dest_byte == src_byte)
		return (dest);
	else if (src_byte < dest_byte && src_byte + (n - 1) >= dest_byte)
		ft_memset_seq((int)n - 1, 0, dest_byte, src_byte);
	else
		ft_memset_seq(0, (int)n - 1, dest_byte, src_byte);
	return (dest);
}
