/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dead_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:06:10 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 01:01:20 by yabtaour         ###   ########.fr       */
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
	free(data);
	exit (1);
}

void	*ft_check_dead(void *ptr)
{
	t_philo		*philosopher;
	t_data		*norm;
	long long	now;

	philosopher = (t_philo *)ptr;
	while (1)
	{
		now = ft_timestamp();
		norm = philosopher->data;
		if (philosopher->eat == norm->must_eat
			&& philosopher->philo_id == norm->philos_num)
			ft_end(philosopher->data);
		if (now - philosopher->last_meal >= philosopher->data->time_to_die)
		{
			norm->norm3 = now - philosopher->data->birth;
			philosopher->is_dead = 1;
			sem_wait(philosopher->data->output);
			printf("[%lld] philo %d died\n", norm->norm3, philosopher->philo_id);
			ft_end(philosopher->data);
		}
	}
	return (NULL);
}
