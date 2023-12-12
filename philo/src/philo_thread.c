/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:40:19 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/12 18:21:18 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

static int	take_forks(t_seat *s)
{
	int	r;
	int	l;
	int	tmp;

	r = 1;
	l = 1;
	while (r != 0 || l != 0)
	{
		r = get_fork(s->right_fork);
		if (r < 0)
			return (-1);
		l = get_fork(s->left_fork);
		if (l < 0)
			return (-1);
		if (l == 0 && r != 0 && cancel_fork(s->left_fork) < 0)
			return (-1);
		if (l != 0 && r == 0 && cancel_fork(s->right_fork) < 0)
			return (-1);
		tmp = think(s);
		if (tmp != 0)
			return (tmp);
	}
	return (0);
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
	if (s->must_eat == 0)
		return (1);
	return (0);
}

void	*philo_thread(void *seat)
{
	t_seat			*s;
	int				tmp;
	struct timeval	t;

	s = (t_seat *) seat;
	if (gettimeofday(&t, NULL) != 0)
		return ((void *) -1);
	s->prev_meal = (int)(t.tv_usec / 1000);
	while (1)
	{
		if (control_read(s) != 0 || s->must_eat == 0)
			return (NULL);
		tmp = eat(s);
		if (tmp != 0)
			return ((void *)(tmp - 1));
		tmp = sleep(s);
		if (tmp != 0)
			return ((void *)(tmp - 1));
	}
	return (NULL);
}
