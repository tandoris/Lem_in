/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:12:00 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/10 15:02:11 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		size;
	char		*tmp;

	size = 0;
	tmp = (char *)s;
	while (size < n)
	{
		tmp[size] = c;
		size++;
	}
	return (s);
}
