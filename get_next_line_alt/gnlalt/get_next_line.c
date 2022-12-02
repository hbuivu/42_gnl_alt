/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:08:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/24 11:41:33 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*overflow;
	char 		*line;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	line = NULL;
	i = 1;
	if (!overflow)
	{
		overflow = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!overflow)
			return (NULL);
		i = read(fd, overflow, BUFFER_SIZE);
		if (i <= 0)
		{
			free(overflow);
			overflow = NULL;
			return (NULL);
		}
	}
	while (detect_nline(overflow) < 0 && i > 0)
	{
		line = ft_strjoin(line, overflow);
		clear(overflow);
		i = read(fd, overflow,BUFFER_SIZE);
	}
	if (detect_nline(overflow) >= 0)
		line = ft_strjoin(line, overflow);
	clean(&overflow);
	return (line);
}