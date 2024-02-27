/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:15:50 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/27 13:05:20 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
			ft_swap(&tab[min_index], &tab[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	argc -= 1;
	while (argc > i)
	{
		write(1, argv[argc], ft_strlen(argv[argc]));
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
