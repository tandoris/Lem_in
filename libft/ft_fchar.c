/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 23:55:26 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/07 12:30:02 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	returns 1 if int c found once in string line, else returns 0
*/

int		ft_fchar(const char *line, int c)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}
