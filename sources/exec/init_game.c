#include "cub3d.h"

void load_textures(t_data *data)
{
    int bpp;
    int size_line;
    int endian;

    data->north_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->north_texture,
                                                    &data->north_texture.width, &data->north_texture.height);
    data->north_texture.data = (int *)mlx_get_data_addr(data->north_texture.img, &bpp, &size_line, &endian);

    data->south_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->south_texture,
                                                    &data->south_texture.width, &data->south_texture.height);
    data->south_texture.data = (int *)mlx_get_data_addr(data->south_texture.img, &bpp, &size_line, &endian);

    data->west_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->west_texture,
                                                   &data->west_texture.width, &data->west_texture.height);
    data->west_texture.data = (int *)mlx_get_data_addr(data->west_texture.img, &bpp, &size_line, &endian);

    data->east_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->east_texture,
                                                   &data->east_texture.width, &data->east_texture.height);
    data->east_texture.data = (int *)mlx_get_data_addr(data->east_texture.img, &bpp, &size_line, &endian);
    if (!data->north_texture.img || !data->south_texture.img ||
        !data->west_texture.img || !data->east_texture.img)
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
    init_player(&data->player, data->config);
}

void init_player(t_player *player, t_config *config)
{
    // j'ajoute 0.5 ici pour etre bien au centre de la case
    player->x = config->player_x + 0.5;
    player->y = config->player_y + 0.5;
    if (config->player_orientation == 'N')
    {
        player->dirX = 0;
        player->dirY = -1;
        player->planeX = 0.66;
        player->planeY = 0;
    }
    else if (config->player_orientation == 'S')
    {
        player->dirX = 0;
        player->dirY = 1;
        player->planeX = -0.66;
        player->planeY = 0;
    }
    else if (config->player_orientation == 'E')
    {
        player->dirX = 1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = 0.66;
    }
    else if (config->player_orientation == 'W')
    {
        player->dirX = -1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = -0.66;
    }
}