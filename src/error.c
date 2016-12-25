#include <lem_in.h>

void	ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl_fd(message, 2);
	exit(0);
}