/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:18:00 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/29 21:05:38 by lboukrou         ###   ########.fr       */
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

size_t	*flow_cpy(size_t *src)
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

size_t	put_pioneers(t_paths *roads, size_t stationary)
{
	size_t	road_index;

	road_index = 0;
	while (road_index < roads->nb_paths && stationary > 0)
	{
		roads->paths[road_index]->ant = stationary;
		stationary--;
		road_index++;
	}
	return (road_index);
}

void	print_lem_in(t_paths *roads, size_t *flow, size_t nb_ants)
{
	size_t		i;
	// size_t		gone_ants;
	int			tour;
	size_t		*flowMax;
	size_t		arrived_ants;
	size_t		stationary;

	i = 0;
	flowMax = flow_cpy(flow);
	printf("------\n");
	arrived_ants = 0;
	tour = 0;
	roads->nb_paths = count_actual_paths(roads->nb_paths, flow);
	stationary = nb_ants - put_pioneers(roads, nb_ants);
	// while (arrived_ants < nb_ants)
	// {
	// 	i = 0;
	// 	while (i < roads->nb_paths)
	// 	{
	// 		arrived_ants += print_one_trip(&roads->paths[i], roads->nb_paths, tour, i, flowMax[i]);
	// 		flow[i]--;
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	tour++;
	// }
	while (nb_ants != arrived_ants)
	{
		i = 0;
		while (i < roads->nb_paths)
		{
			arrived_ants += print_one_trip(&roads->paths[i], roads->nb_paths, tour, i, flowMax[i]);
			flow[i]--;
			i++;
		}
		stationary -= put_pioneers(roads, stationary);
		printf("\n");
		tour++;
	}
}

void	recurse_forward_and_move(t_node *current, t_node *next, size_t old)
{
	size_t	ant;
	size_t	other;

	if (!next)
		return ;
	ant = next->ant;
	next->ant = current->ant;
	current->ant = old;
	return recurse_back_and_move(next, next->next, old);
}

size_t	print_one_trip(t_node **path, int nb_paths, int duration, int f, size_t flow)
{
	t_node		*tmp;
	int			i;
	size_t		arrived_ants;
	// static size_t ant_name = 1;
	size_t		tmp_name;
	int			len;

	i = 0;
	(void)nb_paths;
	(void)f;
	tmp = *path;
	len = tmp->distance;
	arrived_ants = 0;
	tmp_name = 0;
	// while (tmp)
	// {
	// 	if (tmp->ant == 0)
	// 		tmp->ant = ant_name++;
	// 	else if (tmp->next)
	// 	{
	// 		tmp_name = tmp->next->ant;
	// 		tmp->next->ant = tmp->ant;

	// 	}
	// 	tmp = tmp->next;
	// 	i++;
	// }
	while  (tmp->next->next)
		tmp = tmp->next;
	recurse_back_and_move(tmp->next, tmp, len, 0);
	i = 0;
	tmp = *path;
	while (tmp && i <= duration)
	{
		if (tmp->visitors < flow || tmp->status == END_ROOM)
		{
			if (tmp->status == END_ROOM)
				arrived_ants++;
			print_one_move(tmp->ant, tmp->name_room);
			tmp->visitors++;
		}
		tmp = tmp->next;
		i++;
	}
	return (arrived_ants);
}

size_t	print_one_move(size_t ant_name, char *room)
{
	// if (ant_name)
		printf("L%zu-%s ", ant_name, room);
	return (1);
}