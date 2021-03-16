/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_and_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:17:38 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 14:38:35 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rr
** ra and rb at the same time.
*/

#include "commands.h"

void	rotate_a_and_b(t_checker *checker)
{
	rotate_a(&(checker->stack_a));
	rotate_b(&(checker->stack_b));
}
