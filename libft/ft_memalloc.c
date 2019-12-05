/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:56:07 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/13 22:20:04 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*zone;
	size_t	i;

	i = 0;
	zone = NULL;
	if (size != 0)
	{
		if ((zone = (char *)malloc(size)) == NULL)
			return (NULL);
		ft_bzero(zone, size);
	}
	return (zone);
}
