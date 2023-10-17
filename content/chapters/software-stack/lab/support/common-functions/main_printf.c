/* SPDX-License-Identifier: BSD-3-Clause */

#include "./syscall.h"
#include "./string.h"
#include "./printf.h"

static const char src[] = "warhammer40k";
static char dest[128];
static char out_buffer[256];

/* _putchar implementation has to be provided. */
void _putchar(char character)
{
	write(1, &character, 1);
}

int main(void)
{
  char buffer[100];
	sprintf(buffer, "[before] src is at %p, len is %lu, content: \"%s\"\n", src, strlen(src), src);
  write(1, buffer, strlen(buffer));
  
	printf("[before] dest is at %p, len is %lu, content: \"%s\"\n", dest, strlen(dest), dest);

	printf("copying src to dest\n");
	strcpy(dest, src);

	printf("[after] src is at %p, len is %lu, content: \"%s\"\n", src, strlen(src), src);
	printf("[after] dest is at %p, len is %lu, content: \"%s\"\n", dest, strlen(dest), dest);

	exit(0);
	return 0;
}
