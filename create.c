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