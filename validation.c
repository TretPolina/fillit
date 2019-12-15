/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:40:03 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:06:06 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_elements(char *tetr)
{
	int i;
	int	dot;
	int	hash;
	int	sn;

	i = 0;
	dot = 0;
	hash = 0;
	sn = 0;
	while (i < 20)
	{
		if (tetr[i] == '.')
			dot++;
		if (tetr[i] == '#')
			hash++;
		if (tetr[i] == '\n')
			sn++;
		i++;
	}
	if ((dot == 12 && hash == 4 && sn == 4))
		return (1);
	return (0);
}

int	check_lines(char *tetr)
{
	int	i;
	int k;

	i = 0;
	while (i < 20)
	{
		k = 0;
		while (tetr[i] != '\n')
		{
			k++;
			i++;
		}
		if (!(tetr[i] == '\n' && k == 4))
			return (0);
		i++;
	}
	return (1);
}

int	check_sides(char *tetr)
{
	int i;
	int side;

	i = 0;
	side = 0;
	while (i < 20)
	{
		if (tetr[i] == '#')
		{
			if (tetr[i + 1] == '#')
				side++;
			if (i < 15 && tetr[i + 5] == '#')
				side++;
		}
		i++;
	}
	if (side == 3 || side == 4)
		return (1);
	else
		return (0);
}

int	full_check_tetr(char *tetr, int k, int count, int ret)
{
	if (!check_elements(tetr) || !check_lines(tetr) || !check_sides(tetr))
		return (0);
	if ((k < count - 1) && (tetr[20] != '\n'))
		return (0);
	if ((k == count - 1) && (ret != 20))
		return (0);
	return (1);
}
