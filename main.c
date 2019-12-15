/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:40:18 by fford             #+#    #+#             */
/*   Updated: 2019/12/15 00:19:54 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_coord	coord;
	t_val	val;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	val.block = creat_three_arr(26, 4, 5);
	count_field(&val, av);
	val.fd = open(av[1], O_RDONLY);
	val.block = read_tetr(val.fd, val.block, val.count, 0);
	if (!val.block)
	{
		ft_putstr("error\n");
		exit(1);
	}
	close(val.fd);
	move_field(&val, &coord);
	val.field = create_field();
	size_field(&val);
	print_field(val.field, val.size);
	free_three_arr(val.block);
	free_field(val.field);
	return (0);
}
