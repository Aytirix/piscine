/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:09:04 by tbartocc          #+#    #+#             */
/*   Updated: 2024/03/03 21:25:45 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int	write_base(char **dict, int str_len, char *str, int nb_3)
{
	static int	space = 0;
	int			i;

	nb_3 = 0;
	if (nb_3 == 0)
		if (*(str - 3) != '0' && *(str - 2) - '0' != '0' && *(str - 1)
			- '0' != '0')
			ft_putstr(dict[29 + (str_len / 3) - 1]);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			i++;
		else
		{
			if (space == 0)
				ft_putchar(' ');
			space = 1;
			return (0);
		}
	}
	space = 0;
	return (1);
}

int	error_gestion(int ac, char **av)
{
	int		i;
	char	*numbers;

	numbers = av[ac - 1];
	if ((ac != 3 && ac != 2) || (ft_strlen(numbers) > 39))
	{
		ft_putstr("Error\n");
		return (1);
	}
	i = 0;
	while (numbers[i] != '\0')
	{
		if ((numbers[i] < '0' || numbers[i] > '9') && numbers[i] != ' ')
		{
			ft_putstr("Dict Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	divide_number(char *str, char **dict, int i)
{
	int	str_len;
	int	str_len_cpy;

	str_len = ft_strlen(str);
	str_len_cpy = str_len;
	while (str[i] != '\0')
	{
		if (str_len - i > 3)
			write_number(str, i, str_len, dict);
		else
			write_number_bis(str, i, str_len, dict);
		if ((str_len - i) % 3 == 0)
			i += 3;
		if ((str_len - i) % 3 == 2)
			i += 2;
		if ((str_len - i) % 3 == 1)
			i += 1;
		if (str_len_cpy > 3)
		{
			if (write_base(dict, str_len_cpy - 1, str + i, (str_len - i) % 3))
				break ;
			str_len_cpy -= 3;
		}
	}
}
