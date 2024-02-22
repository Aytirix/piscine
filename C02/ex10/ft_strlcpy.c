/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:43:07 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/22 12:14:48 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	char dest[10] = "salut !";
	char *src = "hello comment";
	ft_strlcpy(dest, src , 10);
	printf("%s", dest);
	return (0);
}*/