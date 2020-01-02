/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:29:15 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 14:54:23 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Search and returnns a room by its status
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

t_node	**search_by_index(t_graph *graph, size_t index)
{
	if (index > graph->nb_vertices)
		return (NULL);
	else
		return (&graph->adj_list[index]);
}
