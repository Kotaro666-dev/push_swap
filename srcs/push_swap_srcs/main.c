
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:04:09 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/20 08:58:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			count_step_from_top(t_main *main, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_a;
	head = main->stack_a;
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

int			count_step_from_tail(t_main *main, int maximum)
{
	t_stack	*current;
	t_stack	*head;
	int		step;

	current = main->stack_a;
	head = main->stack_a;
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

void		put_minimum_number_on_top(t_main *main)
{
	int	position;
	int	size;

	if (is_minimum_number_on_top(main->stack_b))
	{
		return ;
	}
	position = find_minimum_position(main->stack_b);
	size = get_stack_size(main->stack_b);
	// printf("position = %d\n", position);
	// printf("size = %d\n", size);
	if (position <= size / 2)
	{
		while (position != 0)
		{
			rotate_b(main);
			position--;
		}
	}
	else
	{
		while (position != 0)
		{
			reverse_rotate_b(main);
			position--;
		}
	}
}

void		sort_stack_with_a_hundred_numbers(t_main *main)
{
	int		border;
	int		div;
	int		maximum;
	t_stack	**stack_a;
	int		step_from_top;
	int		step_from_tail;

	border = main->size / 5;
	div = main->size / 5;
	maximum = main->array[border - 1];
	stack_a = &(main->stack_a);
	while (!is_stack_empty(main->stack_a))
	{
		step_from_top = count_step_from_top(main, maximum);
		step_from_tail = count_step_from_tail(main, maximum);
		if (step_from_top == NOT_FOUND && step_from_tail == NOT_FOUND)
		{
			border += div;
			maximum = main->array[border - 1];
			continue ;
		}
		if (step_from_top < step_from_tail)
		{
			while (step_from_top != 0)
			{
				rotate_a(main);
				step_from_top--;
			}
			push_b(main);
		}
		else
		{
			while (step_from_tail != 0)
			{
				reverse_rotate_a(main);
				step_from_tail--;
			}
			push_b(main);
		}
		put_minimum_number_on_top(main);
		print_out_stack(main->stack_a, main->stack_b);
	}
	// stack_bから数字が大きい順にstack_aに戻していく

}


void		sort_stack_a_by_size(t_main *main)
{
	ft_qsort(main->array, 0, main->size - 1);
	if (main->size < 2)
		return ;
	else if (main->size == 2)
	{
		sort_stack_with_two_numbers(main);
	}
	else if (main->size == 3)
	{
		sort_stack_with_three_numbers(main);
	}
	else if (main->size >= 4 && main->size <= 7)
	{
		sort_stack_with_more_than_four_numbers(main);
	}
	else
	{
		sort_stack_with_a_hundred_numbers(main);
	}
}

int			main(int argc, char *argv[])
{
	t_main main;

	if (argc == 1)
	{
		return (0);
	}
	if (initialize_struct(&main, argc) == MALLOC_ERROR)
	{
		return (MALLOC_ERROR);
	}
	if (initialize_stack_a(&main, argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(main.stack_a))
	{
		return (print_out_error());
	}
	// SORT
	sort_stack_a_by_size(&main);
	// print_out_stack(main.stack_a, main.stack_b);
	print_out_count(&main);
	// free_memory(&(main.stack_a), &(main.stack_b));
	return (print_out_ok());
}
