/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 20:41:45 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	get_mchar(int i, int j, t_map_p *map);

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (-1);
	t_map_p map;
	t_file *file;

	file = get_file(argv[1]);
	check_map(file, &map);
	printf("lines: %d\ncolumns: %d\nc_e: %c\nc_o: %c\nc_f: %c\n", map.lines, map.columns, map.c_e, map.c_o, map.c_f);
	extract_map(file, &map);
	for (int i = 0; i < map.lines * map.columns; i++)
	{
		write(1, map.map + i, 1);
		if (i % map.columns == map.columns - 1)
			write(1, "\n", 1);
	}
	get_solution(&map);
	return (0);
}
