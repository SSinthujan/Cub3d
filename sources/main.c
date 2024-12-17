/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:22:57 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/16 04:25:39 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_parse2(int ac, char **av, t_data *cub)
{
	if (ac != 2)
		return (printf("Error\nFormat: ./cub3D <map_file.cub>\n"), 1);
	if (check_mapname(av[1]))
		return (printf("Error\nMap name incorrect\n"), 1);
	if (check_config(av[1], cub))
		return (1);
	return (0);
}

// static char	*lines[4] = {"11111111111111", "1N000000000001", "11111111111111",
// 		NULL};

void	init_parse(t_data *cub)
{
	cub->config.map_width = 14;
	cub->config.map_height = 3;
	cub->config.player_x = 1;
		// Player's initial X position (grid-based)
	cub->config.player_y = 1;
		// Player's initial Y position (grid-based)
	cub->config.player_orientation = 'N'; // Player is facing North
	// config->map = malloc(sizeof(char *) * (config->map_height + 1)); //
		// +1 si vous voulez terminer par NULL
	// if (!config->map)
	// {
	//     fprintf(stderr, "Error\nMemory allocation failed for map\n");
	//     exit(EXIT_FAILURE);
	// }
	// Affectation des lignes de la carte (normalement faites pendant le parsing)
	// cub->config.map = check_map(cub);
	// print_config(config);
}

// int	main(int ac, char **av)
// {
// 	static t_data	cub = {0};

// 	if (init_parse2(ac, av, &cub))
// 		return (1);
// 	init_parse(&cub); // finir le parsing et retirer
// 	if (init_game(&cub))
//         return (1);
// 	handle_keyhook(&cub);
// 	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
// 	mlx_loop(cub.mlx_ptr);
// 	return (0);
// }

void	print_map(char **map)
{
	int i = 0;
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	static t_data cub = {0};
	if (init_parse2(ac, av, &cub))
		return (1);
	check_map(&cub);
	print_map(cub.config.map);
	free_map(cub.config.map);
	return (0);
}

// UTILS

/*

void print_config(t_data *cub)
{
	int i = 0;
	printf("ceiling :");
	while(i < 3)
	{
		printf("%d", cub->config.ceiling_color[i]);
		if (i < 2)
			printf(",");
		i++;
	}
	printf("\n");
	i = 0;
	printf("floor :");
	while(i < 3)
	{
		printf("%d", cub->config.floor_color[i]);
		if (i < 2)
			printf(",");
		i++;
	}
	printf("\n");
	printf("north :%s\n", cub->config.north_texture);
	printf("south :%s\n", cub->config.south_texture);
	printf("east :%s\n", cub->config.east_texture);
	printf("west :%s\n", cub->config.west_texture);
}

*/