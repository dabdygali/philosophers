/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:40:19 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:19:54 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <inttypes.h>

static int	release_forks(t_seat *s)
{
	if (pthread_mutex_lock(&s->left_fork->lock))
	{
		control_write(s, -1);
		return (-1);
	}
	s->left_fork->status = s->id;
	if (pthread_mutex_unlock(&s->left_fork->lock))
	{
		control_write(s, -1);
		return (-1);
	}
	if (pthread_mutex_lock(&s->right_fork->lock))
	{
		control_write(s, -1);
		return (-1);
	}
	s->right_fork->status = s->id;
	if (pthread_mutex_unlock(&s->right_fork->lock))
	{
		control_write(s, -1);
		return (-1);
	}
	return (0);
}

static int	sleep(t_seat *s)
{
	int	tmp;

	tmp = control_read(s);
	if (tmp != 0)
		return (tmp);
	tmp = is_dead(s);
	if (tmp != 0)
		return (tmp);
	if (print_sleep(s) < 0)
	{
		control_write(s, -1);
		return (-1);
	}
	s->state = sleeping;
	tmp = safe_sleep(s, s->sleep_time);
	if (tmp != 0)
		return (tmp);
	tmp = is_dead(s);
	if (tmp != 0)
		return (tmp);
	return (0);
}

static int	take_forks(t_seat *s)
{
	int	r;
	int	l;
	int	tmp;

	r = 1;
	l = 1;
	while (r != 0 || l != 0)
	{
		r = get_fork(s->right_fork, s);
		if (r < 0)
			return (-1);
		l = get_fork(s->left_fork, s);
		if (l < 0)
			return (-1);
		if (l == 0 && r != 0 && cancel_fork(s->left_fork, s) < 0)
			return (-1);
		if (l != 0 && r == 0 && cancel_fork(s->right_fork, s) < 0)
			return (-1);
		tmp = think(s);
		if (tmp != 0)
			return (tmp);
	}
	tmp = print_fork(s);
	return (tmp);
}

static int	eat(t_seat *s)
{
	int	tmp;

	tmp = control_read(s);
	if (tmp != 0)
		return (tmp);
	if (s->must_eat == 0)
		return (1);
	tmp = take_forks(s);
	if (tmp != 0)
		return (tmp);
	tmp = chew(s);
	if (tmp != 0)
		return (tmp);
	tmp = release_forks(s);
	if (tmp != 0)
		return (tmp);
	if (s->must_eat == 0)
		return (1);
	return (0);
}

void	*philo_thread(void *seat)
{
	t_seat			*s;
	int				tmp;

	s = (t_seat *) seat;
	if (control_read(s) != 0 || s->must_eat == 0)
		return (NULL);
	s->prev_meal = s->start_time;
	while (1)
	{
		if (control_read(s) != 0 || s->must_eat == 0)
			return (NULL);
		tmp = eat(s);
		if (tmp != 0)
			return ((void *)(intptr_t)(tmp - 1));
		tmp = sleep(s);
		if (tmp != 0)
			return ((void *)(intptr_t)(tmp - 1));
	}
	return (NULL);
}
