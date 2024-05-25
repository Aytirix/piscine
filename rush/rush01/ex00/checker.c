/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:05:40 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/25 15:41:42 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	count_line(int tab[4][4])
{
	int	row;
	int	row_value;
	int	sum;

	row = 0;
	while (row < 4)
	{
		sum = 0;
		row_value = 0;
		while (row_value < 4)
		{
			sum += tab[row][row_value];
			row_value++;
		}
		if (sum != 10)
			return (0);
		row++;
	}
	return (1);
}

int	count_column(int tab[4][4])
{
	int	col;
	int	col_value;
	int	sum;

	col_value = 0;
	while (col_value < 4)
	{
		sum = 0;
		col = 0;
		while (col < 4)
		{
			sum += tab[col][col_value];
			col++;
		}
		if (sum != 10)
			return (0);
		col_value++;
	}
	return (1);
}

int	count_visible_boxes_from_start(int *line)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	count_visible_boxes_from_end(int *line)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 3;
	while (i >= 0)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}

int	is_valid_solution(int tab[4][4], int user_number[16])
{
	int	temp_line[4];
	int	i;
	int	j;

	i = 0;
	if (count_line(tab) == 0 || count_column(tab) == 0)
		return (0);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			temp_line[j] = tab[j][i];
		if (count_visible_boxes_from_start(temp_line) != user_number[i]
			|| count_visible_boxes_from_end(temp_line) != user_number[i + 4])
			return (0);
		i++;
	}
	i = -1;
	while (++i < 4)
		if (count_visible_boxes_from_start(tab[i]) != user_number[i + 8]
			|| count_visible_boxes_from_end(tab[i]) != user_number[i + 12])
			return (0);
	return (1);
}
