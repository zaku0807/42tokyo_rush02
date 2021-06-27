/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarai <rarai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:43:48 by dogawa            #+#    #+#             */
/*   Updated: 2021/03/07 21:30:43 by rarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	char	**num_array;
	char	*num_str;
	int		flag;

	if (argc < 2 || 3 < argc)
		return (1);
	flag = fileread(argc, argv[1]);
	if (1 <= flag)
	{
		str_free(flag);
		return (1);
	}
	num_str = ft_atoi(argv[argc - 1]);
	num_array = NULL;
	if (split_num1(num_array, num_str) == 1)
	{
		str_free(1);
		ft_putstr("Error\n");
		return (1);
	}
	str_free(1);
	free(num_str);
	return (0);
}

void	str_free(int i)
{
	if (i <= 2)
		free(g_buff);
	if (i == 1)
	{
		free(g_point->key);
		free(g_point->value);
		free(g_point);
	}
}
