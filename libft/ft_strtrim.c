/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:37:03 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:39:12 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// detects occurence of character in a string
static int	ft_cins(int c, const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

// searches string s1 for index of next occurence where char 
// is not in string set
// starting from start, with the option to set forward searching 
// direction as true or false
static int	ft_next_i_not_in_set(const char *s1, const char *set,\
	unsigned int start, int forward)
{
	unsigned int	i;

	i = start;
	while (ft_cins(s1[i], set))
	{
		if (forward)
			i++;
		else
			i--;
	}
	return (i);
}

// NOTE:
// return value is NULL ONLY when allocation fails
// assume user will not put '\0' in set
// check for any character in set, not exactly in the exact order or count
// need to consider possibility of '\0' in set?
// Edge cases:
// 1. when whole string s1 consists of char from set, return empty string
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	strtrim_start;
	unsigned int	strtrim_end;

	strtrim_start = ft_next_i_not_in_set(s1, set, 0, 1);
	if (s1[strtrim_start] == '\0')
		return ((char *)ft_memset(malloc(1), '\0', 1));
	strtrim_end = ft_next_i_not_in_set(s1, set, ft_strlen(s1) - 1, 0);
	return (ft_substr(s1, strtrim_start, (strtrim_end - strtrim_start + 1)));
}
