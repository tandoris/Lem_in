/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:18:00 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/28 22:56:53 by lboukrou         ###   ########.fr       */
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

void	print_lem_in(t_paths *roads, size_t *flow, size_t nb_ants)
{
	size_t		i;
	size_t		gone_ants;
	int			tour;
	size_t		*flowMax;

	flowMax = flow_cpy(flow);
	printf("------\n");
	gone_ants = 0;
	tour = 0;
	roads->nb_paths = count_actual_paths(roads->nb_paths, flow);
	while (gone_ants < nb_ants)
	{
		i = 0;
		while (i < roads->nb_paths)
		{
			if (flow[i])
			{
				print_one_trip(&roads->paths[i], (roads->nb_paths), tour, i, flowMax[i]);
				flow[i]--;
				gone_ants++;
			}
			i++;
		}
		printf("\n");
		tour++;
	}
}

void	print_one_trip(t_node **path, int nb_paths, int duration, int f, size_t flow)
{
	t_node		*tmp;
	int			i;

	i = 0;
	tmp = *path;
	while (tmp && i <= duration)
	{
		if (tmp->visitors != flow || tmp->status == END_ROOM)
		{
			print_one_move((duration - i) * nb_paths + f + 1, tmp->name_room);
			tmp->visitors++;
		}
		tmp = tmp->next;
		i++;
	}
}

void	print_one_move(size_t ant_name, char *room)
{
	printf("L%zu-%s ", ant_name, room);
}