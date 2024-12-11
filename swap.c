/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:38:06 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/19 17:38:12 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (third)
		third->prev = first;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	first->index = 1;
	second->index = 0;
	*stack = second;
}

void	swap_a(t_node **stack, int print)
{
	if (!stack || !*stack || ft_size_stack(*stack) < 2)
		return ;
	ft_swap(stack);
	if (print)
		ft_putstr("sa\n");
}

void	swap_b(t_node **stack, int print)
{
	if (!stack || !*stack || ft_size_stack(*stack) < 2)
		return ;
	ft_swap(stack);
	if (print)
		ft_putstr("sb\n");
}

void	swap_s(t_node **stack_a, t_node **stack_b, int print)
{
	if (!stack_a || !*stack_a || ft_size_stack(*stack_a) < 2)
		return ;
	if (!stack_b || !*stack_b || ft_size_stack(*stack_b) < 2)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print)
		ft_putstr("ss\n");
}
