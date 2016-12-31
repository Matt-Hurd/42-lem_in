/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:44:23 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 21:48:59 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int		debug_print(t_ps *ps)
{
	int i;

	if (!ps->debug)
		return (0);
	if (ps->printslow)
	{
		nanosleep(&(struct timespec){0, 60000000}, 0);
		ft_putstr("\e[1;1H\e[2J");
	}
	ps->color ? ft_putstr(RED) : ft_putstr("");
	ft_putendl("Stack A:");
	i = ps->a_len;
	ps->color ? ft_putstr(GREEN) : ft_putstr("");
	while (i--)
		ft_putendl(ft_itoa(ps->a[i]));
	ps->color ? ft_putstr(RED) : ft_putstr("");
	ft_putendl("Stack B:");
	i = ps->b_len;
	ps->color ? ft_putstr(BLUE) : ft_putstr("");
	while (i--)
		ft_putendl(ft_itoa(ps->b[i]));
	ft_putendl("");
	ps->color ? ft_putstr(NC) : ft_putstr("");
	return (0);
}

int		check_duplicates(t_ps *ps)
{
	int		x;
	int		y;

	x = -1;
	while (++x < ps->a_len)
	{
		y = -1;
		while (++y < ps->a_len)
			if (x != y && ps->a[x] == ps->a[y])
				return (-1);
	}
	return (0);
}

void	handle_options(int *ac, char ***av, t_ps *ps)
{
	int x;

	x = -1;
	while (++x < *ac)
	{
		if (*ac > 1 && ft_strequ((*av)[x], "-d"))
			ps->debug = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-c"))
			ps->color = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-p"))
			ps->printsort = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-l"))
			ps->printlen = 1;
		else if (*ac > 1 && ft_strequ((*av)[x], "-s"))
			ps->printslow = 1;
		else
			continue;
		ps->a_len--;
		(*ac)--;
		x--;
		(*av)++;
	}
	return ;
}

int		handle_args(int ac, char **av, t_ps *ps)
{
	int		i;
	int		x;
	long	tmp;

	handle_options(&ac, &av, ps);
	i = 0;
	while (++i < ac)
	{
		x = -1;
		while (av[i][++x])
			if ((!ft_isdigit(av[i][x])) && !(av[i][x] == '-' && x == 0))
				return (-1);
		if (x == 0)
			return (-1);
		if (x > 11)
			return (-1);
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (-1);
		ps->a[ac - 1 - i] = (int)tmp;
	}
	return (0);
}

void	setup_env(t_ps *ps, int ac, char **av)
{
	ps->a = ft_memalloc(sizeof(int) * (ac - 1));
	ps->b = ft_memalloc(sizeof(int) * (ac - 1));
	ps->ta = ft_memalloc(sizeof(int) * (ac - 1));
	ps->tb = ft_memalloc(sizeof(int) * (ac - 1));
	ps->a_len = ac - 1;
	ps->b_len = 0;
	ps->len = 0;
	ps->debug = 0;
	ps->color = 0;
	ps->printsort = 0;
	ps->printlen = 0;
	ps->printslow = 0;
	if (handle_args(ac, av, ps) || check_duplicates(ps) || ps->a_len == 0)
	{
		free(ps->a);
		free(ps->b);
		free(ps->ta);
		free(ps->tb);
		if (ps->a_len != 0)
			ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
