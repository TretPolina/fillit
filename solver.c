/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_on_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:40:26 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:06:06 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		height_tetr(char ***block, int k)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((block[k][j][i] != '.') && j > h)
				h = j;
			i++;
		}
		j++;
	}
	return (h + 1);
}

int		width_tetr(char ***block, int k)
{
	int	i;
	int	j;
	int	w;

	w = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((block[k][j][i] != '.') && i > w)
				w = i;
			i++;
		}
		j++;
	}
	return (w + 1);
}

int		solver_t(char ***field, char ***block, int k, t_val *val)
{
	int xy[2];

	if (k == val->count)
		return (1);
	xy[1] = 0;
	while (xy[1] + height_tetr(block, k) < val->size)
	{
		xy[0] = 0;
		while (xy[0] + width_tetr(block, k) < val->size)
		{
			if (can_put_t(*field, block, k, xy))
			{
				*field = put_on_field_t(*field, block, k, xy);
				if (solver_t(field, block, k + 1, val))
					return (1);
				*field = remove_on_field_t(*field, block, k, xy);
			}
			xy[0]++;
		}
		xy[1]++;
	}
	return (0);
}
