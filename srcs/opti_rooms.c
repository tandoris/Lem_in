/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:23:42 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/27 21:23:01 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns int i that counts number of rooms occupied in a room and its connexions
*/

static int	how_many_free_rooms(t_graph *graph, t_node *room)
{
	int			i;
	t_node		*tmp;

	if (!room)
		return (0);
	i = 0;
	tmp = room;
	while (tmp)
	{
		if (!(*search_by_name(graph, tmp->name_room))->occupied)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
**	Set rooms having 2 or less free connexions to occupied 
**	(rooms that won't be used in algo)   
*/

void	opti_rooms(t_graph **graph)
{
	int			i;
	int			len;
	int			mark;

	mark = 1;
	while (mark)
	{
		i = 0;
		mark = 0;
		while ((*graph)->adj_list[i])
		{
			len = how_many_free_rooms(*graph, (*graph)->adj_list[i]);
			if (len <= 2 && !(*graph)->adj_list[i]->status && !(*graph)->adj_list[i]->occupied)
			{
				(*graph)->adj_list[i]->occupied = 1;
				mark = 1;
			}
			i++;
		}
	}
}