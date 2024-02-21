/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:06 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/21 17:55:32 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_isspace(char str)
{
	return ((str == ' ' || str == '\\n'
		|| str == '\\t' || str == '\\v'
		|| str == '\\f' || str == '\\r'));
}

int ft_atoi(char *str)
{
	int i;
	int	sign;
	int	result;

	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
	}
	while ()
	{
		
	}
}

int	main(void)
{
	ft_atoi("---+--+1234ab567");
	return (0);
}
