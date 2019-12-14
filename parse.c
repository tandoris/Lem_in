/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/14 20:51:20 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Cherche et renvoie le nombre de fourmis. ERROR si fourmis n'existe pas.
*/

size_t		get_num_ants(char *line)
{
	size_t			ants;
	int				ret;

	if ((ret = get_next_line(0, &line)) > -1)
	{
		if (is_number(line) == 1)
		{
			ants = ft_atoilong(line);
			if (ft_atoilong(line) > 0)
				return (ants);
		}
		else
			ft_error();
	}
	ft_error();
	return (0);
}

/*
**	Met les infos lues dans la map en t_node et l'ajoute dans une liste chainee
*/

int		fill_room(t_node **first, char **tab, t_room_status status)
{
	t_node		*new_node;
	t_node		*tmp;

	tmp = *first;
	new_node = create_room(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
	new_node->status = status;
	while (tmp)
	{
		if (!(ft_strcmp(new_node->name_room, tmp->name_room)))
			return (0);
		tmp = tmp->next;
	}
	add_end_list(first, new_node);
	printf("name_room : %s\n", new_node->name_room);
	return (1);
}

/*
**	 Duplique les salles de first dans graph. Si !start ou !end, renvoie erreur
*/

void	put_rooms_in_graph(t_graph **graph, t_node **first)
{
	int		i;
	int		len;
	int		end;
	int		start;
	t_node	*tmp;

	i = 0;
	end = 0;
	start = 0;
	len = get_list_length(*first);
	if (!*first || len == 0)
	{	printf("Bonjour put rooms\n");
		ft_error();}
	*graph = create_empty_graph(len);
	while (i < len)
	{
		if ((*first)->status == START_ROOM)
			start += 1;
		else if ((*first)->status == END_ROOM)
			end += 1;
		(*graph)->adj_list[i] = duplicate_room(*first);
		tmp = *first;
		*first = (*first)->next;
		free(tmp);
		i++;
	}
	if (start != 1 || end != 1)
		{
			
			printf("valu start : %d, val end : %d\n", start, end);
			ft_error();
		}
}

/*
**	Lis les tubes et les stock dans graph
*/

void	get_tubes(t_graph **graph, char *line)
{
	int		ret;
	char	**tab_tube;

	if ((tab_tube = identify_tube(line)) && add_tube(graph, tab_tube[0], tab_tube[1]))
		;
	else
		return ;
	while ((ret = get_next_line(0, &line)) > 0 && (identify_tube(line) || identify_comment(line)))
	{
		if (identify_comment(line))
			;
		else if ((tab_tube = identify_tube(line)) && add_tube(graph, tab_tube[0], tab_tube[1]))
			;
		else
			break ;
	}
}

/*
**	Lis les salles et les stock dans la liste chainee tmp, puis dans graph
*/

int		get_rooms(t_graph **graph, char **line)
{
	int				ret;
	int				ret_fill_room;
	char			**tab_room;
	t_node			*tmp;
	t_room_status	status;
	
	tmp = NULL;
	status = NORMAL;
	ret_fill_room = 1;
	while (ret_fill_room && (ret = get_next_line(0, line)) > 0 && (identify_room(*line) || identify_comment(*line)))
	{
		if ((tab_room = identify_room(*line)))
			ret_fill_room = fill_room(&tmp, tab_room, NORMAL);
		else if (identify_comment(*line))
		{
			if ((status = identify_room_status(*line)))
			{
				if (get_next_line(0, line) > 0 && (tab_room = identify_room(*line)) != NULL)
					ret_fill_room = fill_room(&tmp, tab_room, status);
				else
					break ;
			}
		}
		else
			break ;
	}
	put_rooms_in_graph(graph, &tmp);
	printf("valeur rest_fill_room : %d\n", ret_fill_room);
	return (ret_fill_room);
}

/*
**	Lis la map sur l'entree standard
*/

t_graph		*get_infos(void)
{
	t_graph		*graph;
	t_node 		*tmp;
	char		*line;

	tmp = NULL;
	graph = NULL;
	line = NULL;
	if (!get_num_ants(line))
		ft_error();
	if (get_rooms(&graph, &line))
		get_tubes(&graph, line);
	return (graph);
}

int		main(void)
{
	get_infos();
	printf("Algo begins\n");
	// print_graph(get_infos());
	return (0);
}

