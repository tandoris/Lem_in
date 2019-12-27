/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:48:58 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/27 21:08:15 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph		*new_graph;

	new_graph = get_infos();
	printf("Algo begins\n");
	print_graph(new_graph);
	opti_rooms(&new_graph);
	printf("OPTI begins\n");
	print_graph(new_graph);
	find_all_paths(&new_graph);
	free_graph(&new_graph);
	return (0);
}
