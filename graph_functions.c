/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:01:59 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/10 20:17:22 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Fonction pour creer une room
*/

t_node	*create_room(char *name, int x, int y)
{
	t_node		*new_node;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		return NULL;
	if (!(new_node->name_room = (char *)ft_memalloc(sizeof(name))))
		return NULL;
	new_node->status = NORMAL;
	new_node->name_room = name;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

/*
**	Fonction pour ajouter un tube entre 2 salles
*/

void	add_tube(t_graph **graph, char *src, char *dest)
{
    t_node *node_1;
    t_node *node_2;

	int		i;
	int		j;
	i = 0;
	j = 0;
	node_1 = NULL;
	node_2 = NULL;
	if (*graph)
		printf("Courgette\n");
	while ((*graph)->adj_list[i])
	{
		printf("Ma bite\n");		
		printf("nom room%s\n", (*graph)->adj_list[i]->name_room);
		if (!(ft_strcmp(src, (*graph)->adj_list[i]->name_room)))
			node_1 = (*graph)->adj_list[i];
		if (!(ft_strcmp(dest, (*graph)->adj_list[i]->name_room)))
			node_2 = (*graph)->adj_list[i];
        i++;
		j++;
	}
	if (node_1 && node_2)
	{
		add_end_list(node_1, duplicate_room(node_2));
		add_end_list(node_2, duplicate_room(node_1));
	}
	else
		ft_error();
}

/*
**	Fonction qui copie le maillon src dans dest. Renvoie maillon dest 
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
**	Fonction pour ajouter une nouvelle connexion a la fin d'une room
*/

void	add_end_list(t_node	*room, t_node *new_cnx)
{
	t_node	*tmp;

	tmp = room;
	if (room == NULL)
	{
		room = new_cnx;
		return ;
	}
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_cnx;
}

/*
**	Fonction pour creer un graphe vide
*/

t_graph *create_empty_graph(int vertices)
{
    t_graph		*graph;
    int			i;

    if (!(graph = (t_graph *)ft_memalloc(sizeof(t_graph) )))
       { printf("ma b\n");
	   	ft_malloc_error();
	   }
    if (!(graph->adj_list = ft_memalloc(vertices * sizeof(t_node *))))
		{
			printf("%d loulou\n", vertices);
			ft_malloc_error();}
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
**	Fonction pour print un graph
*/

void    print_graph(t_graph *graph)
{
    int     i;

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
    }
}

// int		main()
// {
// 	t_graph		*graph;

// 	graph = create_empty_graph(5);
// 	graph->adj_list[0] = create_room("start", 3, 4);
// 	graph->adj_list[1] = create_room("two", 1, 2);
// 	graph->adj_list[2] = create_room("three", 2, 2);
// 	graph->adj_list[3] = create_room("four", 4, 2);
// 	graph->adj_list[4] = create_room("end", 2, 1);
	
// 	add_tube(&graph, "start", "two");
// 	add_tube(&graph, "start", "three");
// 	add_tube(&graph, "start", "four");
// 	add_tube(&graph, "three", "end");
// 	add_tube(&graph, "four", "end");

// 	print_graph(graph);
// 	return (0);
// }