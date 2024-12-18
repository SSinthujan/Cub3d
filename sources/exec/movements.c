/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:19 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 02:47:15 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->config.map[(int)(data->player.y)][(int)(data->player.x
			+ data->player.dirX * movespeed)] != '1')
		data->player.x += data->player.dirX * movespeed;
	if (data->config.map[(int)(data->player.y + data->player.dirY
			* movespeed)][(int)(data->player.x)] != '1')
		data->player.y += data->player.dirY * movespeed;
}

void	move_backward(t_data *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->config.map[(int)(data->player.y)][(int)(data->player.x
			- data->player.dirX * movespeed)] != '1')
		data->player.x -= data->player.dirX * movespeed;
	if (data->config.map[(int)(data->player.y - data->player.dirY
			* movespeed)][(int)(data->player.x)] != '1')
		data->player.y -= data->player.dirY * movespeed;
}

void	move_left(t_data *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->config.map[(int)(data->player.y)][(int)(data->player.x
			- data->player.planeX * movespeed)] != '1')
		data->player.x -= data->player.planeX * movespeed;
	if (data->config.map[(int)(data->player.y - data->player.planeY
			* movespeed)][(int)(data->player.x)] != '1')
		data->player.y -= data->player.planeY * movespeed;
}

void	move_right(t_data *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->config.map[(int)(data->player.y)][(int)(data->player.x
			+ data->player.planeX * movespeed)] != '1')
		data->player.x += data->player.planeX * movespeed;
	if (data->config.map[(int)(data->player.y + data->player.planeY
			* movespeed)][(int)(data->player.x)] != '1')
		data->player.y += data->player.planeY * movespeed;
}

void	rotate_left(t_data *data)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(rotspeed) - data->player.dirY
		* sin(rotspeed);
	data->player.dirY = olddirx * sin(rotspeed) + data->player.dirY
		* cos(rotspeed);
	oldplanex = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(rotspeed)
		- data->player.planeY * sin(rotspeed);
	data->player.planeY = oldplanex * sin(rotspeed) + data->player.planeY
		* cos(rotspeed);
}
