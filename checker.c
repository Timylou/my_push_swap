/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:45:03 by yel-mens          #+#    #+#             */
/*   Updated: 2024/12/11 12:06:49 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

static void	ft_error(t_node **stack_a, t_node **stack_b, char *line)
{
	ft_free_stacks(stack_a, stack_b);
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

static void	ft_switch(t_node **stack_a, t_node **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(stack_a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(stack_b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		swap_s(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		rotate_a(stack_a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_b(stack_b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rotate_r(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		reverse_rotate_r(stack_a, stack_b, 0);
	else
		ft_error(stack_a, stack_b, line);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

	stack_a = ft_parse(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (EXIT_FAILURE);
	line = get_next_line(0);
	while (line)
	{
		ft_switch(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
