/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/03/04 16:08:31 by thmouty           #+#    #+#             */
/*   Updated: 2024/03/04 16:08:31 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	float max;
	float min;
	float m;
	int i;

	max = 46340;
	min = 0;
	i = 0;
	while (i < 50)
	{
		m = (min + max) / 2;
		if ((int)m * (int)m == nb)
			return (m);
		else if ((int)m * (int)m > nb)
			max = m;
		else
			min = m;
		i++;
	}
	return (0);
}