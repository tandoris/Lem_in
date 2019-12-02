/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:32:06 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/10 16:41:49 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[end] = src[i];
		i++;
		end++;
	}
	dest[end] = src[i];
	return (dest);
}
