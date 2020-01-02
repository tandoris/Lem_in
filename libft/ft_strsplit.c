/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:19:15 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/21 19:03:03 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_free_all(char ***tab)
{
	int		i;

	i = 0;
	if (!*tab)
		return (NULL);
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	return (NULL);
}

static size_t	ft_words_count(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = -1;
	words = 0;
	while (++i < ft_strlen(s))
		words = (s[i] != c && (!i || s[i - 1] == c)) ? words + 1 : words;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;
	size_t	y;

	if (s == NULL || !c)
		return (NULL);
	words = ft_words_count(s, c);
	if ((tab = malloc(sizeof(char*) * (words + 1))) == NULL)
		return (ft_free_all(&tab));
	i = -1;
	words = -1;
	while (s[++i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			y = i;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			tab[++words] = ft_strsub(s, y, i - y + 1);
			if (!tab[words])
				return (ft_free_all(&tab));
		}
	}
	tab[words + 1] = NULL;
	return (tab);
}
