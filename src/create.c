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

#include "../includes/fillit.h"

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
    cor = ft_find_cord(map, side, x, y);
    while(start)
    {
        tim = start->next;
        if (cor == NULL)
        {
            free(cor);
            free(cor1);
            return (0);
        }
        map2 = ft_fill(map, cor[0], cor[1], start->tet, start->bukva, side);
        while(map2 == NULL)
        {
            cor = ft_find_cord(map, side, cor[0], cor[1]);
            if (cor == NULL)
            {
                free(cor);
                free(cor1);
                return (0);//заменить обе штуки на break и написать free cor внизу
            }
            map2 = ft_fill(map, cor[0], cor[1], start->tet, start->bukva, side);
        }
        cor1 = ft_memcpy((void *)cor1, (void *)cor, sizeof(int) * (2));
        tim1 = start;
        if (ft_solve1(map2, tim, side, -1, 0) == 1)//вместо x y: -1 0
        {
            free(cor);
            free(cor1);
            return (1);
        }
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

int	**ft_clear_base1(int **arr)
{
    int **cpy;
    int i;

    i = 0;
    cpy = arr;
    while (arr[i][0] != -1)
    {
        free(*cpy++);
        i++;
    }
    free(*cpy);
    free(arr);
    return (NULL);
}

int	**ft_clear_base2(int **arr, int m)
{
    int **cpy;
    int i;

    i = 0;
    cpy = arr;
    while (i <= m)
    {
        free(*cpy++);
        i++;
    }
    free(*cpy);
    free(arr);
    return (NULL);
}

