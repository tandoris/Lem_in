/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:31:14 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/31 20:17:00 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Free a single node
*/

void	free_node(t_node **node)
{
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

void	free_t_map_node(t_map **display_map)
{
	free((*display_map)->data);
	free(*display_map);
}

void	free_t_map_list(t_map **display_map)
{
	t_map	*tmp;

	while (*display_map)
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
