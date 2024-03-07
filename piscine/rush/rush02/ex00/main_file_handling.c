/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:55:40 by daricard          #+#    #+#             */
/*   Updated: 2024/03/03 21:33:05 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_open_and_read(char **buff, int fd, int nb_read)
{
	int	allocation;

	allocation = 2000;
	*buff = malloc(sizeof(char) * allocation);
	if (*buff == 0)
		return (-1);
	if (fd == -1)
		return (-1);
	nb_read = read(fd, *buff, allocation);
	if (nb_read == -1)
		return (-1);
	return (nb_read);
}

int	main_loop(char *buff, int nb_read, char **dict, int fd)
{
	int	i;

	i = 0;
	while (i < nb_read)
	{
		fill_line(buff, i, dict, fd);
		i += (ft_strlen_n(buff + i) + 1);
		fd++;
	}
	return (fd);
}

int	main(int ac, char **av)
{
	char	*buff;
	int		fd;
	int		nb_read;
	char	**dict;

	if (error_gestion(ac, av))
		return (1);
	if (ac == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	nb_read = ft_open_and_read(&buff, fd, 0);
	if (nb_read == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	dict = malloc(sizeof(char *) * count_n(buff, nb_read));
	if (dict == 0)
		return (1);
	close(fd);
	fd = main_loop(buff, nb_read, dict, 0);
	divide_number(ft_atoa(av[ac - 1]), dict, 0);
	free_all(dict, fd, buff);
	return (0);
}
