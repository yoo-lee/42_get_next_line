#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"


int main()
{
	char *line;
	int fd ,fd2,fd3;
	size_t i;
	fd = open("study/1.txt", O_RDONLY);
	fd2 = open("study/2.txt", O_RDONLY);
	fd3 = open("study/3.txt", O_RDONLY);
	i = 0;
	while (1)
	{
	line = get_next_line(fd);
	line = get_next_line(fd2);
 	printf("[%zu]:-----------\n", i);
 	printf("fd = 3\n line = %s\n", get_next_line(fd));
 	printf("fd = 4\n line = %s\n", get_next_line(fd2));
 	printf("fd = 5\n line =%s\n", get_next_line(fd3));
 		if (!line)
 		{
 			free(line);
 			break;
 		}
 		free(line);
		i++;
	}
close(fd);
return (0);
}