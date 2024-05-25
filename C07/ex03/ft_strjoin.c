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

int	ft_strcat(char *dest, char *src, int lendest)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[lendest] = src[j];
		lendest++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	int		lendest;
	char	*dest;

	len = ft_strlen(sep) * (size - 1);
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]) - 1;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL || size == 0)
		if (dest != NULL)
			dest[0] = '\0';
		return (dest);
	i = -1;
	lendest = 0;
	while (++i < size)
	{
		lendest += ft_strcat(dest, strs[i], lendest);
		if (i < size - 1)
			lendest += ft_strcat(dest, sep, lendest);
	}
	dest[lendest] = '\0';
	return (dest);
}

/*int	main(void)
{
	int		size;
	char	sep1[6] = "salut";
	char	sep2[8] = "comment";
	char	sep3[5] = "cava";
	char	sep4[3] = " ?";
	char	*strs[] = {sep1, sep2, sep3, sep4};
	char	sep[4] = "/-/";

	size = 4;
	ft_strjoin(size, strs, sep);
}*/
