/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:51:27 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 01:51:29 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "tokens.h"
#include <stdbool.h>

bool	is_an_operator(char *args)
{
	return ((args[1] == '\0' || args[1] == ' ')
		&& (args[0] == '+' || args[0] == '-'
			|| args[0] == '*' || args[0] == '/'));
}

static bool	should_push_previous(t_token *previous, int operator_priority)
{
	int	previous_priority;

	if (previous->type != OPERATOR)
		return (false);
	previous_priority = get_operator_priority(previous->data);
	return (operator_priority <= previous_priority);
}

static	t_token *get_new_token(t_list **tokens, t_list **operators,
					char operator)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		ft_lst_clear(tokens);
		ft_lst_clear(operators);
		exit(1);
	}
	new_token->type = OPERATOR;
	if (operator == '+')
		new_token->data = PLUS;
	else if (operator == '-')
		new_token->data = MINUS;
	else if (operator == '*')
		new_token->data = MULT;
	else
		new_token->data = DIV;
	return (new_token);
}

void	add_operator(t_list **tokens, t_list **operators, char operator)
{
	t_token	*new_token;
	t_list	*new_node;

	while (should_push_previous((*tokens)->content,
		get_operator_priority(operator)))
		ft_lst_push(tokens, operators);
	new_token = get_new_token(tokens, operators, operator);
	new_node = ft_lstnew(new_token);
	if (new_node == NULL)
	{
		ft_lst_clear(tokens);
		ft_lst_clear(operators);
		exit(1);
	}
	ft_lstadd_front(tokens, new_node);
}
