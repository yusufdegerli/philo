/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:45:31 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/30 17:55:14 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	def_of_datas2(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->routine, NULL);
	pthread_mutex_init(&data->maklube, NULL);
	pthread_mutex_init(&data->death, NULL);
	while (++i < data->philo_ct)
	{
		data->philos[i].porchion_counter = 0;
		data->philos[i].data = data;
		data->philos[i].name = i + 1;
		data->philos[i].last_eat_time = 0;
		pthread_mutex_init(&(data->philos[i].l_fork), NULL);
		if (i == data->philo_ct - 1)
			data->philos[i].r_fork = &(data->philos[0].l_fork);
		else
			data->philos[i].r_fork = &(data->philos[i + 1].l_fork);
	}
}

int	creating_peasants(t_data *data)
{
	int	i;

	i = -1;
	data->now = moment();
	while (++i < data->philo_ct)
		pthread_create(&(data->philos[i].philo_id), NULL, \
		schopenhauers_cage, &(data->philos[i]));
	while (die_like_a_nietzsche(data->philos) != 1)
		if (eat_check(data))
			break ;
	destroyer_of_the_world(data);
	return (1);
}

int	def_of_datas(char **av, t_data *data, int ac)
{
	int	i;

	i = -1;
	data->philo_ct = ft_atoi(av[1]);
	data->time_t_die = ft_atoi(av[2]);
	data->time_t_eat = ft_atoi(av[3]);
	data->time_t_sleep = ft_atoi(av[4]);
	data->is_died = 0;
	data->eat_cnt = 0;
	data->porchion = 0;
	if (data->philo_ct < 0)
		return (0);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_ct);
	data->philos->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_ct));
	if (!data->philos || !data)
		return (0);
	if (data->time_t_die < 0 || data->time_t_eat < 0)
		return (0);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	def_of_datas2(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		if (!argument_ctl(av))
			printf("Wrong Argument!\n");
		if (!def_of_datas(av, data, ac))
			return (-1);
		if (!creating_peasants(data))
			return (-1);
	}
	else
		printf("Wrong Argument!\n");
}
