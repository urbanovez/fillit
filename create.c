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

#include "fillit.h"

t_tetris		*tetris_new(int tet, char bukva, t_tetris *prev)
{
    t_tetris		*new;

    new = ft_memalloc(sizeof(t_tetris));
    new->tet = tet;
    new->bukva = bukva;
    new->next = NULL;
    if (prev != NULL)
        prev->next = new;
    return (new);
}
 char **ft_solve(char **map, t_tetris *start, int side, int x, int y)
 {
    int *cor;
    char **map2;
    t_tetris *tim;
    tim = start->next;

    map2 = map;
    cor = (int *)malloc(sizeof(int) * (2));
    cor[0] = x;
    cor[1] = y;
    map2 = ft_fill(map, cor[0], cor[1], tim->tet, tim->bukva, side);//взять след. элемент
    if (map2 == NULL)
    {
        cor = ft_find_cord(map, side, x, y);
        ft_solve(map, start, side, cor[0], cor[1]);
    }
     return (map2);
 }

int ft_solve1(char **map, t_tetris *start, int side, int x, int y)
{
    int *cor;
    t_tetris *tim;
    char **map2;
    int *cor1;
    t_tetris *tim1;

    if (start == NULL)//дошли до конца структуры
    {
        ft_print_map(map, side);
        return (1);
    }
    cor = (int *)malloc(sizeof(int) * (3));
    cor1 = (int *)malloc(sizeof(int) * (3));
    cor[2] = '\0';
    while(start)
    {
        tim = start->next;
        cor = ft_find_cord(map, side, x, y);
        if (cor == NULL)
            return(0);
        map2 = ft_fill(map, cor[0], cor[1], start->tet, start->bukva, side);
        while(map2 == NULL)
        {
            cor = ft_find_cord(map, side, cor[0], cor[1]);
            if (cor == NULL)
                return(0);
            map2 = ft_fill(map, cor[0], cor[1], start->tet, start->bukva, side);
        }
        cor1 = ft_memcpy((void *)cor1, (void *)cor, sizeof(int) * (3));
        tim1 = start;
        if (ft_solve1(map2, tim, side, cor[0], cor[1]) == 1)
            return(1);
        map = ft_dot_filling(map, cor1[0], cor1[1], tim1->tet, '.', side);
        cor = ft_find_cord(map, side, cor[0], cor[1]);
    }
    return(0);
}

void	ft_clear_array(char **arr, int side)
{
    char **cpy;
    int i;

    i = 0;
    cpy = arr;
    while (i < side)
    {
        free(*cpy++);
        i++;
    }
    free(arr);
}

void	ft_clear_base(int **arr, int side)
{
    int **cpy;
    int i;

    i = 0;
    cpy = arr;
    while (i <= side)
    {
        free(*cpy++);
        i++;
    }
    free(arr);
}
