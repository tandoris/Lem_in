/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:20:36 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:21:16 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			make_next_move(t_node **path)
{
	t_node		*tmp;

	tmp = *path;
	while (tmp)
	{
		if (tmp->next)
		{
			tmp->next->prev_ant = tmp->ant;
		}
		tmp->ant = tmp->prev_ant;
		tmp = tmp->next;
	}
}

int				print_one_trip(t_node **path, int duration, int nb_ants,
								long int flow)
{
	t_node		*tmp;
	int			i;
	int			arrived_ants;
	int			len;

	i = 0;
	tmp = *path;
	len = tmp->distance;
	arrived_ants = 0;
	i = 0;
	while (tmp && i <= duration)
	{
		if (tmp->visitors < flow)
		{
			if (tmp->status == END_ROOM)
				arrived_ants++;
			print_one_move(nb_ants - tmp->ant, tmp->name_room);
			tmp->visitors++;
		}
		tmp = tmp->next;
		i++;
	}
	make_next_move(path);
	return (arrived_ants);
}

int				print_one_move(size_t ant_name, char *room)
{
	char *nbr;

	nbr = ft_itoa((int)ant_name + 1);
	print_buffer("L", 1);
	print_buffer(nbr, ft_strlen(nbr));
	print_buffer("-", 1);
	print_buffer(room, ft_strlen(room));
	print_buffer(" ", 1);
	free(nbr);
	return (1);
}
