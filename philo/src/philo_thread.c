/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:40:19 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/12 11:13:01 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *seat)
{
	t_seat	*s;

	s = (t_seat *) seat;
	while (1)
	{
		if (control_read(s) != 0 || s->must_eat == 0)
			return (NULL);
	}
	return (NULL);
}
