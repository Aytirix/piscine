/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:05:40 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/25 15:54:24 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_table(int tab[4][4]);
int		is_valid_solution(int tab[4][4], int user_number[16]);

int	brute_force(int tab[4][4], int position, int user_number[16])
{
	int	num;
	int	row;
	int	row_value;

	num = 1;
	if (position == 16)
	{
		if (is_valid_solution(tab, user_number))
		{
			print_table(tab);
			return (1);
		}
	}
	while (position != 16 && num <= 4)
	{
		row = position / 4;
		row_value = position % 4;
		tab[row][row_value] = num;
		if (brute_force(tab, position + 1, user_number) == 1)
			return (1);
		tab[row][row_value] = 0;
		num++;
	}
	return (0);
}
