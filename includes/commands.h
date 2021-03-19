/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:22:16 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 13:59:11 by kkamashi         ###   ########.fr       */
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
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_and_b(t_main *main);

#endif
