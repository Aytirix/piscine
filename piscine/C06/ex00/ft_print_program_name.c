/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:23:06 by thmouty           #+#    #+#             */
/*   Updated: 2024/02/27 18:33:28 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	(void) argc;
	i = 0;
	while (argv[0][i] != '\0')
		write(1, &argv[0][i++], 1);
	write(1, "\n", 1);
	return (0);
}
