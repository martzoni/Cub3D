/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:20 by martinmason       #+#    #+#             */
/*   Updated: 2024/04/04 11:05:43 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include "libraries/get_next_line/get_next_line.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define PIXEL_X 64
# define PIXEL_Y 64
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800
# define BORDER 25

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define FOV 66
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 7

# define NO						0
# define EA						1
# define SO						2
# define WE						3
# define C						4
# define F						5
# define EMPTY					6

# define W 						13
# define A 						0
# define S 						1
# define D 						2
# define UP 					126
# define DOWN 					125
# define LEFT 					123
# define RIGHT 					124

typedef struct s_txtr
{
	int				id;
	char			*key;
	char			*value;
	void			*pointer_to_image;
	char			*address;
	char			*address_char;
	int				*address_int;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
} t_txtr;

typedef struct s_player
{
	int				pl_pix_x;
	int				pl_pix_y;
	int				pl_map_x;
	int				pl_map_y;
	float			ang_dir;
	float			ang_fov;
	int				rot;
	int				l_r;
	int				u_d;
} t_player;

typedef struct s_ray
{
	int				index;
	int				line_height;
	double			curr_angle;
	double			horiz_x;
	double			horiz_y;
	double			vert_x;
	double			vert_y;
	int				draw_start;
	int				draw_end;
	double			distance;
	int				flag;
}	t_ray;




typedef struct s_game
{
	int				fd;
	char			*line;
	char			**map_2d;
	unsigned long	ff;
	unsigned long	cc;
	int				x_len;
	int				y_len;
	int				x_player;
	int				y_player;
	char			direc_player;
	int				texture[4][PIXEL_X * PIXEL_Y];
	int				txtr_3d[4][PIXEL_Y][PIXEL_X];
	t_txtr			*frame;
	t_ray			*ray;
	t_player		*player;
	double			map_distance;

	void			*mlx;
	void			*win;

	t_txtr			a_txtr[6];
}	t_game;

// General_utils
void	free_2d(char **tab);
int		ft_error_message(int fd, char *message, int ret);
t_game	*game(void);
void	show_txtr(void);
void	show_map(void);
void	add_word(char ***tab, char *word);

// Parser
int		open_file(char *file);

// Parser_txtr
int		parse_txtr(void);

// Parser_txtr_valid
int		l_txtr_len(t_txtr *l_txtr);
int		valid_txtr(void);
unsigned long	rgb_to_hex(char *red, char *green, char *blue);

// Parser_map
int		parse_map(void);

// Parser_map_valid
int		not_a_wall(char c);
int		cardinal_counter(char **map2d);
int		rounded_by_wall(char **map2d);
int		cardinal_char(char c);

int		a_txtr_len(t_txtr a_txtr[6]);
int		valid_txtr2(void);
int		new_texture2(char *line);

// Init
void	init(void);

// Launcher
int	launcher(t_game *cur_game);
float	fix_angle(float angle);

// Render
void	draw_floor(void);
void	draw_ceiling(void);
void	render_wall(t_game *game, int ray);
void	mini_map(t_game *game);
void	print_player(void);

// Movements
void	update_pos(t_game *game, double move_x, double move_y);
int		key_press(int keycode);
int		key_release(int keycode);
int	mouse_move(int keycode);
int	mouse_stop(int keycode);
#endif
