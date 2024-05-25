/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:29:08 by thmouty           #+#    #+#             */
/*   Updated: 2024/03/03 21:28:42 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_n(char *str, int nb_read);
int		ft_strlen_n(char *str);
void	free_all(char **dict, int j, char *buff);
void	fill_line(char *str, int i, char **dict, int j);
void	divide_number(char *str, char **dict, int i);
int		error_gestion(int ac, char **av);
char	*ft_atoa(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	write_number(char *str, int i, int str_len, char **dict);
void	write_number_bis(char *str, int i, int str_len, char **dict);