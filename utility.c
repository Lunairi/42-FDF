/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

int		count_map(char *str, int value, int i)
{
	if (value == 0)
		while (str[i] != '\n' || str[i] != '\0')
		{
			if (ft_isdigit(str[i]))
			{
				value++;
				if (ft_isdigit(str[i + 1]))
					i++;
			}
			i++;
			if (str[i] == '\n' || str[i] == '\0')
				return (value);
		}
	else if (value == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n' && str[i + 1] != '\0')
				value++;
			i++;
		}
		return (value);
	}
	return (0);
}

void	init_coord(t_map *init, t_grid *map)
{
	map->current = 0;
	init->row = (count_map(map->map, 0, 0));
	init->col = (count_map(map->map, 1, 0));
	init->x = (750 / init->row);
	init->y = (300 / init->col);
	init->align = 450;
	if (init->col > init->row)
	{
		init->tile = (750 / init->col);
		init->center = (750 + ((375 * init->row) / init->col));
	}
	else
	{
		init->tile = init->x;
		init->center = (750 - (375 - ((375 * init->col) / init->row)));
	}
}
