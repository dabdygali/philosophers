/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:18 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 11:01:14 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

static int	set_start(t_seat *seats, int qty)
{
	int				i;
	struct timeval	t;
	int				time;

	if (gettimeofday(&t, NULL) != 0)
		return (-1);
	time = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000));
	i = 0;
	while (i < qty)
	{
		(seats + i)->start_time = time;
		i++;
	}
	return (0);
}

static int	join_threads(pthread_t *tid, int qty)
{
	int		i;
	int		status;
	void	*tmp;

	status = 0;
	i = 0;
	while (i < qty)
	{
		if (pthread_join(*(tid + i), &tmp) != 0)
			return (-1);
		if (tmp != NULL)
			status = -1;
		i++;
	}
	return (status);
}

static int	start_threads(pthread_t *tid, t_seat *seats, int qty)
{
	int				i;
	pthread_mutex_t	*lock;

	if (lock_warn(&seats->cntrl->lock, &seats->print->lock) != 0)
		return (-1);
	i = 0;
	while (i < qty)
	{
		if (pthread_create((tid + i), NULL, philo_thread, (void *)(seats + i)))
		{
			seats->cntrl->status = -1;
			unlock_warn(&seats->cntrl->lock, &seats->print->lock);
			join_threads(tid, i);
			return (-1);
		}
		i++;
	}
	lock = &seats->print->lock;
	if (set_start(seats, qty) || unlock_warn(&seats->cntrl->lock, lock))
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
