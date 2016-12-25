#include <lem_in.h>

void	sort_paths(t_lemin *lemin)
{
	(void)lemin;
}

void	ft_put_move(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	move_ant(t_lemin *lemin, int path)
{
	int x;

	x = -1;
	while (++x < lemin->num_ants)
	{
		if (lemin->ants[x].path == -1)
		{
			ft_put_move(x + 1, lemin->patharr[path]->links[0]->name);
			lemin->remaining_ants--;
			lemin->ants[x].path = path;
			return ;
		}
	}
}

void	continue_ants(t_lemin *lemin)
{
	int x;

	x = -1;
	lemin->finished = 1;
	char *next;
	while (++x < lemin->num_ants)
	{
		if (lemin->ants[x].room != -1 && lemin->ants[x].path != -1)
		{
			next = (lemin->ants[x].room + 1 >= lemin->patharr[lemin->ants[x].path]->length) ? lemin->end->name : lemin->patharr[lemin->ants[x].path]->links[lemin->ants[x].room + 1]->name;
			ft_put_move(x + 1, next);
			lemin->ants[x].room += 1;
			if (lemin->patharr[lemin->ants[x].path]->length <= lemin->ants[x].room)
				lemin->ants[x].room = -1;
		}
		if (lemin->ants[x].room != -1)
			lemin->finished = 0;
	}
}

void	do_turn(t_lemin *lemin)
{
	int x;
	int y;
	int total;

	x = -1;
	continue_ants(lemin);
	while (++x < lemin->pc)
	{
		y = -1;
		total = 0;
		while (++y < lemin->pc)
		{
			if (x == y)
				continue;
			if (lemin->patharr[lemin->best_paths[x]]->length > lemin->patharr[lemin->best_paths[y]]->length)
				total += lemin->patharr[lemin->best_paths[x]]->length / lemin->patharr[lemin->best_paths[y]]->length;
		}
		if (total < lemin->remaining_ants)
			move_ant(lemin, lemin->best_paths[x]);
	}
	ft_putchar('\n');
}

void	print_solution(t_lemin *lemin)
{
	lemin->remaining_ants = lemin->num_ants;
	ft_putchar('\n');
	sort_paths(lemin);
	lemin->finished = 0;
	while (!lemin->finished)
		do_turn(lemin);
}