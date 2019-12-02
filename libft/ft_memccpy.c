/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:11:01 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/10 21:09:35 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				size;
	unsigned char		*first;
	const unsigned char	*second;

	first = (unsigned char*)dest;
	second = (const unsigned char*)src;
	size = 0;
	while (size < n)
	{
		first[size] = (second[size]);
		if (second[size] == (unsigned char)c)
		{
			return (dest + size + 1);
		}
		size++;
	}
	return (NULL);
}
