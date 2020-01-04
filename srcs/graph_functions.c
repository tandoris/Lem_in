/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:01:59 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 22:39:37 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function to create a new room
*/

t_node	*create_room(size_t room_index, char *name, int x, int y)
{
	t_node		*new_node;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		ft_malloc_error();
	new_node->status = NORMAL;
	if (!(new_node->name_room = ft_strdup(name)))
		ft_malloc_error();
	new_node->x = x;
	new_node->y = y;
	new_node->room_index = room_index;
	new_node->distance = -1;
	new_node->occupied = 0;
	new_node->visitors = 0;
	new_node->ant = 0;
	new_node->prev_ant = 0;
	new_node->next = NULL;
	return (new_node);
}

/*
**	Checks if room of name src exists in graph and returns corresponding node
*/

t_node	*find_existing_room(t_graph **graph, char *src)
{
	t_node		*node;
	int			i;

	i = 0;
	node = NULL;
	while ((*graph)->adj_list[i])
	{
		if (!(ft_strcmp(src, (*graph)->adj_list[i]->name_room)))
			node = (*graph)->adj_list[i];
		i++;
	}
	return (node);
}

/*
**	Add tube between 2 rooms
*/

int		add_tube(t_graph **graph, char *src, char *dest)
{
	t_node		*node_1;
	t_node		*node_2;
	int			i;

	i = 0;
	node_1 = find_existing_room(graph, src);
	node_2 = find_existing_room(graph, dest);
	if (node_1 && node_2)
	{
		if (no_duplicate_tube(node_1, node_2)
			&& no_duplicate_tube(node_2, node_1))
		{
			add_end_list(&node_1, duplicate_room(node_2));
			add_end_list(&node_2, duplicate_room(node_1));
		}
		return (1);
	}
	return (0);
}

/*
**	Check if a connexion is already made
*/

int		no_duplicate_tube(t_node *room, t_node *to_check)
{
	t_node	*tmp;

	tmp = room;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name_room, to_check->name_room)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**	Copies a room and returns it
*/

t_node	*duplicate_room(t_node *room_src)
{
	t_node		*room_dest;

	room_dest = NULL;
	if (room_src)
	{
		room_dest = create_room(room_src->room_index, room_src->name_room,
								room_src->x, room_src->y);
		room_dest->status = room_src->status;
		room_dest->distance = room_src->distance;
	}
	return (room_dest);
}
