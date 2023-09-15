/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:44:43 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/31 13:08:47 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	neg = 1;
	i = 0;
	num = 0;
	while (for_spaces(str[i]) == 1)
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + str[i++] - 48;
		if (num * neg < -2147483648)
			return (0);
		if (num * neg > 2147483647)
			return (-1);
	}
	return (neg * num);
}

void	daily_routine_of_a_nihilist(t_data *data, int philo_num, char *routine)
{
	pthread_mutex_lock(&(data->routine));
	pthread_mutex_lock(&(data->death));
	if (data->is_died != 1)
	{
		pthread_mutex_unlock(&(data->death));
		printf("%lld ", moment() - data->now);
		printf("%d ", philo_num + 1);
		printf("%s\n", routine);
		pthread_mutex_lock(&(data->death));
	}
	if (ft_strcmp(routine, "died") != 0)
		pthread_mutex_unlock(&(data->routine));
	pthread_mutex_unlock(&(data->death));
}
