/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:05:40 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/25 16:41:04 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

void	print_table(int tab[4][4])
{
	int	row;
	int	row_value;

	row = 0;
	while (row < 4)
	{
		row_value = 0;
		while (row_value < 4)
		{
			ft_putchar(tab[row][row_value] + '0');
			ft_putchar(' ');
			row_value++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	fill_table(int tab[4][4])
{
	int	row;
	int	row_value;

	row = 0;
	while (row < 4)
	{
		row_value = 0;
		while (row_value < 4)
		{
			tab[row][row_value] = 0;
			row_value++;
		}
		row++;
	}
}
