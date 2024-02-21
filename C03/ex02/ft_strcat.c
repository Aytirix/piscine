/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:15 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/20 18:15:21 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size_dest;

	size_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = '\0';
	return (dest);
}

/*int main(void)
{
	char s1[100] = "Hello";
	char s2[5\] = " Worldd";
	char *result = ft_strcat(s1, s2);
	printf("%s", result);
	return (0);
}*/