/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:29:10 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/21 20:50:39 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_strupcase(char *str)
{
	if ('a' <= *str && 'z' >= *str)
		*str = *str - 32;
}

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && 'Z' >= str[i])
			str[i] = str[i] + 32;
		i++;
	}
}

int	ft_str_is_alpha_num(char *str)
{
	return ((*str >= 'a' && *str <= 'z')
		|| (*str >= 'A' && *str <= 'Z')
		|| (*str >= '0' && *str <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (ft_str_is_alpha_num(&str[i]) == 1)
			if ((i == 0) || (ft_str_is_alpha_num(&str[i] - 1) == 0))
				ft_strupcase(&str[i]);
		i++;
	}
	return (str);
}

/*int	main()
{
	char str[] = "comment tu vas ? 42mots quarante-deux; cinquante+et+un\n";
	char *res = ft_strcapitalize(str);
	printf("%s", res);
	printf("Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un");

	return (0);
}*/