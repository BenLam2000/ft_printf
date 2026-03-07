/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:31:33 by belam             #+#    #+#             */
/*   Updated: 2026/02/25 21:10:01 by belam            ###   ########.fr       */
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
int	ft_atoi_end(const char **nptr)
{
	int	sign;
	int	num;

	while (ft_isspace(**nptr))
	{
		(*nptr)++;
	}
	sign = 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -sign;
		(*nptr)++;
	}
	num = 0;
	while (ft_isdigit(**nptr))
	{
		num = num * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (sign * num);
}
