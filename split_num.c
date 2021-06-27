/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogawa <dogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:44:05 by dogawa            #+#    #+#             */
/*   Updated: 2021/03/07 20:44:08 by dogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_i;
int g_j;

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	num_array_free(char **array, int elem_cnt)
{
	int i;

	i = 0;
	while (i < elem_cnt)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	split_num3(char **array, char *num_str, int elem_cnt)
{
	int count;
	int k;

	while (g_i < elem_cnt)
	{
		count = 0;
		while (count < 3)
		{
			array[g_i][count] = num_str[g_j];
			g_j++;
			count++;
		}
		array[g_i][count] = '\0';
		g_i++;
	}
	k = 0;
	while (elem_cnt > 0)
	{
		key_check(array[k], elem_cnt - 1);
		elem_cnt--;
		k++;
	}
	write(1, "\n", 1);
	num_array_free(array, elem_cnt);
}

void	split_num2(char **array, char *num_str, int rem, int elem_cnt)
{
	int count;

	g_i = 0;
	g_j = 0;
	if (rem != 0)
	{
		count = 0;
		while (count < rem)
		{
			array[0][count] = num_str[g_j];
			count++;
			g_j++;
		}
		g_i++;
	}
	split_num3(array, num_str, elem_cnt);
}

int		split_num1(char **array, char *num_str)
{
	int num_length;
	int rem;
	int div_quo;
	int elem_cnt;

	num_length = ft_strlen(num_str);
	rem = num_length % 3;
	div_quo = num_length / 3;
	if (rem != 0)
		elem_cnt = div_quo + 1;
	else
		elem_cnt = div_quo;
	if (elem_cnt > 13 || num_str == NULL)
		return (1);
	g_i = 0;
	array = (char **)malloc(sizeof(char *) * elem_cnt);
	while (g_i < elem_cnt)
	{
		array[g_i] = (char *)malloc(sizeof(char) * 4);
		g_i++;
	}
	split_num2(array, num_str, rem, elem_cnt);
	return (0);
}
