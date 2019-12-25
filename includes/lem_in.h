/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:32 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/25 17:26:00 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

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
	char			*name_room;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct		s_graph
{
	int				nb_vertices;
	struct s_node	**adj_list;
}					t_graph;

typedef struct		s_map
{
	char			*data;
	struct s_map	*next;
}					t_map;

/*
**	Utility functions
*/

int					is_number(char *str);
int					nb_elem_tab(char **tab);
int					get_list_length(t_node *list);
void				add_end_list(t_node	**room, t_node *new_cnx);
void				ft_error(void);
void				ft_malloc_error(void);
long long			ft_atoilong(const char *nptr);

/*
**	Utility graph functions
*/

t_node				*create_room(char *name, int x, int y);
int					add_tube(t_graph **graph, char *src, char *dest);
t_graph				*create_empty_graph(int vertices);
void				add_end_list(t_node **room, t_node *new_cnx);
t_node				*duplicate_room(t_node *room_src);

/*
**	Utility display functions
*/

void				add_end_map_list(t_map **first, char *data);
void				print_map(t_map **display_map);

/*
**	Parse functions
*/

size_t				get_num_ants(char *line, t_map **display_map);
t_room_status		identify_room_status(char *buf);
int					nb_elem_tab(char **tab);
char				**identify_tube(char *line);
char				**identify_room(char *line);
unsigned int		identify_comment(char *line);
int					fill_room(t_node **first, char **tab, t_room_status status);
void				put_rooms_in_graph(t_graph **graph, t_node **first);
int					get_tubes(t_graph **graph, char *line, t_map **display_map);
int					get_rooms(t_graph **graph, char **line,
								t_map **display_map);
t_graph				*get_infos(void);
int					no_duplicate_tube(t_node *room, t_node *to_check);
t_node				*find_existing_room(t_graph **graph, char *src);
int					read_rooms(char **line, t_map **display_map, t_node **tmp,
								t_room_status *status);
int					read_tubes(t_graph **graph, char **line,
								t_map **display_map, char **tab_tube);

/*
**	Free Functions
*/

void				free_node(t_node **node);
void				free_node_list(t_node **node);
void				free_graph(t_graph **graph);
void				free_tab(char **tab);
void				free_t_map_node(t_map **display_map);
void				free_t_map_list(t_map **display_map);

/*
**	Functions to be deleted
*/

void				print_graph(t_graph *graph);

#endif
