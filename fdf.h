/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct		s_grid
{
	void			*mlx;
	void			*win;
	char			*map;
	int				current;
}					t_grid;

typedef struct		s_map
{
	int				x;
	int				y;
	int				tile;
	int				row;
	int				col;
	int				center;
	int				align;
}					t_map;

typedef struct		s_coord
{
	int				*x;
	int				*y;
	int				*z;
	int				*color;
}					t_coord;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				p;
	int				x;
	int				y;
	int				i;
	int				temp;
	int				swap;
	int				s1;
	int				s2;
	int				a;
}					t_draw;

typedef struct		s_vars
{
	int				a;
	int				b;
	int				c;
	int				i;
	int				j;
	int				k;
}					t_vars;

typedef struct		s_parse
{
	int				i;
	int				x_axis;
	int				y_axis;
	int				a;
}					t_parse;

/*
** initialize.c
*/
int					start_initialize(t_coord *coord, t_map *init, t_grid *map);
void				initialize_draw(t_coord *coord, t_map *init, t_grid *map);

/*
** draw.c
*/
void				draw_row(t_coord *coord, t_map *init, t_grid *map, int a);
void				draw_col(t_coord *coord, t_map *init, t_grid *map, int a);

/*
** color.c
*/
void				draw_image(t_coord *coord, t_map *init,
						t_grid *map, t_draw draw);

/*
** key.c
*/
int					exit_map(int key, void *mlx);

/*
** reader.c
*/
void				store_coord(t_coord *coord, t_map *init, t_grid *map);

/*
** parser.c
*/
void				positive_double(t_coord *coord, t_map *init,
						t_grid *map, t_parse parse);
void				negative_double(t_coord *coord, t_map *init,
						t_grid *map, t_parse parse);
void				positive_single(t_coord *coord, t_map *init,
						t_grid *map, t_parse parse);
void				negative_single(t_coord *coord, t_map *init,
						t_grid *map, t_parse parse);

/*
** utility.c
*/
void				init_coord(t_map *init, t_grid *map);
int					sign(int x);

# define WHITE 0x00FFFFFF
# define LIGHTGRAY 0x00D3D3D3
# define DARKGRAY 0x00A9A9A9
# define LIGHTCORAL 0x00F08080
# define SALMON 0x00FA8072
# define LIGHTSALMON 0x00FFA07A
# define RED 0x00FF0000
# define MAROON 0x00800000
# define YELLOW 0x00FFFF00
# define OLIVE 0x00808000
# define LIME 0x0000FF00
# define GREEN 0x00008000
# define AQUA 0x0000FFFF
# define TEAL 0x00008080
# define BLUE 0x000000FF
# define NAVY 0x00000080
# define FUCHSIA 0x00FF00FF
# define PURPLE 0x00800080

#endif
