/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarai <rarai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:43:45 by rarai             #+#    #+#             */
/*   Updated: 2021/03/07 21:13:58 by rarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef	struct	s_rush
{
	char		*key;
	char		*value;
	char		*key_right;
	char		*value_right;
	int			len;
	int			key_len;
}				t_rush;

int				g_flag;
char			*g_buff;
t_rush			*g_point;
int				ft_strlen(char *str);
int				split_num1(char **array, char *num_str);
void			split_num2(char **array, char *num_str, int rem, int elem_cnt);
void			split_num3(char **array, char *num_str, int elem_count);
void			num_array_free(char **num_array, int elem_count);
void			put_unit(int cnt, t_rush *g_point);
void			key_put(char *str, t_rush *g_point);
void			output3(char *p, t_rush *g_point);
void			output2(char *p, t_rush *g_point);
void			key_check(char *str, int cnt);
int				zero_skip(char *str);
char			*ft_charcat(char *dest, char src);
char			*n_atoi(char *str, char *fix, int i);
char			*ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				dict_right(t_rush *g_point, int i);
int				fileopen(char *buff, int argc, char *file_n);
int				linenumber(char *buff);
int				store_key(char *buff, char **ft_key, int i, int j);
int				store_value(char *buff, char **ft_value, int i, int j);
int				store(char *buff, int cnt, t_rush *g_point);
int				right(t_rush *g_point);
int				fileread(int argc, char *file_n);
void			str_free(int i);

#endif
