/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:39:11 by fford             #+#    #+#             */
/*   Updated: 2019/12/15 15:53:24 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	size_field(t_val *val)
{
	val->size = 2;
	while (val->size * val->size < 4 * val->count)
		val->size++;
	while (!solver_t(&val->field, val->block, 0, val))
		val->size++;
	val->size--;
}

void	move_field(t_val *val, t_coord *coord)
{
	val->block = alf_tetr(val->block, val->count);
	val->k = -1;
	while (++val->k < val->count)
	{
		coord->x = 10;
		coord->y = 10;
		val->block[val->k] = move_tetr(coord_alf(val->block[val->k], coord),
				coord);
	}
}

void	count_field(t_val *val, char **av)
{
	val->fd = open(av[1], O_RDONLY);
	if (val->fd == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	val->count = count_tetr(val->fd);
	close(val->fd);
}
