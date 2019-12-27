/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 22:07:06 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/27 21:22:00 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns smallest nb
*/

static size_t	who_is_smallest(size_t a, size_t b, size_t c)
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
**	Returns max numm of paths
*/

size_t			count_max_paths(t_graph *graph)
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
	// add_end_list(&path, duplicate_room(closest));
	while ((closest)->status != END_ROOM)
	{
		printf("closest -> %s\n", closest->name_room);
		if (!(closest = search_closest_room(*graph, &closest)))
			return (NULL);
		add_end_list(&path, duplicate_room(closest));
		if (closest->status != END_ROOM)
		{
			tmp = search_by_name(*graph, closest->name_room);
			(*tmp)->occupied = 1;
		}
	}
	printf("\n");
	return (path);
}
//TODO : supprimer les rooms qui ont moins de 2 connexions - peut-etre on verra

/*
**	Returns adjencency room that is closest to end, if it's unoccupied 
*/

t_node			*search_closest_room(t_graph *graph, t_node **room)
{
	t_node		*closest;
	t_node		*tmp;

	tmp = *room;
	closest = tmp;
	printf("-->room : %s - ", tmp->name_room);
	tmp = tmp->next;
	while (tmp)
	{
		// printf(" %s - ", tmp->name_room);
		if (!(is_room_occupied(graph, tmp)))
			closest = comp_distance(graph, closest->name_room, tmp->name_room);
		tmp = tmp->next;
	}
	printf("\n");
	if (!(ft_strcmp(closest->name_room, (*room)->name_room)))
		return (NULL);
	return (closest);
}

/*
**	Returns 1 if room occupied, 0 if room is free
*/

int				is_room_occupied(t_graph *graph, t_node *room)
{
	t_node	*tmp;

	tmp = *search_by_name(graph, room->name_room);
	return (tmp->occupied);
}

/*
**	//TODO mettre commentaire intelligent et precism allez hop
*/

void			find_all_paths(t_graph **graph)
{
	t_node		**paths;
	t_node		**end;
	size_t		nb_paths;
	size_t		i;
	t_node		*pass;

	end = search_by_status(*graph, END_ROOM);
	// printf("debut\n");
	calc_distance(graph, end, 0);
	if (!(nb_paths = count_max_paths(*graph)))
		ft_error();
	if (!(paths = ft_memalloc(sizeof(t_node *) * (nb_paths + 1))))
		ft_malloc_error();
	i = 0;
	while (i < nb_paths)
	{
		if (!(paths[i] = get_shortest_path(graph)))
			break ;
		reset_distance(graph);
		calc_distance(graph, end, 0);
		i++;
	}
	printf("nb max path : %zu\n", nb_paths);
	printf("nb path : %zu\n", i);
	nb_paths = i;
	if (nb_paths == 0)
		ft_error();
	i = 0;
	while (paths[i])
	{
		pass = paths[i];
		while (pass)
		{
			printf("name room : %s - ", pass->name_room);
			pass = pass->next;
		}
		printf("\n");
		i++;
	}
}