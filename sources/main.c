#include "cub3d.h"

int main(int argc, char **argv)
{
    (void)argv;
    t_data data;
    if (argc != 2)
        return (printf("Error\nUsage: ./cub3D <map_file.cub>\n"), 1);
    init_game(&data);
    mlx_loop(data.mlx_ptr);
}
