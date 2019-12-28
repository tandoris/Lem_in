/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:00:10 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/28 17:59:49 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	*spread_ants(t_paths *roads, size_t nb_ants)
{
	// size_t		flow[roads->nb_paths];
	size_t		*flow;
	size_t		i;
	size_t		tmp;
	size_t		rest;

	i = 0;
	tmp = nb_ants;
	if (!(flow = (size_t*)ft_memalloc(sizeof(size_t) * (roads->nb_paths + 1))))
		ft_malloc_error();
	while (i < roads->nb_paths)
	{
		tmp += roads->paths[i]->distance;
		i++;
	}
	rest = tmp % roads->nb_paths;
	tmp /= roads->nb_paths;
	i = 0;
	while (i < roads->nb_paths)
	{
		flow[i] = tmp - roads->paths[i]->distance;
		i++;
	}
	i = 0;
	while (rest > 0)
	{
		rest--;
		flow[i] += 1; 
		i++;
	}
	return (flow);
}

void	print_flow(t_paths *roads, size_t *flow)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	while (i < roads->nb_paths)
	{
		printf("nb fourmis %zu pour ->", flow[i]);
		tmp = roads->paths[i];
		while (tmp)
		{
			printf("%s - ", tmp->name_room);
			tmp = tmp->next;
		}
		i++;
		printf("\n");
	}
}