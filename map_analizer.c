/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:47:59 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/31 11:03:27 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	line_length(char *str);
int	count_nl(t_file *file);

int	check_printable(t_file *file)
{
	int	i;

	i = 0;
	while (i < file->size)
	{
		if (!(PRINTABLE((file->data)[i]) || (file->data)[i] == '\n'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_first_line(t_file *file, t_map_p *map)
{
	int	n;
	int	i;

	i = 0;
	while ((file->data)[i] != '\n')
		if (i >= file->size)
			return (-1);
	else
			i++;
	if (i < 4)
		return (-1);
	map->c_f = (file->data)[i - 1];
	map->c_o = (file->data)[i - 2];
	map->c_e = (file->data)[i - 3];
	if (map->c_f == map->c_o || map->c_f == map->c_e || map->c_o == map->c_e)
		return (-1);
	n = ft_atoi(file->data, i - 3);
	if (n <= 0)
		return (-1);
	map->lines = n;
	return (0);
}

int	check_lines_length(t_file *file)
{
	int	l_length;
	int	length;
	int	i;

	l_length = 0;
	i = 0;
	while (file->data[i] != '\n')
		i++;
	i++;
	l_length = line_length(file->data + i);
	i += l_length + 1;
	while (i < file->size)
	{
		length = line_length(file->data + i);
		if (length != l_length)
			return (-1);
		i += length + 1;
	}
	return (l_length);
}

int	check_map(t_file *file, t_map_p *map)
{
	if ((check_printable(file) < 0)
		|| (check_first_line(file, map) < 0)
		|| (count_nl(file) != map->lines + 1))
		return (show_error());
	map->columns = check_lines_length(file);
	if (map->columns < 1)
		return (show_error());
	return (0);
}
