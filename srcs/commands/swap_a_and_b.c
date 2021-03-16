/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_and_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:23 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:45:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rr
** ra and rb at the same time.
*/

#include "commands.h"

void	swap_a_and_b(t_main *main)
{
	swap_a(&(main->stack_a));
	swap_b(&(main->stack_b));
}
