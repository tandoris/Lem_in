/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:53:01 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/16 18:51:23 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Retourne l'enum correspondant a une salle
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
**	Identifier si line est un tube Si oui, retourne tableau malloque, si non NULL
*/

char	**identify_tube(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, '-'))
	{
		tab = ft_strsplit(line, '-');
		if (nb_elem_tab(tab) == 2)
			return (tab);
		ft_memdel((void **)tab);
	}
	return NULL;
}

/*
**	Identifier si line est une room. Si oui, retourne tableau malloque, si non NULL
*/

char	**identify_room(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, ' '))
	{
		tab = ft_strsplit(line, ' ');
		if (nb_elem_tab(tab) == 3 && tab[0][0] != 'L' && tab[0][0] != '#' && is_number(tab[1]) && is_number(tab[2])) 
			return (tab);
		ft_memdel((void **)tab);	
	}
	return NULL;
}

/*
**	Identifier si line est un comment
*/

unsigned int	identify_comment(char *line)
{
	if (ft_strchr(line, '#'))
		return (1);
	return (0);
}