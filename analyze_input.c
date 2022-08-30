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

t_file	*fake_file(void)
{
	t_file	*file;
	int		size;

	size = 1;

	return (0);
}