/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:22:57 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/30 23:20:01 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void init_parse(t_config *config)
// {
//     config->north_texture = "./textures/wall1.xpm";
//     config->south_texture = "./textures/wall3.xpm";
//     config->west_texture = "./textures/wall2.xpm";
//     config->east_texture = "./textures/wall4.xpm";

//     config->floor_color[0] = 220;   // Floor color: RGB(220, 100, 0)
//     config->floor_color[1] = 100;
//     config->floor_color[2] = 0;

//     config->ceiling_color[0] = 225; // Ceiling color: RGB(225, 30, 0)
//     config->ceiling_color[1] = 30;
//     config->ceiling_color[2] = 0;

//     config->map_width = 14;
//     config->map_height = 3;

//     config->player_x = 1;            // Player's initial X position (grid-based)
//     config->player_y = 1;            // Player's initial Y position (grid-based)
//     config->player_orientation = 'N'; // Player is facing North

//     config->map = malloc(sizeof(char *) * (config->map_height + 1)); // +1 si vous voulez terminer par NULL

//     if (!config->map)
//     {
//         fprintf(stderr, "Error\nMemory allocation failed for map\n");
//         exit(EXIT_FAILURE);
//     }

//     // Affectation des lignes de la carte (normalement faites pendant le parsing)
//     config->map[0] = strdup("11111111111111");
//     config->map[1] = strdup("1N000000000001");
//     config->map[2] = strdup("11111111111111");
//     config->map[3] = NULL; // Si vous terminez par NULL
//     //print_config(config);

// };

// int main(int argc, char **argv)
// {
//     (void)argv;
//     t_data data = {0};
//     data.movement = (t_movement){0, 0, 0, 0, 0, 0};
//     if (argc != 2)
//         return (printf("Error\nUsage: ./cub3D <map_file.cub>\n"), 1);
//     init_parse(&data.config);
//     init_game(&data, argv[1]);
//     handle_keyhook(&data);
//     mlx_loop_hook(data.mlx_ptr, game_loop, &data);
//     mlx_loop(data.mlx_ptr);
//     return (0);
// }

// void print_config(t_data *cub)
// {
// 	int i = 0;
// 	printf("ceiling :");
// 	while(i < 3)
// 	{
// 		printf("%d", cub->config.ceiling_color[i]);
// 		printf(",");
// 		i++;
// 	}
// 	printf("\n");
// 	i = 0;
// 	printf("floor :");
// 	while(i < 3)
// 	{
// 		printf("%d", cub->config.floor_color[i]);
// 		printf(",");
// 		i++;
// 	}
// 	printf("\n");
// 	printf("north :%s\n", cub->config.north_texture);
// 	printf("south :%s\n", cub->config.south_texture);
// 	printf("east :%s\n", cub->config.east_texture);
// 	printf("west :%s\n", cub->config.west_texture);
// }

int init_parse(int ac, char **av, t_data *cub)
{
	if (ac != 2)
		return (printf("Error\nFormat: ./cub3D <map_file.cub>\n"), 1);
	if (check_mapname(av[1]))
		return (printf("Error\nMap name incorrect\n"), 1);
	if (check_config(av[1], cub))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	static t_data cub = {0};
	if (init_parse(ac, av, &cub))
		return (1);
	print_config(&cub);
	return (0);
}