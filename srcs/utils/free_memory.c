/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:25:58 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 14:02:04 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void		free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *head;
	t_stack *next;

	if (*stack == NULL)
	{
		return ;
	}
	current = *stack;
	head = *stack;
	while (current->next != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	current = NULL;
}

static void		free_array(t_main *main)
{
	free(main->array);
	main->array = NULL;
}

void			dispose_memory(t_main *main)
{
	free_stack(&(main->stack_a));
	free_stack(&(main->stack_b));
	free_array(main);
}
