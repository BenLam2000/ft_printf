/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
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

static void ft_iter_int(const char *format_str, char *d, int option)
{
	if (option == 1)
		printf("\treturn: %d", printf(format_str, d));
	else if (option == 2)
		printf("\treturn: %d", ft_printf(format_str, d));
	else if (option == 3)
		printf("\"%s\"", format_str);
	else if (option == 4)
	{
	        if (d == (char *)0)
	                printf("(char *)0");
	        else
		        printf("\"%s\"", d);
	}
}

int	main(int argc, char *argv[])
{
	int   test;
	char  *s = "hello";
	char  a[5] = {'h','e','l','l','o'}; // no '\0'
	char  *n = (char *)0;
	int   fn;

	if (argc == 1)
	{
	        printf("%d", 31); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	if (test == 1)
		ft_iter_int("|%s|", s, fn);
	else if (test == 2)
		ft_iter_int("|%s|", "hello\n", fn);
	else if (test == 3)
		ft_iter_int("|%s|", "hello\r", fn);
	else if (test == 4)
		ft_iter_int("|%s|", "hello\x10", fn);
	else if (test == 5)
		ft_iter_int("|%7s|", s, fn);
        else if (test == 6)
		ft_iter_int("|%-7s|", s, fn);
	else if (test == 7)
		ft_iter_int("|% +#07s|", s, fn);
        else if (test == 8)
		ft_iter_int("|% +-0#7s|", s, fn);
	else if (test == 9)
		ft_iter_int("|% -0+ -0+7s|", s, fn);
	else if (test == 10)
		ft_iter_int("|%s|", a, fn);
        else if (test == 11)
		ft_iter_int("|%.8s|", s, fn);
	else if (test == 12)
		ft_iter_int("|%.8s|", a, fn);
	else if (test == 13)
		ft_iter_int("|%.3s|", s, fn);
	else if (test == 14)
		ft_iter_int("|%.3s|", a, fn);
	else if (test == 15)
		ft_iter_int("|%.0s|", s, fn);
	else if (test == 16)
		ft_iter_int("|%.-3s|", s, fn);	
        else if (test == 17)
		ft_iter_int("|%s|", "", fn);
	else if (test == 18)
		ft_iter_int("|%-8s|", "", fn);
	else if (test == 19)
		ft_iter_int("|% +#08s|", "", fn);
	else if (test == 20)
		ft_iter_int("|%.0s|", "", fn);
	else if (test == 21)
		ft_iter_int("|%.3s|", "", fn);
	else if (test == 22)
		ft_iter_int("|%s|", n, fn);
	else if (test == 23)
		ft_iter_int("|%-8s|", n, fn);
	else if (test == 24)
		ft_iter_int("|% +#08s|", n, fn);
	else if (test == 25)
		ft_iter_int("|%.0s|", n, fn);
	else if (test == 26)
		ft_iter_int("|%.3s|", n, fn);
	else if (test == 27)
		ft_iter_int("|%.6s|", n, fn);	
        else if (test == 28)
	{
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%s%.0s%-7s|", "abc", "012", "*$\'"));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%s%.0s%-7s|", "abc", "012", "*$\'"));
                else if (fn == 3)
		        printf("\"%s\"", "|%c%c%-5s|");
                else if (fn == 4)
                        printf("\\n, \\0, *");
        }
        else if (test == 29)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*.*s|", 6, 3, "hello"));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*.*s|", 6, 3, "hello"));
                else if (fn == 3)
		        printf("\"%s\"", "|%*.*s|");
                else if (fn == 4)
                        printf("%d, %d, %s", 6, 3, "hello");
        }
        else if (test == 30)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*.*s|", -6, -3, "hello"));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*.*s|", -6, -3, "hello"));
                else if (fn == 3)
		        printf("\"%s\"", "|%*.*s|");
	        else if (fn == 4)
		        printf("%d, %d, %s", -6, -3, "hello");
        }
        else if (test == 31)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%-*.*s|", 6, 3, "hello"));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%-*.*s|", 6, 3, "hello"));
                else if (fn == 3)
		        printf("\"%s\"", "|%-*.*s|");
	        else if (fn == 4)
		        printf("%d, %d, %s", 6, 3, "hello");
        }
	
	return (0);
}
