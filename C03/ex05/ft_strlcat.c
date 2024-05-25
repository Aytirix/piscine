/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:15 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/20 19:24:30 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (i < (dstsize - dest_len) && src[i] != '\0'
		&& (dest_len + i < dstsize -1))
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}

/*int main(void)
{
	char dest[8] = "Hello";
	char src[] = " World !";
	int result = ft_strlcat(dest, src, 8);
	printf("TEST 1 \n");
	printf("return : %u \n%s\n", result, dest);
	printf("attendu : Hello W\n");

	char dest2[20] = "Hello";
	char src2[] = " World !";
	int result2 = ft_strlcat(dest2, src2, 20);
	printf("TEST 1 \n");
	printf("return : %u \n%s\n", result2, dest2);
	printf("attendu : Hello World !\n");

	char dest3[14] = "Hello";
	char src3[] = " World !";
	int result3 = ft_strlcat(dest3, src3, 14);
	printf("TEST 1 \n");
	printf("return : %u \n%s\n", result3, dest3);
	printf("attendu : Hello World !\n");
	return (0);
}*/