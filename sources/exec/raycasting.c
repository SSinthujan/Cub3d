/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:14 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 02:45:25 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_direction(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y)
			* ray->delta_dist_y;
	}
}

void	initialize_ray(t_data *data, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = data->player.dirX + data->player.planeX * camera_x;
	ray->ray_dir_y = data->player.dirY + data->player.planeY * camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
}

double	calculate_wall_x(t_data *data, t_ray *ray, double perp_wall_dist)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.y + perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.x + perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

void	perform_raycasting(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		initialize_ray(data, &ray, x);
		initialize_delta(&ray);
		define_direction(data, &ray);
		if (perform_dda(data, &ray))
			render_column(data, &ray, x);
		x++;
	}
}
