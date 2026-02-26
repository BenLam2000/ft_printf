/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:10:00 by belam             #+#    #+#             */
/*   Updated: 2026/02/24 23:54:51 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int a = 2;
	//char format_str[] = "##%d##\n";
	if (argc > 1)
	{
		if (argv[3][0] == 'c')
			printf(argv[1], argv[2][0]);
		else if (argv[3][0] == 's')
			printf(argv[1], argv[2]);
		else if (argv[3][0] == 'p')
			printf(argv[1], (void *)&a);
		else if (argv[3][0] == 'x' || argv[3][0] == 'X')
			printf(argv[1], atoi(argv[2]));
		else if (argv[3][0] == 'd' || argv[3][0] == 'i' || argv[3][0] == 'u')
			printf(argv[1], atoi(argv[2]));
			//printf(format_str, atoi(argv[2]));
	}
	else
	{
		//unsigned int b = -1;
		printf("%u\n", UINT_MAX);

		printf("\nfixed width\n");
		printf("%20s: %ld\n", "uint8_t", sizeof(uint8_t)*8);
		printf("%20s: %ld\n", "uint16_t", sizeof(uint16_t)*8);
		printf("%20s: %ld\n", "uint32_t", sizeof(uint32_t)*8);
		printf("%20s: %ld\n", "uint64_t", sizeof(uint64_t)*8);

		printf("\nstd (may vary with system)\n");
		printf("%20s: %ld\n", "int", sizeof(int)*8);
		printf("%20s: %ld\n", "unsigned int", sizeof(unsigned int)*8);
		printf("%20s: %ld\n", "long", sizeof(long)*8);
		printf("%20s: %ld\n", "long unsigned", sizeof(long unsigned)*8);
		printf("%20s: %ld\n", "long long unsigned", sizeof(long long unsigned)*8);
		printf("%20s: %ld\n", "void *", sizeof(void *)*8);
	
		printf("\nensures allowable to fit max size of ptr/mem allocation\n");
		printf("%20s: %ld\n", "size_t", sizeof(size_t)*8);
		printf("%20s: %ld\n", "uintptr_t", sizeof(uintptr_t));
	
		printf("\ndecimal point\n");
		printf("%20s: %ld\n", "float", sizeof(float)*8);
		printf("%20s: %ld\n", "double", sizeof(double)*8);
	}
}
