/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:01:33 by dimolin2          #+#    #+#             */
/*   Updated: 2023/07/04 18:33:06 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	a;
	int		flag;

	if (ac != 5 && ac != 6)
		ft_error_msg("Invalid arguments number");
	flag = ft_init_and_set(&a, av);
	if (flag)
		ft_flag_error(flag);
	if (ft_starter(&a))
		ft_error_msg("There was an error creating the threads");
	return (0);
}
