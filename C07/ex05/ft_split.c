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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strcpy(char *src, int start, int end)
{
	int		i;
	int		len;
	char	*dest;

	dest = malloc(sizeof(char) * (end - start + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strstrV2(char **pstr, char *charset)
{
	char	*str;
	char	*strcpy;
	int		i;
	int		j;
	int		se[3];

	str = *pstr;
	strcpy = str;
	i = 0;
	j = 0;
	se[0] = -1;
	se[1] = ft_strlen(str);
	se[2] = se[1];
	while (str[i] && (se[0] == -1 || se[1] == se[2]))
	{
		j = 0;
		while (str[i + j] == charset[j] || charset[j] == '\0')
		{
			if (charset[j] == '\0')
			{
				if (se[0] == -1)
					se[0] = i + j;
				else
					se[1] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	*pstr = &str[se[1]];
	return (ft_strcpy(strcpy, se[0], se[1] - 1));
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		lendest;
	char	**dest;

	i = 0;
	while (str[i])
	{
		break ;
	}
	return (dest);
}

int	main(void)
{
	int		size;
	char	str[20] = "salut salot alutaow";
	char	charset[3] = "sa";
	char	*end;

	ft_strstrV2(&str, charset);
	printf("%s", str);
}
