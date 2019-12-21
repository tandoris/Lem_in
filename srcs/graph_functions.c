/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:01:59 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/21 20:51:02 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function to create a room
*/

t_node	*create_room(char *name, int x, int y)
{
	t_node		*new_node;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		return NULL;
	new_node->status = NORMAL;
	new_node->name_room = ft_strdup(name);
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

/*
**	Add tube between 2 rooms
*/

int		add_tube(t_graph **graph, char *src, char *dest)
{
    t_node *node_1;
    t_node *node_2;
	int		i;

	i = 0;
	node_1 = NULL;
	node_2 = NULL;
	while ((*graph)->adj_list[i])//(i < (*graph)->nb_vertices) // (*graph)->adj_list[i]
	{
		if (!(ft_strcmp(src, (*graph)->adj_list[i]->name_room)))
			node_1 = (*graph)->adj_list[i];
		if (!(ft_strcmp(dest, (*graph)->adj_list[i]->name_room)))
			node_2 = (*graph)->adj_list[i];
        i++;
	}
	if (node_1 && node_2)
	{
		if (no_duplicate_tube(node_1, node_2) && no_duplicate_tube(node_2, node_1))
		{
			add_end_list(&node_1, duplicate_room(node_2));
			add_end_list(&node_2, duplicate_room(node_1));
		}
		return (1);
	}
	return (0);
}

/*
**	Check if a connexion  is already made
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
		room_dest = create_room(room_src->name_room, room_src->x, room_src->y);
	return (room_dest);
}

/*
**	Creates an empty graph
*/

t_graph *create_empty_graph(int vertices)
{
    t_graph		*graph;
    int			i;

    if (!(graph = (t_graph *)ft_memalloc(sizeof(t_graph) )))
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
    return graph;
}

/*
**	Prints a graph
*/

void    print_graph(t_graph *graph)
{
    int     i;

	if (!graph)
		return;
	for (i = 0; i < graph->nb_vertices; i++)
    {
		t_node *tmp;
        tmp = graph->adj_list[i];
        printf("\n Adjacency list of index %d\n ", i) ;
        while (tmp)
        {
            printf("%s -> ", tmp->name_room);
            tmp = tmp->next;
        }
        printf("\n");
		// printf("printgraph\n");
    }
}

