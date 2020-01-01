#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

int
main(int ac, const char **av)
{
	if (ac < 2)
	{
		(void)fputs("usage ./a.out foobar\n", stderr);
		return 1;
	}
	(void) printf("ft_strlen: %zu\n", ft_strlen(av[1]));
	(void) printf("strlen   : %zu\n", strlen(av[1]));
	return 0;
}
