/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:56:28 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/18 11:56:30 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *  Fonction rush :
 *
 *      Cette fonction dessine un rectangle dans la console avec des dimensions
 		et des caractères spécifiés.
 *
 *  Paramètres :
 *      int x - largeur du rectangle (nombre de caractères par ligne).
 *      int y - hauteur du rectangle (nombre de lignes).
 */

void	ft_putchar(int width, char start, char middle, char end);

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	while (i <= y)
	{
		if (i == 1)
			ft_putchar(x, 'A', 'B', 'C');
		else if (y != i)
			ft_putchar(x, 'B', ' ', 'B');
		else
			ft_putchar(x, 'C', 'B', 'A');
		i++;
	}
}
