/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:45:52 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/24 15:39:54 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	buffer = malloc(count * size);
	if (!buffer)
		return (NULL);
	while (i < (count * size))
		((unsigned char *)buffer)[i++] = '\0';
	return (buffer);
}

int	detect_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*joinstr(char **line, char **overflow)
{
	int		llen;
	int		olen;
	int		i;
	int		j;
	char	*return_line;

	llen = ft_strlen_gnl(*line);
	olen = ft_strlen_gnl(*overflow);
	if (llen == 0 && olen == 0)
		return (NULL);
	return_line = (char *)ft_calloc(llen + olen + 1, sizeof(char));
	if (!return_line)
		return (NULL);
	i = 0;
	j = 0;
	while (i < llen)
	{
		return_line[i] = (*line)[i];
		i++;
	}
	free(*line);
	while (j < olen)
		return_line[i++] = (*overflow)[j++];
	return_line[i] = '\0';
	return (return_line);
}

char	*clean(char **overflow)
{
	int		i;
	int		j;
	char	*new_overflow;

	if (!(*overflow))
	{
		new_overflow = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_overflow)
			return (NULL);
		*overflow = new_overflow;
	}
	i = detect_line(*overflow) + 1;
	j = 0;
	while (i > 0 && (*overflow)[i])
		(*overflow)[j++] = (*overflow)[i++];
	while (j <= BUFFER_SIZE)
		(*overflow)[j++] = '\0';
	return (*overflow);
}
