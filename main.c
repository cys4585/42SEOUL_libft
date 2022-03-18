#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char dst[2];
	char src[4] = {1,1,1,1};
	size_t n = 4;

	for (size_t i = 0; i < 4; i++)
		printf("dst[%zu] : %p | %d\n",  i, &dst[i], dst[i]);
	printf("\n");

	for (size_t i = 0; i < sizeof(src); i++)
		printf("src[%zu] : %p | %d\n", i, &src[i], src[i]);	
	printf("\n");

	printf("%p\n", NULL);
	printf("memcpy() start...\n");
	memcpy(dst, src, n);
	printf("memcpy() done...\n\n\n");

	for (size_t i = 0; i < 4; i++)
		printf("dst[%zu] : %p | %d\n",  i, &dst[i], dst[i]);
	printf("\n");

	for (size_t i = 0; i < sizeof(src); i++)
		printf("src[%zu] : %p | %d\n", i, &src[i], src[i]);	
	printf("\n");
	return (0);
}
