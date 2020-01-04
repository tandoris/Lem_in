/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:00:10 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 22:39:21 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	equally_spread_ants(t_paths **roads, int nb_ants, long int **flow)
{
	int			i;
	long int	result;
	int			rest;

	i = 0;
	if (!(*flow = (long int*)ft_memalloc(sizeof(long int)
		* ((*roads)->nb_paths + 1))))
		ft_malloc_error();
	result = nb_ants;
	while (i < (*roads)->nb_paths)
	{
		result += (*roads)->paths[i]->distance;
		i++;
	}
	rest = result % (*roads)->nb_paths;
	result /= (long int)(*roads)->nb_paths;
	i = 0;
	while (i < (*roads)->nb_paths)
	{
		(*flow)[i] = result - (*roads)->paths[i]->distance;
		i++;
	}
	return (rest);
}

long int	*spread_ants(t_paths **roads, int nb_ants)
{
	long int	*flow;
	int			i;
	int			rest;
	int			tmp;

	flow = NULL;
	rest = equally_spread_ants(roads, nb_ants, &flow);
	while (flow[(*roads)->nb_paths - 1] <= 0)
	{
		rest += flow[(*roads)->nb_paths - 1];
		(*roads)->nb_paths--;
	}
	i = 0;
	tmp = (rest < 0) ? -1 : 1;
	while (rest)
	{
		if (!(tmp == -1 && flow[i] <= 0))
		{
			flow[i] += tmp;
			rest -= tmp;
		}
		i++;
		i = (i == (*roads)->nb_paths) ? 0 : i;
	}
	return (flow);
}
