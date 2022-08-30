/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:10:12 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 12:17:57 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	show_error(void);

int	check_map_chars(t_map_p *map)
{
	int	i;

	i = 0;
	while (i < map->lines * map->columns)
	{
		if ((map->map)[i] != map->c_e && (map->map)[i] != map->c_o)
			return (show_error());
		i++;
	}
	return (0);
}

int	extract_map(t_file *file, t_map_p *map)
{
	int	size;
	int	f;
	int	i;

	f = 0;
	while ((file->data)[f] != '\n')
		f++;
	i = 0;
	size = map->lines * map->columns;
	map->map = malloc(sizeof(char) * size);
	while (i < size)
	{
		if ((file->data)[f] != '\n')
		{
			(map->map)[i] = (file->data)[f];
			i++;
		}
		f++;
	}
	free(file->data);
	free(file);
	return (check_map_chars(map));
}
