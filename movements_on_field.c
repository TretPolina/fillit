/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_on_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:52:11 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:06:06 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_put_t(char **field, char ***block, int k, int *xy)
{
	int	i;
	int	j;
	int	p_x;
	int p_y;

	p_y = xy[1];
	j = 0;
	while (j < 4)
	{
		i = 0;
		p_x = xy[0];
		while (i < 4)
		{
			if ((block[k][j][i] > 64 && block[k][j][i] < 91) &&
			field[p_y][p_x] != '.')
				return (0);
			i++;
			p_x++;
		}
		j++;
		p_y++;
	}
	return (1);
}

char	**put_on_field_t(char **field, char ***block, int k, int *xy)
{
	int	i;
	int	j;
	int	p_x;
	int p_y;

	p_y = xy[1];
	j = 0;
	while (j != 4)
	{
		i = 0;
		p_x = xy[0];
		while (i != 4)
		{
			if (block[k][j][i] > 64 && block[k][j][i] < 91)
				field[p_y][p_x] = block[k][j][i];
			i++;
			p_x++;
		}
		j++;
		p_y++;
	}
	return (field);
}

char	**remove_on_field_t(char **field, char ***block, int k, int *xy)
{
	int	i;
	int	j;
	int	p_x;
	int p_y;

	p_y = xy[1];
	j = 0;
	while (j != 4)
	{
		i = 0;
		p_x = xy[0];
		while (i != 4)
		{
			if (block[k][j][i] > 64 && block[k][j][i] < 91)
				field[p_y][p_x] = '.';
			i++;
			p_x++;
		}
		j++;
		p_y++;
	}
	return (field);
}
