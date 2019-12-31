/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:00:10 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/31 21:30:25 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	equally_spread_ants(t_paths **roads, int nb_ants, int **flow)
{
	int 		i;
	int			result;
	int			rest;
	i = 0;
	result = nb_ants;
	while (i < (*roads)->nb_paths)
	{
		result += (*roads)->paths[i]->distance;
		i++;
	}
	rest = result % (*roads)->nb_paths;
	result /= (*roads)->nb_paths;
	i = 0;
	while (i < (*roads)->nb_paths)
	{
		(*flow)[i] = result - (*roads)->paths[i]->distance;
		i++;
	}
	return (rest);
}

int			*spread_ants(t_paths **roads, int nb_ants)
{
	int			*flow;
	int			i;
	int			rest;
	int			tmp = 0;

	if (!(flow = (int*)ft_memalloc(sizeof(int) * ((*roads)->nb_paths + 1))))
		ft_malloc_error();
	rest = equally_spread_ants(roads, nb_ants, &flow);
	while (flow[(*roads)->nb_paths - 1] <= 0)
	{
		rest += flow[(*roads)->nb_paths - 1];
		(*roads)->nb_paths--;
	}
	i = 0;
	tmp = (rest < 0) ? -1 : 1;
		printf("coucou %d\n", (*roads)->nb_paths);
	while (rest)
	{
		if (!(tmp == -1 && flow[i] <= 0))
		{
			flow[i] += tmp; 
			rest -= tmp;
		}
		i++;
		if (i == (*roads)->nb_paths)
			i = 0;
	}
	return (flow);
}

void	print_flow(t_paths *roads, int *flow)
{
	int		i;
	t_node	*tmp;
	i = 0;
	while (i < roads->nb_paths)
	{
		printf("nb fourmis %d pour path n`%d -> ", flow[i], i);
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