/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:06 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/21 15:44:56 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbs;

	nbs = nb;
	if (nbs < 0)
	{
		ft_putchar('-');
		nbs = -nbs;
	}
	if (nbs <= -10 || nbs >= 10)
		ft_putnbr(nbs / 10);
	ft_putchar(nbs % 10 + '0');
}

/*int main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/