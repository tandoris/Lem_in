/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:00:10 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/30 20:38:51 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*spread_ants(t_paths **roads, int nb_ants)
{
	int			*flow;
	int			i;
	int			result;
	int			rest;
	int			tmp;

	i = 0;
	result = nb_ants;
	if (!(flow = (int*)ft_memalloc(sizeof(int) * ((*roads)->nb_paths + 1))))
		ft_malloc_error();
	while (i < (*roads)->nb_paths)
	{
		result += (*roads)->paths[i]->distance;
		i++;
	}
	rest = result % (*roads)->nb_paths;
	result /= (*roads)->nb_paths;
	// printf("\nmod : %zu -- div : %zu\n", rest, tmp);
	// printf("----\n");
	i = 0;
	while (i < (*roads)->nb_paths)
	{
		// if (tmp <= (size_t)(*roads)->paths[i]->distance)
		// {
		// 	flow[i] = 0;
		// 	(*roads)->nb_paths--;
		// }
		// else
		flow[i] = result - (*roads)->paths[i]->distance;
		// printf("paths[%zu] -> tmp : %zu --  dist : %d  flow : %d\n", i, tmp, (*roads)->paths[i]->distance, flow[i]);
		i++;
	}
	// printf("----\n");
	// printf("rest : %zu\n", rest);
	// i = 0;
	// rest %= (*roads)->nb_paths;
	// printf("rest : %d\n", rest);

	while (flow[(*roads)->nb_paths - 1] <= 0)
	{
		rest += flow[(*roads)->nb_paths - 1];
		// printf("---------- rest : %d\n", rest);

		// flow[(*roads)->nb_paths - 1] = 0;
		(*roads)->nb_paths--;
		// i++;
	}
	tmp = rest % (*roads)->nb_paths;
	// printf("rest : %d && paths nb : %zu\n", rest, (*roads)->nb_paths);
	rest /= (*roads)->nb_paths;
	// printf("rest : %d\n", rest);
	// printf("good/\n");
	// printf("fourmis restantes : %d \n", rest);
	// print_flow(*roads, flow);
	// printf("----\n");
	i = 0;
	while (i < (*roads)->nb_paths)
	{
		// printf("rest : %d - i : %zu \n", rest, i);
		// rest--;
		flow[i] += rest; 
		i++;
	}
	// printf("pas good\n");
	// print_flow(*roads, flow);
	// printf("----\n");
	i = 0;
	tmp = 0;
	while (i < (*roads)->nb_paths)
	{
		if (flow[i] < 0)
		{
			tmp -= flow[i];
			flow[i] = 0;
		}
		i++;
	}

	i = 0;
	// printf("TMP : %d\n", tmp);
	rest = (tmp < 0) ? -1 : 1; 
	while (tmp)
	{
		if (flow[i] > 0)
		{
			flow[i] -= rest;
			tmp--;
		}
		i++;
		if (i == (*roads)->nb_paths)
			i = 0;
	}
	// rest = (tmp < 0) ? -1 : 1; 
	// i = 0;
	// printf("tmp : %d et rest : %d\n", tmp, rest);
	// while (tmp)
	// {
	// 	flow[i] += rest;
	// 	tmp -= rest;
	// 	i++;
	// }
	// if (rest)
	// {
	// 	printf("rest %zu\n", rest);
	// 	ft_error();
	// }
	// printf("fourmis restantes : %d \n", rest);
	// print_flow(*roads, flow);
	// printf("----\n");
	return (flow);
}

void	print_flow(t_paths *roads, int *flow)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < roads->nb_paths)
	{
		printf("nb fourmis %d pour ->", flow[i]);
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