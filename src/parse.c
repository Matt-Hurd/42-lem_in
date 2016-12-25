#include <lem_in.h>

void	parse_link(t_lemin *lemin, char *str)
{
	// Need checks for duplicate links
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
		// printf("%p\n", iter->content);
		// printf("%s, %s, %s\n", split[0], split[1], (*(t_room **)iter->content)->name);
		if (ft_strequ(split[0], (*(t_room **)iter->content)->name))
			r1 = *(t_room **)iter->content;
		if (ft_strequ(split[1], (*(t_room **)iter->content)->name))
			r2 = *(t_room **)iter->content;
		iter = iter->next;
		// printf("%p, %p\n", r1, r2);
	}
	if (r2 && r1 && r1 != r2)
	{
		ft_lstadd(&(r1->links), ft_lstnew(&r2, sizeof(t_room *)));
		ft_lstadd(&(r2->links), ft_lstnew(&r1, sizeof(t_room *)));
	}
	else
		{} //throw error
}

void	parse_room(t_lemin *lemin, char *str, int next)
{
	//Need checks for duplicate room names
	char **split;
	t_room *room;

	if (ft_count_words(str, ' ') != 3 || str[0] == 'L')
		exit(1); //bad input
	split = ft_strsplit(str, ' ');
	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = split[0];
	room->x = ft_atoi(split[1]); //add check from push_swap
	room->y = ft_atoi(split[2]); //add check from push_swap
	ft_lstadd(&lemin->rooms, ft_lstnew(&room, sizeof(t_room *)));
	if (next == 2) //merge these two?
	{
		if (lemin->start)
			{} //throw error
		lemin->start = room;
	}
	else if (next == 3)
	{
		if (lemin->end)
			{} //throw error
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
		printf("%s\n", str);
		if (next == 2 || next == 3)
		{
			parse_room(lemin, str, next);
			next = 1;
		}
		if (line++ == 0)
			lemin->num_ants = ft_atoi(str);
		else if (ft_strequ(str, "##start"))
			next = 2;
		else if (ft_strequ(str, "##end"))
			next = 3;
		else if (ft_count_words(str, ' ') == 3)
		{
			if (next == 0)
				{} //throw error
			parse_room(lemin, str, next);
		}
		else if (ft_count_words(str, '-') == 2)
		{
			next = 0;
			parse_link(lemin, str);
		}
		else if (str[0] != '#')
			{} //throw error
	}
}