/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:06:39 by thmouty           #+#    #+#             */
/*   Updated: 2024/03/06 16:27:22 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*dest;
	int					i;

	dest = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		dest[i].size = ft_strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = ft_strdup(av[i]);
		i++;
	}
	dest[i].str = 0;
	return (dest);
}

/*
int	main(int ac, char *av[])
{
	struct s_stock_str	*dest;
	int					i;

	*dest = ft_strs_to_tab(ac, av);
	i = 0;
	while (i < ac)
	{
		printf("Structure : %d\n", i);
		printf("taille : %d\n", dest[i].size);
		printf("chaine  : %s\n", dest[i].str);
		printf("copie   : %s\n", dest[i].copy);
		printf("\n\n");
		free(dest[i].copy);
		i++;
	}
	free(dest);
}
*/