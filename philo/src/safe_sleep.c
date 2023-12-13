/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:00:08 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:01:11 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/time.h>

int	safe_sleep(t_seat *s, int ts)
{
	struct timeval	t;
	int				start;
	int				tmp;

	if (gettimeofday(&t, NULL) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	start = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000));
	tmp = 0;
	while (tmp < ts)
	{
		if (usleep((useconds_t) UNIT_SLEEP) || gettimeofday(&t, NULL))
		{
			control_write(s, -1);
			return (-1);
		}
		tmp = is_dead(s);
		if (tmp != 0)
			return (tmp);
		tmp = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000)) - start;
	}
	return (0);
}
