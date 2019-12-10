/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/10 20:22:35 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("ERROR : cannot allocate memory", 2);
	exit(0);
}

// TODO : mettre is_number dans libft
int			is_number(char *str) 
{
	if (str[0] == '-')
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

/*
**	Cherche et renvoie le nombre de fourmis. ERROR si fourmis n'existe pas.
*/

unsigned int		get_num_ants(char *line)
{
	unsigned int	ants;
	int				ret;

	if ((ret = get_next_line(0, &line)) > -1)
	{
		if (is_number(line) == 1)
		{
			ants = ft_atoi(line);
			return (ants);
		}
		else
		{
			ft_putendl("ERROR");
			exit(0);
		}
	}
	ft_putendl("ERROR");
	exit(0);
	return (0);
}

/*
**	Retourne l'enum correspondant a une salle
*/

t_room_status	identify_room_status(char *buf)
{
	if (!(ft_strcmp(buf, "##start")))
		return (START_ROOM);
	else if (!(ft_strcmp(buf, "##end")))
		return (END_ROOM);
	else
		return (NORMAL);
}

int		nb_elem_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
**	Identifier si line est un tube Si oui, retourne tableau malloque, si non NULL
*/

char	**identify_tube(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, '-'))
	{
		tab = ft_strsplit(line, '-');
		if (nb_elem_tab(tab) == 2)
			return (tab);
		// ft_memdel((void **)tab);
	}
	return NULL;
}

/*
**	Identifier si line est une room. Si oui, retourne tableau malloque, si non NULL
*/

char	**identify_room(char *line)
{
	char	**tab;

	tab = NULL;
	if (ft_strchr(line, ' '))
	{
		tab = ft_strsplit(line, ' ');
		if ((nb_elem_tab(tab)) == 3)
			return (tab);
		ft_memdel((void **)tab);		
	}
	return NULL;
}

/*
**	Identifier si line est un comment qui n'est pas start ou end(return 1) ou non (0).
*/

unsigned int	identify_comment(char *line)
{
	if (ft_strchr(line, '#'))
		return (1);
	return (0);
}

/*
**	Rajoute les infos d'une room dans un graphe
*/

// void		fill_room(t_graph **graph, char **tab, t_room_status status)
// {
// 	static int i = 0;
	
// 	(*graph)->adj_list[i] = create_room(*tab[0], ft_atoi(*tab[1]), ft_atoi(*tab[2]));
// 	(*graph)->adj_list[i]->status = status;
// 	i++;
// }

int		get_list_length(t_node *list)
{
	int			i;
	t_node		*tmp;

	i = 0;
	tmp = list;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	fill_room(t_node **first, char **tab, t_room_status status)
{
	t_node		*new_node;

	new_node = create_room(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
	new_node->status = status;
	add_end_list(*first, new_node);
}

void	put_rooms_in_graph(t_graph **graph, t_node **first)
{
	int		i;
	int		len;
	t_node	*tmp;

	i = 0;
	len = get_list_length(*first); // TODO len = 0 SA MERE
	printf("prout : %d\n", len);
	*graph = create_empty_graph(len);
	while (i < len)
	{
		(*graph)->adj_list[i] = duplicate_room(*first);
		tmp = *first;
		*first = (*first)->next;
		free(tmp);
		i++;
	} 
}

/*
**	Lis la map sur l'entree standard (pas fini)
*/

t_graph		*get_infos(void)
{
	t_graph		*graph;
	char		*line;
	int			ret;
	int			vertices;
	char		**tab_room;
	char		**tab_tube;
	t_node 		*tmp;
	t_room_status status;

	tmp = NULL;
	vertices = 0;
	graph = NULL;
	line = NULL;
	status = NORMAL;
	if (!get_num_ants(line))
		return NULL;
	while ((ret = get_next_line(0, &line)) > 0 && (identify_room(line) || identify_comment(line)))
	{
		if ((tab_room = identify_room((line))))
		{
			fill_room(&tmp, tab_room, NORMAL);
		}
		else if (identify_comment(line))
		{
			if ((status = identify_room_status(line)))
			{
				if (get_next_line(0, &line) > 0 && (tab_room = identify_room(line)) != NULL)
					fill_room(&tmp, tab_room, status); // fill room
				else
					break ;
			}
		}
		else
			break ;
	}
	put_rooms_in_graph(&graph, &tmp);
	while ((ret = get_next_line(0, &line)) > 0 && (identify_tube(line) || identify_comment(line)))
	{
		if ((tab_tube = identify_tube(line)))
			add_tube(&graph, tab_tube[0], tab_tube[1]); // fill tube
		else if (identify_comment(line))
			;
		else
			break ;
	}
	return (graph);
}

int		main(void)
{
	get_infos();
	return (0);
}

/*
Recuperer nb fourmi

TANT QUE (gnl && (est_une_salle || est_un_com))
	FAIRE
		SI salle = les trucs des salles  
		SINON commentaire
FIN

TANT QUE (gnl && (est_un_tube || est_un_com))
	FAIRE
		SI tube = les trucs des tubes  
		SINON commentaire
FIN

FIN PARSING
DEBUT ALGO
*/
