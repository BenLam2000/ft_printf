/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:25:33 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:26:23 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// edge cases:
// 1. no characters are compared (n = 0)
// 2. len(s1) > len(s2), s2 reaches '\0' first
// 3. len(s2) > len(s1), s1 reaches '\0' first
// while loop stops at n-2 because the final line will check n-1 (last char)
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s1_u = (unsigned const char *) s1;
	unsigned const char	*s2_u = (unsigned const char *) s2;

	if (n == 0)
		return (0);
	i = 0;
	while (s1_u[i] != '\0' && s2_u[i] != '\0' && i < n - 1)
	{
		if (s1_u[i] != s2_u[i])
			return (s1_u[i] - s2_u[i]);
		i++;
	}
	return (s1_u[i] - s2_u[i]);
}
