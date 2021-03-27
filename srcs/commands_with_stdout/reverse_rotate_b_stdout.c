/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b_stdout.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:15 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 14:34:45 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rrb
** reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

#include "commands.h"

void	reverse_rotate_b_stdout(t_main *main)
{
	t_stack **stack_b;

	stack_b = &(main->stack_b);
	if (*stack_b == NULL)
	{
		return ;
	}
	*stack_b = (*stack_b)->prev;
	ft_putendl_fd("rrb", STDOUT_FILENO);
}
