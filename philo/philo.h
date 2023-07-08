/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:02:05 by dimolin2          #+#    #+#             */
/*   Updated: 2023/07/04 18:27:28 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_all	*rules;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_all
{
	int				philo_num;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				nb_eat;
	int				f;
	int				big_party;
	long long		first_timestamp;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_check;
	t_philo			philos[250];
}					t_all;

// error functions
int					ft_error_msg(char *str);
int					ft_flag_error(int flag);

// starter functions
void				*p_thread(void *void_philosopher);
void				philo_eats(t_philo *philo);
void				death_checker(t_all *r, t_philo *p);
void				exit_launcher(t_all *rules, t_philo *philos);
int					ft_starter(t_all *a);

// init and set functions
int					ft_init_and_set(t_all *a, char **av);
int					ft_set_mutex(t_all *a);
int					ft_set_philos(t_all *a);

// utils functions
void				ft_do_action(t_all *a, int id, char *string);
void				ft_sleep(long long time, t_all *a);
int					ft_atoi(const char *str);
long long			timestamp(void);
long long			time_diff(long long past, long long pres);

#endif