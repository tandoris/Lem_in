/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/04 20:50:12 by lboukrou         ###   ########.fr       */
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

/*
**	Cherche et renvoie le nombre de fourmis. ERROR si fourmis n'existe pas.
*/

unsigned int		get_num_ants(char *line)
{
	
	unsigned int	ants;
	int				ret;

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

void	start_or_end(char *buf)
{
	if (!(ft_strcmp(buf, "##start")) || !(ft_strcmp(buf, "##end")))
		return (1);
	else
		return (0);
}

int		check_line(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (0);
	}
	if (!(start_or_end))
	{
		free(line);
		return (0);
	}
	return (1);
}

int		nb_elem_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
**	Parse les infos des tubes pour construire les edges
*/


void	get_tube(t_graph *graph, char *line)
{
	char	**tab;
	int		i;
	int		j;

	tab = NULL;
	i = 0;
	j = 0;
	if (ft_strchr(&line, '-'))
	{
		tab = ft_strsplit(&line, '-');
		if ((nb_elem_tab(tab)) != 2)
		{
			ft_memdel((void **)tab);
			return (0);
		}
	}
	add_edge(graph, ft_atoi(tab[i]), ft_atoi(tab[i + 1])); // TODO : mettre des char *
}

char	**get_room(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(&line, ' '))
	{
		tab = ft_strsplit(&line, ' ');
		if ((nb_elem_tab(tab)) != 3)
		{
			ft_memdel((void **)tab);
			return (0);
		}
	}
	return (tab);
}

t_graph		*construct_graph(t_nodes);

t_graph		*get_infos(t_node *nodes)
{
	t_graph	*graph;
	char	*line;
	int		ret;
	int		vertices;

	line == NULL;
	if (!(get_num_ants))
		return (0);
	while(ret == get_next_line(0, &line) > 0)
	{
		if (!check_line(line))
			break ;
	}
}