/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:32 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/04 19:39:58 by lboukrou         ###   ########.fr       */
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
	// int				vertex;			// index salle 
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

t_node				*create_room(char *name, int x, int y);
void				add_tube(t_graph **graph, char *src, char *dest);
t_graph 			*create_graph(int vertices);
void				print_graph(t_graph *graph);
void				add_end_list(t_node	*room, t_node *new_cnx);
t_node	*duplicate_room(t_node *room_src);

#endif