#include <stdio.h>
#include "libasm.h"

int
main(int ac, const char **av)
{
	const char	*s1;
	const char	*s2;

	if (ac < 2)
	{
		(void)fputs("usage ./a.out str1 str2\n", stderr);
		return 1;
	}
	s1 = av[1];
	s2 = av[2];
	(void) printf("ft_strlen: %zu\n", ft_strlen(s1));
	(void) printf("strlen   : %zu\n", strlen(s1));
	(void) printf("ft_strcmp: %i\n", ft_strcmp(s1, s2));
	(void) printf("strcmp   : %i\n", strcmp(s1, s2));
	return 0;
}
