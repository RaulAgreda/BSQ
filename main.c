/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/31 11:00:38 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	start(t_file *file, t_map_p *map)
{
	if (file == NULL)
		return (show_error());
	if (check_map(file, map) == 0)
	{
		if (extract_map(file, map) == 0)
			get_solution(map);
		free(map->map);
	}
	return (-1);
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
			start(file, &map);
			i++;
		}
	}
	else
	{
		file = read_stdin();
		start(file, &map);
	}
	exit(0);
}
