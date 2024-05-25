/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:03:27 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/14 18:51:55 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	i;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i >= 10 || i <= -10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar(i % 10 + '0');
}

/*int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 2);
	ft_putnbr(2147483647);
	return (0);
}*/
