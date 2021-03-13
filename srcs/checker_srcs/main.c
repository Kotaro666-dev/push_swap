/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:02:55 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/13 19:46:54 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		initialize_both_stack(t_checker *checker)
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
	t_stack *current;

	current = checker->stack_a;
	while (current->next)
	{
		if (current->value == current->next->value)
		{
			return (FALSE);
		}
		current = current->next;
	}
	return (TRUE);
}

int			quick_sort(t_checker *checker)
{

}

int			merge_sort(t_checker *checker)
{

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

int		main(int argc, char *argv[])
{
	t_checker checker;

	if (argc == 1)
	{
		return (0);
	}
	initialize_both_stack(&checker);
	if (initialize_stack_a(&checker, argv + 1) == ERROR)
	{
		print_out_error();
		return (0);
	}
	// check if every number is unique
	if (!is_every_number_unique(&checker))
	{
		print_out_error();
		return (0);
	}
	// START READING AND OPERATE COMMANDS

	// CHECK IF STACK_A IS SORTED AND STACK_B IS EMPTY

	// PRINT OUT OK OR KO
	print_out_stack_a(checker.stack_a);
	return (0);
}
