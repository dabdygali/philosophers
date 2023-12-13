/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:17:42 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 13:23:10 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

int	print_fork(t_seat *s)
{
	char	*str;

	str = build_str(s);
	if (!str)
		return (-1);
	if (pthread_mutex_lock(&s->print->lock) != 0)
		return (-1);
	if (write(STDOUT_FILENO, str, ft_strlen(str)) < 0)
	{
		control_write (s, -1);
		pthread_mutex_unlock(&s->print->lock);
		return (-1);
	}
	free(str);
	if (write(STDOUT_FILENO, " has taken forks\n", 17) < 0)
	{
		control_write(s, -1);
		pthread_mutex_unlock(&s->print->lock);
		return (-1);
	}
	if (pthread_mutex_unlock(&s->print->lock) != 0)
		return (-1);
	return (0);
}
