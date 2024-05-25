/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:55:17 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/28 10:55:19 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;

	dest = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	dest = malloc(sizeof(int) * (max - min));
	if (dest == NULL)
	{
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	*range = dest;
	return (i);
}
