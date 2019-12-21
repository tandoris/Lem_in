/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:31:14 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/21 16:52:20 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Free a single node
*/

void	free_node(t_node **node)
{
	// printf("name room : %s\n", (*node)->name_room);
	ft_memdel((void**)&((*node)->name_room));
	free(*node);
}

/*
**	Free a whole linked list
*/

void	free_node_list(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = *node;
		*node = (*node)->next;
		free_node(&tmp);
	}
}

/*
**	Free a graph
*/

void	free_graph(t_graph **graph)
{
	int		i;
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

void	free_t_map_node(t_map **display_map)
{
	free((*display_map)->data);
	free(*display_map);
}

void	free_t_map_list(t_map **display_map)
{
	t_map	*tmp;

	while  (*display_map)
	{
		tmp = *display_map;
		*display_map = (*display_map)->next;
		free_t_map_node(&tmp);
	}
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	free(tab);
}
