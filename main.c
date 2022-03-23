#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	*s = "In this second part, you must code a set of functions";

	char 	*sub = ft_substr(s, 21, 8);
	
	printf("%s\n", sub);
	free(sub);

	return (0);
}
