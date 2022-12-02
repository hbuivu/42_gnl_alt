#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("text2", O_RDONLY);
	char *str = get_next_line(fd);
	char *s1 = get_next_line(fd);
	char *s2 = get_next_line(fd);
	char *s3 = get_next_line(fd);
	char *s4 = get_next_line(fd);
	char *s5 = get_next_line(fd);
	// char *s6 = get_next_line(fd);
	
	printf("%s\n", str);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", s4);
	printf("%s\n", s5);
	// printf("%s\n", s6);

	// free (str);
	// free(s1);
	// free(s2);
	// free(s3);
	// free(s4);
	// free(s5);
	//free(s6);
}
