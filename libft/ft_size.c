/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 01:50:56 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/07 12:40:25 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finds size of string when c is met, returns it.
** Otherwise returns size of string.
*/

#include <unistd.h>

size_t		ft_size(const char *line, int c)
{
	size_t		i;

	i = 0;
	while (line[i] != c && line[i] != '\0')
		i++;
	return (i);
}
