#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

int main()
{
	char *p;
	char *f;

	p = ft_strdup("Pizza");
	f = ft_strdupdel(&p);

	printf("p = %p\n", p);
	printf("f = %p\n", f);

	free(f);
	sleep(60);
	return (0);
}
