/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_day_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:17 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/31 13:08:26 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_check(t_data *data)
{
	pthread_mutex_lock(&data->maklube);
	if (data->philos->porchion_counter == data->must_eat)
	{
		pthread_mutex_unlock(&data->maklube);
		return (1);
	}
	pthread_mutex_unlock(&data->maklube);
	return (0);
}

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->l_fork);
	daily_routine_of_a_nihilist(data, philo->name - 1, "has taken a fork");
	if (data->philo_ct == 1)
	{
		data->is_died = 1;
		printf("%d %d is died\n", data->time_t_die, philo->name);
		return ;
		sleep_like_a_freud(data->time_t_die * 2, data);
		pthread_mutex_unlock(&(philo->l_fork));
	}
	pthread_mutex_lock(philo->r_fork);
	daily_routine_of_a_nihilist(data, philo->name - 1, "has taken a fork");
	pthread_mutex_lock(&data->meal);
	daily_routine_of_a_nihilist(data, philo->name - 1, "is eating");
	philo->last_eat_time = moment();
	pthread_mutex_unlock(&data->meal);
	pthread_mutex_lock(&data->maklube);
	philo->porchion_counter++;
	pthread_mutex_unlock(&data->maklube);
	sleep_like_a_freud(data->time_t_eat, data);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	*schopenhauers_cage(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->name % 2 == 1)
		usleep(10000);
	while (die_like_a_nietzsche(p) != 1)
	{
		if (eat_check(p->data))
			break ;
		philo_eat(p, p->data);
		daily_routine_of_a_nihilist(p->data, p->name - 1, "is sleeping");
		sleep_like_a_freud(p->data->time_t_sleep, p->data);
		daily_routine_of_a_nihilist(p->data, p->name - 1, "is thinking");
	}
	return (NULL);
}
