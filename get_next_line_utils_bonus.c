/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoo-lee <yoo-lee@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:00:47 by yoo-lee           #+#    #+#             */
/*   Updated: 2021/12/01 19:00:53 by yoo-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*res;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1l + s2l + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1l)
	{
		res[i] = s1[i];
		i++;
	}
	while (i - s1l < s2l)
	{
		res[i] = s2[i - s1l];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(const char *str, size_t cnt)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(str);
	if (cnt < len)
		len = cnt;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
