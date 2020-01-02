/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 22:07:06 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:11:16 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns smallest nb
*/

static int		who_is_smallest(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		return (c);
	}
	if (b < c)
		return (b);
	return (c);
}

/*
**	Returns max num of paths
*/

int				count_max_paths(t_graph *graph)
{
	size_t		ants;
	t_node		*tmp;
	size_t		nb_adj_start;
	size_t		nb_adj_end;

	ants = graph->ants;
	tmp = *search_by_status(graph, START_ROOM);
	nb_adj_start = get_list_length(tmp) - 1;
	tmp = *search_by_status(graph, END_ROOM);
	nb_adj_end = get_list_length(tmp) - 1;
	return (who_is_smallest(ants, nb_adj_start, nb_adj_end));
}

/*
**	Returns smallest path from start to end
*/

t_node			*get_shortest_path(t_graph **graph)
{
	t_node	*path;
	t_node	*closest;
	t_node	**tmp;

	path = NULL;
	closest = *search_by_status(*graph, START_ROOM);
	while ((closest)->status != END_ROOM)
	{
		if (!(closest = search_closest_room(*graph, &closest)))
			return (NULL);
		add_end_list(&path, duplicate_room(closest));
		if (closest->status != END_ROOM)
		{
			tmp = search_by_index(*graph, closest->room_index);
			(*tmp)->occupied = 1;
		}
	}
	return (path);
}

static t_paths	*last_verif(t_paths *p)
{
	if (p->nb_paths <= 0)
	{
		free_paths(&p);
		return (NULL);
	}
	return (p);
}

/*
**	Returns a structure with all possible paths from shortest to longest
*/

t_paths			*find_all_paths(t_graph **graph)
{
	t_paths		*p;
	t_node		**end;
	int			i;

	if (!(p = (t_paths*)ft_memalloc(sizeof(t_paths))))
		ft_malloc_error();
	end = search_by_status(*graph, END_ROOM);
	calc_distance(graph, end, 0);
	if (!(p->nb_paths = count_max_paths(*graph)))
	{
		free_paths(&p);
		return (NULL);
	}
	if (!(p->paths = ft_memalloc(sizeof(t_node *) * (p->nb_paths + 1))))
		ft_malloc_error();
	i = -1;
	while (++i < p->nb_paths)
	{
		if (!(p->paths[i] = get_shortest_path(graph)))
			break ;
		reset_distance(graph);
		calc_distance(graph, end, 0);
	}
	p->nb_paths = i;
	return (last_verif(p));
}
