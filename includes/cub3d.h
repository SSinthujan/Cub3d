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
typedef struct s_config
{
	int			fd;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
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
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_movement	movement;
	int			texture_width;
	int			texture_height;
}				t_data;

// PARSING
int				check_mapname(char *cub);
int				check_config(char *map, t_data *cub);
int				check_texture(t_config *config, char *str);
int				check_color(t_config *config, char *str);
void			free_tab(char **tab);
char			*get_word(char *str);
int				check_rgb(int *color, char *rgb);
int				ft_strcmp(const char *s1, const char *s2);

#endif