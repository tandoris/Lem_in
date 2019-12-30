/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/31 00:15:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph		*new_graph;
	t_paths		*paths;
	int			*flow;

	new_graph = get_infos();
	// printf("Algo begins\n");
	// print_graph(new_graph);
	// opti_rooms(&new_graph);
	// printf("OPTI begins\n");
	paths = find_all_paths(&new_graph);
	flow = spread_ants(&paths, new_graph->ants);
	// print_flow(paths, flow);
	print_lem_in(paths, flow, new_graph->ants);
	// print_graph(new_graph);
	free_graph(&new_graph);
	return (0);
}
