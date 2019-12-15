/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_alf.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:32:16 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:06:06 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**coord_alf(char **block, t_coord *coord)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 5)
		{
			if ((block[j][i] >= 'A' && block[j][i] <= 'Z') && i < coord->x)
				coord->x = i;
			if ((block[j][i] >= 'A' && block[j][i] <= 'Z') && j < coord->y)
				coord->y = j;
		}
	}
	return (block);
}

char	**move_tetr(char **block, t_coord *coord)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		if ((coord->x == 0) && (coord->y == 0))
			return (block);
		i = -1;
		while (++i < 5)
		{
			if (block[j][i] >= 'A' && block[j][i] <= 'Z')
			{
				block[j - coord->y][i - coord->x] = block[j][i];
				block[j][i] = '.';
			}
		}
	}
	return (block);
}

char	***alf_tetr(char ***block, int count)
{
	int		i;
	int		j;
	int		k;
	char	alf;

	alf = 65;
	k = -1;
	while (++k < count)
	{
		j = -1;
		while (++j < 4)
		{
			i = -1;
			while (++i < 5)
			{
				if (block[k][j][i] == '#')
					block[k][j][i] = alf;
			}
		}
		alf++;
	}
	return (block);
}
