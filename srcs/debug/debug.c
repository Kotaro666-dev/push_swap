/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:44:50 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/14 09:10:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_out_stack(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
