/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:31:48 by diego             #+#    #+#             */
/*   Updated: 2023/07/04 17:37:40 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_mutex(t_all *a)
{
	int	x;

	x = a->philo_num;
	while (--x >= 0)
	{
		if (pthread_mutex_init(&(a->fork[x]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(a->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(a->meal_check), NULL))
		return (1);
	return (0);
}

int	ft_set_philos(t_all *a)
{
	int	n;

	n = a->philo_num;
	while (--n >= 0)
	{
		a->philos[n].id = n;
		a->philos[n].x_ate = 0;
		a->philos[n].left_fork_id = n;
		a->philos[n].right_fork_id = (n + 1) % a->philo_num;
		a->philos[n].t_last_meal = 0;
		a->philos[n].rules = a;
	}
	return (0);
}

int	ft_init_and_set(t_all *a, char **av)
{
	a->philo_num = ft_atoi(av[1]);
	a->death_time = ft_atoi(av[2]);
	a->eat_time = ft_atoi(av[3]);
	a->sleep_time = ft_atoi(av[4]);
	a->f = 0;
	a->big_party = 0;
	if (a->philo_num < 1 || a->death_time < 0 || a->eat_time < 0
		|| a->sleep_time < 0 || a->philo_num > 250)
		return (1);
	if (av[5])
	{
		a->nb_eat = ft_atoi(av[5]);
		if (a->nb_eat <= 0)
			return (1);
	}
	else
		a->nb_eat = -1;
	if (ft_set_mutex(a))
		return (2);
	ft_set_philos(a);
	return (0);
}
