/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:18:00 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:21:21 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_buffer(char *str, size_t len)
{
	static char buf[BUFFER_SIZE];
	static int	index = 0;
	size_t		i;

	if (!str)
	{
		write(1, buf, index);
		ft_bzero(buf, BUFFER_SIZE);
		index = 0;
		return ;
	}
	i = 0;
	while (i < len)
	{
		buf[index] = str[i];
		index++;
		if (index == BUFFER_SIZE)
		{
			write(1, buf, index);
			ft_bzero(buf, BUFFER_SIZE);
			index = 0;
		}
		i++;
	}
}

static size_t	count_actual_paths(size_t nb_paths, long int *flow)
{
	size_t	i;
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

static int		put_pioneers(t_paths *roads, long int *flow_max, int stationary)
{
	int	road_index;

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
	print_buffer("\n", 1);
	return (road_index);
}

static long int	*flow_cpy(long int *src)
{
	long int		*dst;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (!(dst = (long int *)ft_memalloc(sizeof(long int) * i)))
		ft_malloc_error();
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}

void			print_lem_in(t_paths *roads, long int *flow, int nb_ants)
{
	int			i;
	int			tour;
	long int	*flow_max;
	int			arrived_ants;
	int			stationary;

	i = 0;
	flow_max = flow_cpy(flow);
	arrived_ants = 0;
	tour = 0;
	roads->nb_paths = count_actual_paths(roads->nb_paths, flow);
	stationary = nb_ants - put_pioneers(roads, flow_max, nb_ants);
	while (nb_ants > arrived_ants)
	{
		i = -1;
		while (++i < roads->nb_paths && arrived_ants < nb_ants)
		{
			arrived_ants += print_one_trip(&roads->paths[i], tour,
												nb_ants, flow_max[i]);
			flow[i] = flow_max[i] - roads->paths[i]->visitors;
		}
		stationary -= put_pioneers(roads, flow_max, stationary);
		tour++;
	}
	free(flow_max);
}
