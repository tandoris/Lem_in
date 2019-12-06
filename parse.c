/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:47:20 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/06 20:05:03 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			ants = ft_atoi(&line);
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

unsigned int	identify_start_or_end(char *buf)
{
	if (!(ft_strcmp(buf, "##start")) || !(ft_strcmp(buf, "##end")))
		return (1);
	else
		return (0);
}

/*
int		check_line(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (0);
	}
	if (!(identify_start_or_end))
	{
		free(line);
		return (0);
	}
	return (1);
}
*/

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
	if (ft_strchr(&line, '-'))
	{	
		tab = ft_strsplit(&line, '-');
		if ((nb_elem_tab(tab)) == 2)
			return (tab);
		ft_memdel((void **)tab);
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
	if (ft_strchr(&line, ' '))
	{
		tab = ft_strsplit(&line, ' ');
		if ((nb_elem_tab(tab)) == 3)
			return (tab);
		ft_memdel((void **)tab);		
	}
	return NULL;
}

/*
**	Identifier si line est un comment (return 1) ou non (0).
*/

unsigned int	identify_comment(char *line)
{
	if (ft_strchr(&line, '#'))
		return (1);
	return (0);
}

/*
**	Rajoute les infos d'une room dans un graphe
*/

void		fill_room(t_graph *graph, char **tab)
{
	int		i;

	i = 0;
	graph->adj_list[i] = create_room(*tab[0], ft_atoi(*tab[1]), ft_atoi(*tab[2]));
}

/*
**	Lis la map sur l'entree standard (pas fini)
*/

t_graph		*get_infos(t_node *nodes)
{
	t_graph	*graph;
	char	*line;
	int		ret;
	int		vertices;
	char	**tab;

	line == NULL;
	if (!(get_num_ants))
		return NULL;
	while (ret == get_next_line(0, &line) > 0 && (identify_room(line) || identify_comment(line)))
	{
		if (tab = identify_room((line)))
			fill_room(graph, tab);
		else if (identify_comment(line))
		{
			if (identify_start_or_end)
			{
				// TODO Fonction fill_start_or_end (quelle structure faire ?)
			}
		}
		else
			break ;
	}
	while (ret == get_next_line(0, &line) > 0 && (identify_tube(line) || identify_comment(line)))
	{
		if (tab = identify_tube(line))
			add_tube(&graph, *tab[0], *tab[1]);
		else if (identify_comment(line))
		{
			if (identify_start_or_end)
				// TODO pareil qu'en haut
		}
		else
			break ;
	}
	return (graph) ;
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
