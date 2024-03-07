#include <stdio.h>
#include <string.h>

int ft_strspn(char *str, char *acc)
{
	int i = 0;
	int j = 0;
	while(str[i])
	{
		j = 0;
		while(acc[j])
		{
			if (str[i] == acc[j])
				break ;
			else if (acc[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(int ac, char *av[]) {
	if (ac == 3)
	{
		int longueur1 = strspn(av[1], av[2]);
		int longueur2 = ft_strspn(av[1], av[2]);
		printf("strspn: %d\n", longueur1);
		printf("ft_strspn: %d\n\n", longueur2);
	}
    return 0;
}
