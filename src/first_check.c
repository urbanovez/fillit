/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:19:54 by ttawna            #+#    #+#             */
/*   Updated: 2020/02/05 23:05:42 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_firstcheck(const	char *sam, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < j)
	{
		if (sam[i] != '.' && sam[i] != '#' && sam[i] != '\n')
			return (-1);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if ((sam[4 + i] == '\n') && (sam[9 + i] == '\n') && (sam[14 + i]\
			== '\n') && (sam[19 + i] == '\n') && (sam[20 + i] == '\n'))
		{
			i += 21;
			k++;
		}
		else
			return (-1);
	}
	return (k);
}

int	**first_check(int fd)
{
	int		sam;
	char	buff[548];
	int		am;
	int		**base1;

	ft_bzero(buff, sizeof(char) * 548);
	if ((sam = read(fd, buff, 546)) < 21)
		return (NULL);
	if (buff[sam - 1] == '\n' && buff[sam - 2] == '\n')
		return (NULL);
	buff[sam] = '\n';
	am = ft_firstcheck(buff, sam);//можно тут убрать sam поменять на am и убрать 1 строку
	if (am == -1)
		return (NULL);
	base1 = last_check(am, buff);
	if (base1 == NULL)
        return (NULL);
    base1[am] = (int *)malloc(sizeof(int) * (1));
    base1[am][0] = -1;
	return (base1);
}

int	ft_tet_check(int *tet)
{
	int i;
	int j;

	j = 0;
	while (j < 19)
	{
		i = 0;
		while (tet[i] == f[j][i])
		{
			if (i == 5)
				return (j);
			i++;
		}
		j++;
	}
	return (-1);
}

int checking_empty(char *k)
{
    int i;

    i = 0;
    while(k[i] != 35)
    {
        if (i == 20)
            return(-1);
        i++;
    }
    return(i);
}

int **last_check(int m, char *k)//проверка на сами фигурки
{
    int x;
    int y;
    int j;//счетчик фигурок ебаных
    int i;// до 21 то есть внутри одного квадрата
    int tet[6];//сюда забиваем координаты одной фигурки
    int mem; //чтобы заполнять массив сверху
    int l;//можно пускать ее на ввод, но это говнокод
    int **base;

	j = 0;
	l = 0;
	base = (int **)malloc(sizeof(int *) * (m + 1));
	while (++j <= m)
	{
		mem = -2;
		i = -1;
        if((i = checking_empty(k)) == -1)
            return (ft_clear_base2(base, m));
		/*while (k[++i] != 35)
		{
			if (i == 20)
				return (ft_clear_base2(base, m));
		}*/
		x = (i + 1) % 5;
		y = (i + 1) / 5;
		while (++i < 19)
		{
		    if (k[i] == 35)
			{
				if ((mem = mem + 2) == 6)
					return (ft_clear_base2(base, m));
				tet[mem] = ((i + 1) % 5) - x;
				tet[mem + 1] = ((i + 1) / 5) - y;
			}
		}
		base[j - 1] = (int *)malloc(sizeof(int) * (2));
		if ((base[j - 1][0] = ft_tet_check(tet)) == -1)
			return (ft_clear_base1(base));
		base[j - 1][1] = (65 + l++);
		ft_bzero(tet, sizeof(int) * 6);
		k = ft_strsub(k, 21, (ft_strlen(k) - 21));
	}
	return (base);
}