#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//char format_str[] = "##%d##\n";
	if (argc > 1)
	{
		if (argv[3][0] == 'c')
			printf(argv[1], argv[2][0]);
		else if (argv[3][0] == 's')
			printf(argv[1], argv[2]);
		else if (argv[3][0] == 'p')
			printf(argv[1], argv[2]); //
		else if (argv[3][0] == 'd')
			printf(argv[1], atoi(argv[2]));
			//printf(format_str, atoi(argv[2]));
	}
}
