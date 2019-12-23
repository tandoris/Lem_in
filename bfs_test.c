/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:48:32 by clboutry          #+#    #+#             */
/*   Updated: 2019/12/19 16:31:28 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int			main(int ac, char **av)
{
	char	**names;
	int		ants;
	int		num_ants;
	int		cmpt;
	int		cmpt2;
	int		*path;
	int		cmpt3;

	cmpt3 = 0;
	cmpt = -1;
	if (!(names = malloc((ac) * (sizeof(char*)))))
		return (0);
	names[ac][0] = '\0';
	if (!(path = malloc((ac) * (sizeof(int)))))
		return (0);
	while (++cmpt < ac)
		path[cmpt] = -1;
	path[cmpt] = '\0';
	num_ants = 1;
	cmpt = 0;
	cmpt2 = 0;
	ants = 25;
	while (av[cmpt + 1])
	{
		while (av[cmpt + 1][cmpt2])
			cmpt2++;
		if (!(names[cmpt] = malloc((cmpt2 + 1) * (sizeof(char)))))
			return (0);
		cmpt2 = -1;
		while (av[cmpt + 1][++cmpt2])
			names[cmpt][cmpt2] = av[cmpt + 1][cmpt2];
		names[cmpt][cmpt2] = '\0';
		cmpt2 = 0;
		cmpt++;
	}
	cmpt = 0;
	cmpt2 = 0;
	while (ants != 0)
	{
		while (cmpt < ac - 1)
		{
			if (cmpt == 0)
			{
				cmpt2 = path[cmpt + 1];
				cmpt3 = path[cmpt + 1];
				path[cmpt + 1] = path[cmpt];
				path[cmpt] = num_ants;
				num_ants  += 1;
				ants--;
			}
			else
			{
				 cmpt2 = path[cmpt + 1];
				 path[cmpt + 1] = cmpt3;
				 cmpt3 = cmpt2;
			}
			cmpt++;
		}
		cmpt = 0;
		while (cmpt < ac - 1)
		{
			if (path[cmpt] != -1)
				printf("L%d-%s ", path[cmpt], names[cmpt]);
			cmpt++;
		}
		if (cmpt == ac - 1)
		{
			if (path[cmpt] != -1)
				printf("L%d-end\n", cmpt2 );
		}
		cmpt = 0;
	}
	return (0);
}
