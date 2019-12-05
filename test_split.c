/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:50:29 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/02 17:23:45 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	char 		**tab;
	const char	*string;
	int			i;
	int			ct;

	i = 0;
	ct = 0;
	string = "moncul 5 9";
	tab = ft_strsplit(string, ' ');
	while (tab[i])
	{
		printf("%s ", tab[i]);
		i++;
		ct++;
	}
	printf("\n%d\n", ct);
	return (0);
}