/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:19:50 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 05:34:03 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	validate_rooms(t_lemin *lemin)
{
	t_list *r1;
	t_list *r2;

	r1 = lemin->rooms;
	while (r1)
	{
		r2 = lemin->rooms;
		while (r2)
		{
			if (r1 == r2)
			{
				r2 = r2->next;
				continue;
			}
			if (ft_strequ((*(t_room **)r1->content)->name,
				(*(t_room **)r2->content)->name))
				ft_error("Duplicate room name");
			r2 = r2->next;
		}
		r1 = r1->next;
	}
}

void	validate_links(t_lemin *lemin)
{
	t_list *r;
	t_list *l1;
	t_list *l2;

	r = lemin->rooms;
	while (r)
	{
		l1 = (*(t_room **)r->content)->links;
		while (l1)
		{
			l2 = (*(t_room **)r->content)->links;
			while (l2)
			{
				if (l1 != l2 && ft_strequ((*(t_room **)l1->content)->name,
					(*(t_room **)l2->content)->name))
					ft_error("Duplicate link");
				l2 = l2->next;
			}
			l1 = l1->next;
		}
		r = r->next;
	}
}

void	validate(t_lemin *lemin)
{
	if (!lemin->start || !lemin->end)
		ft_error("Missing start or end");
	validate_links(lemin);
}
