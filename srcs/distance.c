/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:28:46 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/26 22:07:04 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_distance(t_graph *graph, t_node **room, int distance)
{
	t_node *tmp;
	
	if ((*room)->distance != -1 && (*room)->distance <= distance)
		return ;
	(*room)->distance = distance;
	tmp = *room;
	while(tmp)
	{
		calc_distance(graph, search_by_name(graph, tmp->name_room), distance + 1);
		tmp = tmp->next;
	}
}
