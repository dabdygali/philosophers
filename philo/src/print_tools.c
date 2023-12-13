/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:37:00 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 13:04:34 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdlib.h>

char	*build_str(t_seat *s)
{
	char			*str;
	char			*tmp;
	char			*tmp2;
	int				d;
	struct timeval	t;

	if (gettimeofday(&t, NULL) != 0)
	{
		control_write(s, -1);
		return (NULL);
	}
	d = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000)) - s->start_time;
	tmp = ft_itoa(d);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_itoa(s->id);
	tmp2 = ft_strjoin(str, tmp);
	free(str);
	free(tmp);
	return (tmp2);
}
