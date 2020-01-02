/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:28:46 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:11:49 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	For each rooms of a graph, calculate the distance from End
*/

void		calc_distance(t_graph **graph, t_node **room, int distance)
{
	t_node	*tmp;

	if ((*room)->distance != -1 && (*room)->distance <= distance)
		return ;
	(*room)->distance = distance;
	tmp = *room;
	while (tmp)
	{
		if (!(is_room_occupied(*graph, tmp)))
			calc_distance(graph, search_by_index(*graph, tmp->room_index),
			distance + 1);
		tmp = tmp->next;
	}
}

/*
**	Compares the distance from End of 2 rooms
**	Returns room with shortest distance
*/

t_node		*comp_distance(t_graph *graph, int best, int to_cmp)
{
	t_node	*best_room;
	t_node	*to_cmp_room;

	best_room = *search_by_index(graph, best);
	to_cmp_room = *search_by_index(graph, to_cmp);
	if (best_room->distance > to_cmp_room->distance)
		return (to_cmp_room);
	else
		return (best_room);
}

/*
**	Reset all distances to 0
*/

void		reset_distance(t_graph **graph)
{
	int	i;

	i = 0;
	while ((*graph)->adj_list[i])
	{
		(*graph)->adj_list[i]->distance = -1;
		i++;
	}
}

/*
**	Returns adjencency room that is closest to end, if it's unoccupied
*/

t_node		*search_closest_room(t_graph *graph, t_node **room)
{
	t_node		*closest;
	t_node		*tmp;

	tmp = *room;
	closest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(is_room_occupied(graph, tmp)))
			closest = comp_distance(graph, closest->room_index,
						tmp->room_index);
		tmp = tmp->next;
	}
	if (closest->room_index == (*room)->room_index)
		return (NULL);
	return (closest);
}
