/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:41:25 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 16:42:13 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// man: memory areas must not overlap = assumes user input src and 
// dest do not overlap
// does not safely handle memory overlap
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_byte;
	unsigned char		*dest_byte;
	size_t				i;

	src_byte = (const unsigned char *) src;
	dest_byte = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		dest_byte[i] = src_byte[i];
		i++;
	}
	return (dest);
}
