/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:43:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/25 17:07:11 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*overflow;
	char		*line;
	ssize_t		i;

	line = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	while (detect_line(line) < 0 && i > 0)
	{
		line = joinstr(&line, &overflow);
		overflow = clean(&overflow);
		if (!overflow)
			return (NULL);
		if (detect_line(line) > -1)
			break ;
		i = read(fd, overflow, BUFFER_SIZE);
	}
	if (ft_strlen_gnl(overflow) == 0)
	{
		free(overflow);
		overflow = NULL;
	}
	return (line);
}
