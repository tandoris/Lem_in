/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:29:15 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/25 23:19:27 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*search_by_status(t_graph *graph, t_room_status status)
{
	int		i;

	i = 0;
	while (graph->adj_list[i])
	{
		if (graph->adj_list[i]->status == status)
			return (graph->adj_list[i]);
		i++;
	}
	return (NULL);
}

t_node	*search_by_name(t_graph *graph, char *name)
{
	int		i;

	i = 0;
	while (graph->adj_list[i])
	{
		if (!ft_strcmp(graph->adj_list[i]->name_room, name))
			return (graph->adj_list[i]);
		i++;
	}
	return (NULL);
}
