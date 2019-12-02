/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:24 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/15 15:42:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	index;
	size_t			longueur;

	if (s == NULL)
		return (NULL);
	index = 0;
	longueur = 0;
	string = NULL;
	if ((string = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (longueur < len)
	{
		string[index] = s[start];
		start++;
		longueur++;
		index++;
	}
	string[index] = '\0';
	return (string);
}
