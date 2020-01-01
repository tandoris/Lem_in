/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:11:05 by lboukrou          #+#    #+#             */
/*   Updated: 2020/01/01 23:10:59 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long long	ft_atoilong(const char *nptr)
{
	size_t		i;
	long long	retour;
	long long	negatif;

	i = 0;
	negatif = 1;
	retour = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\r') ||
			(nptr[i] == '\f') || (nptr[i] == '\v') || (nptr[i] == '\t'))
		i++;
	if (nptr[i] == '-')
		negatif = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		retour *= 10;
		retour += nptr[i] - '0';
		i++;
		if (retour > 9223372036854775807)
			return (negatif == -1 ? 0 : -1);
	}
	return (retour * negatif);
}

int			is_number(char *str)
{
	if (!str)
		return (0);
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

int			nb_elem_tab(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			get_list_length(t_node *list)
{
	int			i;
	t_node		*tmp;

	if (!list)
		return (0);
	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
**	Adds new connexion at the end of a room
*/

void		add_end_list(t_node **room, t_node *new_cnx)
{
	t_node	*tmp;

	tmp = *room;
	if (*room == NULL)
	{
		*room = new_cnx;
		return ;
	}
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_cnx;
}
