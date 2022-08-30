/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 11:35:45 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	get_mchar(int i, int j, t_map_p *map);

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
			if (check_map(file, &map) == 0)
			{
				extract_map(file, &map);
				free(file->data);
				free(file);
				get_solution(&map);
				free(map.map);
			}
			i++;
		}
	}
	//system("leaks bsq");
	exit(0);
}
