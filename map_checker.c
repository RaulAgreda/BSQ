/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:28:22 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 15:56:36 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	line_length(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n')
		count++;
	return (count);
}

int	check_length(char *str)
{
	return (1);
}
