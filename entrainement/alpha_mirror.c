#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char *av[])
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			// if (av[1][i] >= 'a' && av[1][i] <= 'm')
			// 	ft_putchar('a' - av[1][i] + 122);
			// else if (av[1][i] >= 'n' && av[1][i] <= 'z')
			// 	ft_putchar('z' - av[1][i] + 97);
			// else if (av[1][i] >= 'A' && av[1][i] <= 'M')
			// 	ft_putchar('A' - av[1][i] + 90);
			// else if (av[1][i] >= 'N' && av[1][i] <= 'Z')
			// 	ft_putchar('Z' - av[1][i] + 97);
			// else
			// 	ft_putchar(av[1][i]);
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				ft_putchar('m' - (av[1][i] - 'n'));
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				ft_putchar('M' - (av[1][i] - 'N'));
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}