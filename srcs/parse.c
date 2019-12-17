/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/17 20:54:18 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Cherche et renvoie le nombre de fourmis. ERROR si fourmis n'existe pas.
*/

size_t		get_num_ants(char *line, t_map **display_map)
{
	size_t			ants;
	int				ret;

	if ((ret = get_next_line(0, &line)) > -1)
	{
		if (is_number(line) == 1)
		{
			ants = ft_atoilong(line);
			if (ft_atoilong(line) > 0)
			{	
				add_end_map_list(display_map, line);
				return (ants);
			}
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
	// printf("name_room : %s and room status : %d\n", new_node->name_room, new_node->status);
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
		ft_error();
	*graph = create_empty_graph(len);
	// printf("len : %d\n", len);
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
			// printf("value start : %d, val end : %d\n", start, end);
			ft_error();
		}
}

/*
**	Lis les tubes et les stock dans graph
*/

int		get_tubes(t_graph **graph, char *line, t_map **display_map)
{
	int		ret;
	char	**tab_tube;

	if ((tab_tube = identify_tube(line)) && add_tube(graph, tab_tube[0], tab_tube[1]))
		add_end_map_list(display_map, line);
	else
		return (0);
	while ((ret = get_next_line(0, &line)) > 0 && (identify_tube(line) || identify_comment(line)))
	{
		if (identify_comment(line))
			add_end_map_list(display_map, line);
		else if ((tab_tube = identify_tube(line)) && add_tube(graph, tab_tube[0], tab_tube[1]))
			add_end_map_list(display_map, line);
		else
			return (0);
	}
	return (1);
}

/*
**	Lis les salles et les stock dans la liste chainee tmp, puis dans graph
*/

int		get_rooms(t_graph **graph, char **line, t_map **display_map)
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
		{	
			if ((ret_fill_room = fill_room(&tmp, tab_room, NORMAL)))
				add_end_map_list(display_map, *line);
		}
		else if (identify_comment(*line))
		{
			// printf("\nline : %s\n", *line);
			add_end_map_list(display_map, *line);
			if ((status = identify_room_status(*line)))
			{
				// printf("igdfnidfni\n");
				if (get_next_line(0, line) > 0 && (tab_room = identify_room(*line)) != NULL)
				{	
					if ((ret_fill_room = fill_room(&tmp, tab_room, status)))
						add_end_map_list(display_map, *line);
				}
				else
					break ;
			}
		}
		else
			break ;
	}
	put_rooms_in_graph(graph, &tmp);
	return (ret_fill_room);
}

/*
**	Lis la map sur l'entree standard
*/

t_graph		*get_infos(void)
{
	t_graph		*graph;
	t_node 		*tmp;
	t_map		*display_map;
	char		*line;

	tmp = NULL;
	graph = NULL;
	line = NULL;
	display_map = NULL;
	if (!get_num_ants(line, &display_map))
		ft_error();
	if (get_rooms(&graph, &line, &display_map))
		get_tubes(&graph, line, &display_map);
	print_map(&display_map);
	free(line);
	return (graph);
}

int		main(void)
{
	t_graph		*new_graph;

	new_graph = get_infos();
	print_graph(new_graph);
	free_graph(&new_graph);
	printf("Algo begins\n");
	return (0);
}

