/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:30:51 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/11 17:20:21 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*zone1;
	unsigned char		*zone2;

	i = 0;
	zone1 = (unsigned char*)s1;
	zone2 = (unsigned char*)s2;
	while (i < n)
	{
		if (zone1[i] != zone2[i])
			return (int)(zone1[i] - zone2[i]);
		i++;
	}
	return (0);
}
