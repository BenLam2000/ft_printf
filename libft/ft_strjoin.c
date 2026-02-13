/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:35:53 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:36:23 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NOTE:
// i traverses whole joined string, but need to minus s1_len to index s2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	int		i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str_joined = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!str_joined)
		return ((char *)0);
	i = 0;
	while (s1[i] != '\0')
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len] != '\0')
	{
		str_joined[i] = s2[i - s1_len];
		i++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}
