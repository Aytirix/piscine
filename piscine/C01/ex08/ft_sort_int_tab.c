/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:54:44 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/22 18:07:59 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			{
				min_index = j;
			}
			j++;
		}
		if (min_index != i)
		{
			ft_swap(&tab[min_index], &tab[i]);
		}
		i++;
	}
}
/*int	main(void)
{
	int tab[15] = {25,4,5,65,2,48,1,4,8,6,6,48,458,5};
	ft_sort_int_tab(tab, 15);
	int i = 0;
	printf("%d", tab);
	return (0);
}*/