/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:13:33 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/18 15:09:41 by hbui-vu          ###   ########.fr       */
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

int	detect_nline(char *overflow)
{
	int	index;

	index = 0;
	while(overflow[index])
	{
		if (overflow[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int	ft_strlen(char *str)
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

char	*ft_strjoin(char *line, char *overflow)
{
	char	*return_line;
	int		i;
	int		j;
	int		line_len;
	int		overflow_len;

	i = 0;
	j = 0;
	line_len = ft_strlen(line);
	overflow_len = ft_strlen(overflow);
	if (line_len == 0 && overflow_len == 0)
		return (NULL);
	return_line = (char *)ft_calloc(line_len + overflow_len + 1, sizeof(char));
	if (!return_line)
		return (NULL);
	while (i < line_len)
	{
		return_line[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	while (j < overflow_len)
		return_line[i++] = overflow[j++];
	return (return_line);
}

void	clean(char **overflow)
{
	int	i;
	int	j;

	i = 0;
	j = detect_nline(*overflow) + 1;
	if (j == 0)
	{
		free(*overflow);
		*overflow = NULL;
		return ;
	}
	while ((*overflow)[j])
		(*overflow)[i++] = (*overflow)[j++];
	while ((*overflow)[i])
		(*overflow)[i++] = '\0';
	return; 
}

void	clear(char *overflow)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(overflow);
	while (i < len)
		overflow[i++] = '\0';
}
