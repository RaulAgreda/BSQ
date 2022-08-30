/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 12:24:15 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	start(t_file *file, t_map_p *map)
{
	if (check_map(file, map) == 0)
	{
		if (extract_map(file, map) == 0)
			get_solution(map);
		free(map->map);
	}
}

void	leaks(void)
{
	system("leaks -q bsq");
}

int	main(int argc, char **argv)
{
	t_map_p	map;
	t_file	*file;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			file = get_file(argv[i]);
			if (file == NULL)
				show_error();
			else
				start(file, &map);
			i++;
		}
	}
	else
	{
		file = read_stdin();
		if (file == NULL)
			show_error();
		else
			start(file, &map);
	}
	exit(0);
}
