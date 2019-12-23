/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 12:05:46 by clboutry          #+#    #+#             */
/*   Updated: 2019/12/23 16:36:34 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_same(char *tab, char *search)
{
	int	i;
	int cmpt;

	i = 0;
	cmpt = 0;
	while (tab[i])
	{
		if (search[cmpt] != tab[i])
			cmpt = 0;
		else
			cmpt++;
		if (search[cmpt] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_rest(char *tab, char *now)
{
	int		i;
	int		cmpt;
	char  res[100];

	i = 0;
	cmpt = 0;
	while (tab[i])
	{
		if (now[cmpt] != tab[i])
			cmpt++;
		else
			cmpt = 0;
		if (now[cmpt] == '\0' && tab[i + 1] == '\0')
		{
			cmpt = i - cmpt;
			i = 0;
			while(i < cmpt)
			{
				res[i] = tab[i];
				i++;
			}
			res[i] = '\0';
			return (res);
		}
		if (now[cmpt] == '\0' && tab[i + 1] != '\0')
		{
			cmpt = 0;
			while (tab[i + 1] != '\0')
			{
				res[cmpt] = tab[i];
				cmpt++;
				i++;
			}
		}
		i++;
	}
	res[i] = '\0'';
	return (*res);
}

void	ft_path(int	max, char ** av, char *step)
{
	char update[100];
	char *now;
	int		x;
	int		y;

	x = 0;
	y = 0;
	now = step;
	while (ft_same(now, "END") != 1)
	{
		while (av[x])
		{
			if (ft_same(av[x], now) == 1)
			{
				ft_path(max, av, ft_rest(av[x], now));
			}
			x++;
		}
		return (0);
	}

	return (update);
}

int		main(int ac, char **av)
{
	int		cmpt_x;
	int		cmpt_y;
	int		*num;
	char	**tab_path;
	int		nbr_max_path;
	int		i;

	i = 0;
	nbr_max_path = 0;
	cmpt_x = 0;
	cmpt_y = 0;
	while (av[cmpt_x])
	{
		i += ft_same(av[cmpt_x], "START");
		nbr_max_path += ft_same(av[cmpt_x], "END");
		cmpt_x++;
	}
	if (i < nbr_max_path)
		nbr_max_path = i;
	i = 0;
	printf("%d\n", nbr_max_path);
	if (!(tab_path = (malloc((nbr_max + 1) * (sizeof(char*))))))
		return (0);
	ft_path(nbr_max_path, av, "START");
	return (0);
}
