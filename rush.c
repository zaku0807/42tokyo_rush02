/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarai <rarai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:43:48 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/07 21:30:52 by rarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	put_unit(int cnt, t_rush *g_point)
{
	int temp;
	int i;

	temp = 3 * cnt + 1;
	i = 0;
	while (i < 41)
	{
		if (temp == g_point[i].key_len)
		{
			write(1, " ", 1);
			ft_putstr(g_point[i].value);
			return ;
		}
		i++;
	}
}

void	output3(char *p, t_rush *g_point)
{
	char c1;
	char c2;

	c1 = p[1];
	c2 = p[2];
	p[1] = '\0';
	key_put(p, g_point);
	key_put("100", g_point);
	p[0] = c1;
	p[1] = c2;
	p[2] = '\0';
	if (p[0] == '1' || p[1] == '0')
		key_put(p, g_point);
	else
	{
		p[1] = '0';
		if (p[0] != '0')
			key_put(p, g_point);
		p[0] = c2;
		p[1] = '\0';
		key_put(p, g_point);
	}
}

void	output2(char *p, t_rush *g_point)
{
	char c;

	if (p[0] == '1' || p[1] == '0')
		key_put(p, g_point);
	else
	{
		c = p[1];
		p[1] = '0';
		key_put(p, g_point);
		p[0] = c;
		p[1] = '\0';
		key_put(p, g_point);
	}
}

int		zero_skip(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		return (i);
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (5);
	else if (str[0] == '0' && str[1] == '0')
	{
		str[0] = str[2];
		str[1] = '\0';
		return (1);
	}
	else if (str[0] == '0')
	{
		str[0] = str[1];
		str[1] = str[2];
		str[2] = '\0';
		return (2);
	}
	else
		return (3);
}

void	key_check(char *str, int cnt)
{
	int len;
	int i;

	i = 0;
	len = 0;
	len = zero_skip(str);
	if (len == 5)
		return ;
	else if (len == 3)
		output3(str, g_point);
	else if (len == 2)
		output2(str, g_point);
	else
		key_put(str, g_point);
	if (cnt > 0)
		put_unit(cnt, g_point);
}
