/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/10/23 14:59:25 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *str)
{
	int c;

	c = ft_strcmp(ft_strchr(str, '.'), ".cub");
	if (c)
	{
		ft_printf("Error: Map name\n");
		return (c);
	}
	return (0);
}

