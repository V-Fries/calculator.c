/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:51:27 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 02:57:38 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "tokens.h"
#include <stdbool.h>
#include <stdlib.h>

bool	is_an_operator(char *args)
{
	return ((args[1] == '\0' || args[1] == ' ')
		&& (args[0] == '+' || args[0] == '-'
			|| args[0] == '*' || args[0] == '/'));
}

int	get_operator_priority(int operator)
{
	if (operator == '+' || operator == '-')
		return (PLUS_MINUS_PRIORITY);
	if (operator == '*' || operator == '/')
		return (MULT_DIV_PRIORITY);
	return (PARENTHESES_PRIORITY);
}

static bool	should_push_previous(t_token *previous, int operator_priority)
{
	int	previous_priority;

	if (previous->type != OPERATOR)
		return (false);
	previous_priority = get_operator_priority(previous->data);
	return (operator_priority <= previous_priority);
}

static t_token	*get_new_token(t_list **tokens, t_list **operators,
					char operator)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		ft_lstclear(tokens, &free);
		ft_lstclear(operators, &free);
		exit(1);
	}
	new_token->type = OPERATOR;
	new_token->data = operator;
	return (new_token);
}

void	add_operator(t_list **tokens, t_list **operators, char operator)
{
	t_token	*new_token;
	t_list	*new_node;

	while (*operators != NULL && should_push_previous((*operators)->content,
			get_operator_priority(operator)))
		ft_lst_push(tokens, operators);
	new_token = get_new_token(tokens, operators, operator);
	new_node = ft_lstnew(new_token);
	if (new_node == NULL)
	{
		free(new_token);
		ft_lstclear(tokens, &free);
		ft_lstclear(operators, &free);
		exit(1);
	}
	ft_lstadd_front(operators, new_node);
}
