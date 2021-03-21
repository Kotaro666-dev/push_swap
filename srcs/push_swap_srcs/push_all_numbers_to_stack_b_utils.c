/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_b_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:11:48 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:01:48 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			count_step_from_top(t_stack *stack, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->next != head)
	{
		if (current->value <= maximum)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value <= maximum)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			count_step_from_tail(t_stack *stack, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->prev != head)
	{
		if (current->value <= maximum)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value <= maximum)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			is_minimum_number_on_top(t_stack *stack)
{
	int		top;
	t_stack	*head;

	top = stack->value;
	head = stack;
	if (stack == NULL || stack->next == NULL)
	{
		return (TRUE);
	}
	stack = stack->next;
	while (stack->next != head)
	{
		if (top > stack->value)
		{
			return (FALSE);
		}
		stack = stack->next;
	}
	if (top > stack->value)
	{
		return (FALSE);
	}
	return (TRUE);
}

int			get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*head;

	size = 0;
	head = stack;
	while (stack->next != head)
	{
		size++;
		stack = stack->next;
	}
	size++;
	return (size);
}

int			find_minimum_position(t_stack *stack)
{
	int		position;
	int		index;
	int		minimum;
	t_stack	*head;

	position = 0;
	index = 0;
	minimum = INT_MAX;
	head = stack;
	while (stack->next != head)
	{
		if (stack->value < minimum)
		{
			minimum = stack->value;
			position = index;
		}
		stack = stack->next;
		index++;
	}
	if (stack->value < minimum)
	{
		position = index;
	}
	return (position);
}

void			put_minimum_number_on_top(t_main *main)
{
	int	position;
	int	size;

	if (is_minimum_number_on_top(main->stack_b))
	{
		return ;
	}
	position = find_minimum_position(main->stack_b);
	size = get_stack_size(main->stack_b);
	if (position <= size / 2)
	{
		while (position != 0)
		{
			rotate_b_stdout(main);
			position--;
		}
	}
	else
	{
		while (position != 0)
		{
			reverse_rotate_b_stdout(main);
			position--;
		}
	}
}
