/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:18:00 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 17:26:38 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_buffer(char *str, size_t len)
{
	static char buf[BUFFER_SIZE];
	static int	index = 0;
	size_t	i;

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

static long int	*flow_cpy(long int *src)
{
	long int		*dst;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if(!(dst = (long int *)ft_memalloc(sizeof(long int) * i)))
		ft_malloc_error();
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}

static int	put_pioneers(t_paths *roads, long int *flow_max, int stationary)
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
	return (road_index);
}

void	print_lem_in(t_paths *roads, long int *flow, int nb_ants)
{
	int			i;
	int			tour;
	long int	*flow_max;
	int			arrived_ants;
	int			stationary;

	i = 0;
	flow_max = flow_cpy(flow);
	print_buffer("\n", 1);		
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
		print_buffer("\n", 1);
		tour++;
	}
	free(flow_max);
}

int		print_one_trip(t_node **path, int duration, int nb_ants, long int flow)
{
	t_node		*tmp;
	int			i;
	int			arrived_ants;
	int			len;

	i = 0;
	tmp = *path;
	len = tmp->distance;
	arrived_ants = 0;
	i = 0;
	while (tmp && i <= duration)
	{
		if (tmp->visitors < flow)
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


int	print_one_move(size_t ant_name, char *room)
{
	char *nbr;

	nbr = ft_itoa((int)ant_name + 1);
	print_buffer("L", 1);
	print_buffer(nbr, ft_strlen(nbr));
	print_buffer("-", 1);
	print_buffer(room, ft_strlen(room));
	print_buffer(" ", 1);
	free(nbr);
	return (1);
}