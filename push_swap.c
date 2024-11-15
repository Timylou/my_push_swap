/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/15 13:50:45 by yel-mens         ###   ########.fr       */
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
	size_stack = ft_size_stack(stack_a);
	if (size_stack < 2)
		ft_sort_small_stack(stack_a, size_stack);
	else if (size_stack == 3)
		ft_sort_three_stack(stack_a);
	else
		ft_sort_stacks(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
	return (EXIT_SUCCESS);
}
