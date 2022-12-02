/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:43:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/24 16:09:46 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*overflow[1024];
	char		*line;
	ssize_t		i;

	line = NULL;
	i = 1;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	while (detect_line(line) < 0 && i > 0)
	{
		line = joinstr(&line, &(overflow[fd]));
		overflow[fd] = clean(&(overflow[fd]));
		if (!(overflow[fd]))
			return (NULL);
		if (detect_line(line) > -1)
			break ;
		i = read(fd, overflow[fd], BUFFER_SIZE);
	}
	if (ft_strlen_gnl(overflow[fd]) == 0)
	{
		free(overflow[fd]);
		overflow[fd] = NULL;
	}
	return (line);
}
