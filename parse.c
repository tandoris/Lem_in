/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/30 20:11:42 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_number(char *str)
{
	if (str[0] == '-')
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

unsigned int		get_num_ants()
{
	unsigned int	ants;
	int				ret;
	char			*line;

	if ((ret = get_next_line(0, &line)) > -1)
	{
		if (is_number(line) == 1)
		{
			ants = ft_atoi(&line);
			return (ants);
		}
		else
		{
			ft_putendl("ERROR");
			exit(0);
		}
	}
	ft_putendl("ERROR");
	exit(0);
	return (0);
}

t_graph		*get_infos()
{
	t_graph	*graph;
	char	*line;
	int		ret;

	line == NULL;
	while(ret == get_next_line(0, &line) > 0)

}