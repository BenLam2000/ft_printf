/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:32:07 by belam             #+#    #+#             */
/*   Updated: 2026/03/04 21:57:42 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

static void ft_iter_int(const char *format_str, void *d, int option)
{
	if (option == 1)
		printf("\treturn: %d", printf(format_str, d));
	else if (option == 2)
		printf("\treturn: %d", ft_printf(format_str, d));
	else if (option == 3)
		printf("\"%s\"", format_str);
	else if (option == 4)
		printf("(void *)%llu", (long long unsigned)d);
}

int	main(int argc, char *argv[])
{
	int test;
	void *d;
	int fn;

	if (argc == 1)
	{
	        printf("%d", 30); // number of tests
	        return (0);
	}
	else if (argc == 2)
                return (1);
        else if (argc > 3)
                return (1);
	
	test = atoi(argv[1]);
	fn = atoi(argv[2]); // 1: printf, 2: ft_printf	

	d = (void *)18446744073709551615ULL;
	if (test == 1)
		ft_iter_int("|%p|", d, fn);
	
	d = (void *)0;
	if (test == 2)
		ft_iter_int("|%p|", d, fn);
	
	d = (void *)-123;
	if (test == 3)
		ft_iter_int("|%p|", d, fn);
	
	d = (void *)123;
	if (test == 4)
		ft_iter_int("|%7p|", d, fn);
	else if (test == 5)
		ft_iter_int("|%-7p|", d, fn);
	else if (test == 6)
		ft_iter_int("|%07p|", d, fn);
	else if (test == 7)
		ft_iter_int("|%-07p|", d, fn);
	else if (test == 8)
		ft_iter_int("|%- 07p|", d, fn);
	else if (test == 9)
		ft_iter_int("|% 7p|", d, fn);
	else if (test == 10)
		ft_iter_int("|% 07p|", d, fn);
	else if (test == 11)
		ft_iter_int("|% +7p|", d, fn);
	else if (test == 12)
		ft_iter_int("|% +07p|", d, fn);
	else if (test == 13)
		ft_iter_int("|%#p|", d, fn);
	else if (test == 14)
		ft_iter_int("|% +-0#7p|", d, fn);
        else if (test == 15)
		ft_iter_int("|% -0+ -0+7p|", d, fn);
	
	d = (void *)1;
	if (test == 16)
		ft_iter_int("|%p|", d, fn);

	d = (void *)123;
	if (test == 17)
		ft_iter_int("|%.0p|", d, fn);
	else if (test == 18)
		ft_iter_int("|%.5p|", d, fn);
	else if (test == 19)
		ft_iter_int("|%0.5p|", d, fn);
	else if (test == 20)
		ft_iter_int("|%0.p|", d, fn);
	else if (test == 21)
		ft_iter_int("|%.-3p|", d, fn);

	d = (void *)0;
	if (test == 22)
		ft_iter_int("|%-7p|", d, fn);
	else if (test == 23)
		ft_iter_int("|% +#07p|", d, fn);
	else if (test == 24)
		ft_iter_int("|%p|", d, fn);
	else if (test == 25)
		ft_iter_int("|%.7p|", d, fn);
	else if (test == 26)
		ft_iter_int("|%.0p|", d, fn);
		
	if (test == 27)
	{
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%p%p%-5p|", (void *)123, (void *)0, (void *)-123));
                if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%p%p%-5p|", (void *)123, (void *)0, (void *)-123));
                else if (fn == 3)
		        printf("\"%s\"", "|%p%p%-5p|");
	        else if (fn == 4)
		        printf("(void *)%d, (void *)%d, (void *)%d", 123, 0, -123);
        }
        else if (test == 28)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*p|", 6, (void *)123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*p|", 6, (void *)123));
                else if (fn == 3)
		        printf("\"%s\"", "|%*p|");
	        else if (fn == 4)
		        printf("%d, (void *)%d", 6, 123);
        }
        else if (test == 29)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%*p|", -6, (void *)123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%*p|", -6, (void *)123));
                else if (fn == 3)
		        printf("\"%s\"", "|%*p|");
	        else if (fn == 4)
		        printf("%d, (void *)%d", -6, 123);
        }
        else if (test == 30)
        {
	        if (fn == 1)
		        printf("\treturn: %d", printf("|%-*p|", 6, (void *)123));
                else if (fn == 2)
                        printf("\treturn: %d", ft_printf("|%-*p|", 6, (void *)123));
                else if (fn == 3)
		        printf("\"%s\"", "|%-*p|");
	        else if (fn == 4)
		        printf("%d, (void *)%d", 6, 123);
        }
	
	return (0);
}
