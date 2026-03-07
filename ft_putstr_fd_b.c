/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:45:16 by belam             #+#    #+#             */
/*   Updated: 2026/03/07 23:19:01 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// same as ft_putstr_fd, with additional return bytes printed from write
ssize_t	ft_putstr_fd_b(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
