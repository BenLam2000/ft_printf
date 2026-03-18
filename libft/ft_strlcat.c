/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:17:10 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:17:47 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: ft_strlen
// assumes user to ensure dst and src are null-terminated
// size = size of dst buffer
// edge cases:
// 1. dst has no free bytes after original string -> don't modify dst at all
// 2. size of dst > length of dst + src + 1 -> 
// dst will have unfilled bytes at end
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_ori_len;

	dest_ori_len = ft_strlen(dst);
	if (size < dest_ori_len + 1)
		return (size + ft_strlen(src));
	else if (size == dest_ori_len + 1)
		return (dest_ori_len + ft_strlen(src));
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_ori_len + ft_strlen(src));
}
