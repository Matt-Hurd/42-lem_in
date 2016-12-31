/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:19:46 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:57:15 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int				has_overlap(t_lemin *lemin, int one, int two)
{
	int	x;
	int	y;

	x = -1;
	if (one == two)
		return (1);
	while (++x < lemin->patharr[one]->length)
	{
		y = -1;
		while (++y < lemin->patharr[two]->length)
			if (ft_strequ(lemin->patharr[one]->links[x]->name,
				lemin->patharr[two]->links[y]->name))
				return (1);
	}
	return (0);
}

void			backtrack(t_lemin *lemin, int *test_path, int pc, int index)
{
	int i;
	int invalid;

	if (pc == lemin->pc)
	{
		if (find_length(lemin, test_path, pc) < lemin->bl || lemin->bl == -1)
		{
			copy_arr(lemin->best_paths, test_path, pc);
			lemin->bl = find_length(lemin, test_path, pc);
		}
		return ;
	}
	while (lemin->patharr[++index])
	{
		i = -1;
		invalid = 0;
		while (++i < pc)
			invalid = (invalid || test_path[i] == index
				|| has_overlap(lemin, test_path[i], index));
		if (!invalid)
		{
			test_path[pc] = index;
			backtrack(lemin, test_path, pc + 1, index);
		}
	}
}

void			find_best_paths(t_lemin *lemin)
{
	t_list	*lst;
	int		*test_path;

	lst = lemin->start->links;
	while (lst && ++lemin->pc)
		lst = lst->next;
	test_path = (int *)ft_memalloc(sizeof(int) * lemin->pc);
	lemin->best_paths = (int *)ft_memalloc(sizeof(int) * lemin->pc);
	lemin->pc += 1;
	while (lemin->bl == -1 && --lemin->pc)
		backtrack(lemin, test_path, 0, -1);
	free(test_path);
}

static void		list_to_array(t_lemin *lemin, t_list *lst)
{
	int		len;
	t_list	*l;

	len = 0;
	l = lst;
	while (l)
	{
		len++;
		l = l->next;
	}
	lemin->totalpaths = len;
	lemin->patharr = (t_path **)ft_memalloc(sizeof(t_path *) * (len + 1));
	while (lst)
	{
		lemin->patharr[--len] = (*(t_path **)lst->content);
		lst = lst->next;
	}
}

void			solve(t_lemin *lemin)
{
	int x;
	int y;

	lemin->bl = -1;
	find_paths(lemin, NULL, lemin->start);
	list_to_array(lemin, lemin->paths);
	x = -1;
	while (lemin->patharr[++x])
	{
		y = -1;
		while (lemin->patharr[x]->links[++y])
			;
		lemin->patharr[x]->length = y;
	}
	find_best_paths(lemin);
	lemin->ants = (t_ant *)ft_memalloc(sizeof(t_ant) * (lemin->num_ants + 1));
	x = -1;
	while (++x < lemin->num_ants)
		lemin->ants[x].path = -1;
	print_solution(lemin);
}
