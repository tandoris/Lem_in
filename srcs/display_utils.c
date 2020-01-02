/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:36:26 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/01 20:57:00 by lboukrou         ###   ########.fr       */
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
		if (!((*first)->data = ft_strdup(data)))
			ft_malloc_error();
		(*first)->next = NULL;
		return ;
	}
	tmp = *first;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = ft_memalloc(sizeof(t_map))))
		ft_malloc_error();
	if (!(tmp->next->data = ft_strdup(data)))
		ft_malloc_error();
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
		print_buffer(tmp->data, ft_strlen(tmp->data));
		print_buffer("\n", 1);
		tmp = tmp->next;
	}
}
