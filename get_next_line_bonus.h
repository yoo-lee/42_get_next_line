#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, size_t cnt);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
void	ft_free(char **p);
char	*splitline(char *buf);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*split_line(char *buf, char **tmp);
#endif
