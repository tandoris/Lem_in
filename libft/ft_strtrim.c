/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:33:02 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/16 18:04:19 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			j;
	char			*string;
	size_t			blank;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	blank = 0;
	while (s[i] && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
	{
		i++;
		blank++;
	}
	while (j > 0 && ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')))
	{
		j--;
		blank++;
	}
	if (blank == 0)
		return (ft_strdup(s));
	blank = blank > ft_strlen(s) ? ft_strlen(s) : blank;
	string = ft_strsub(s, i, (ft_strlen(s) - blank));
	return (string);
}
