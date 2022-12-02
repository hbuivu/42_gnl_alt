/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:13:46 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/10/24 11:40:03 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h> //delete 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 //must limit this to one below
# endif

void	*ft_calloc(size_t count, size_t size);
int		detect_nline(char *overflow);
int		ft_strlen(char *str);
char	*ft_strjoin(char *overflow, char *line);
void	clean(char **overflow);
char	*get_next_line(int fd);
void	clear(char *overflow);

#endif