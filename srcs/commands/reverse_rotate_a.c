/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:17 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 14:34:11 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rra
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

#include "commands.h"

void	reverse_rotate_a(t_main *main)
{
	t_stack **stack_a;

	stack_a = &(main->stack_a);
	if (*stack_a == NULL)
	{
		return ;
	}
	*stack_a = (*stack_a)->prev;
}
