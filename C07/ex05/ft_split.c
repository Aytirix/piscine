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

char	*ft_strstrV2(char *str, char *charset, int *endsplit)
{
	int	i;
	int	j;
	int	se[3] = {-1, 0, 0};

	i = *endsplit;
	j = 0;
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
	*endsplit = se[1] + j;
	return (ft_strcpy(str, se[0], se[1] - 1));
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		lendest;
	char	**dest;
	char	**destcpy;
	char	*strsplit;

	i = 0;
	lendest = 0;
	dest = malloc(sizeof(char *) + lendest);
	while (str[i])
	{
		destcpy = dest;
		strsplit = ft_strstrV2(str, charset, &i);
		lendest++;
		dest = malloc(sizeof(char *) + lendest);
		j = 0;
		while (j < lendest - 1)
		{
			dest[j] = destcpy[j];
			j++;
		}
		free(destcpy);
		dest[j] = strsplit;
	}
	// dest[strsplit] = "0";
	return (dest);
}

int	main(void)
{
	int size;
	char str[] = "a b c";
	char charset[] = " ";
	char *end;

	ft_split(str, charset);
	printf("%s", str);
}