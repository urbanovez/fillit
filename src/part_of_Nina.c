/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_Nina.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:23:31 by ttawna            #+#    #+#             */
/*   Updated: 2020/02/05 23:07:54 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_map_create(int side)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc((side) * sizeof(char *));
	while (i < side)
	{
		j = 0;
		map[i] = (char *)malloc((side + 1) * sizeof(char));
		while (j < side)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

t_tetris	*ft_tet_create(int **base)
{
	int			i;
	t_tetris	*new;
	t_tetris	*start;

	new = tetris_new(base[0][0], base[0][1], NULL);
	start = new;
	i = 1;
	while (base[i][0] != -1)
	{
		new = tetris_new(base[i][0], base[i][1], new);
		i++;
	}
	return (start);
}

void		ft_print_map(char **map, int side)
{
	int i;

	i = 0;
	while (i < side)
		ft_putendl(map[i++]);
}

char		**ft_fill(char **map, int x, int y, int num, char value, int side)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 6)
	{
		if ((f[num][i] + x) >= side || (f[num][j] + y) >= side\
			|| (f[num][i] + x) < 0 || (f[num][j] + y) < 0)
			return (NULL);
		i += 2;
		j += 2;
	}
	i = 0;
	if ((map[y + (f[num][1])][x + (f[num][0])] == '.') &&\
		(map[y + (f[num][3])][x + (f[num][2])] == '.')\
		&& (map[y + (f[num][5])][x + (f[num][4])] == '.'))
	{
		map[y][x] = value;
		while (i <= 4)
		{
			map[y + (f[num][i + 1])][x + (f[num][i])] = value;
			i += 2;
		}
	}
	else
		return (NULL);
	return (map);
}

char		**ft_dot_filling(char **map, int x, int y, int num, char value, int side)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 6)
	{
		if ((f[num][i] + x) >= side || (f[num][j] + y) >= side\
			|| (f[num][i] + x) < 0 || (f[num][j] + y) < 0)
			return (NULL);
		i += 2;
		j += 2;
	}
	i = 0;
	map[y][x] = value;
	while (i <= 4)
	{
		map[y + (f[num][i + 1])][x + (f[num][i])] = value;
		i += 2;
	}
	return (map);
}

int			*ft_find_cord(char **map, int side, int m, int n)
{
	int *cor;

	cor = (int *)malloc(sizeof(int) * (2));
	m++;
	while (n < side)
	{
		if (m == (side - 1) && n == (side - 1))
			return (NULL);
		while (m <= side - 1)
		{
			if ((map[n][m]) == '.')
			{
				cor[1] = (n);
				cor[0] = (m);
				return (cor);
			}
			m++;
		}
		n++;
		m = 0;
	}
	return (NULL);
}

int			ft_square_root(int n)
{
	int i;

	i = 1;
	while (i <= n / 2)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_body(int **base)
{
	int			side;
	char		**map;
	int			i;
	t_tetris	*start;

	i = 0;
	while (base[i][0] != -1)
		i++;
	start = ft_tet_create(base);
	ft_clear_base(base, i);
	side = ft_square_root(i * 4);
	map = ft_map_create(side);
	while (!ft_solve1(map, start, side, -1, 0))
	{
		ft_clear_array(map, side);
		map = ft_map_create(++side);
	}
}
