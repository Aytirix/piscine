/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:15 by thmouty           #+#    #+#             */
/*   Updated: 2024/04/22 20:29:18 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (str[0] == '\0' && to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] || to_find[j] == '\0')
		{
			if (to_find[j] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int main(int ac, char **av)
{
	char s1[] = "Hello World !!!";
	char s2[] = "World";
	char *result = ft_strstr(av[1], av[2]);
	char *result2 = strstr(av[1], av[2]);
	printf("%s\n", result);
	printf("%s\n", result2);
	return (0);
}*/