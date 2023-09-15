/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:42:17 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/30 17:58:41 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	moment(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	sleep_like_a_freud(long long t, t_data *data)
{
	long long	i;

	i = moment();
	pthread_mutex_lock(&(data->death));
	while (data->is_died != 1)
	{
		pthread_mutex_unlock(&(data->death));
		if ((moment() - i) >= t)
		{
			pthread_mutex_lock(&(data->death));
			break ;
		}
		usleep(100);
		pthread_mutex_lock(&(data->death));
	}
	pthread_mutex_unlock(&(data->death));
}
