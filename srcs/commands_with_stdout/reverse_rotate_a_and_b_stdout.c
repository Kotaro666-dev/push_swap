/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b_stdout.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:13 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 16:02:10 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rrr
** rra and rrb at the same time.
*/

#include "commands.h"

void	reverse_rotate_a_and_b_stdout(t_main *main)
{
	reverse_rotate_a_and_b(main);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
