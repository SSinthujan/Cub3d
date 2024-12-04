/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:13:57 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/30 23:07:39 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_line(t_data *cub, int i)
{
	char	*res;
	int		j;

	res = ft_calloc(1, cub->config.map_width + 1);
	if (!res)
		return (1);
	j = 0;
	while (j < ft_strlen(cub->config.map[i]))
	{
		if (cub->config.map[i][j] == ' ')
			res[j] = '2';
		else
			res[j] = cub->config.map[i][j];
		j++;
	}
	while (j < cub->config.map_width)
		res[j++] = '2';
	cub->config.map[i] = res;
	return (0);
}

void	format_line(t_data *cub, int i)
{
	int	j;

	j = 0;
	while (j < cub->config.map_width)
	{
		if (cub->config.map[i][j] == ' ')
			cub->config.map[i][j] = '2';
		j++;
	}
}

void	pre_format_map(t_data *cub)
{
	int	i;

	i = 0;
	while (cub->config.map[i])
	{
		if (ft_strlen(cub->config.map[i]) < cub->config.map_width)
			new_line(cub, i);
		else
			format_line(cub, i);
		i++;
	}
}

void	format_map(t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->config.map[i])
	{
		j = 0;
		while (cub->config.map[i][j])
		{
			if (cub->config.map[i][j] == '2')
				cub->config.map[i][j] = '1';
			j++;
		}
		i++;
	}
}
