/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_and_b_stdout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:23 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 16:02:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rr
** ra and rb at the same time.
*/

#include "commands.h"

void	swap_a_and_b_stdout(t_main *main)
{
	swap_a_and_b(main);
	ft_putendl_fd("ss", STDOUT_FILENO);
}
