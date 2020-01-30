/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:19:54 by ttawna            #+#    #+#             */
/*   Updated: 2019/11/23 23:36:06 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
#include "fillit.h"

int	ft_firstcheck(const	char *sam, int j)//проверка на то, что фигурки в квадратах
{
	int i;
	int k;

	i = 0;
	k = 0;

	while (i < j)//переписать через указатели
    {
	    if (sam[i] != '.' && sam[i] != '#' && sam[i] != '\n')
	        return(-1);
	    i++;
    }
	i = 0;
	while (i < j)
	{
		if ((sam[4 + i] == '\n') && (sam[9 + i] == '\n') && (sam[14 + i] == '\n') && (sam[19 + i] == '\n') && (sam[20 + i] == '\n'))
		{
			i += 21;
			k++;// к показывает количество фигурок, надо его вернуть
		}
		else
			return(-1);
	}
	return(k);
}

int   **first_check (int fd)
{
	int 	sam;
	char	buff[548];
	int 	am;//количество фигур
	int **base1;

	if (fd < 0 || fd > 10240)
		return(NULL);
	ft_bzero(buff, sizeof(char) * 548);
	if ((sam = read(fd, buff, 546)) < 21)
	    return (NULL);
	buff[sam] = '\0';
	buff[sam] = '\n';//что из этого оставить?
	am = ft_firstcheck(buff, sam);
	if (am == -1)
		return(NULL);
	base1 = last_check(am, buff);
	return(base1);
}

int ft_tet_check(int *tet)
{
	int i;
	int j;
	j = 0;
	while (j < 19)
	{
		i = 0;
		while(tet[i] == f[j][i])
		{
			if(i == 5)
				return(j);
			i++;
		}
		j++;
	}
	return(-1);
}


int **last_check(int m, char *k)//проверка на сами фигурки
{
	int x;
	int y;
	int j;//счетчик фигурок ебаных
	int i;// до 21 то есть внутри одного квадрата
	int tet[6];//сюда забиваем координаты одной фигурки
	int mem; //чтобы заполнять массив сверху
	int l;
	int **base;

	j = 1;
	l = 0;

	base = (int **)malloc(sizeof(int *) * (m + 1));
	while( j <= m)
	{
        mem = 0;
	    i = 0;
		while (k[i] != 35)
		{
			if (i == 20)//случай когда пустой
			{
				return (NULL);
			}
			i++;
		}
		x = (i + 1) % 5;
		y = (i + 1) / 5;
		i++;
		while (i <19)
		{
			if (k[i] == 35)
			{
			    if (mem == 6)
			    {
					return (NULL);
				}
				tet[mem] = ((i + 1) % 5) - x;
				tet[mem + 1] = ((i + 1) / 5) - y;
				mem = mem + 2;
			}
			i++;
		}
		base[j-1] = (int *)malloc(sizeof(int) * (2));
		base[j-1][0] = ft_tet_check(tet);
		if(base[j-1][0] == -1)//проверка фигурки по базе
		{
			return (NULL);//возможно эту проверку запихнуть в главную функцию
		}
		base[j-1][1] = (65 + l);//каждой терамине своя буква
		j++;
		l++;
        ft_bzero(tet, sizeof(int) * 6);
		k = ft_strsub(k, 21, (ft_strlen(k)-21));
	}
	base[j-1] = (int *)malloc(sizeof(int) * (1));
	base[j-1][0] = -1;
	return (base);
}
		
