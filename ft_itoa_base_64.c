/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:11:11 by belam             #+#    #+#             */
/*   Updated: 2026/03/09 16:09:32 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// num_len - number count, not including '-'
// num_len will always reach back to 0 at the end
char	*ft_itoa_base_64(long num, char *radix, int sign)
{
	static int	neg_num;
	static int	num_len = 0;
	static int	num_len_max;
	static char	*conv;

	if (num_len == 0)
		neg_num = num < 0 && sign;
	if (num < 0 && sign)
		num = -num;
	num_len++;
	if ((unsigned long)num / ft_strlen(radix) > 0)
		ft_itoa_base_64((unsigned long)num / ft_strlen(radix), radix, sign);
	else
	{
		num_len_max = num_len;
		conv = (char *)malloc((neg_num + num_len_max + 1) * sizeof(char));
		if (!conv)
			return ((char *)0);
		conv[neg_num + num_len_max] = '\0';
		if (neg_num)
			conv[0] = '-';
	}
	conv[neg_num + num_len_max - num_len--] = radix[(unsigned long)num
		% ft_strlen(radix)];
	return (conv);
}
