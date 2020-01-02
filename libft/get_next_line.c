/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:57:44 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/01 20:53:13 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_file(const int fd, char **str, int ret)
{
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	if (ft_fchar(*str, '\n') != 1)
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (!(tmp = ft_strjoin(*str, buf)))
				return (-1);
			ft_strdel(str);
			if (!(*str = (ft_strdup(tmp))))
				return (-1);
			ft_strdel(&tmp);
			if (ft_fchar(buf, '\n') == 1)
				break ;
			ft_bzero(buf, BUFF_SIZE + 1);
		}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char *str;
	int			ret;
	char		*tmp;

	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (str == NULL && !(str = ft_strnew(0)))
		return (-1);
	ret = read_file(fd, &str, ret);
	if (ret > 0 || ft_strlen(str))
	{
		if (!(*line = ft_strnew(ft_size(str, '\n'))))
			return (-1);
		*line = ft_strncpy(*line, str, ft_size(str, '\n'));
		ret = ft_strlen(str) > 0 ? 1 : ret;
		if (!(tmp = ft_strsub(str, ft_size(str, '\n') + 1,
				ft_strlen(str) - ft_size(str, '\n'))))
			return (-1);
		free(str);
		str = tmp;
	}
	if (ret <= 0)
		ft_strdel(&str);
	return (ret);
}
