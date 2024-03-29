/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:56:11 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/18 11:56:13 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	main(void)
{
	write(1, "rush(5, 3);\n", 12);
	rush(5, 3);
	write (1, "\nrush(5, 1);\n", 13);
	rush(5, 1);
	write (1, "\nrush(1, 1);\n", 13);
	rush(1, 1);
	write(1, "\nrush(1, 5);\n", 13);
	rush(1, 5);
	write(1, "\nrush(4, 4);\n", 13);
	rush(4, 4);
	write(1, "\nrush(123, 42);\n", 16);
	rush(123, 42);
	write(1, "\nrush(2, 3);\n", 13);
	rush(2, 3);
	write(1, "\nrush(3, 3);\n", 13);
	rush(3, 3);
	return (0);
}
