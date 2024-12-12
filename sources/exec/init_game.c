/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:33 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/12 18:17:47 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_textures(t_data *data)
{
    int bpp;
    int size_line;
    int endian;

    data->wall[0].img = mlx_xpm_file_to_image(data->mlx_ptr, data->config.north_texture,
                                                    &data->wall[0].width, &data->wall[0].height);
    // if mlx = 0 free et return error
    data->wall[0].data = (int *)mlx_get_data_addr(data->wall[0].img, &bpp, &size_line, &endian);

    data->wall[1].img = mlx_xpm_file_to_image(data->mlx_ptr, data->config.south_texture,
                                                    &data->wall[1].width, &data->wall[1].height);
    data->wall[1].data = (int *)mlx_get_data_addr(data->wall[1].img, &bpp, &size_line, &endian);

    data->wall[2].img = mlx_xpm_file_to_image(data->mlx_ptr, data->config.west_texture,
                                                   &data->wall[2].width, &data->wall[2].height);
    data->wall[2].data = (int *)mlx_get_data_addr(data->wall[2].img, &bpp, &size_line, &endian);

    data->wall[3].img = mlx_xpm_file_to_image(data->mlx_ptr, data->config.east_texture,
                                                   &data->wall[3].width, &data->wall[3].height);
    data->wall[3].data = (int *)mlx_get_data_addr(data->wall[3].img, &bpp, &size_line, &endian);
    if (!data->wall[0].img || !data->wall[1].img ||
        !data->wall[2].img || !data->wall[3].img)
    {
        printf("Error\nFailed to load textures\n");
        close_window(data);
    }
}

void init_game(t_data *data, char *cub_file)
{
    (void)cub_file;
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to initialize MLX\n");
        close_window(data);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to create window\n");
        close_window(data);
    }
    load_textures(data);
    init_player(&data->player, &data->config);
}

void	set_player_orientation_ns(t_player *player, t_config *config)
{
	if (config->player_orientation == 'N')
	{
		player->dirX = 0;
		player->dirY = -1;
		player->planeX = 0.66;
		player->planeY = 0;
	}
	else
	{
		player->dirX = 0;
		player->dirY = 1;
		player->planeX = -0.66;
		player->planeY = 0;
	}
}

void	set_player_orientation_ew(t_player *player, t_config *config)
{
	if (config->player_orientation == 'E')
	{
		player->dirX = 1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = 0.66;
	}
	else
	{
		player->dirX = -1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = -0.66;
	}
}

void	init_player(t_player *player, t_config *config)
{
	player->x = config->player_x + 0.5;
	player->y = config->player_y + 0.5;
	if (config->player_orientation == 'N' || config->player_orientation == 'S')
		set_player_orientation_ns(player, config);
	else if (config->player_orientation == 'E' || config->player_orientation == 'W')
		set_player_orientation_ew(player, config);
}
