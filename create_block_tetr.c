/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_tetr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:39:45 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:06:06 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***creat_three_arr(int k, int j, int i)
{
	char	***block;
	int		a;
	int		b;

	if (!(block = (char***)malloc(sizeof(char**) * (k + 1))))
		exit(0);
	b = 0;
	while (b < k)
	{
		if (!(block[b] = (char**)malloc(sizeof(char*) * j)))
			exit(0);
		a = 0;
		while (a < j)
			if (!(block[b][a++] = (char*)malloc(sizeof(char) * i)))
				exit(0);
		b++;
	}
	block[k] = NULL;
	return (block);
}

void	free_three_arr(char ***block)
{
	int j;
	int k;

	k = 0;
	while (block[k] != NULL)
	{
		j = 0;
		while (j < 4)
		{
			free(block[k][j]);
			j++;
		}
		free(block[k]);
		k++;
	}
	free(block);
}

int		count_tetr(int fd)
{
	int		count;
	int		ret;
	char	tetr[22];

	count = 0;
	while ((ret = read(fd, tetr, 21)))
		count++;
	if ((count < 1) || (count > 26))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (count);
}

char	***read_tetr(int fd, char ***block, int count, int k)
{
	char	tetr[22];
	int		ret;
	int		i;
	int		j;
	int		t;

	k = 0;
	while ((ret = read(fd, tetr, 21)))
	{
		if (ret < 19)
			return (0);
		tetr[ret] = '\0';
		if (!full_check_tetr(tetr, k, count, ret))
			return (0);
		t = 0;
		j = -1;
		while (++j < 4)
		{
			i = 0;
			while (i < 5)
				block[k][j][i++] = tetr[t++];
		}
		k++;
	}
	return (block);
}
