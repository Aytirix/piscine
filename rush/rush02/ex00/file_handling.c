/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:48:47 by daricard          #+#    #+#             */
/*   Updated: 2024/03/03 21:18:46 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_n(char *str, int nb_read)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nb_read && str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_word(char *str)
{
	int		i;
	int		ic;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen_n(str) + 1));
	i = 0;
	ic = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i + 1] != ' ' || str[i] != ' ')
		{
			res[ic] = str[i];
			ic++;
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	fill_line(char *str, int i, char **dict, int j)
{
	char	*word;
	int		point;

	point = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == ':')
			point = 1;
		else if (point && str[i] == ' ' && str[i + 1] != ' ')
		{
			word = my_word(str + i + 1);
			dict[j] = malloc(sizeof(char) * (ft_strlen_n(word) + 1));
			ft_strcpy(dict[j], word);
			free(word);
			break ;
		}
		i++;
	}
}

void	free_all(char **dict, int j, char *buff)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(dict[i]);
		i++;
	}
	free(dict);
	free(buff);
}
