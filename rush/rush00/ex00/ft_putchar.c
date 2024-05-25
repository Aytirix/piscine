/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:56:49 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/18 11:56:50 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

/**
 *  Fonction print :
 *
 *      Cette fonction permet d'afficher sur une ligne une séquence de 
 		caractères selon les paramètres spécifiés.
 *
 *  Paramètres :
 *      int width - quantité de caractère à afficher
 *      char start - le premier caractère de la ligne sera afficher
 		une seul fois
 *      char middle - le caractère du millieu sera afficher width-2 
 		fois par ligne (on décompte le premier et le dernier caractère)
 *      char end - le dernier caractère de la ligne sera afficher une 
 		seul fois (seulement si width >= 3)
 *
 *  Exemple d'utilisation :
 *      print(5, "G", "U", "V");
 *      résultat : "GUUUV"
 */
void	ft_putchar(int width, char start, char middle, char end)
{
	int	i;

	if (width >= 3)
		i = 2;
	else
		i = 1;
	print(start);
	while (i < width)
	{
		print(middle);
		i++;
	}
	if (width >= 3)
		print(end);
	print('\n');
}
