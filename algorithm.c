/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:50:35 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 17:31:18 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>


t_square	*initialize_square(void)
{
	t_square *sq;

	sq = malloc(sizeof(t_square));
	sq->dim = 0;
	sq->index = 0;
	return (sq);
}

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

int	check_next_size(int idx, t_map_p *map, int size)
{
	int line;
	int col;
	int	i;
	int	j;

	line = get_line(idx, map);
	col = get_column(idx, map);
	if (size == 1)
		return (get_mchar(line, col, map) == map->c_e);
	if (line + size > map->lines || col + size > map->columns)
		return (0);
	i = 0;
	while (i < size)
	{
		if (i < size - 1)
			j = size - 1;
		else
			j = 0;
		while (j < size)
		{
			if (get_mchar(line + i, col + j, map) == map->c_o)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_sq(int idx, t_map_p *map)
{
	int	size;

	if ((map->map)[idx] == map->c_o)
		return (0);
	size = 1;
	while (check_next_size(idx, map, size))
		size++;
	return (size - 1);
}

/*
t_square	get_next_sq(int idx, t_square sq, t_map_p map)
{
	int i;
	int j;
	int start_i = get_line(idx, map);
	int start_j = get_column(idx, map);
	int cont;
	int shortest;

	if (get_mchar(start_i, start_j, map) == map.c_o)
		return (sq);
	//empties Primera linea
	shortest = 0;
	j = 0;
	while (j + start_j < map.columns)
	{
		if(get_mchar(start_i, j + start_j, map) == map.c_e)
			shortest++;
		else
			break;
		j++;
	}
	i = 1;
	while (i + start_i < map.lines)
	{
		if (i >= shortest)
		{
			if (shortest > sq.dim)
				return (get_sq(idx, shortest));
			else
				return (sq);
		}
		cont = 0;
		j = 0;
		while (j + start_j < map.columns)
		{
			if (get_mchar(i + start_i, j + start_j, map) == map.c_e)
			{
				cont++;
			}
			else
				break;
			j++;
		}
		if (cont < sq.dim)
			return (sq);
		if (cont < shortest)
		{
			shortest = cont;
		}
		i++;
	}
	return (sq);
}
*/
void	print_solution(t_square sq, t_map_p *map)
{
	int		i;
	int		j;
	int		line = get_line(sq.index, map);
	int		column = get_column(sq.index, map);
	char	c;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (i >= line && i < line + sq.dim
			&& j >= column && j < column + sq.dim)
				c = map->c_f;
			else
				c =	get_mchar(i, j, map);
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_solution(t_map_p *map)
{
	t_square	*sq;
	int			idx;
	int			size;

	sq = initialize_square();
	
	idx = 0;
	while (idx < map->lines * map->columns)
	{
		size = get_sq(idx, map);
		if (size > sq->dim)
		{
			sq->dim = size;
			sq->index = idx;
		}
		idx++;
	}
	print_solution(*sq, map);
	printf("idx: %d dim: %d\n", sq->index, sq->dim);
	free(sq);
}
