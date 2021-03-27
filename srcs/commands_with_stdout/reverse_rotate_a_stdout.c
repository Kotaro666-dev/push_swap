/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_stdout.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:17 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 14:39:50 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rra
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

#include "commands.h"

void	reverse_rotate_a_stdout(t_main *main)
{
	reverse_rotate_a(main);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
