/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:38 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/31 13:17:08 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				name;
	struct s_data	*data;
	pthread_mutex_t	l_fork;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*r_fork;
	pthread_t		philo_id;
	long long		last_eat_time;
	long long		last_sleep_time;
	long long		last_think_time;
	int				porchion_counter;
}	t_philo;
typedef struct s_data
{
	long long		now;
	pthread_mutex_t	meal;
	pthread_mutex_t	death;
	int				eat_cnt;
	int				is_died;
	pthread_mutex_t	maklube;
	pthread_mutex_t	routine;
	t_philo			*philos;
	int				philo_ct;
	int				must_eat;
	int				porchion;
	int				time_t_die;
	int				time_t_eat;
	int				time_t_sleep;
}	t_data;

long long	moment(void);
int			ft_isdigit(int c);
int			for_spaces(char c);
int			check_num(char **str);
int			eat_check(t_data *data);
int			argument_ctl(char **av);
int			ft_atoi(const char *str);
void		def_of_datas2(t_data *data);
int			ft_strcmp(char *s1, char *s2);
int			creating_peasants(t_data *data);
void		*schopenhauers_cage(void *data);
int			die_like_a_nietzsche(t_philo *philo);
void		destroyer_of_the_world(t_data *data);
void		philo_eat(t_philo *philo, t_data *data);
void		sleep_like_a_freud(long long t, t_data *data);
int			def_of_datas(char **av, t_data *data, int ac);
void		becoming_to_a_death(t_data *data, t_philo *philo);
void		daily_routine_of_a_nihilist(t_data *data, int philo_num, \
			char *routine);

#endif
