/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:55:15 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/30 12:13:44 by ragreda-         ###   ########.fr       */
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
int		extract_map(t_file *file, t_map_p *map);
void	get_solution(t_map_p *map);
int		check_map(t_file *file, t_map_p *map);
int		ft_atoi(char *str, int size);
int		ft_isspace(char c);
int		mtoa(int i, int j, t_map_p *map);
char	get_mchar(int i, int j, t_map_p *map);
int		get_line(int i, t_map_p *map);
int		get_column(int i, t_map_p *map);
int		show_error(void);
t_file	*get_file(char *file_name);
t_file	*analyze_input(void);
#endif
