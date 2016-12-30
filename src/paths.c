/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:19:22 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 05:27:00 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_room	**list_to_array(t_list *lst)
{
	int		len;
	t_room	**ret;
	t_list	*l;

	len = 0;
	l = lst;
	while (l)
	{
		len++;
		l = l->next;
	}
	ret = (t_room **)ft_memalloc(sizeof(t_room *) * (len + 1));
	while (lst)
	{
		ret[--len] = (*(t_room **)lst->content);
		lst = lst->next;
	}
	return (ret);
}

void			add_path(t_lemin *lemin, t_list *lst)
{
	t_path	*path;

	path = (t_path *)ft_memalloc(sizeof(t_path));
	path->links = list_to_array(lst);
	while (path->links[++path->length])
		;
	ft_lstadd(&lemin->paths, ft_lstnew(&path, sizeof(t_path *)));
}

int				is_link_in_path(t_list *path, t_room *room)
{
	while (path)
	{
		if (room == *(t_room **)path->content)
			return (1);
		path = path->next;
	}
	return (0);
}

void			find_paths(t_lemin *lemin, t_list *path, t_room *room)
{
	t_list *links;

	links = room->links;
	while (links)
	{
		if (*(t_room **)links->content == lemin->end)
			add_path(lemin, path);
		else if (!is_link_in_path(path, *(t_room **)links->content) &&
			*(t_room **)links->content != lemin->start)
		{
			ft_lstadd(&path, ft_lstnew(links->content, sizeof(t_room *)));
			find_paths(lemin, path, *(t_room **)links->content);
			path = path->next;
		}
		links = links->next;
	}
}
