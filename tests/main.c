#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"

int
main(int ac, const char **av)
{
	const char	*s1;
	const char	*s2;
	char		buffer[512];
	char		*ptr;

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

	bzero(buffer, sizeof(buffer));
	(void) printf("ft_strcpy: %s\n", ft_strcpy(buffer, s1));
	bzero(buffer, sizeof(buffer));
	(void) printf("strcpy   : %s\n", strcpy(buffer, s1));

	(void) printf("ft_strdup: %s\n", (ptr = ft_strdup(s2)));
	free(ptr);
	(void) printf("strdup   : %s\n", (ptr = strdup(s2)));
	free(ptr);

	return 0;
}
