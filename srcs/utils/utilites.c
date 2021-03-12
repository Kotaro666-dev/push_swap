/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:40:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/12 15:18:13 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_arg_numeric(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
