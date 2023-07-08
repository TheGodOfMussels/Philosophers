/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:09:13 by dimolin2          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:19 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_msg(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, "Error: ", 7);
	write(1, str, len);
	write(1, "\n", 1);
	exit(0);
	return (1);
}

int	ft_flag_error(int flag)
{
	if (flag == 1)
		return (ft_error_msg("At least one wrong argument"));
	if (flag == 2)
		return (ft_error_msg("Fatal error when intializing mutex"));
	return (1);
}
