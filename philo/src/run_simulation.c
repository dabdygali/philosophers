/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:18 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 17:07:16 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static int	join_threads(pthread_t *tid, int qty)
{
	int		i;
	int		status;
	void	*tmp;

	status = 0;
	i = 0;
	while (i < qty)
	{
		if (pthread_join(tid + i, &tmp) != 0)
			return (-1);
		if (tmp != NULL)
			status = -1;
		i++;
	}
	return (status);
}

static int	start_threads(pthread_t *tid, t_seat *seats, int qty)
{
	int	i;

	if (lock_warn(&seats->cntrl->lock, &seats->print->lock) != 0)
		return (-1);
	i = 0;
	while (i < qty)
	{
		if (pthread_create(tid + i, NULL, philosopher, seats + i) != 0)
		{
			seats->cntrl->status = -1;
			unlock_warn(&seats->cntrl->lock, &seats->print->lock);
			join_threads(tid, i);
			return (-1);
		}
		i++;
	}
	if (unlock_warn(&seats->cntrl->lock, &seats->print->lock) != 0)
	{
		seats->cntrl->status = -1;
		join_threads(tid, qty);
		return (-1);
	}
	return (0);
}

int	run_simulation(t_seat *seats, int qty)
{
	pthread_t	*tid;

	tid = (pthread_t *) malloc(sizeof(pthread_t) * qty);
	if (tid == NULL)
	{
		ft_putstr_fd("Failed to malloc \"tid\"\n", STDERR_FILENO);
		return (-1);
	}
	if (start_threads(tid, seats, qty) < 0)
	{
		free(tid);
		return (-1);
	}
	if (join_threads(tid, qty) < 0)
	{
		free(tid);
		return (-1);
	}
	free(tid);
	return (0);
}
