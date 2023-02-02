/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoo-lee <yoo-lee@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:00:33 by yoo-lee           #+#    #+#             */
/*   Updated: 2021/12/01 19:00:33 by yoo-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **p)
{
	free(*p);
	*p = NULL;
}

char	*split_line(char *buf, char **tmp)
{
	char		*line_after_n;
	char		*line_before_n;
	ssize_t		line_before_n_len;
	ssize_t		nlen;
	char		*tmp1;

	tmp1 = ft_strchr(buf, '\n');
	nlen = ft_strlen(buf);
	line_before_n_len = nlen - ft_strlen(tmp1);
	line_after_n = ft_substr(buf, line_before_n_len + 1, nlen);
	*tmp = line_after_n;
	line_before_n = ft_strndup(buf, line_before_n_len + 1);
	return (line_before_n);
}

int	judge_n(char *buf, char **memo, char **line)
{
	char	*tmp2;

	*line = NULL;
	tmp2 = ft_strjoin(*memo, buf);
	if (!tmp2)
		return (-1);
	ft_free(memo);
	if (ft_strchr(tmp2, '\n'))
	{
		*line = split_line(tmp2, memo);
		ft_free(&tmp2);
	}
	else if (ft_strlen(buf) != 0)
		*memo = tmp2;
	else if (ft_strlen(buf) == 0 && ft_strlen(tmp2) != 0)
		*line = tmp2;
	else
		ft_free(&tmp2);
	ft_free(&buf);
	return (-1);
}

int	read_line(char **line, char **memo, int fd)
{
	int		result;
	char	*buf;

	buf = NULL;
	result = 1;
	while (result > 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (-1);
		result = read(fd, buf, BUFFER_SIZE);
		buf[result] = '\0';
		judge_n(buf, memo, line);
		if (*line)
		{
			return (1);
		}
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*memo;
	char		*line;
	int			tmp;
	// size_t			i;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (judge_n < 0)
		ft_free(&line);
	if (!memo)
		memo = ft_strndup("", 0);
	tmp = read_line (&line, &memo, fd);
	printf("fd = %d\n", fd);
	printf("getnextline = %s\n", line);
	// while(i <= fd)
	// {
	// read_line (&line, &memo, i);
	// }
	return (line);
}
