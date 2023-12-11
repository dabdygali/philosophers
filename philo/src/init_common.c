/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:40:10 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 13:53:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static void	destroy_forks(t_resource *forks, int qty)
{
	int	i;

	i = 0;
	while (i < qty)
	{
		pthread_mutex_destroy(&forks[i].lock);
		i++;
	}
	free(forks);
}

static int	init_forks(t_resource **forks, int qty)
{
	int	i;

	*forks = (t_resource *) malloc(sizeof(t_resource) * qty);
	if (*forks == NULL)
	{
		ft_putstr_fd("Failed to malloc forks\n", STDERR_FILENO);
		return (-1);
	}
	i = 0;
	while (i < qty)
	{
		if (pthread_mutex_init(&(*forks + i)->lock, NULL) != 0)
		{
			ft_putstr_fd("Failed to init mutex lock\n", STDERR_FILENO);
			destroy_forks(*forks, i);
			return (-1);
		}
		(*forks + i)->status = 0;
		i++;
	}
	return (0);
}

int	init_common_warn_clean(t_shared *common, int argc, char *argv[])
{
	common->total = ft_atoi(argv[CLA_POS_NUM_OF_PHILO]);
	common->die_time = ft_atoi(argv[CLA_POS_TIME_TO_DIE]);
	common->eat_time = ft_atoi(argv[CLA_POS_TIME_TO_EAT]);
	common->sleep_time = ft_atoi(argv[CLA_POS_TIME_TO_SLEEP]);
	if (CLA_POS_MUST_EAT < argc)
		common->must_eat = ft_atoi(argv[CLA_POS_MUST_EAT]);
	else
		common->must_eat = -1;
	if (pthread_mutex_init(&common->print.lock, NULL) != 0)
		return (-1);
	common->print.status = 0;
	if (pthread_mutex_init(&common->cntrl.lock, NULL) != 0)
	{
		pthread_mutex_destroy(&common->print.lock);
		return (-1);
	}
	common->cntrl.status = 0;
	if (init_forks(&common->forks, common->total) < 0)
	{
		pthread_mutex_destroy(&common->print.lock);
		pthread_mutex_destroy(&common->cntrl.lock);
		return (-1);
	}
	return (0);
}
