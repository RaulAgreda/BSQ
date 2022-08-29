/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:55:15 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 16:12:13 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

typedef struct s_file
{
	char	*data;
	int		size;
}			t_file;

typedef struct s_map_params
{
	t_file	file;
	char	*map;
	int		lines;
	int		columns;
	char	c_e;
	char	c_o;
	char	c_f;
}			t_map_p;

typedef struct s_square
{
	int	index;
	int	dim;
}		t_square;

void	get_solution(t_map_p map);

#endif
