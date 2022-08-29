/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 19:48:53 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	get_mchar(int i, int j, t_map_p map);

int	main(int argc, char **argv)
{
	/*
	char c;
	while (read(0, &c, 1) > 0)
	{
		write(1, &c, 1);
	}	

	
	t_map_p map;
	map.map = "................o...o.o.....................o....o.......o.........o.o....o............o...o....o...";
	map.c_e = '.';
	map.c_o = 'o';
	map.c_f = 'X';
	map.lines = 10;
	map.columns = 10;

	//int i = atoi(argv[1]) / map.columns;
	//int j = atoi(argv[1]) % map.columns;
	//printf("%c\n", get_mchar(i, j, map));
	get_solution(map);
	*/
	t_map_p map;

	check_map(get_file(argv[1]), &map);
	printf("lines: %d\ncolumns: %d\nc_e: %c\nc_o: %c\nc_f: %c\n", map.lines, map.columns, map.c_e, map.c_o, map.c_f);
	return (0);
}
