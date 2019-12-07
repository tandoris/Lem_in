/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:32 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/07 20:27:30 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*
**	structure enum état de la salle. NORMAL = 0, START_ROOM = 1, END_ROOM = 2
*/
typedef enum		e_room_status
{
	NORMAL, START_ROOM, END_ROOM
}					t_room_status;					

/*
**	Liste d'adjacence (structure liste chainee pour une salle)
*/

typedef struct		s_node
{
	t_room_status	status;
	char			*name_room;		// nom de la salle
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
t_graph 			*create_empty_graph(int vertices);
void				print_graph(t_graph *graph);
void				add_end_list(t_node	*room, t_node *new_cnx);
t_node				*duplicate_room(t_node *room_src);

/*
**	Parse functions
*/

unsigned int		get_num_ants(char *line);
t_room_status		identify_room_status(char *buf);
int					nb_elem_tab(char **tab);
char				**identify_tube(char *line);
char				**identify_room(char *line);
unsigned int		identify_comment(char *line);
void				fill_room(t_graph *graph, char **tab, t_room_status status);
#endif