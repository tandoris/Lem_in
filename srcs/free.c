/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:31:14 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/18 16:34:10 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	free_node(t_node *node)
// {
	
// }

void	free_graph(t_graph **graph)
{
	int		i;
	t_node	*tmp;
	t_node	*tmp_2;

	i = 0;
	tmp = NULL;
	if (!*graph || !graph)
		return ;
	while (i < (*graph)->nb_vertices)
	{
		
		// printf("i : %d\n",i);
		tmp = (*graph)->adj_list[i];
		while (tmp)
		{
			// printf("bonjour\n");
			tmp_2 = tmp;
			// printf("\n");
			//printf("name : %s\n", tmp_2->name_room);
			tmp = tmp->next;
			ft_memdel((void**)&(tmp_2->name_room));
			free(tmp_2);
		}
		i++;
	}
	free(*graph);
}