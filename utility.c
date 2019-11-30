/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:36:19 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/30 18:50:01 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node  *create_node(int v)
{
    t_node      *new_node;

    if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
        return NULL;
    new_node->vertex = v;
    new_node->next = NULL;
    return (new_node);
}

t_graph *create_graph(int vertices)
{
    t_graph     *graph;
    int            i;

    if (!(graph = (t_graph *)ft_memalloc(sizeof(t_graph))))
        return NULL;
    if (!(graph->adj_list = ft_memalloc(vertices * sizeof(t_node *))))
        return NULL;
    graph->nb_vertices = vertices;
    i = 0;
    while (i < vertices)
    {
        graph->adj_list[i] = NULL;
        i++;
    }
    return graph;
}

void    add_edge(t_graph *graph, int src, int dest)
{
    t_node  *new_node;

    new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

void    print_graph(t_graph *graph)
{
    int     v;

    // v = 0;
    for (v = 0; v < graph->nb_vertices; v++)
    {
        t_node *tmp;
        tmp = graph->adj_list[v];
        printf("\n Adjacency list of vertex %d\n ", v) ;
        while (tmp)
        {
            printf("%d -> ", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
        // v++;
    }
}

int     main()
{
    t_graph *graph;

    // printf("Bonjour\n");
    graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 6);
    add_edge(graph, 5, 1);
    add_edge(graph, 5, 6);

    // printf("Ici\n");
    print_graph(graph);
    // printf("La\n");        
    return (0);
}