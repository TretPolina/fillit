/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:31:52 by fford             #+#    #+#             */
/*   Updated: 2019/12/15 00:18:02 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_val
{
	char		***block;
	char		**field;
	int			count;
	int			size;
	int			fd;
	int			k;
}				t_val;

void			ft_putchar(char c);
void			ft_putstr(char const *s);

int				check_elements(char *tetr);
int				check_lines(char *tetr);
int				check_sides(char *tetr);
int				full_check_tetr(char *tetr, int k, int count, int ret);

char			***creat_three_arr(int k, int j, int i);
void			free_three_arr(char ***block);
char			**coord_alf(char **block, t_coord *coord);
char			**move_tetr(char **block, t_coord *coord);

int				count_tetr(int fd);
char			***read_tetr(int fd, char ***block, int count, int k);
char			***alf_tetr(char ***block, int count);

char			**create_field(void);
void			free_field(char **field);
void			print_field(char **field, int size);

void			size_field(t_val *val);
void			move_field(t_val *val, t_coord *coord);
void			count_field(t_val *val, char **av);

int				can_put_t(char **field, char ***block, int k, int *xy);
char			**put_on_field_t(char **field, char ***block, int k, int *xy);
char			**remove_on_field_t(char **field, char ***block,
				int k, int *xy);
int				solver_t(char ***field, char ***block, int k, t_val *coord_f);

#endif
