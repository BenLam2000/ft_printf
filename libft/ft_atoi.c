/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:31:33 by belam             #+#    #+#             */
/*   Updated: 2025/10/28 17:32:04 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

// dep: ft_isspace, ft_isdigit
// rules:
// 1. arbitrary amount of whitespace
// 2. single + or - sign
// 3. if no number found, return 0
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}
