/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:44:50 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/07 22:54:17 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] == ' ')
			i++;
		else
		{
			flag = 1;
			if (str[i] == ' ')
			{
				write(1, " ", 1);
				while (str[i] == ' ')
					i++;
			}
			write(1, &str[i], 1);
			i++;
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int temp;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			temp = s1[i] - s2[i];
			return (temp);
		}
		i++;
	}
	return (0);
}

void	key_put(char *str, t_rush *g_point)
{
	int i;

	i = 0;
	while (i < 41)
	{
		if (ft_strcmp(str, g_point[i].key_right) == 0)
		{
			if (g_flag == 1)
				write(1, " ", 1);
			ft_putstr(g_point[i].value_right);
			g_flag = 1;
			return ;
		}
		i++;
	}
}
