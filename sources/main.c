/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:22:57 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/12 18:17:57 by ssitchsa         ###   ########.fr       */
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

static char	*lines[4] = {"11111111111111", "1N000000000001", "11111111111111",
		NULL};

void	init_parse(t_config *config)
{
	config->map_width = 14;
	config->map_height = 3;
	config->player_x = 1;            
		// Player's initial X position (grid-based)
	config->player_y = 1;            
		// Player's initial Y position (grid-based)
	config->player_orientation = 'N'; // Player is facing North
	// config->map = malloc(sizeof(char *) * (config->map_height + 1)); //
		// +1 si vous voulez terminer par NULL
	// if (!config->map)
	// {
	//     fprintf(stderr, "Error\nMemory allocation failed for map\n");
	//     exit(EXIT_FAILURE);
	// }
	// Affectation des lignes de la carte (normalement faites pendant le parsing)
	config->map = lines;
	// print_config(config);
}

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

int	main(int ac, char **av)
{
	static t_data	cub = {0};

	if (init_parse2(ac, av, &cub))
		return (1);
	init_parse(&cub.config); // finir le parsing et retirer
	init_game(&cub, av[1]);
	handle_keyhook(&cub);
	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}


// int	main(int ac, char **av)
// {
// 	static t_data cub = {0};
// 	if (init_parse(ac, av, &cub))
// 		return (1);
// 	print_config(&cub);
// 	return (0);
// }