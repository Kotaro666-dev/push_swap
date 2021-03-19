/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:18:44 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 13:43:35 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sb
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

#include "commands.h"

void	swap_b(t_main *main)
{
	int		temp_value;
	t_stack	**stack_b;

	stack_b = &(main->stack_b);
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return;
	}
	temp_value = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp_value;
	main->count++;
}
