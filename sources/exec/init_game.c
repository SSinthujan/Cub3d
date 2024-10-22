#include "cub3d.h"

void init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to initialize MLX\n");
        exit(1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3d");
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to create window\n");
        exit(1);
    }
}