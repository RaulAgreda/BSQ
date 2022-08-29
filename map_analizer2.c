/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analizer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:04:44 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 20:08:04 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

int	show_error(void)
{
	write(1, "map error\n", 10);
	return (-1);
}

int	line_length(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n')
		count++;
	return (count);
}

int	count_nl(t_file *file)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < file->size)
	{
		if ((file->data)[i] == '\n')
			count++;
		i++;
	}
	return (count);
}
