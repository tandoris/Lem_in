/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:11:49 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/11 15:33:09 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*string;
	unsigned char		cc;

	string = (unsigned char*)s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if (string[i] == (cc))
			return (string + i);
		i++;
	}
	return (NULL);
}
