#include "doom-nukem.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_env	e;

	if ((e.parsor.fd = open(av[1], O_RDONLY)) == -1)
		exit(1);
	doom_parsor(&e);
	(void)ac;
	for (int i = 0; i < 4; i++)
		ft_printf("%d\n", e.n_list[i]);
	return (0);
}
