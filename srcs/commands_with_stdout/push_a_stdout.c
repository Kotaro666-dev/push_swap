/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:26 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 14:38:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pa
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

#include "commands.h"

void			push_a_stdout(t_main *main)
{
	push_a(main);
	ft_putendl_fd("pa", STDOUT_FILENO);
}
