/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:44:14 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:55:09 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	print_path(t_path *path)
{
	int x;

	x = -1;
	while (++x < path->length)
		ft_printf("[%s] ", path->links[x]->name);
	ft_printf("\n");
}

void	print_paths(t_lemin *lemin, char all)
{
	int x;
	int end;

	end = 0;
	x = 0;
	while (!end)
	{
		if (all)
		{
			print_path(lemin->patharr[x++]);
			end = (x == lemin->totalpaths);
		}
		else
		{
			print_path(lemin->patharr[lemin->best_paths[x++]]);
			end = (x == lemin->pc);
		}
	}
}

void	print_bonus(t_lemin *lemin)
{
	if (lemin->bonus.allpaths || lemin->bonus.time || lemin->bonus.paths ||
		lemin->bonus.ants || lemin->bonus.steps)
		ft_printf("\nDebug:\n");
	if (lemin->bonus.allpaths)
	{
		ft_printf("All Paths: \n");
		print_paths(lemin, 1);
		ft_printf("\n");
	}
	if (lemin->bonus.paths)
	{
		ft_printf("Used Paths: \n");
		print_paths(lemin, 0);
		ft_printf("\n");
	}
	if (lemin->bonus.ants)
		ft_printf("Number of ants: %d\n", lemin->num_ants);
	if (lemin->bonus.steps)
		ft_printf("Number of steps: %d\n", lemin->steps);
	if (lemin->bonus.time)
		ft_printf("CPU Time: %d clocks\n", clock() - lemin->begin);
}
