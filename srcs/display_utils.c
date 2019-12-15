/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:36:26 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/15 20:50:18 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_end_map_list(t_map **first, char *data)
{
	t_map	*tmp;

	tmp = *first;
	if (*first == NULL)
	{
		if (!(*first = ft_memalloc(sizeof(t_map))))
			ft_malloc_error();
		(*first)->data = ft_strdup(data);
		(*first)->next = NULL;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = ft_memalloc(sizeof(t_map))))
		ft_malloc_error();
	tmp->next->data = ft_strdup(data);
	tmp->next->next = NULL;
	return ;
}

void	print_map(t_map **display_map)
{
	t_map	*tmp;

	while (*display_map)
	{
		ft_putendl((*display_map)->data);
		tmp = *display_map;
		*display_map = (*display_map)->next;
		free(tmp->data);
		// free(tmp);
	}
}

