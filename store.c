/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:43:59 by rarai             #+#    #+#             */
/*   Updated: 2021/03/07 23:16:43 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		dict_right(t_rush *g_point, int i)
{
	int j;

	if (g_point[i].len == 1)
		return (1);
	if ((g_point[i].len == 2)
		&& ((g_point[i].key[0] == '1') || (g_point[i].key[1] == '0')))
		return (1);
	if (g_point[i].len >= 3)
	{
		if (g_point[i].key[0] == '1')
		{
			j = 0;
			while (++j < g_point[i].len)
			{
				if (g_point[i].key[j] != '0')
					return (0);
			}
			if ((4 <= g_point[i].len
				&& g_point[i].len <= 37 && g_point[i].len % 3 == 1)
				|| (g_point[i].len == 3))
				return (1);
		}
	}
	return (0);
}

int		store_key(char *g_buff, char **ft_key, int i, int j)
{
	int k;

	k = 0;
	while ('0' <= g_buff[j + k] && g_buff[j + k] <= '9')
		k++;
	ft_key[i] = malloc(sizeof(char) * (k + 1));
	if (ft_key[i] == NULL)
		return (-1);
	k = 0;
	while ('0' <= g_buff[j] && g_buff[j] <= '9')
	{
		ft_key[i][k] = g_buff[j];
		j++;
		k++;
	}
	ft_key[i][k] = '\0';
	while (g_buff[j] == ' ')
		j++;
	return (j);
}

int		store_value(char *g_buff, char **ft_value, int i, int j)
{
	int k;

	while (g_buff[j] == ' ' || g_buff[j] != ':')
		j++;
	k = 0;
	while (g_buff[j + k] != '\n')
		k++;
	
	ft_value[i] = malloc(sizeof(char) * (k + 1));
	if (ft_value[i] == NULL)
		return (-1);
	k = 0;
	while (g_buff[j] != '\n')
	{
		ft_value[i][k] = g_buff[j];
		j++;
		k++;
	}
	ft_value[i][k] = '\0';
	return (j);
}

int		store(char *g_buff, int cnt, t_rush *g_point)
{
	int		i;
	int		j;
	char	**ft_key;
	char	**ft_value;

	i = 0;
	j = -1;
	ft_key = malloc(sizeof(char *) * (cnt + 1));
	ft_value = malloc(sizeof(char *) * (cnt + 1));
	if (ft_key == NULL || ft_value == NULL)
		return (-1);
	while (g_buff[++j] != '\0')
	{
		if (store_key(g_buff, ft_key, i, j) == -1)
			return (-1);
		j = store_key(g_buff, ft_key, i, j);
		if (store_value(g_buff, ft_value, i, j) == -1)
			return (-1);
		j = store_value(g_buff, ft_value, i, j);
		g_point[i].key = ft_key[i];
		g_point[i].value = ft_value[i];
		g_point[i].len = ft_strlen(g_point[i].key);
		i++;
	}
	return (i);
}

int		right(t_rush *g_point)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_point[i].key != 0)
	{
		if (dict_right(g_point, i) == 1)
		{
			g_point[j].key_right = g_point[i].key;
			g_point[j].value_right = g_point[i].value;
			g_point[j].key_len = ft_strlen(g_point[i].key);
			j++;
		}
		i++;
	}
	g_point[j].key_right = 0;
	g_point[j].value_right = 0;
	g_point[j].key_len = 0;
	if (j != 41)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (0);
}
