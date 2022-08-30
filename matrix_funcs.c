/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:49:40 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 11:49:44 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	mtoa(int i, int j, t_map_p *map)
{
	return (i * map->columns + j);
}

char	get_mchar(int i, int j, t_map_p *map)
{
	return ((map->map)[i * map->columns + j]);
}

int	get_line(int i, t_map_p *map)
{
	return (i / map->columns);
}

int	get_column(int i, t_map_p *map)
{
	return (i % map->columns);
}