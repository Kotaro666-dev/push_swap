/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:25:58 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:26:16 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *next;

	if (*stack == NULL)
	{
		return ;
	}
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_memory(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}