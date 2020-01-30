#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char **ft_map_create(int side)  //функция5, создает карту
{
    char **map;
    int i;
    int j;

    i = 0;
    map = (char **)malloc((side) * sizeof(char *));
    while (i < side)
    {
        j = 0;
        map[i] = (char *) malloc((side + 1) * sizeof(char));
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
t_tetris   *ft_tet_create(int **base)
{
    int i;
    t_tetris *new;
    t_tetris *start;

    new = tetris_new(base[i][0], base[0][1], NULL);
	start = new;
    i = 1;
    while (base[i][0] != -1)
    {
        new = tetris_new(base[i][0], base[i][1], new);
        i++;
    }
    return(start);
}
void ft_print_map(char **map, int side)  //печатает карту
{
    int i;

    i = 0;
    while (i < side)
        ft_putendl(map[i++]);
}

char **ft_fill(char **map, int x, int y, int num, char value, int side)  //заполняет ячейку с заданными координатами заданным символом
{//num это номер фигуры в базе f
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 6)//проверка
	{
		if ((f[num][i] + x) >= side || (f[num][j] + y) >= side || (f[num][i] + x) < 0 || (f[num][j] + y) < 0)
			return (NULL);
		i +=2;
		j +=2;
	}
    map[y][x] = value;
	i = 0;
	while (i <=4)
	{
		if (map[y + (f[num][i + 1])][x + (f[num][i])] == '.')
		{
			map[y + (f[num][i + 1])][x + (f[num][i])] = value;
			i += 2;
		}
		else
			return (NULL);
/*	if (map[y - 1 - (f[num][3])][x - 1 - (f[num][2])] == '.')
    	map[y - 1 - (f[num][3])][x - 1 - (f[num][2])] = value;
	if (map[y - 1 - (f[num][1])][x - 1 - (f[num][0])] == '.')
    	map[y - 1 - (f[num][5])][x - 1 - (f[num][2])] = value;
    	*/
	}
	return (map);
}

/*
 * функция, которая находит свободную координату, нахуя я ее пишу, я знаю, но в АлГоРиТмЕ Нины она есть
 */

int *ft_find(char **map, int side)
{
	int j;
	int i;
	int k;
	int *cor;

	j = 0;
	cor = (int *)malloc(sizeof(int) * (2));
	while (j < side)
	{
		k = 0;
		while(k <= j)
		{
			i = 0;
			if (map[i + k][j - k] == '.')
				return(cor);
			k++;
		}
		j++;
	}
	return (NULL);
}
int ft_square_root(int n)
{
    int i;
    i = 1;
    while (i <= n/2)
    {
        if (i*i >= n)
            return(i);
        i++;
    }
    return(-1);
}

int ft_body(int **base)
{
    int side;
    char **map;
    int i;// количество фигур
    int *cor;
    t_tetris	*start;

    i = 0;
    while (base[i][0] != -1)
    	i++;
    cor = (int *)malloc(sizeof(int) * (2));
    start = ft_tet_create(base);//создаю структуру
    side = ft_square_root(i * 4);
    map = ft_map_create(side);
    cor = ft_find(map, side);//находим ближайшую свободную точку
    map = ft_fill(map, cor[0], cor[1], 16,'A', side);
    ft_print_map(map, side);
    return (0);
}