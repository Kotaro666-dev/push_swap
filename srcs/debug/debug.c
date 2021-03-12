/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:44:50 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/12 14:52:35 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_out_stack_a(t_stack *stack_a)
{
	t_stack *current;

	current = stack_a;
	while (current->next)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n", current->value);
}
