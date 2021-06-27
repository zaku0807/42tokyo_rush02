/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:44:31 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/07 20:44:38 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_charcat(char *dest, char src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

char	*n_atoi(char *str, char *fix, int i)
{
	int		flag;

	flag = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			flag = 1;
			ft_charcat(fix, str[i]);
		}
		else if (str[i] == '0')
		{
			if (flag == 0)
				return (0);
			else
				ft_charcat(fix, '0');
		}
		else
			return (0);
		i++;
	}
	ft_charcat(fix, '\0');
	return (fix);
}

char	*ft_atoi(char *str)
{
	int		i;
	int		flag;
	char	*fix;

	fix = (char *)malloc(sizeof(char) * 300);
	i = 0;
	flag = 1;
	while (str[i] == '\v' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '0')
	{
		if (str[i + 1] != '\0')
			return (0);
		else
		{
			ft_charcat(fix, str[i]);
			return (fix);
		}
	}
	return (n_atoi(str, fix, i));
}
