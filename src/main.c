/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:19:13 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 05:19:14 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(int ac, char **av)
{
	t_lemin *lemin;

	(void)ac;
	(void)av;
	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	parse(lemin);
	validate(lemin);
	solve(lemin);
	return (0);
}
