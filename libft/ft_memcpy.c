/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:22:48 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/10 16:21:53 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		size;
	char		*first;
	const char	*second;

	first = (char*)dest;
	second = (const char*)src;
	size = 0;
	while (size < n)
	{
		first[size] = second[size];
		size++;
	}
	return (dest);
}
