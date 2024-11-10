#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_ray;

typedef struct s_draw
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
}				t_draw;

typedef struct s_texture
{
	void		*img;
	int			*data;
	int			width;
	int			height;
}				t_texture;

typedef struct s_movement
{
	int			move_forward;
	int			move_backward;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}				t_movement;

typedef struct s_player
{
	double		x;
	double		y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

// STRUCTURE PARSING
enum DIRECTION {
	NORD,
	SUD,
	OUEST,
	EST,
};

typedef struct s_config
{
	char *texture[4];

	char *north_texture;     // Chemin vers la texture du mur nord
	char *south_texture;     // Chemin vers la texture du mur sud
	char *west_texture;      // Chemin vers la texture du mur ouest
	char *east_texture;      // Chemin vers la texture du mur est
	char *floor_color;      // Couleur du sol (RGB)
	char *ceiling_color;    // Couleur du plafond (RGB)
	char **map;              // Carte 2D
	int map_width;           // Largeur de la carte
	int map_height;          // Hauteur de la carte
	int player_x;            // Position X du joueur dans la carte
	int player_y;            // Position Y du joueur dans la carte
	char player_orientation; // Orientation initiale du joueur ('N', 'S', 'E', 'W')
}				t_config;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_config	*config;
	t_player	player;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_movement	movement;
	int			texture_width;
	int			texture_height;
}				t_data;

void			load_textures(t_data *data);
void			init_game(t_data *data, char *cub_file);
void			init_player(t_player *player, t_config *config);
int				game_loop(t_data *data);
int				close_window(t_data *data);
void			handle_keyhook(t_data *data);
int				key_pressed(int keycode, t_data *data);
int				key_released(int keycode, t_data *data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			define_direction(t_data *data, t_ray *ray);
void			initialize_ray(t_data *data, t_ray *ray, int x);
void			render_column(t_data *data, t_ray *ray, int x);
void			perform_raycasting(t_data *data);
t_texture		*select_texture(t_data *data, t_ray *ray);
void			calculate_tex_x(t_draw *draw, t_ray *ray, t_texture *texture,
					double wall_x);
double			calculate_perp_wall_dist(t_data *data, t_ray *ray);
void			calculate_draw_limits(t_draw *draw, int win_height);
void			draw_column(t_data *data, int x, t_draw *draw,
					t_texture *texture);
void			free_map(t_config *config);
void			initialize_delta(t_ray *ray);
int				perform_dda(t_data *data, t_ray *ray);

// PARSING
int				check_mapname(char *cub);

#endif