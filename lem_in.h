/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:32 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/02 20:37:22 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*
**	Liste d'adjacence (structure liste chainee pour une salle)
*/

typedef struct		s_node
{
	char			*name_room;		// nom de la salle
	int				vertex;			// index salle
	int				x;				// coord x
	int				y;				// coord y
	struct s_node	*next;			// next
}					t_node;

typedef struct 		s_graph
{
	int				nb_vertices;	// nombre total de salles dans graphe
	struct s_node	**adj_list;		// tableau de listes chaines
}					t_graph;


/*
**	Utility graph functions
*/

t_node  *create_node(int v);
t_graph *create_graph(int vertices);
void    add_edge(t_graph *graph, int src, int dest);

#endif