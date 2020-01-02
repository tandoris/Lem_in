/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:53:40 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/01 20:46:15 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	returns ERROR and exit
*/

void	ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

/*
**	returns malloc ERROR and exit
*/

void	ft_malloc_error(void)
{
	ft_putendl_fd("ERROR : cannot allocate memory", 2);
	exit(0);
}

/*
**	free graph, free display_map, returns ERROR and exit
*/

void	ft_free_and_exit(t_graph **graph, t_map **display_map)
{
	if (graph && *graph)
		free_graph(graph);
	if (display_map && *display_map)
		free_t_map_list(display_map);
	ft_error();
}
