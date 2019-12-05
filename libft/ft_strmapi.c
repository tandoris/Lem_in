/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:40:17 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/15 16:38:34 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	size_t			i;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((string = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		string[i] = (*f)(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
