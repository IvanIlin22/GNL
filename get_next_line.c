/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:16:43 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/28 19:11:41 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int				new_line(const int fd, char **line, char **c)
{
	int			i;
	char		*str;

	i = 0;
	while (c[fd][i] != '\n' && c[fd][i])
		i++;
	str = c[fd];
	if (c[fd][i] == '\n')
		*line = ft_strsub(c[fd], 0, i);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], ft_strlen(*line) + 1,
	ft_strlen(c[fd]) - (ft_strlen(*line) + 1));
	ft_strdel(&str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*c[2147483647];
	char		*str;
	int			nb;

	if (fd < 0 || BUFF_SIZE < 0 || !line || (!c[fd] && !(c[fd] = ft_strnew(1))))
		return (-1);
	while ((nb = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = '\0';
		str = c[fd];
		c[fd] = ft_strjoin(c[fd], buf);
		free(str);
	}
	if (nb < 0)
		return (-1);
	if (nb == 0 && c[fd][0] == '\0')
		return (0);
	return (new_line(fd, line, c));
}
