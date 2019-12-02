/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:01:06 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/16 21:35:16 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (*needle == 0)
		return (char*)(haystack);
	while (haystack[k] && k != len)
	{
		while (haystack[i] && i != len)
		{
			j = haystack[i] == needle[j] ? j + 1 : 0;
			if (ft_strlen(needle) == j)
				return (char*)(haystack + (i - j + 1));
			i++;
		}
		j = 0;
		k++;
		i = k;
	}
	return (NULL);
}
