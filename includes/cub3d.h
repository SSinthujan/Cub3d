#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <linux/limits.h>
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
typedef struct s_config
{
	int			fd;
	int			length;
	char		north_texture[PATH_MAX];
	char		south_texture[PATH_MAX];
	char		west_texture[PATH_MAX];
	char		east_texture[PATH_MAX];
	int			floor_color[3];
	int			floor_set;
	int			ceiling_color[3];
	int			ceiling_set;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	char		player_orientation;
}				t_config;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_config	config;
	t_player	player;
	t_texture	wall[4];
	t_movement	movement;
	int			texture_width;
	int			texture_height;
}				t_data;

// PARSING
int				check_config(char *map, t_data *cub);
int				check_texture(t_config *config, char *str);
int				check_color(t_config *config, char *str);
void			free_tab(char **tab);
char			*get_word(char *str, char *dest, int size);
int				check_rgb(int *color, char *rgb);
int				ft_strcmp(const char *s1, const char *s2);
int				check_map(t_data *cub);
char			**get_copymap(int height, int width);
char			**mapcopymap(t_config *config, char **copy_map);
void			print_map(char **map);
int				is_player(char c);
void			get_playerpos(t_config *config, int i, int j, char c);

// EXEC
int				load_textures(t_data *data);
int				load_textures2(t_data *data);
int				init_game(t_data *data);
void			init_player(t_player *player, t_config *config);
int				game_loop(t_data *data);
int				close_window(t_data *data, int nb);
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
void			free_map(char **map);
void			initialize_delta(t_ray *ray);
int				perform_dda(t_data *data, t_ray *ray);
void			render_ceiling(t_data *data, int x, int draw_start);
void			render_floor(t_data *data, int x, int draw_end);
double			calculate_wall_x(t_data *data, t_ray *ray,
					double perp_wall_dist);
void			set_player_orientation_ns(t_player *player, t_config *config);
void			set_player_orientation_ew(t_player *player, t_config *config);
int				rgb_to_hex(int r, int g, int b);

#endif