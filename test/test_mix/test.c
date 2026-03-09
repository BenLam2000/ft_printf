/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix.c                                         :+:      :+:    :+:   */
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

int	main(int argc, char *argv[])
{
	int test;
	int fn;
	const char *str;

	if (argc == 1)
	{
	        printf("%d", 3); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	if (test == 1)
	{
	        str = "Student name: %-5.3s\tScore: %u%%\tGrade: %c\n";
	        if (fn == 1)
		        printf("\treturn: %d", printf(str, "Abu Bakar", 86, 'A'));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf(str, "Abu Bakar", 86, 'A'));
                else if (fn == 3)
                        printf("\"%s\"", str);
                else if (fn == 4)
                        printf("\"Abu Bakar\", 86, \'A\'");
        }
        else if (test == 2)
	{
	        str = "Min: %5d\tMax: % +.5i\nMin(%c): %#5x\tMax(%c): %05X\nAdress: %p";
	        if (fn == 1)
		        printf("\treturn: %d", printf(str, -175, 216, 'x', -175, 'X', 216, (void *)0x7ffdb3c02168));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf(str, -175, 216, 'x', -175, 'X', 216, (void *)0x7ffdb3c02168));
                else if (fn == 3)
                        printf("\"%s\"", str);
                else if (fn == 4)
                        printf("-175, 216, \'x\', -175, \'X\', 216, (void *)0x7ffdb3c02168");
        }
        else if (test == 3)
	{
	        str = "|% +8.5k|";
	        if (fn == 1)
		        printf("\treturn: %d", printf(str, 100));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf(str, 100));
                else if (fn == 3)
                        printf("\"%s\"", str);
                else if (fn == 4)
                        printf("100");
        }
	
	return (0);
}
