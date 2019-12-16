#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>	
#include <string.h>


int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret = read(fd, (void *)buf, BUFFER_SIZE);
	buf[ret] = '\0';
    :q
	*line = strdup(buf, ret);
	return 0;

/*	void *buf;
	buf = malloc(sizeof(char) * 100);
	printf("a\n");
	line = malloc(sizeof(char) * 100);
	*line = "je suis la";
	printf("%s\n", *line);
	read(fd, buf, BUFFER_SIZE);
	((char*)buf)[5] = '\0';
	printf("%s\n", (char*)buf);
	printf("a\n");*/
	return 1;
}

int main()
{
	int fd;
	char *line;
	fd = open("./abc", O_RDONLY);
	printf("%d\n", fd);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return 0;
	/*int fd;
	fd = open("./abc", O_WRONLY);
	write(fd, "je suislaa", 10);
	close(fd);
	return 0;*/
	
}
