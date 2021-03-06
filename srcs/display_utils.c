/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:36:26 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/22 17:02:28 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Add a node at the end of display linked list
*/

void	add_end_map_list(t_map **first, char *data)
{
	t_map	*tmp;

	if (*first == NULL)
	{
		if (!(*first = ft_memalloc(sizeof(t_map))))
			ft_malloc_error();
		(*first)->data = ft_strdup(data);
		(*first)->next = NULL;
		return ;
	}
	tmp = *first;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = ft_memalloc(sizeof(t_map))))
		ft_malloc_error();
	tmp->next->data = ft_strdup(data);
	tmp->next->next = NULL;
	return ;
}

/*
**	Print linked list containing map
*/

void	print_map(t_map **display_map)
{
	t_map	*tmp;

	tmp = *display_map;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}
