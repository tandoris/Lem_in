/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:53:01 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 15:58:53 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns right enum while reading line
*/

t_room_status	identify_room_status(char *buf)
{
	if (!(ft_strcmp(buf, "##start")))
		return (START_ROOM);
	else if (!(ft_strcmp(buf, "##end")))
		return (END_ROOM);
	else
		return (NORMAL);
}

/*
**	Read line, if tube identified, returns array, else NULL
*/

char			**identify_tube(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, '-'))
	{
		if (!(tab = ft_strsplit(line, '-')))
			ft_malloc_error();
		if (nb_elem_tab(tab) == 2)
			return (tab);
		free_tab(tab);
	}
	return (NULL);
}

/*
**	Read line, if room detected, returns array, else NULL
*/

char			**identify_room(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, ' '))
	{
		if (!(tab = ft_strsplit(line, ' ')))
			ft_malloc_error();
		if (nb_elem_tab(tab) == 3 && tab[0][0] != 'L' && tab[0][0] != '#'
			&& is_number(tab[1]) && is_number(tab[2]))
			return (tab);
		free_tab(tab);
	}
	return (NULL);
}

/*
**	Read line, if comment detected, 1, else 0
*/

unsigned int	identify_comment(char *line)
{
	if ((line - ft_strchr(line, '#')) == 0)
		return (1);
	return (0);
}
