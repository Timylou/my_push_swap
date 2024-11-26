/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/26 14:39:01 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack;

	stack_a = ft_parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (EXIT_FAILURE);
	if (ft_is_sorted(stack_a))
	{
		ft_free_stacks(&stack_a, &stack_b);
		return (EXIT_SUCCESS);
	}
	size_stack = ft_size_stack(stack_a);
	if (size_stack < 3)
		ft_sort_small_stack(&stack_a, size_stack);
	else if (size_stack == 3)
		ft_sort_three_stack(&stack_a);
	else if (size_stack == 4)
		ft_sort_four_stack(&stack_a, &stack_b);
	else
		ft_sort_stacks(&stack_a, &stack_b);
	ft_free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
