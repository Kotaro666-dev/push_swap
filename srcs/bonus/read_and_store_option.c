/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_store_option.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:03:51 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 13:04:54 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			read_and_store_option(t_main *main, char **argv)
{
	while (*argv)
	{
		if (!ft_strcmp("-v", *argv))
		{
			main->option.is_v = TRUE;
		}
		else if (!ft_strcmp("-c", *argv))
		{
			main->option.is_c = TRUE;
		}
		else
		{
			argv++;
			break ;
		}
		argv++;
	}
}
