/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
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

static void ft_iter_int(const char *format_str, long d, int option)
{
	if (option == 1)
		printf("\treturn: %d", printf(format_str, d));
	else if (option == 2)
		printf("\treturn: %d", ft_printf(format_str, d));
	else if (option == 3)
		printf("\"%s\"", format_str);
	else if (option == 4)
		printf("%ld", d);
}

int	main(int argc, char *argv[])
{
	int test;
	long d;
	int fn;

	if (argc == 1)
	{
	        printf("%d", 33); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	d = 2147483647;
	if (test == 1)
		ft_iter_int("|%d|", d, fn);
	
	d = -2147483648;
	if (test == 2)
		ft_iter_int("|%d|", d, fn);
	
	d = 2147483650;
	if (test == 3)
		ft_iter_int("|%d|", d, fn);
	
	d = -2147483650;
	if (test == 4)
		ft_iter_int("|%d|", d, fn);
	
	d = 123;
	if (test == 5)
		ft_iter_int("|%7d|", d, fn);
	else if (test == 6)
		ft_iter_int("|%-7d|", d, fn);
	else if (test == 7)
		ft_iter_int("|%07d|", d, fn);
	else if (test == 8)
		ft_iter_int("|%-07d|", d, fn);
	else if (test == 9)
		ft_iter_int("|%- 07d|", d, fn);
	else if (test == 10)
		ft_iter_int("|% 7d|", d, fn);
	else if (test == 11)
		ft_iter_int("|% 07d|", d, fn);
	else if (test == 12)
		ft_iter_int("|% +7d|", d, fn);
	else if (test == 13)
		ft_iter_int("|% +07d|", d, fn);
	else if (test == 14)
		ft_iter_int("|%#d|", d, fn);
	else if (test == 15)
		ft_iter_int("|%#07d|", d, fn);
	else if (test == 16)
		ft_iter_int("|%#7.4d|", d, fn);
	else if (test == 17)
		ft_iter_int("|% +-0#7d|", d, fn);
	else if (test == 18)
		ft_iter_int("|% -0+ -0+7d|", d, fn);
	
	d = 1;
	if (test == 19)
		ft_iter_int("|%d|", d, fn);

	d = 123;
	if (test == 20)
		ft_iter_int("|%.0d|", d, fn);
	else if (test == 21)
		ft_iter_int("|%.5d|", d, fn);
	else if (test == 22)
		ft_iter_int("|%0.5d|", d, fn);
	else if (test == 23)
		ft_iter_int("|%0.d|", d, fn);
	else if (test == 24)
		ft_iter_int("|%.-3d|", d, fn);

	d = 0;
	if (test == 25)
		ft_iter_int("|%-7d|", d, fn);
	else if (test == 26)
		ft_iter_int("|% +#07d|", d, fn);
	else if (test == 27)
		ft_iter_int("|%.7d|", d, fn);
	else if (test == 28)
		ft_iter_int("|%.0d|", d, fn);
	else if (test == 29)
		ft_iter_int("|%d|", d, fn);
	
	if (test == 30)
	{
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%+d% .0d%-5d|", 123, 0, -123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%+d% .0d%-5d|", 123, 0, -123));
                else if (fn == 3)
		        printf("\"%s\"", "|%+d% .0d%-5d|");
	        else if (fn == 4)
		        printf("%d, %d, %d", 123, 0, -123);
        }
        else if (test == 31)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*.*d|", 6, 5, 123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*.*d|", 6, 5, 123));
                else if (fn == 3)
		        printf("\"%s\"", "|%*.*d|");
	        else if (fn == 4)
		        printf("%d, %d, %d", 6, 5, 123);
        }
        else if (test == 32)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*.*d|", -6, -5, 123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*.*d|", -6, -5, 123));
                else if (fn == 3)
		        printf("\"%s\"", "|%*.*d|");
	        else if (fn == 4)
		        printf("%d, %d, %d", -6, -5, 123);
        }
        else if (test == 33)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%-*.*d|", 6, 5, 123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%-*.*d|", 6, 5, 123));
                else if (fn == 3)
		        printf("\"%s\"", "|%-*.*d|");
	        else if (fn == 4)
		        printf("%d, %d, %d", 6, 5, 123);
        }
	
	return (0);
}
