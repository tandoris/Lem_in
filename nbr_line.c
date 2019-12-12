/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:18:59 by clboutry          #+#    #+#             */
/*   Updated: 2019/12/12 15:19:52 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int 	*sort_list(int	*path)
{
	int		cmpt;
	int		bridge;

	cmpt = 0;
	bridge = 0;
	while (path[cmpt] != '\0')
	{
		if (path[cmpt] > path[cmpt + 1] && path[cmpt + 1] != '\0')
		{
			bridge = path[cmpt + 1];
			path[cmpt + 1] = path[cmpt];
			path[cmpt] = bridge;
			cmpt = -1;
		}
		cmpt++;
	}
	return (path);
}

int		nbr_line(int *paths, int ants, int nbr_path, int *nbr_ants_path)
{
	int		cmpt;
	int		total;

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
	int		*paths;
	int		minimum_line;
	int		nbr_path;
	int		*nbr_ants_path;
	char	**path_name;
	int		cmpt;

	cmpt = 0;
	nbr_path = 5;
	if (!(paths = malloc((nbr_path + 1) * (sizeof(int))))) 
		return (0);
	if (!(path_name = malloc((nbr_path + 1) * (sizeof(char*)))))
		return (0);
	paths[0] = 9;
	paths[1] = 86;
	paths[2] = 25;
	paths[3] = 15;
	paths[4] = 6;
	paths[5] = '\0';
	ants = 54;
	while (cmpt < nbr_path)
	{
		if (!(path_name[cmpt] = malloc((paths[cmpt]) * (sizeof(char)))))
			return (0);
		cmpt++;
	}
	sort_list(paths);
	minimum_line = nbr_line(paths, ants, nbr_path, nbr_ants_path);
	printf("nbr de ligne minimum = %d\n", minimum_line);
	printf("chemin %d taille %d = %d fourmis\n", 4, paths[4], nbr_ants_path[4]);
}
