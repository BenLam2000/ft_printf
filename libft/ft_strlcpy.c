/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:16:08 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:16:51 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: ft_strlen
// size = full size of dst buffer
// edge cases: 
// 1. dst is empty, no space for even '\0' -> don't modify dst at all
// 2. dst only has 1 free byte -> skip while loop and just fill dst with '\0'
// 3. size of dst > src -> copies src normally, 
// dst will have unfilled bytes at end
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
