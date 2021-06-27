/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarai <rarai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:43:36 by rarai             #+#    #+#             */
/*   Updated: 2021/03/07 21:22:59 by rarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		fileopen(char *g_buff, int argc, char *file_n)
{
	int fd;
	int flag;

	fd = 0;
	if (argc == 2)
		fd = open("./numbers.dict", O_RDONLY);
	if (argc == 3)
		fd = open(file_n, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	flag = read(fd, g_buff, 60000);
	if (flag == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	g_buff[flag] = '\0';
	close(fd);
	return (0);
}

int		linenumber(char *g_buff)
{
	int i;
	int cnt;

	cnt = 0;
	i = 0;
	while (g_buff[i] != '\0')
	{
		if (g_buff[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

int		fileread(int argc, char *file_n)
{
	int		cnt;
	char	*g_buff;
	int		i;

	g_buff = (char*)malloc(sizeof(char) * 60000);
	if (g_buff == NULL)
		return (3);
	if (fileopen(g_buff, argc, file_n) == 1)
		return (2);
	cnt = linenumber(g_buff);
	g_point = (t_rush *)malloc(sizeof(t_rush) * (cnt + 1));
	if (g_point == NULL)
		return (2);
	if (store(g_buff, cnt, g_point) == -1)
		return (1);
	i = store(g_buff, cnt, g_point);
	g_point[i].key = 0;
	g_point[i].value = 0;
	g_point[i].len = 0;
	if (right(g_point) == 1)
		return (1);
	return (0);
}
