/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daricard <daricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:50:04 by tbartocc          #+#    #+#             */
/*   Updated: 2024/03/03 16:17:12 by daricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "lib.h"

void	write_number_bis_2(char *str, int i, int str_len, char **dict)
{
	if ((str_len - i) % 3 == 0)
	{
		if (str[i] != '0')
		{
			ft_putstr(dict[(str[i] - '0')]);
			ft_putchar(' ');
			ft_putstr(dict[28]);
			if (str[i + 1] != '0' || str[i + 2] != '0')
				ft_putchar(' ');
		}
		if (str[i + 1] == '1')
			ft_putstr(dict[10 + (str[i + 2] - '0')]);
		else if ((str[i + 1] != '1') && (str[i + 1] != '0'))
		{
			ft_putstr(dict[18 + (str[i + 1] - '0')]);
			ft_putchar(' ');
			ft_putstr(dict[str[i + 2] - '0']);
		}
		else if (str[i + 2] != '0')
			ft_putstr(dict[str[i + 2] - '0']);
	}
}

void	write_number_bis(char *str, int i, int str_len, char **dict)
{
	if (((str_len - i) % 3 == 1))
		ft_putstr(dict[str[i] - '0']);
	if ((str_len - i) % 3 == 2)
	{
		if (str[i] == '1')
			ft_putstr(dict[10 + (str[i + 1] - '0')]);
		else if ((str[i] != '1') && (str[i] != '0'))
		{
			ft_putstr(dict[18 + (str[i] - '0')]);
			ft_putchar(' ');
			if (str[i + 1] != '0')
				ft_putstr(dict[str[i + 1] - '0']);
		}
	}
	write_number_bis_2(str, i, str_len, dict);
}

void	write_number3(char *str, int i, char **dict)
{
	if (str[i + 1] == '1')
	{
		ft_putstr(dict[10 + (str[i + 2] - '0')]);
		ft_putchar(' ');
	}
	else if ((str[i + 1] != '1') && (str[i + 1] != '0'))
	{
		ft_putstr(dict[18 + (str[i + 1] - '0')]);
		ft_putchar(' ');
		ft_putstr(dict[str[i + 2] - '0']);
		ft_putchar(' ');
	}
	else if (str[i + 2] != '0')
	{
		ft_putstr(dict[str[i + 2] - '0']);
		ft_putchar(' ');
	}
}

void	write_number2(char *str, int i, int str_len, char **dict)
{
	if ((str_len - i) % 3 == 0)
	{
		if (str[i] != '0')
		{
			ft_putstr(dict[(str[i] - '0')]);
			ft_putchar(' ');
			ft_putstr(dict[28]);
			ft_putchar(' ');
		}
		write_number3(str, i, dict);
	}
}

void	write_number(char *str, int i, int str_len, char **dict)
{
	if (((str_len - i) % 3 == 1))
	{
		ft_putstr(dict[str[i] - '0']);
		ft_putchar(' ');
	}
	if ((str_len - i) % 3 == 2)
	{
		if (str[i] == '1')
		{
			ft_putstr(dict[10 + (str[i + 1] - '0')]);
			ft_putchar(' ');
		}
		else if ((str[i] != '1') && (str[i] != '0'))
		{
			ft_putstr(dict[18 + (str[i] - '0')]);
			ft_putchar(' ');
			if (str[i + 1] != '0')
			{
				ft_putstr(dict[str[i + 1] - '0']);
				ft_putchar(' ');
			}
		}
	}
	write_number2(str, i, str_len, dict);
}
