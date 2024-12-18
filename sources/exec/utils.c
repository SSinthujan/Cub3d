/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:00 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 02:46:17 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(-rotspeed) - data->player.dirY
		* sin(-rotspeed);
	data->player.dirY = olddirx * sin(-rotspeed) + data->player.dirY
		* cos(-rotspeed);
	oldplanex = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-rotspeed)
		- data->player.planeY * sin(-rotspeed);
	data->player.planeY = oldplanex * sin(-rotspeed) + data->player.planeY
		* cos(-rotspeed);
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

int	load_textures2(t_data *data)
{
	int	bpp;
	int	size_line;
	int	endian;

	data->wall[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->config.west_texture, &data->wall[2].width,
			&data->wall[2].height);
	if (!data->wall[2].img)
		return (close_window(data, 1), 1);
	data->wall[2].data = (int *)mlx_get_data_addr(data->wall[2].img, &bpp,
			&size_line, &endian);
	data->wall[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->config.east_texture, &data->wall[3].width,
			&data->wall[3].height);
	if (!data->wall[3].img)
		return (close_window(data, 1), 1);
	data->wall[3].data = (int *)mlx_get_data_addr(data->wall[3].img, &bpp,
			&size_line, &endian);
	return (0);
}
