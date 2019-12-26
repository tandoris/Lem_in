/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/26 22:33:11 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph		*new_graph;
	t_node		**tmp;

	new_graph = get_infos();
	printf("Algo begins\n");
	tmp = search_by_status(new_graph, END_ROOM);
	// if (tmp)
	// {
	// 	printf("retour search status : %s\n", tmp->name_room);
	// 	printf("retour search name_room : %d\n", (search_by_name(new_graph, "prout")->x));
	// }
	calc_distance(new_graph, tmp, 0);
	printf("paths nb : %zu\n", count_paths(new_graph));
	print_graph(new_graph);
	free_graph(&new_graph);
	return (0);
}
