/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_free_graph.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:31:00 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:26:39 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Creates an empty graph
*/

t_graph	*create_empty_graph(int vertices)
{
	t_graph		*graph;
	int			i;

	if (!(graph = (t_graph *)ft_memalloc(sizeof(t_graph))))
		ft_malloc_error();
	if (!(graph->adj_list = ft_memalloc((vertices + 1) * sizeof(t_node *))))
		ft_malloc_error();
	graph->nb_vertices = vertices;
	i = 0;
	while (i < vertices)
	{
		graph->adj_list[i] = NULL;
		i++;
	}
	return (graph);
}

/*
**	Free a graph
*/

void	free_graph(t_graph **graph)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	if (!*graph || !graph)
		return ;
	while (i < (*graph)->nb_vertices)
	{
		tmp = (*graph)->adj_list[i];
		free_node_list(&tmp);
		i++;
	}
	free((*graph)->adj_list);
	free(*graph);
}

/*
**	s
*/

void	free_paths(t_paths **paths_to_free)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	if (!(*paths_to_free) || !paths_to_free)
		return ;
	if ((*paths_to_free)->paths)
	{
		while ((*paths_to_free)->paths[i])
		{
			tmp = (*paths_to_free)->paths[i];
			free_node_list(&tmp);
			i++;
		}
		free((*paths_to_free)->paths);
	}
	free(*paths_to_free);
}
