/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:03:17 by lboukrou          #+#    #+#             */
/*   Updated: 2017/12/17 15:07:59 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	s_size;
	long	n_cp;
	char	*str;

	n_cp = n;
	s_size = ((n < 0) || !n) ? 1 : 0;
	while (n_cp)
	{
		n_cp /= 10;
		s_size++;
	}
	n_cp = n;
	if ((str = malloc(sizeof(char) * (s_size + 1))) == NULL)
		return (NULL);
	if (!n)
		str[0] = '0';
	str[s_size] = 0;
	while (n_cp)
	{
		str[s_size-- - 1] = n_cp < 0 ? (n_cp * -1) % 10 + '0' : n_cp % 10 + '0';
		n_cp /= 10;
	}
	if (n < 0 && n)
		str[0] = '-';
	return (str);
}
