#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/errno.h>
# include "minilibx-linux/mlx.h"
# include "texture.h"
# include "move.h"
# define IMG_SIZE 35

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		start;
	int		col;
	int		exit;
	int		player[2];
	int		patrol[2];
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_pixel;
	int		line_l;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*win;
	t_data	*text;
	t_data	*img;
	int		nbMove;
}	t_game;

/*	main.c	*/
int				check_arg(char *file, t_map *map);

/*	check_map.c	*/
int				get_map(int fd, t_map *map);
int				check_line(char *line, int *val);

/*	error.c	*/
void			error_malloc(char *message);
void			error_read(int fd, char *str, char *line, t_map *map);
int				error_split(t_map *map);
int				error_map(t_map *map, char *message);

/*	start.c	*/
unsigned int	get_col(t_data *img, int x, int y);
void			start_game(t_map *map);
void			my_mlx_pixel_put(t_data *img, int x, int y, t_data *im);
void			printMap(t_game *g, t_data *img);

/*	map_utils.c	*/
int				valid_char(char c);
int				need_wall(t_map	*map, int y, int x);
int				enough(t_map *map);
void			clear_map(t_map *map);

/*	game_utils.c	*/
t_game			*init_game( t_map *map);
int				close_g(t_game *g);

/*	move.c	*/
void			majPlayer(t_game *g, int x, int y, t_data *img);
int				key_hook(int keycode, t_game *g);

/*	render.c	*/
void			movement(t_game *g);
int				which_text(char c);
int				render_frame(t_game *g);

#endif
