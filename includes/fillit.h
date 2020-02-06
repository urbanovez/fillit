/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggorilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:53:49 by ggorilla          #+#    #+#             */
/*   Updated: 2019/11/25 17:55:34 by ggorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_etris
{
    int     tet;
    char            bukva;
    struct s_etris  *next;
}				t_tetris;

int     f[19][6];
int 	main(int argc, char ** argv);
int   **first_check (int fd);
int **last_check(int m, char *k);
t_tetris		*tetris_new(int tet, char bukva, t_tetris *prev);
void ft_body(int **base);
int *ft_find_cord(char **map, int side,int m, int n);
char **ft_map_create(int side);
char **ft_fill(char **map, int x, int y, int num, char value, int side);
void	ft_clear_array(char **arr, int side);
void ft_print_map(char **map, int side);
int ft_solve1(char **map, t_tetris *start, int side, int x, int y);
void	ft_clear_base(int **arr, int side);
char **ft_dot_filling(char **map, int x, int y, int num, char value, int side);
int	**ft_clear_base1(int **arr);
int	**ft_clear_base2(int **arr, int m);
#endif
