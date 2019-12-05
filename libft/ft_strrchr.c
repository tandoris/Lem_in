/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:57:56 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/16 21:25:35 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*string;
	size_t		i;
	char		cc;
	long		size;

	string = (char*)s;
	i = 0;
	cc = c;
	size = ft_strlen(s);
	while (size >= 0)
	{
		if (string[size] == cc)
			return (string + size);
		size--;
	}
	if (cc == '\0')
		return (string + size);
	return (NULL);
}
