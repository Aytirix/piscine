/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:20:45 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/25 16:38:55 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_numeric(char str);
int		ft_strlen(char *str);
int		brute_force(int tab[4][4], int position, int user_number[16]);
void	fill_table(int tab[4][4]);

int	check_str(char *str, int user_number[])
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_str_is_numeric(str[i]) && i % 2 == 0)
		{
			user_number[nb] = str[i] - '0';
			nb++;
			i++;
		}
		else if (i % 2 != 0 && str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	user_number[16];
	int	tab[4][4];

	if (ac != 2 || check_str(av[1], user_number) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fill_table(tab);
	if (brute_force(tab, 0, user_number) == 0)
		write(1, "Error\n", 6);
	return (0);
}
