/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:34:21 by belam             #+#    #+#             */
/*   Updated: 2025/10/30 01:03:56 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: ft_strlen, malloc
// NOTES:
// len is max length of substring
// test cases:
// len = 0 -> handled in while condition
// start after strlen(s)
// substr is shorter than max len, don't waste memory, 
// only allocate amount required
// memory not allocated
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	int		end;
	int		i;

	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len - 1 >= ft_strlen(s))
		substr_len = ft_strlen(s) - start;
	else
		substr_len = len;
	substr = (char *)malloc(substr_len * sizeof(char) + 1);
	if (!substr)
		return ((char *)0);
	i = start;
	end = (int)start + (int)substr_len - 1;
	while (i <= end && len > 0)
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[i - start] = '\0';
	return (substr);
}
