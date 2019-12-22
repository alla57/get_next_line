#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(dest = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = s2[j];
	return (dest);
}

char	*ft_strbefore(char *s, char c)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	if (s[i])
	{
		s[i] = '\0';
		s2 = ft_strdup(s);
		s[i] = c;
		return (s2);
	}
	return (s);
}

char	*ft_strafter(char *s, char c)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	if (s[i])
	{
		s2 = ft_strdup(s + i + 1);
		return (s2);
	}
	return (s);
}

int		get_next_line(int fd, char **line)
{
	int			len;
	static char	buf[BUFFER_SIZE + 1] = "";

	if (fd < 0 || !line)
		return (-1);
	if (!(*line = ft_strdup(buf)))
		return (-1);
	while (ft_strchr(buf, '\n') < 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			return (len);
		buf[len] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	ft_strcpy(buf, ft_strafter(buf, '\n'));
	*line = ft_strbefore(*line, '\n');
	return (1);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	char *line;

	fd = open("./abc", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}
	close(fd);
	return 0;
}
