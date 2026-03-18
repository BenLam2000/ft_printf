/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:23:46 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:24:48 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr_last_occ;
	int			char_found;

	char_found = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			ptr_last_occ = (char *)(s + i);
			char_found = 1;
		}
		i++;
	}
	if (char_found)
		return ((char *)ptr_last_occ);
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return ((char *)0);
}
