/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/29 22:14:19 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph		*new_graph;
	t_paths		*paths;
	size_t		*flow;

	new_graph = get_infos();
	// printf("Algo begins\n");
	// print_graph(new_graph);
	// opti_rooms(&new_graph);
	// printf("OPTI begins\n");
	paths = find_all_paths(&new_graph);
	flow = spread_ants(paths, new_graph->ants);
	// print_flow(paths, flow);
	print_lem_in(paths, flow, new_graph->ants);
	// print_graph(new_graph);
	free_graph(&new_graph);
	return (0);
}

/*
L1-3 L2-2
L1-4 L3-3 L2-5 L4-2
L1-0 L3-4 L2-6 L5-3 L4-5 L6-2
L3-0 L2-0 L5-4 L4-6 L7-3 L6-5 L8-2
L5-0 L4-0 L7-4 L6-6 L9-3 L8-5 L10-2
L7-0 L6-0 L9-4 L8-6 L11-3 L10-5
L9-0 L8-0 L11-4 L10-6 L12-3
L11-0 L10-0 L12-4
L12-0
*/