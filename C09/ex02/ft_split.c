/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:38:59 by thmouty           #+#    #+#             */
/*   Updated: 2024/03/07 21:09:09 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	whitespace(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_whitespace(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (whitespace(str[i], charset) || str[i + 1] == '\0')
		{
			while (whitespace(str[i], charset) && str[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strndup(char *src, int nb, char *charset)
{
	int		i;
	int		cpy;
	char	*dest;

	i = 0;
	cpy = 0;
	dest = malloc(sizeof(char) * (nb + 1));
	while (i < nb)
	{
		if (whitespace(src[i], charset) == 0)
		{
			dest[cpy] = src[i];
			cpy++;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	up_whitespace(char *str, int i, char *charset)
{
	while (whitespace(str[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cpy;
	int		cwp;
	char	**split;

	i = 0;
	cpy = 0;
	cwp = count_whitespace(str, charset) + 1;
	split = malloc(sizeof(char *) * cwp);
	i = up_whitespace(str, i, charset);
	while (str[i])
	{
		if (whitespace(str[i], charset) || str[i + 1] == '\0')
		{
			if (str[i + 1] == '\0')
				i++;
			split[cpy++] = ft_strndup(str, i, charset);
			i = up_whitespace(str, i, charset);
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
	char	*charset;
	int		i;

	if (ac == 2)
	{
		charset = "a";
		split = ft_split(av[1], charset);
		i = 0;
		while (split[i] != 0)
		{
			printf("chaine %d : %s\n", i, split[i]);
			i++;
		}
	}
	return (0);
}
