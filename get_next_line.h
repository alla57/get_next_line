#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strbefore(char *s, char c);
char	*ft_strafter(char *s, char c);
int		get_next_line(int fd, char **line);

#endif
