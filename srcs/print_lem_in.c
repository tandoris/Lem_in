/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:18:00 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/30 14:40:13 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	count_actual_paths(size_t nb_paths, size_t *flow)
{
	size_t		i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < nb_paths)
	{
		if (flow[i])
			count++;
		i++;
	}
	return (count);
}

static size_t	*flow_cpy(size_t *src)
{
	size_t	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if(!(dst = (size_t *)ft_memalloc(sizeof(size_t) * i)))
		ft_malloc_error();
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}

static size_t	put_pioneers(t_paths *roads, size_t *flow_max, size_t stationary)
{
	size_t	road_index;

	(void)flow_max;
	road_index = 0;
	while (road_index < roads->nb_paths && stationary > 0)
	{
		roads->paths[road_index]->ant = stationary;
		roads->paths[road_index]->prev_ant = 1;
		stationary--;
		if (roads->paths[road_index]->visitors >= flow_max[road_index])
			break ;
		road_index++;
	}
	return (road_index);
}

void	print_lem_in(t_paths *roads, size_t *flow, size_t nb_ants)
{
	size_t		i;
	int			tour;
	size_t		*flow_max;
	size_t		arrived_ants;
	size_t		stationary;

	i = 0;
	flow_max = flow_cpy(flow);
	printf("\n");
	arrived_ants = 0;
	tour = 0;
	roads->nb_paths = count_actual_paths(roads->nb_paths, flow);
	stationary = nb_ants - put_pioneers(roads, flow_max, nb_ants);
	while (nb_ants > arrived_ants)
	{
		i = 0;
		while (i < roads->nb_paths && arrived_ants < nb_ants)
		{
			arrived_ants += print_one_trip(&roads->paths[i], tour, nb_ants, flow_max[i]);
			flow[i] = flow_max[i] - roads->paths[i]->visitors;
			i++;
		}
		stationary -= put_pioneers(roads, flow_max, stationary);
		printf("\n");
		tour++;
	}
}

size_t	print_one_trip(t_node **path, int duration, int nb_ants, size_t flow)
{
	t_node		*tmp;
	int			i;
	size_t		arrived_ants;
	size_t		tmp_name;
	int			len;

	i = 0;
	tmp = *path;
	len = tmp->distance;
	arrived_ants = 0;
	tmp_name = 0;
	i = 0;
	while (tmp && i <= duration)
	{
		if (tmp->visitors < flow || tmp->status == END_ROOM)
		{
			if (tmp->status == END_ROOM)
				arrived_ants++;
			print_one_move(nb_ants - tmp->ant, tmp->name_room);
			tmp->visitors++;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *path;
	while (tmp)
	{
		if (tmp->next)
		{
			tmp->next->prev_ant = tmp->ant;
		}
		tmp->ant = tmp->prev_ant;
		tmp = tmp->next;
	}
	return (arrived_ants);
}

size_t	print_one_move(size_t ant_name, char *room)
{
	printf("L%zu-%s ", ant_name + 1, room);
	return (1);
}
