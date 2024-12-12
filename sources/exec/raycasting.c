/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:14 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/30 18:23:18 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

ça c'est une grille (une map en gros)

on va appeller chaque chiffre ici une "cellule", chaque cellule est constué soit de 1 ou 1 ou N S W E tas capter

1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

donc delta_dist_x c la distance que dois parcourir ton rayon pour traverser UNE cellule
et side_dist_x c la distance exact a laquelle ton rayon va passer a une autre cellule
*/

// dirx = plus je regarde a l'est plus c negatif (-1) et vice versa
// diry = plus je regarde vers le sud plus c negatif (-1) et vice versa
// camera_x = position relative de la colonne sur l'écran en gros plus ta cam est a gauche plus c negatif (-1) et vice versa
// plane = c'est ta pov
// side_dist = distance jusqu'à la prochaine ligne de la grille
// perp_wall_dist = distance perpendiculaire au mur (pour calculer la hauteur du mur a afficher)

// step_x et y c la direction dans laquelle va le rayon
// si step_x est -1, cv dire que le rayon va de gauche a droite et vice versa pareil pr y 

// en gros jcalcule les directions de rayons pour chaque colonne de l'écran
// jparcours tt les rayons pour trouver un mur
// je calcule la distance au mur et donc la hauteur a afficher
// je render le ciel, le mur et le sol pixel par pixel
// je calcule les cordonnées X et Y des textures pour chaque colonne
// et japplique pixel par pixel la texture en remplacant la couleur par la couleur du pixel de la cordonnée de la la texture

void define_direction(t_data *data, t_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
    }
}

void initialize_ray(t_data *data, t_ray *ray, int x)
{
    double camera_x;

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

void perform_raycasting(t_data *data)
{
    int x;
    t_ray ray;

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
