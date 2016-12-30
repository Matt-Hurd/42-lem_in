/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:39:20 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 05:32:59 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct	s_room
{
	char		*name;
	t_list		*links;
	int			x;
	int			y;
}				t_room;

typedef struct	s_path
{
	t_room		**links;
	int			length;
}				t_path;

typedef struct	s_ant
{
	int			path;
	int			room;
}				t_ant;

typedef struct	s_lemin
{
	int			num_ants;
	int			remaining_ants;
	t_list		*rooms;
	t_room		*start;
	t_room		*end;
	t_list		*paths;
	t_path		**patharr;
	int			*best_paths;
	int			bl;
	int			override;
	int			pc;
	t_ant		*ants;
	int			finished;
}				t_lemin;

void			parse(t_lemin *lemin);
void			find_paths(t_lemin *lemin, t_list *path, t_room *room);
void			solve(t_lemin *lemin);
void			print_rooms(t_lemin *lemin);
void			print_solution(t_lemin *lemin);
void			ft_error(char *message);
void			validate(t_lemin *lemin);
void			validate_rooms(t_lemin *lemin);
int				find_length(t_lemin *lemin, int *test_path, int pc);
void			copy_arr(int *dest, int *src, int len);

#endif
