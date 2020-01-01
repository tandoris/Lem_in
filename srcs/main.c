/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/01 15:13:58 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph		*new_graph;
	t_paths		*paths;
	int			*flow;
	t_map		*display_map;
	size_t		i;

	display_map = NULL;
	new_graph = get_infos(&display_map);
	// printf("Algo begins\n");
	// print_graph(new_graph);
	// opti_rooms(&new_graph);
	// printf("OPTI begins\n");
	printf("lloo\n");
	if (!(paths = find_all_paths(&new_graph)))
		ft_free_and_exit(&new_graph, &display_map);
			printf("au revoir\n");
	flow = spread_ants(&paths, new_graph->ants);
	printf("chatte\n");
	// print_flow(paths, flow);

	print_map(&display_map);
	free_t_map_list(&display_map);

	i = 0;
	if (paths->paths[0]->status == END_ROOM)
	{
		printf("\n");
		while (i < new_graph->ants)
		{
			print_one_move(i, paths->paths[0]->name_room);
			i++;
		}
		printf("\n");
	}
	else
		print_lem_in(paths, flow, new_graph->ants);
	// print_graph(new_graph);
	free_graph(&new_graph);
	free_paths(&paths); //ca change rien, revoir fonction free ?
	free(flow);
	return (0);
}
