/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:42:20 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:48:08 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

static int		is_result_overflow(long long int num, int is_minus)
{
	if (is_minus)
	{
		if (INT_MAX < num - 1)
		{
			return (TRUE);
		}
	}
	else
	{
		if (INT_MAX < num)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

int				ft_atoi(const char *str)
{
	long long int	result;
	int				is_minus;

	if (str == NULL)
		return (0);
	result = 0;
	is_minus = FALSE;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		is_minus = *str == '-' ? TRUE : FALSE;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (is_result_overflow(result, is_minus))
			return (-1);
		str++;
	}
	return ((int)(result * (is_minus ? -1 : 1)));
}
