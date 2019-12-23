/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:47:47 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/11 13:21:27 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*source;
	char		*desti;

	source = (const char*)src;
	desti = (char*)dest;
	i = n;
	if (src < dest)
	{
		while (i > 0)
		{
			desti[i - 1] = source[i - 1];
			i--;
		}
	}
	else if (dest < src)
		ft_memcpy(desti, source, n);
	return (dest);
}
