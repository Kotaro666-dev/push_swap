/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:15:19 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 13:40:53 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void		remove_head_node(t_stack ***stack, t_stack *node)
{
	**stack = node->next;
	(**stack)->prev->prev->next = **stack;
	(**stack)->prev = (**stack)->prev->prev;
}

void		insert_node_at_front(t_stack ***stack, t_stack *node)
{
	**stack = node;
	node->prev = node;
	node->next = node;
}

void		insert_node_at_end(t_stack ***stack, t_stack *node)
{
	node->next = **stack;
	node->prev = (**stack)->prev;
	(**stack)->prev->next = node;
	(**stack)->prev = node;
}
