/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:55:26 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/09 17:10:38 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	size_t				i;
	unsigned long long	retour;
	int					negatif;

	i = 0;
	negatif = 1;
	retour = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\r') ||
			(nptr[i] == '\f') || (nptr[i] == '\v') || (nptr[i] == '\t'))
		i++;
	if (nptr[i] == '-')
		negatif = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		retour *= 10;
		retour += (int)nptr[i] - '0';
		i++;
		if (retour > 9223372036854775807)
			return (negatif == -1 ? 0 : -1);
	}
	return (retour * negatif);
}
