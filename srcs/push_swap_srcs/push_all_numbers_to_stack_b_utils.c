/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_numbers_to_stack_b_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:11:48 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 18:25:50 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			update_main_members(t_main *main)
{
	main->border += main->diff;
	if (main->border > main->size)
	{
		main->border = main->size;
	}
	main->max_number = main->array[main->border - 1];
}

void			set_main_members(t_main *main, int divider)
{
	main->border = main->size / divider;
	main->diff = main->size / divider;
	main->max_number = main->array[main->border - 1];
}

void			push_b_from_top(t_main *main, int step_from_head)
{
	while (step_from_head != 0)
	{
		rotate_a_stdout(main);
		step_from_head--;
	}
	push_b_stdout(main);
}

void			push_b_from_tail(t_main *main, int step_from_tail)
{
	while (step_from_tail != 0)
	{
		reverse_rotate_a_stdout(main);
		step_from_tail--;
	}
	push_b_stdout(main);
}

int			count_step_from_head(t_stack *stack, int max_number)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->next != head)
	{
		if (current->value <= max_number)
		{
			return (step);
		}
		current = current->next;
		step++;
	}
	if (current->value <= max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			count_step_from_tail(t_stack *stack, int max_number)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = stack;
	head = stack;
	step = 0;
	while (current->prev != head)
	{
		if (current->value <= max_number)
		{
			return (step);
		}
		current = current->prev;
		step++;
	}
	if (current->value <= max_number)
	{
		return (step);
	}
	return (NOT_FOUND);
}

int			is_minimum_number_on_head(t_stack *stack)
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

void			put_minimum_number_on_head(t_main *main)
{
	int	position;
	int	size;

	if (is_minimum_number_on_head(main->stack_b))
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
