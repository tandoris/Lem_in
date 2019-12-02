/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:57:44 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/07 12:24:52 by lboukrou         ###   ########.fr       */
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
			tmp = ft_strjoin(*str, buf);
			ft_strdel(str);
			*str = (ft_strdup(tmp));
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
	if (str == NULL)
		str = ft_strnew(0);
	ret = read_file(fd, &str, ret);
	if (ret > 0 || ft_strlen(str))
	{
		*line = ft_strnew(ft_size(str, '\n'));
		*line = ft_strncpy(*line, str, ft_size(str, '\n'));
		ret = ft_strlen(str) > 0 ? 1 : ret;
		tmp = ft_strsub(str, ft_size(str, '\n') + 1,
				ft_strlen(str) - ft_size(str, '\n'));
		free(str);
		str = tmp;
	}
	if (ret <= 0)
		ft_strdel(&str);
	return (ret);
}
