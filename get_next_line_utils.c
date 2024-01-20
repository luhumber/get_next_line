/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:02:51 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/30 12:54:09 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if ((unsigned char)(str[i]) == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	char	*ret;
	size_t	i;
	ssize_t	j;

	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}

char	*ft_joinbuffer(char *new_buffer, char *buf)
{
	char	*new_temp;

	new_temp = ft_strjoin(new_buffer, buf);
	free(new_buffer);
	return (new_temp);
}
