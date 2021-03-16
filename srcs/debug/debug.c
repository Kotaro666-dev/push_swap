/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:44:50 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 16:10:18 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_out_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = stack_a;
	current_b = stack_b;
	printf("_ _\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("%d ", current_a->value);
			current_a = current_a->next;
		}
		else
		{
			printf("  ");
		}
		if (current_b)
		{
			printf("%d", current_b->value);
			current_b = current_b->next;
		}
		else
		{
			printf(" ");
		}
		printf("\n");
	}
	printf("_ _\n");
	printf("a b\n");
}
