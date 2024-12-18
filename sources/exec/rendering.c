/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:10 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 02:43:40 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	render_ceiling(t_data *data, int x, int draw_start)
{
	int	y;
	int	color;

	color = rgb_to_hex(data->config.ceiling_color[0],
			data->config.ceiling_color[1], data->config.ceiling_color[2]);
	y = 0;
	while (y < draw_start)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		y++;
	}
}

void	render_floor(t_data *data, int x, int draw_end)
{
	int	y;
	int	color;

	y = draw_end + 1;
	color = rgb_to_hex(data->config.floor_color[0], data->config.floor_color[1],
			data->config.floor_color[2]);
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		y++;
	}
}

void	render_column(t_data *data, t_ray *ray, int x)
{
	t_draw		draw;
	t_texture	*current_texture;
	double		perp_wall_dist;
	double		wall_x;

	perp_wall_dist = calculate_perp_wall_dist(data, ray);
	draw.line_height = (int)(WIN_HEIGHT / perp_wall_dist);
	calculate_draw_limits(&draw, WIN_HEIGHT);
	current_texture = select_texture(data, ray);
	render_ceiling(data, x, draw.draw_start);
	wall_x = calculate_wall_x(data, ray, perp_wall_dist);
	calculate_tex_x(&draw, ray, current_texture, wall_x);
	draw_column(data, x, &draw, current_texture);
	render_floor(data, x, draw.draw_end);
}
