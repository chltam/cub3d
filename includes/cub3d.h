/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:50:46 by htam              #+#    #+#             */
/*   Updated: 2023/06/26 11:50:48 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include "../libft/includes/libft.h"

# define W_WIDTH 720
# define W_HEIGHT 1080
# define MAP_WIDTH 720
# define MAP_HEIGHT 512
# define GAME_WIDTH	300
# define GAME_HEIGHT 200

// Dimension of the Projection Plane = 320 x 200 units
// Center of the Projection Plane = (160,100)
// Distance to the Projection Plane = 277 units
// Angle between subsequent rays = 60/320 degrees

# define MAP_SIZE 64
# define UNIT_SIZE 64
# define NUM_RAYS 320
# define RAD_BETW_RAYS 0.00318522588
# define DIST_TO_PLANE 255

# define M_PI	3.14159265358979323846

# define ESC	65307

# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

# define W_KEY	119
# define A_KEY	97
# define S_KEY	115
# define D_KEY	100

# define BLACK	0x00000000
# define WHITE	0xFFFFFFFF
# define GREY	0xD3D3D3FF
# define RED	0x7CFC0000
# define GREEN	0xFC7CDD00

/*.cub parsing*/

typedef struct s_cub
{
	char	*north_file;
	char	*east_file;
	char	*south_file;
	char	*west_file;
	int		floor[3];
	int		ceiling[3];
	char	**map;
}	t_cub;

/* image */

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	float	x;
	float	y;
	float	pov;
	float	dx;
	float	dy;
}	t_player;

typedef struct s_vars {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			map_width;
	int			map_height;
	float		tx_scale;
	float		wall_height;
	t_cub		*cub;
	t_player	*player;
	t_data		*map_img;
	t_data		*image;
	t_data		*north_xpm;
	t_data		*east_xpm;
	t_data		*south_xpm;
	t_data		*west_xpm;
}				t_vars;

/* raycasting */

typedef enum e_hit {
	EAST,
	WEST,
	NORTH,
	SOUTH,
	DEFAULT
}			t_hit;

typedef struct s_rc {
	int			hor_u_val;
	int			hor_map_x;
	int			hor_map_y;
	int			vert_u_val;
	int			vert_map_x;
	int			vert_map_y;
	t_hit		hit_dir;
	int			y_tex;
}				t_rc;

/* line drawing */

typedef struct s_lcoords {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_lcoords;

typedef struct s_line_vars {
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_line_vars;

/*init*/

t_vars	*init_vars(char *file);
t_cub	*cub_parse(char *file);
int		player_setup(t_vars *vars);
t_data	*map_img_setup(t_vars *vars);
t_data	*init_img(void *mlx_ptr, char *path, int width, int height);

/*cub parser*/

t_cub	*cub_parse(char *file);
int		map_1d_check(char *map_1d);

/*cub read set*/

int		read_cub_file(int cub_fd, t_cub *cub);

/*cub_validate*/

int		valid_cub(t_cub *cub);

/*cub_helper*/

int		ft_atoi_lite(char *str);
bool	is_info(char *tag);
bool	is_player(char c);
int		max_row(char **map);
bool	is_info_allset(t_cub *cub);

/* drawing */

void	draw(t_vars *vars, t_data *img);
void	draw_scene(t_vars *vars);
void	draw_wall_slice(t_vars *v, double ray, int num_ray, t_rc *rc);

void	set_coords(t_lcoords *coords, t_vars *vars, int factor);
void	set_wall_coords(t_lcoords *coords, int wall_top, int wall_btm,
			int num_ray);
void	draw_line(t_data *img, t_lcoords *coords, int color);
void	put_pix_to_img(t_data *img, int x, int y, int color);
void	put_pix_to_img_wild(t_data *img, int x, int y, int color);
void	draw_blank(t_data *map_img, int width, int height);
void	draw_tile(t_data *img, int x, int y, int color);

/* map */

void	draw_map(t_vars *vars);
void	draw_minimap(t_vars *vars);
void	draw_blank(t_data *map_img, int width, int height);

/* raycaster */

void	rays_loop(t_vars *vars);
int		check_vert_grid(t_rc *rc, t_vars *v);
int		check_horiz_grid(t_rc *rc, t_vars *v);
void	get_hit_dir(t_rc *rc, t_vars *v);

/* texture mapping */

void	draw_line_xpm(t_vars *v, t_data *img, t_lcoords *coords, t_rc *rc);

/* events */

int		key_events(int keycode, t_vars *vars);
int		close_cross(t_vars *vars);
int		close_esc(int keycode, t_vars *v);
int		mouse_move(int mousecode, int x, int y, void *param);
int		mouse_event(int x, int y, void	*param);

/*free*/

void	free_2d(char **str);
void	free_cub(t_cub *cub);
void	free_vars(t_vars *vars);

#endif
