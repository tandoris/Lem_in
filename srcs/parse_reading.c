/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:22:28 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/02 21:38:02 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Reads tubes and put it in graph
*/

int		get_tubes(t_graph **graph, char *line, t_map **display_map)
{
	int		ret;
	char	**tab_tube;

	if ((tab_tube = identify_tube(line))
		&& add_tube(graph, tab_tube[0], tab_tube[1]))
	{
		add_end_map_list(display_map, line);
		free_tab(tab_tube);
		free(line);
	}
	else
	{
		free_tab(tab_tube);
		free(line);
		return (0);
	}
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!read_tubes(graph, &line, display_map, tab_tube))
			return (0);
	}
	return (1);
}

int		read_tubes(t_graph **graph, char **line, t_map **display_map,
					char **tab_tube)
{
	if (identify_comment(*line) && !(identify_room_status(*line)))
	{
		if ((*line - ft_strstr(*line, "##") || (*line)[2] == '#'))
			add_end_map_list(display_map, *line);
		free(*line);
	}
	else if ((tab_tube = identify_tube(*line))
			&& add_tube(graph, tab_tube[0], tab_tube[1]))
	{
		add_end_map_list(display_map, *line);
		free(*line);
		free_tab(tab_tube);
	}
	else
	{
		free(*line);
		free_tab(tab_tube);
		return (0);
	}
	return (1);
}

/*
**	Read rooms, put it in tmp linked list, then in graph
*/

int		get_rooms(t_graph **graph, char **line, t_map **display_map)
{
	int				ret;
	int				ret_fill_room;
	t_node			*tmp;
	t_room_status	status;

	tmp = NULL;
	status = NORMAL;
	ret_fill_room = 1;
	while (ret_fill_room && (ret = get_next_line(0, line)) > 0)
	{
		if ((ret_fill_room = read_rooms(line, display_map,
										&tmp, &status)) == -1)
		{
			ret_fill_room = 1;
			break ;
		}
	}
	if (!(put_rooms_in_graph(graph, &tmp)))
	{
		if (ret > 0 && ret_fill_room)
			free(*line);
		ft_free_and_exit(graph, display_map);
	}
	return (ret == 0 ? 0 : ret_fill_room);
}

int		read_rooms(char **line, t_map **display_map, t_node **tmp,
					t_room_status *status)
{
	char			**tab_room;
	int				ret_fill_room;

	ret_fill_room = 1;
	if ((tab_room = identify_room(*line)))
	{
		if ((ret_fill_room = fill_room(tmp, tab_room, *status)))
			add_end_map_list(display_map, *line);
		*status = NORMAL;
		free(*line);
		free_tab(tab_room);
	}
	else if (identify_comment(*line))
	{
		if (identify_room_status(*line) != NORMAL)
			*status = identify_room_status(*line);
		if (identify_room_status(*line) || (*line - ft_strstr(*line, "##")
										|| (*line)[2] == '#'))
			add_end_map_list(display_map, *line);
		free(*line);
	}
	else
		return (-1);
	return (ret_fill_room);
}
