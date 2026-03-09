#include <stdio.h>
#include <string.h>

/*
int foo(const char *format_str, void *arg)
{
	return (printf(format_str, arg));
}*/


int	main(void)
{
/*
	int a;
	a = printf("hello\b");
	printf("return: %d\n", a);
*/

	return(printf("return: %d", printf("|%.3k|")));
}

/*
int main() {
    #if defined(__STDC__)
        #if defined(__STDC_VERSION__)
            if (__STDC_VERSION__ >= 202311L) {
                printf("We are using C23 or later!\n");
            } else if (__STDC_VERSION__ >= 201710L) {
                printf("We are using C17/C18!\n");
            } else if (__STDC_VERSION__ >= 201112L) {
                printf("We are using C11!\n");
            } else if (__STDC_VERSION__ >= 199901L) {
                printf("We are using C99!\n");
            } else {
                printf("We are using an earlier standard with __STDC_VERSION__, possibly C95.\n");
            }
        #else
            printf("We are using C89/C90 (ANSI C) standard.\n");
        #endif
    #else
        printf("We are using a pre-C89 standard or a non-conforming compiler dialect (e.g., old GNU C without flags).\n");
    #endif
    
    // Optional: Print the exact macro value if defined
    #if defined(__STDC_VERSION__)
        printf("__STDC_VERSION__ value: %ldL\n", __STDC_VERSION__);
    #endif

    return 0;
}
*/
