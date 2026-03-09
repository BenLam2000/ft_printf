/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
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
	        if (d == 0)
	                printf("\\0");
	        else
		        printf("\'%c\'", d);
	}
}

int	main(int argc, char *argv[])
{
	int test;
	int d;
	int fn;

	if (argc == 1)
	{
	        printf("%d", 23); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	if (test == 1)
		ft_iter_int("|%c|", '\0', fn);
	else if (test == 2)
		ft_iter_int("|%c|", '\\', fn);
	else if (test == 3)
		ft_iter_int("|%c|", '\n', fn);
	else if (test == 4)
		ft_iter_int("|%c|", 27, fn);
	else if (test == 5)
		ft_iter_int("|%c|", 127, fn);
        else if (test == 6)
		ft_iter_int("|%c|", '*', fn);
	else if (test == 7)
		ft_iter_int("|%c|", 'g', fn);
        else if (test == 8)
		ft_iter_int("|%c|", 255, fn);
	else if (test == 9)
		ft_iter_int("|%c|", 0, fn);
	else if (test == 10)
		ft_iter_int("|%c|", 300, fn);
        else if (test == 11)
		ft_iter_int("|%c|", -130, fn);
  
	d = 'a';
	if (test == 12)
		ft_iter_int("|%7c|", d, fn);
	else if (test == 13)
		ft_iter_int("|%-7c|", d, fn);
	else if (test == 14)
		ft_iter_int("|%07c|", d, fn);
	else if (test == 15)
		ft_iter_int("|% +#c|", d, fn);
	else if (test == 16)
		ft_iter_int("|% +-0#7c|", d, fn);
	else if (test == 17)
		ft_iter_int("|% -0+ -0+7c|", d, fn);
	else if (test == 18)
		ft_iter_int("|%.5c|", d, fn);
	else if (test == 19)
		ft_iter_int("|%.-3c|", d, fn);
	
	if (test == 20)
	{
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%c%c%-5c|", '\n', '\0', '*'));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%c%c%-5c|", '\n', '\0', '*'));
                else if (fn == 3)
		        printf("\"%s\"", "|%c%c%-5c|");
                else if (fn == 4)
                        printf("\\n, \\0, *");
        }
        else if (test == 21)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*c|", 6, 'a'));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*c|", 6, 'a'));
                else if (fn == 3)
		        printf("\"%s\"", "|%*.*c|");
                else if (fn == 4)
                        printf("%d, %c", 6, 'a');
        }
        else if (test == 22)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*c|", -6, 'a'));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*c|", -6, 'a'));
                else if (fn == 3)
		        printf("\"%s\"", "|%*c|");
	        else if (fn == 4)
		        printf("%d, %c", -6, 'a');
        }
        else if (test == 23)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%-*c|", 6, 'a'));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%-*c|", 6, 'a'));
                else if (fn == 3)
		        printf("\"%s\"", "|%-*.*c|");
	        else if (fn == 4)
		        printf("%d, %c", 6, 'a');
        }
	
	return (0);
}
