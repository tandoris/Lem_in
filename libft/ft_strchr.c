/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 23:01:11 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/12 15:37:17 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		*string;
	int			i;
	char		cc;

	string = (char*)s;
	i = 0;
	cc = c;
	while (string[i] != '\0')
	{
		if (string[i] == cc)
			return (string + i);
		i++;
	}
	if (cc == '\0')
		return (string + i);
	return (NULL);
}
