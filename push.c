/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:40:16 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/26 14:35:00 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_node **src, t_node **dest)
{
	t_node	*to_push;

	if (!src || !*src)
		return ;
	(*src)->index = 0;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
		(*dest)->prev = to_push;
	to_push->next = *dest;
	*dest = to_push;
}

static void	ft_reload_index(t_node *stack, int sign)
{
	while (stack)
	{
		stack->index += 1 * sign;
		stack = stack->next;
	}
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_b)
		return ;
	ft_reload_index(*stack_a, 1);
	ft_reload_index(*stack_b, -1);
	ft_push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	ft_reload_index(*stack_b, 1);
	ft_reload_index(*stack_a, -1);
	ft_push(stack_a, stack_b);
	ft_putstr("pb\n");
}
