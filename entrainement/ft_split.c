#include <stdio.h>
#include <stdlib.h>

int whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == ' ');
}

int count_whitespace(char *str)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if (whitespace(str[i]) || str[i + 1] == '\0')
		{
			while(whitespace(str[i]) && str[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

char *ft_strndup(char *src, int nb)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * (nb + 1));
	while(i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    **ft_split(char *str)
{
    int        i = 0;
    int        cpy = 0;

    int cwp = count_whitespace(str) + 1;
    char    **split = malloc(sizeof(char *) * cwp);
    while(whitespace(str[i]))
        i++;
    while(str[i])
    {
        if (whitespace(str[i]) || str[i + 1] == '\0')
            {
				if (str[i + 1] == '\0')
					i++;
                split[cpy++] = ft_strndup(str, i);
                while(whitespace(str[i]))
                    i++;
                str += i;
                i = 0;
            }
        i++;
    }
    split[cwp - 1] = 0;
    return (split);
}

int	main(int ac, char *av[])
{
	char	**split;

	if (ac == 2)
	{
		split = ft_split(av[1]);
		int i = 0;
		while (split[i] != 0)
		{
			printf("chaine %d : %s\n", i, split[i]);
			i++;
		}
	}
	return (0);
}
