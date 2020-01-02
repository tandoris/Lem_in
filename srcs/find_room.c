/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:29:15 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:12:08 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Search and returns a room by its status
*/

t_node	**search_by_status(t_graph *graph, t_room_status status)
{
	int		i;

	i = 0;
	while (graph->adj_list[i])
	{
		if (graph->adj_list[i]->status == status)
			return (&graph->adj_list[i]);
		i++;
	}
	return (NULL);
}

/*
**	Search and returns a room by its index
*/

t_node	**search_by_index(t_graph *graph, size_t index)
{
	if (index > graph->nb_vertices)
		return (NULL);
	else
		return (&graph->adj_list[index]);
}

/*
**	Returns 1 if room occupied, 0 if room is free
*/

int		is_room_occupied(t_graph *graph, t_node *room)
{
	t_node	*tmp;

	tmp = *search_by_index(graph, room->room_index);
	return (tmp->occupied);
}
