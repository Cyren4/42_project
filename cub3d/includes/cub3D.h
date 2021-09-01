/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:55:15 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/17 09:40:09 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../lib/header_lib.h"


typedef struct  s_conf
{
    int     resol[2]; // 0 = x , 1 = y
    char    *text[5];//0 = SO, 1 = WE, 2 = EA, 3 = NO, 4 = split
    int     col[2][3]; // 0 = F , 1 = C
    void    *mlx_ptr;
    void    *win;
}               t_conf;

typedef struct s_map
{
    char    **map;
    int     height;
    int     nb_map;
    int     start;
    int     valid;
}               t_map;

typedef struct s_data
{
    int     win_size_x;
    int     win_size_y;
    void    *mlx_ptr;
	void    *mlx_win;
	t_conf	*conf;
	t_map	*map;
}               t_data;


/*	parsing.c	*/
int			parsing(int fd, t_data *data);

// int         check_name_file(int ac, char **av);//check args

// int         check_cub(char *cub, t_conf *conf, t_map *map);//open fd & call check conf / map
// int         check_conf(int fd, char **line, t_conf *conf, t_map *map); //read and get conf
// int         check_line(char *line, t_conf *conf, int *all_c);

// int         which(char **sep, char *line, t_conf *conf, int *all_c);
// int         text(char **sep, t_conf *conf, int *all_c, int i);
// int         res(char **sep, t_conf *conf, int *all_c, int i);
// int         color(char *line, t_conf *conf, int *all_c, int i);

// int         error_message(int *check, int check_end);
// void        clean(char **sep);
// int         all_good(int *check);
// int         len(char **str);
// int         all_valid(t_conf *conf, int *check);

// int         check_map(int fd, char **line, t_map *map);
// int         get_map(int fd, char **line, t_map *map);
// int         new_line(char *line, t_map *map, int nb_line);

// // int         cub3d(t_conf *conf, t_map *map);
// void        show_conf(t_conf *conf);

#endif
