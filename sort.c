/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:09:18 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/26 18:31:46 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stacks(t_node **stack_a, t_node **stack_b, int size)
{
	t_node	*min;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (ft_size_stack(*stack_a) > 3)
	{
		ft_set_target(*stack_a, *stack_b, 1);
		ft_set_costs(*stack_a, ft_size_stack(*stack_b));
		ft_set_cheapest(stack_a, stack_b);
	}
	ft_sort_three_stack(stack_a);
	while (*stack_b)
	{
		ft_set_target(*stack_b, *stack_a, 0);
		ft_set_costs(*stack_b, ft_size_stack(*stack_a));
		ft_set_cheapest_back(stack_a, stack_b);
	}
	min = ft_find_min(*stack_a);
	while (min->index && min->index < size / 2)
		rotate_a(stack_a);
	while (min->index && min->index >= size / 2)
		reverse_rotate_a(stack_a);
}
