/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:08:48 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 00:08:49 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc != 5 && argc != 6)
		return (1);
	data->argc = argc;
	data->argv = argv;
	if (!ft_parsing(data))
		return (1);
	if (!ft_initialize_data(data))
		return (1);
	if (!ft_start_semaphores(data))
		return (1);
	ft_start(data);
	return (0);
}
