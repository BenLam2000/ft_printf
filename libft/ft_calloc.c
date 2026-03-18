/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:32:29 by belam             #+#    #+#             */
/*   Updated: 2025/10/30 00:54:42 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: malloc, ft_bzero
// NOTE:
// allocate memory and set all bytes to 0
// if memory not allocated, don't set to 0 (cannot dereference NULL ptr),
// just return NULL ptr
// Edge cases:
// 1. nmemb or size is 0, return unique ptr that can be passed to free()
// 2. overflow past SIZE_MAX (max value of size_t)
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(1));
	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return ((void *)0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
