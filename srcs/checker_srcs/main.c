/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:02:55 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 17:36:54 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		initialize_checker(t_checker *checker)
{
	checker->stack_a = NULL;
	checker->stack_b = NULL;
}

int			store_value_in_stack_a(t_stack **stack_a, int num)
{
	t_stack *new;
	t_stack *current;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		return (ERROR);
	}
	new->value = num;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		new->prev = NULL;
		new->next = NULL;
		return (SUCCESS);
	}
	current = *stack_a;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	new->next = NULL;
	return (SUCCESS);
}

int			is_every_number_unique(t_checker *checker)
{
	t_stack	*first;
	t_stack	*second;

	first = checker->stack_a;
	while (first->next)
	{
		second = first->next;
		while (second)
		{
			if (first->value == second->value)
			{
				return (FALSE);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (TRUE);
}

int			initialize_stack_a(t_checker *checker, char **argv)
{
	int num;

	while (*argv)
	{
		if (!is_arg_numeric(*argv))
		{
			return (ERROR);
		}
		if ((num = ft_atoi(*argv)) == OVERFLOW &&
			ft_strncmp(*argv, "-1", 2) != 0)
		{
			return (ERROR);
		}
		if (store_value_in_stack_a(&(checker->stack_a), num) == ERROR)
		{
			return (ERROR);
		}
		argv++;
	}
	return (SUCCESS);
}

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

void	dispose_memory(t_checker *checker)
{
	free_stack(&(checker->stack_a));
	free_stack(&(checker->stack_b));

}

int		main(int argc, char *argv[])
{
	t_checker checker;

	if (argc == 1)
	{
		return (0);
	}
	initialize_checker(&checker);
	if (initialize_stack_a(&checker, argv + 1) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_every_number_unique(&checker))
	{
		return (print_out_error());
	}
	if (read_and_operate_commands(&checker) == ERROR)
	{
		return (print_out_error());
	}
	if (!is_stack_sorted(checker.stack_a))
	{
		return (print_out_ko());
	}
	if (!is_stack_empty(checker.stack_b))
	{
		return (print_out_ko());
	}
	dispose_memory(&checker);
	return (print_out_ok());
}
