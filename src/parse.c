#include <lem_in.h>

void	parse_link(t_lemin *lemin, char *str)
{
	char **split;
	t_room *r1;
	t_room *r2;
	t_list *iter;

	split = ft_strsplit(str, '-');
	iter = lemin->rooms;
	r1 = 0;
	r2 = 0;
	while (iter)
	{
		if (ft_strequ(split[0], (*(t_room **)iter->content)->name))
			r1 = *(t_room **)iter->content;
		if (ft_strequ(split[1], (*(t_room **)iter->content)->name))
			r2 = *(t_room **)iter->content;
		iter = iter->next;
	}
	if (r2 && r1 && r1 != r2)
	{
		ft_lstadd(&(r1->links), ft_lstnew(&r2, sizeof(t_room *)));
		ft_lstadd(&(r2->links), ft_lstnew(&r1, sizeof(t_room *)));
	}
	else
		ft_error("Invalid link");
}

void	parse_room(t_lemin *lemin, char *str, int next)
{
	char **split;
	t_room *room;

	if (ft_count_words(str, ' ') != 3 || str[0] == 'L')
		ft_error("Bad room name");
	split = ft_strsplit(str, ' ');
	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = split[0];
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	ft_lstadd(&lemin->rooms, ft_lstnew(&room, sizeof(t_room *)));
	if (next == 2)
	{
		if (lemin->start)
			ft_error("Extra start");
		lemin->start = room;
	}
	else if (next == 3)
	{
		if (lemin->end)
			ft_error("Extra end");
		lemin->end = room;
	}
}

void	parse(t_lemin *lemin)
{
	int		res;
	int		next;
	char	*str;
	int		line;

	next = 1;
	line = 0;
	while ((res = ft_get_next_line(0, &str)) > 0)
	{
		if (next == 2 || next == 3)
		{
			parse_room(lemin, str, next);
			next = 1;
		}
		else if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
			next = (str[2] == 's' ? 2 : 3);
		else if (str[0] == '#')
			;
		else if (line++ == 0)
			lemin->num_ants = ft_atoi(str);
		else if (ft_count_words(str, ' ') == 3)
		{
			if (next == 0)
				ft_error("Room in the middle of links");
			parse_room(lemin, str, next);
		}
		else if (ft_count_words(str, '-') == 2 && str[0] != '-' && str[ft_strlen(str) - 1] != '-')
		{
			if (next != 0)
				validate_rooms(lemin);
			next = 0;
			parse_link(lemin, str);
		}
		else
			ft_error("Invalid line");
		ft_putendl(str);
	}
}