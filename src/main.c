/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:12:12 by ttawna            #+#    #+#             */
/*   Updated: 2020/02/05 23:12:30 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	f[19][6] = {
		{0, 1, 1, 1, 0, 2}, {-1, 1, 0, 1, 0, 2}, {0, 1, 1, 1, 2, 1},
		{-2, 1, -1, 1, 0, 1}, {0, 1, 0, 2, 0, 3}, {-1, 1, 0, 1, 1, 1},
		{0, 1, 1, 1, 1, 2}, {-1, 1, 0, 1, -1, 2}, {0, 1, -1, 2, 0, 2},
		{0, 1, 0, 2, 1, 2}, {1, 0, -1, 1, 0, 1}, {1, 0, 1, 1, 2, 1},
		{1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 1, 2}, {1, 0, 0, 1, 0, 2},
		{1, 0, 2, 0, 1, 1}, {1, 0, 2, 0, 2, 1}, {1, 0, 2, 0, 0, 1},
		{1, 0, 2, 0, 3, 0}};

int	main(int argc, char **argv)
{
	int **base;
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
        if (fd < 0)
            ft_putstr_fd("error\n", 1);
		base = first_check(fd);
		if (base == NULL)
		{
			ft_putstr_fd("error\n", 1);
			return (0);
		}
		ft_body(base);
	}
	return (0);
}
