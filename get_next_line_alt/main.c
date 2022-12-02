#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("text2", O_RDONLY);
	char *str;
	for(int i = 0; i < 3; i++)
	{
		str = get_next_line(1000);
		printf("%s", str);
		free(str);
	}


	// while (str != NULL)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// 	str = get_next_line(fd);		
	// }
	// printf("%i\n", fd);
	// char *str = get_next_line(fd);
	// char *s1 = get_next_line(42);
	// char *s2 = get_next_line(42);
	// // printf("%s\n", str);
	// free (str);
	// free (s1);
	// free (s2);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// char *s1 = get_next_line(fd);
	// char *s2 = get_next_line(fd);
	// char *s3 = get_next_line(fd);
	// char *s4 = get_next_line(fd);
	// char *s5 = get_next_line(fd);
	// char *s6 = get_next_line(fd);

	// int f
	
	// char *s8 = get_next_line(fd1);
	// char *s9 = get_next_line(fd1);
	// char *s10 = get_next_line(fd1);
	// char *s11 = get_next_line(fd1);
	// char *s12 = get_next_line(fd1);
	
	// printf("%s\n", s1);
	// printf("%s\n", s2);
	// printf("%s\n", s3);
	// printf("%s\n", s4);
	// printf("%s\n", s5);
	// printf("%s\n", s6);

	// printf("%s\n", s7);
	// printf("%s\n", s8);
	// printf("%s\n", s9);
	// printf("%s\n", s10);
	// printf("%s\n", s11);
	// printf("%s\n", s12);


	// free (str);
	// free(s1);
	// free(s2);
	// free(s3);
	// free(s4);
	// free(s5);
	// free(s6);
}
