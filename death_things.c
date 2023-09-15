/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:44 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/30 17:55:38 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	die_like_a_nietzsche(t_philo *philo)
{
	int	i;
	int	tmp;

	i = -1;
	pthread_mutex_lock(&(philo->data->death));
	while ((++i < philo->data->philo_ct) && (philo->data->is_died == 0))
	{
		pthread_mutex_unlock(&(philo->data->death));
		pthread_mutex_lock(&(philo->data->meal));
		if (moment() - philo[i].last_eat_time > \
		(long long)philo->data->time_t_die && philo[i].last_eat_time != 0)
		{
			pthread_mutex_lock(&(philo->data->death));
			philo->data->is_died = 1;
			pthread_mutex_unlock(&(philo->data->death));
			printf("%lld %d is died\n", moment() - \
			philo->data->now, philo->name);
		}
		pthread_mutex_unlock(&(philo->data->meal));
		usleep(100);
		pthread_mutex_lock(&(philo->data->death));
	}
	tmp = philo->data->is_died;
	pthread_mutex_unlock(&(philo->data->death));
	return (tmp);
}

void	destroyer_of_the_world(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_ct)
		pthread_join(data->philos[i++].philo_id, NULL);
	i = 0;
	while (i < data->philo_ct)
		pthread_mutex_destroy(&(data->philos[i++].l_fork));
	pthread_mutex_destroy(&(data->meal));
	pthread_mutex_destroy(&(data->maklube));
	pthread_mutex_destroy(&(data->routine));
	pthread_mutex_destroy(&(data->death));
}
