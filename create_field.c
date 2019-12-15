/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:40:14 by fford             #+#    #+#             */
/*   Updated: 2019/12/14 21:45:52 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_field(void)
{
	int		i;
	int		j;
	char	**field;

	if (!(field = ((char**)malloc(sizeof(char*) * 17))))
		exit(0);
	j = 0;
	while (j < 16)
	{
		i = 0;
		if (!(field[j] = (char*)malloc(sizeof(char) * 17)))
			exit(0);
		while (i < 16)
			field[j][i++] = '.';
		field[j][i] = '\0';
		j++;
	}
	field[j] = NULL;
	return (field);
}

void	free_field(char **field)
{
	int		j;

	j = 0;
	while (field[j] != 0)
	{
		free(field[j]);
		j++;
	}
	free(field);
}

void	print_field(char **field, int size)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = -1;
		while (++i < size)
			ft_putchar(field[j][i]);
		ft_putchar('\n');
		j++;
	}
}
