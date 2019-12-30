/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/30 14:24:23 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns number of ants, error if it doesn't exist
*/

size_t	get_num_ants(char *line, t_map **display_map)
{
	size_t			ants;
	int				ret;

	if ((ret = get_next_line(0, &line)) > -1)
	{
		if (is_number(line) == 1 && (ft_atoilong(line)) > 0
			&& (ft_atoilong(line)) < INT_MAX)
		{
			ants = ft_atoilong(line);
			add_end_map_list(display_map, line);
			free(line);
			return (ants);
		}
		free(line);
	}
	ft_error();
	return (0);
}

/*
**	Creates room from map's infos, adds it to 'first' linked list
*/

int		fill_room(t_node **first, char **tab, t_room_status status)
{
	t_node			*new_node;
	t_node			*tmp;
	static size_t	room_index = 0;

	tmp = *first;
	new_node = create_room(room_index, tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
	room_index++;
	new_node->status = status;
	while (tmp)
	{
		if (new_node->room_index == tmp->room_index)
		{
			free_node(&new_node);
			return (0);
		}
		tmp = tmp->next;
	}
	add_end_list(first, new_node);
	return (1);
}

/*
**	Copies rooms from 'first' to graph. if !start or !end, returns error
*/

void	put_rooms_in_graph(t_graph **graph, t_node **first)
{
	int		i;
	int		len;
	int		end;
	int		start;
	t_node	*tmp;

	i = -1;
	end = 0;
	start = 0;
	len = get_list_length(*first);
	if (!(tmp = *first) || len == 0)
		ft_error();
	*graph = create_empty_graph(len);
	while (++i < len)
	{
		if (tmp->status == START_ROOM)
			start += 1;
		else if (tmp->status == END_ROOM)
			end += 1;
		(*graph)->adj_list[i] = duplicate_room(tmp);
		tmp = (tmp)->next;
	}
	free_node_list(first);
	if (start != 1 || end != 1)
		ft_error();
}

/*
**	Read map from stdin
*/

t_graph	*get_infos(void)
{
	t_graph		*graph;
	t_map		*display_map;
	char		*line;
	size_t		ants;

	graph = NULL;
	line = NULL;
	display_map = NULL;
	if (!(ants = get_num_ants(line, &display_map)))
		ft_error();
	if (get_rooms(&graph, &line, &display_map))
		get_tubes(&graph, line, &display_map);
	print_map(&display_map);
	free_t_map_list(&display_map);
	graph->ants = ants;
	return (graph);
}
