/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 17:05:51 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		start_end_print(int nb_ants, t_paths *paths)
{
	int		i;

	i = 0;
	print_buffer("\n", 1);
	while (i < nb_ants)
	{
		print_one_move(i, paths->paths[0]->name_room);
		i++;
	}
	print_buffer("\n", 1);
}

int				main(void)
{
	t_graph		*new_graph;
	t_paths		*paths;
	long int	*flow;
	t_map		*display_map;

	display_map = NULL;
	new_graph = get_infos(&display_map);
	if (!(paths = find_all_paths(&new_graph)))
		ft_free_and_exit(&new_graph, &display_map);
	flow = spread_ants(&paths, new_graph->ants);
	print_map(&display_map);
	free_t_map_list(&display_map);
	if (paths->paths[0]->status == END_ROOM)
		start_end_print(new_graph->ants, paths);
	else
		print_lem_in(paths, flow, new_graph->ants);
	print_buffer(NULL, 0);
	free_graph(&new_graph);
	free_paths(&paths);
	free(flow);
	return (0);
}
