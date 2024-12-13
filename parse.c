/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:45:16 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/25 16:08:31 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_str(char *str)
{
	int	i;
	int	check;

	check = 1;
	if (str[0] == ' ')
		check = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !('9' >= str[i] && str[i] >= '0')
			&& str[i] != '-' && str[i] != '+')
			check = 0;
		if ((str[i] == '-' || str[i] == '+')
			&& !('9' >= str[i + 1] && str[i + 1] >= '0'))
			check = 0;
		i++;
	}
	if (!check)
		ft_putstr("Error\n");
	return (check);
}

static int	ft_add_to_stack(t_node **stk, int *sign, long long int *data)
{
	if (*sign)
		*data *= -1;
	if (!ft_add_end_stack(stk, *data))
	{
		ft_free_stacks(stk, NULL);
		*stk = NULL;
		return (0);
	}
	*data = 0;
	*sign = 0;
	return (1);
}

static t_node	*ft_read_string(char *str)
{
	int					i;
	long long int		current_data;
	int					sign;
	t_node				*stack;

	if (!ft_check_str(str))
		return (NULL);
	stack = NULL;
	current_data = 0;
	sign = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign = 1;
		if ('9' >= str[i] && str[i] >= '0')
			current_data = current_data * 10 + str[i] - '0';
		if (str[i++] == ' ')
		{
			if (!ft_add_to_stack(&stack, &sign, &current_data))
				return (NULL);
		}
	}
	ft_add_to_stack(&stack, &sign, &current_data);
	return (stack);
}

static t_node	*ft_read_argv(int argc, char **argv)
{
	int		i;
	t_node	*stack;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_check_str(argv[i]))
		{
			ft_free_stacks(&stack, NULL);
			return (NULL);
		}
		if (!ft_add_end_stack(&stack, ft_atoi(argv[i])))
		{
			ft_free_stacks(&stack, NULL);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

t_node	*ft_parse(int argc, char **argv)
{
	t_node	*stack;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	if (argc == 2)
		stack = ft_read_string(argv[1]);
	else
		stack = ft_read_argv(argc, argv);
	if (!stack)
		return (NULL);
	return (stack);
}
