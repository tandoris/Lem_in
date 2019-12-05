/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:56:28 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/15 21:06:01 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		size1;
	size_t		size2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if ((new = ft_strnew(size1 + size2)) == NULL)
		return (NULL);
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	return (new);
}
