/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:03:15 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/27 10:49:40 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_costs(t_node *stack, int size_dest)
{
	int	size_stack;

	size_stack = ft_size_stack(stack);
	while (stack)
	{
		stack->cost = stack->index;
		if (stack->index >= size_stack / 2)
			stack->cost = size_stack - (stack->index);
		if (stack->target->index < size_dest / 2)
			stack->cost += stack->target->index;
		else
			stack->cost += size_dest - (stack->target->index);
		stack = stack->next;
	}
}

void	ft_up_chpst(t_node **a, t_node **b, t_node *chp, int size[2])
{
	while (chp->index && chp->target->index)
	{
		if (chp->index < size[0] / 2 && chp->target->index < size[1] / 2)
			rotate_r(a, b);
		else if (chp->index >= size[0] / 2 && chp->target->index >= size[1] / 2)
			reverse_rotate_r(a, b);
		else if (chp->index < size[0] / 2 && chp->target->index >= size[1] / 2)
		{
			rotate_a(a);
			reverse_rotate_b(b);
		}
		else if (chp->index >= size[0] / 2 && chp->target->index < size[1] / 2)
		{
			reverse_rotate_a(a);
			rotate_b(b);
		}
	}
	while (chp->index && chp->index < size[0] / 2)
		rotate_a(a);
	while (chp->index && chp->index >= size[0] / 2)
		reverse_rotate_a(a);
	while (chp->target->index && chp->target->index < size[1] / 2)
		rotate_b(b);
	while (chp->target->index && chp->target->index >= size[1] / 2)
		reverse_rotate_b(b);
}

void	ft_up_chpst_bk(t_node **a, t_node **b, t_node *chp, int size[2])
{
	while (chp->index && chp->target->index)
	{
		if (chp->index < size[1] / 2 && chp->target->index < size[0] / 2)
			rotate_r(a, b);
		else if (chp->index >= size[1] / 2 && chp->target->index >= size[0] / 2)
			reverse_rotate_r(a, b);
		else if (chp->index < size[1] / 2 && chp->target->index >= size[0] / 2)
		{
			rotate_b(b);
			reverse_rotate_a(a);
		}
		else if (chp->index >= size[1] / 2 && chp->target->index < size[0] / 2)
		{
			reverse_rotate_b(b);
			rotate_a(a);
		}
	}
	while (chp->index && chp->index < size[1] / 2)
		rotate_b(b);
	while (chp->index && chp->index >= size[1] / 2)
		reverse_rotate_b(b);
	while (chp->target->index && chp->target->index < size[0] / 2)
		rotate_a(a);
	while (chp->target->index && chp->target->index >= size[0] / 2)
		reverse_rotate_a(a);
}

void	ft_set_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*tmp;
	int		size[2];

	cheapest = *stack_a;
	if (cheapest->cost)
	{
		tmp = cheapest;
		while (tmp)
		{
			if (tmp->cost > cheapest->cost)
				cheapest = tmp;
			tmp = tmp->next;
		}
	}
	size[0] = ft_size_stack(*stack_a);
	size[1] = ft_size_stack(*stack_b);
	ft_up_chpst(stack_a, stack_b, cheapest, size);
	push_b(stack_a, stack_b);
}

void	ft_set_cheapest_back(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*tmp;
	int		size[2];

	cheapest = *stack_b;
	if (cheapest->cost)
	{
		tmp = cheapest;
		while (tmp)
		{
			if (tmp->cost > cheapest->cost)
				cheapest = tmp;
			tmp = tmp->next;
		}
	}
	size[0] = ft_size_stack(*stack_a);
	size[1] = ft_size_stack(*stack_b);
	ft_up_chpst_bk(stack_a, stack_b, cheapest, size);
	push_a(stack_a, stack_b);
}
