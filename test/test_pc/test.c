/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:32:07 by belam             #+#    #+#             */
/*   Updated: 2026/03/05 04:21:19 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

static void ft_iter_int(const char *format_str, int d, int option)
{
	if (option == 1)
		printf("\treturn: %d", printf(format_str, d));
	else if (option == 2)
		printf("\treturn: %d", ft_printf(format_str, d));
	else if (option == 3)
		printf("\"%s\"", format_str);
	else if (option == 4)
	{
	        printf("\b\b"); // to remove , from error message
	}
}

int	main(int argc, char *argv[])
{
	int test;
	int fn;

	if (argc == 1)
	{
	        printf("%d", 5); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	if (test == 1)
		ft_iter_int("|%%|", 0, fn);
	else if (test == 2)
		ft_iter_int("|%-7%|", 0, fn);
	else if (test == 3)
		ft_iter_int("|% +#07%|", 0, fn);
	else if (test == 4)
		ft_iter_int("|%.3%|", 0, fn);
	if (test == 5)
	{
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%%hi%%|"));
                if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%%hi%%|"));
        }
	
	return (0);
}
