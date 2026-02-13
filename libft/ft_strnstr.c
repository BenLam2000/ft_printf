/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:29:37 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:31:01 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: ft_strlen
// NOTE:
// 1. len is the max char searched in big, not little
// 2. when checking little, once i+j exceeds len, no point checking further
// edge cases:
// 1. little is empty string -> return BIG
// 2. len = 0 -> handled at last line
// 3. impossible to find: len(little) > len(big) OR len -> return NULL
// 4. len < strlen(big) and little appears at end, ex: ("hello", "llo", 3)
//    last condition in inner loop for little makes sure doesn't exceed len 
// len(little) == 0 takes precedence over len == 0
// DOUBT:
// does it search '\0' also?
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(little) > ft_strlen(big) || ft_strlen(little) > len)
		return ((char *)0);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && (i + j) < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		if ((i + j) >= len)
			return ((char *)0);
		i++;
	}
	return ((char *)0);
}
