/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:13 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 15:25:04 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rrr
** rra and rrb at the same time.
*/

#include "commands.h"

void	reverse_rotate_a_and_b(t_checker *checker)
{
	reverse_rotate_a(&(checker->stack_a));
	reverse_rotate_b(&(checker->stack_b));
}
