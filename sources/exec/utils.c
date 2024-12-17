/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:00 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/17 22:34:10 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

// void	free_map(t_config *config)
// {
// 	int i;

// 	if (config->map)
// 	{
// 		i = 0;
// 		while (i < config->map_height)
// 		{
// 			free(config->map[i]);
// 			i++;
// 		}
// 		free(config->map);
// 	}
// }

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	else
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	rotate_right(t_data *data)
{
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;

	rotSpeed = 0.05;
	oldDirX = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY
		* sin(-rotSpeed);
	data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY
		* cos(-rotSpeed);
	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-rotSpeed)
		- data->player.planeY * sin(-rotSpeed);
	data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY
		* cos(-rotSpeed);
}

void	initialize_delta(t_ray *ray)
{
	if (ray->ray_dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	else
		ray->delta_dist_x = fabs(1 / 0.0001);
	if (ray->ray_dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	else
		ray->delta_dist_y = fabs(1 / 0.0001);
}

int	perform_dda(t_data *data, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= data->config.map_height
			|| ray->map_x < 0 || ray->map_x >= data->config.map_width
			|| data->config.map[ray->map_y][ray->map_x] == '1')
			return (1);
	}
}
