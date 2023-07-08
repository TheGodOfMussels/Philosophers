/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:47:08 by diego             #+#    #+#             */
/*   Updated: 2023/07/04 17:51:45 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_all	*a;

	a = philo->rules;
	pthread_mutex_lock(&(a->fork[philo->left_fork_id]));
	ft_do_action(a, philo->id, "has taken a fork");
	pthread_mutex_lock(&(a->fork[philo->right_fork_id]));
	ft_do_action(a, philo->id, "has taken a fork");
	pthread_mutex_lock(&(a->meal_check));
	ft_do_action(a, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(a->meal_check));
	ft_sleep(a->eat_time, a);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(a->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(a->fork[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philo			*philo;
	t_all			*a;

	i = 0;
	philo = (t_philo *)void_philosopher;
	a = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(a->f))
	{
		philo_eats(philo);
		if (a->big_party)
			break ;
		ft_do_action(a, philo->id, "is sleeping");
		ft_sleep(a->sleep_time, a);
		ft_do_action(a, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_all *rules, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->philo_num)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->philo_num)
		pthread_mutex_destroy(&(rules->fork[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	death_checker(t_all *r, t_philo *p)
{
	int	i;

	while (!(r->big_party))
	{
		i = -1;
		while (++i < r->philo_num && !(r->f))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->death_time)
			{
				ft_do_action(r, i, "died");
				r->f = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->f)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->philo_num && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->philo_num)
			r->big_party = 1;
	}
}

int	ft_starter(t_all *a)
{
	int		i;
	t_philo	*phi;

	i = 0;
	phi = a->philos;
	a->first_timestamp = timestamp();
	if (a->philo_num == 1)
	{
		ft_do_action(a, a->philos->id, "has taken a fork");
		usleep(a->death_time * 1000);
		ft_do_action(a, a->philos->id, "died");
		return (0);
	}
	while (i < a->philo_num)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(a, a->philos);
	exit_launcher(a, phi);
	return (0);
}
