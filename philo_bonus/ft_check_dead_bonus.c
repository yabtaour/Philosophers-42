/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dead_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:06:10 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 11:42:16 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

void	ft_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		kill (data->pid[i], SIGINT);
		i++;
	}
}

void	ft_destroy_sem(t_data *data)
{
	sem_close(data->fork);
	sem_close(data->output);
	sem_close(data->eat);
	sem_unlink("philo_forks");
	sem_unlink("philo_output");
	sem_unlink("philo_eat");
}

void	ft_end(t_data *data)
{
	ft_kill(data);
	ft_destroy_sem(data);
	free(data->pid);
	free(data);
}

void	*ft_check_dead(t_philo *philo)
{
	long long	now;

	while (1)
	{
		now = ft_timestamp();
		if (philo->eat == philo->data->must_eat)
			return (NULL);
		if (now - philo->last_meal >= philo->data->time_to_die)
		{
			philo->is_dead = 1;
			sem_wait(philo->data->output);
			printf("[%lld] philo %d is ded\n", now - philo->data->birth, philo->philo_id);
			ft_end(philo->data);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}
