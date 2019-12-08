/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:18:59 by clboutry          #+#    #+#             */
/*   Updated: 2019/12/08 17:01:42 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		nbr_line(int *paths, int ants, int nbr_path)
{
	int		cmpt;
	int		total;
	int		*nbr_ants_path;

	if (!(nbr_ants_path = (malloc((nbr_path + 1) * (sizeof(int))))))
		return (0);
	cmpt = -1;
	total = 0;
	while (++cmpt < nbr_path)
		nbr_ants_path[cmpt] = 0;
	nbr_ants_path[cmpt] = '\0';
	cmpt = 0;
	while (ants > 0)
	{
		total++;
		while (paths[cmpt])
		{
			if (paths[cmpt] <= total && ants > 0)
			{
				ants--;
				nbr_ants_path[cmpt] += 1;
			}
			cmpt++;
		}
		cmpt = 0;
	}
	cmpt = 0;
	while (cmpt < nbr_path)
	{
		printf("chemin %d, taille %d = %d fourmis\n", cmpt, paths[cmpt],  nbr_ants_path[cmpt]);
		cmpt++;
	}
	return(total);
}

int		main(void)
{
    int		ants;
	int		paths[6];
	int		minimum_line;
	int		nbr_path;

	nbr_path = 5;
	paths[0] = 3;
	paths[1] = 2;
	paths[2] = 2;
	paths[3] = 5;
	paths[4] = 6;
	paths[5] = '\0';
	ants = 7;
	minimum_line = nbr_line(paths, ants, nbr_path);
	printf("nbr de ligne minimum = %d\n", minimum_line);
}
