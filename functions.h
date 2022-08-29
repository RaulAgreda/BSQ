/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:55:15 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/29 20:32:19 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# define PRINTABLE(x) (x >= 32 && x <= 126)

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
void	extract_map(t_file *file, t_map_p *map);
void	get_solution(t_map_p *map);
t_file	*get_file(char *file_name);
int		check_map(t_file *file, t_map_p *map);
int		ft_atoi(char *str, int size);
int		ft_isspace(char c);
#endif
