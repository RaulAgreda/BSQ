/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:47:23 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/31 10:58:11 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	file_size(char *file_name)
{
	int		fd;
	int		size;
	char	c;

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) != 0)
		size++;
	close(fd);
	return (size);
}

t_file	*get_file(char *file_name)
{
	int		size;
	int		fd;
	char	*buffer;
	t_file	*file;

	file = malloc(sizeof(t_file));
	size = file_size(file_name);
	if (size < 0)
	{
		free(file);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * size);
	fd = open(file_name, O_RDONLY);
	read(fd, buffer, size);
	close(fd);
	file->data = buffer;
	file->size = size;
	return (file);
}

t_file	*read_stdin(void)
{
	char	buf[1024];
	int		fd;

	fd = open(".stdin.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (read(0, buf, 1) > 0)
	{
		write(fd, buf, 1);
	}
	close(fd);
	return (get_file(".stdin.txt"));
}
