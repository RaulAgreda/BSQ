/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:35:28 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 16:27:15 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"
#include <fcntl.h>
#include <unistd.h>

char	*ft_char_realloc(char *pointer, int old_size, int new_size)
{
	char	*new_p;
	int		i;

	i = 0;
	new_p = malloc(sizeof(char) * new_size);
	while (i < old_size)
	{
		new_p[i] = pointer[i];
		i++;
	}
	free(pointer);
	return (new_p);
}

t_file	*analyze_input(void)
{
	char	buf[1024];
	int		fd;
	int		ret;

	fd = open(".stdin.txt", O_RDWR | O_CREAT, 0666);
	while ((ret = read(0, buf, 1024)) > 0)
	{
		write(fd, buf, ret);
	}
	close(fd);
	return (get_file("./.stdin.txt"));
}