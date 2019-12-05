/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:01:00 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/08 15:24:57 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	size;
	char	*tmp;

	size = 0;
	tmp = (char *)s;
	while (size < n)
	{
		tmp[size] = '\0';
		size++;
	}
}
