/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:22:16 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:45:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "main.h"
# include "struct.h"

void	swap_a(t_main *main);
void	swap_b(t_main *main);
void	swap_a_and_b(t_main *main);
void	push_a(t_main *main);
void	push_b(t_main *main);
void	rotate_a(t_main *main);
void	rotate_b(t_main *main);
void	rotate_a_and_b(t_main *main);
void	reverse_rotate_a(t_main *main);
void	reverse_rotate_b(t_main *main);
void	reverse_rotate_a_and_b(t_main *main);

/*
** 	COMMANDS_WITH_STDOUT
*/

void	push_a_stdout(t_main *main);
void	push_b_stdout(t_main *main);
void	reverse_rotate_a_and_b_stdout(t_main *main);
void	reverse_rotate_a_stdout(t_main *main);
void	reverse_rotate_b_stdout(t_main *main);
void	rotate_a_and_b_stdout(t_main *main);
void	rotate_a_stdout(t_main *main);
void	rotate_b_stdout(t_main *main);
void	swap_a_and_b_stdout(t_main *main);
void	swap_a_stdout(t_main *main);
void	swap_b_stdout(t_main *main);

/*
** PUSH_UTILS.C
*/

void	remove_head_node(t_stack ***stack, t_stack *node);
void	insert_node_at_front(t_stack ***stack, t_stack *node);
void	insert_node_at_end(t_stack ***stack, t_stack *node);

#endif
