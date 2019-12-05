/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:03:45 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/11 21:12:45 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dst_end = i;
	while (size != 0 && i < size - 1 && src[i - dst_end] != '\0')
	{
		dst[i] = src[i - dst_end];
		i++;
	}
	if (size != 0 && i < size)
		dst[i] = '\0';
	return (dst_end + ft_strlen(src));
}
