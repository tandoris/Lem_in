/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:53:40 by lboukrou          #+#    #+#             */
/*   Updated: 2019/12/14 18:10:44 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("ERROR : cannot allocate memory", 2);
	exit(0);
}