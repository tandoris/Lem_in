/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:14:22 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/10 17:41:29 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		end;

	i = 0;
	end = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[end] = src[i];
		i++;
		end++;
	}
	dest[end] = '\0';
	return (dest);
}
