/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers_patterns.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:05:57 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 18:06:39 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			is_two_one_three(t_main *main)
{
	if (main->top > main->middle && main->top < main->bottom)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_three_two_one(t_main *main)
{
	if (main->top > main->middle && main->middle > main->bottom)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_three_one_two(t_main *main)
{
	if (main->top > main->middle && main->middle < main->bottom)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_one_three_two(t_main *main)
{
	if (main->top < main->middle && main->top < main->bottom &&
		main->middle > main->bottom)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_two_three_one(t_main *main)
{
	if (main->top < main->middle && main->top > main->bottom &&
		main->middle > main->bottom)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
