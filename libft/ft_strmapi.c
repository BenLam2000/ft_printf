/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:42:56 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:43:14 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dep: malloc, ft_strlen
// f(index, char at this index)
// function call can be used (*f)(i, s[i]) OR f(i, s[i])
// the name of the function acts as a pointer to the first line 
// of the function instruction
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_mapped;

	str_mapped = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str_mapped)
		return ((char *)0);
	i = 0;
	while (s[i] != '\0')
	{
		str_mapped[i] = f(i, s[i]);
		i++;
	}
	str_mapped[i] = '\0';
	return (str_mapped);
}
