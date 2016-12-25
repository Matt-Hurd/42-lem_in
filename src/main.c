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