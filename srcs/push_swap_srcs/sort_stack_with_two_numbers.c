/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_two_numbers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:07:52 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 13:59:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		sort_stack_with_two_numbers(t_main *main)
{
	t_stack *stack_a;

	stack_a = main->stack_a;
	if (stack_a->value < stack_a->next->value)
	{
		return ;
	}
	swap_a_stdout(main);
}
