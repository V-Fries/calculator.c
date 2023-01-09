/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:34:06 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 02:51:49 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "parsing.h"
#include "ft_linked_list.h"
#include "ft_numbers.h"
#include "ft_io.h"
#include <stdlib.h>

static void	add_number(t_list **tokens, t_list **operators, char *args)
{
	t_token	*new_token;
	t_list	*new_node;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		ft_lstclear(tokens, &free);
		ft_lstclear(operators, &free);
		exit(1);
	}
	new_token->type = NUMBER;
	new_token->data = ft_atoi(args);
	new_node = ft_lstnew(new_token);
	if (new_node == NULL)
	{
		free(new_token);
		ft_lstclear(tokens, &free);
		ft_lstclear(operators, &free);
		exit(1);
	}
	ft_lstadd_front(tokens, new_node);
}

static void	push_all_operators(t_list **tokens, t_list **operators)
{
	while (*operators != NULL)
	{
		if (((t_token *)(*operators)->content)->type == PARENTHESES)
		{
			ft_lstclear(tokens, &free);
			ft_lstclear(operators, &free);
			ft_putstr(PARENTHES_ERROR);
			exit(1);
		}
		ft_lst_push(tokens, operators);
	}
}

t_list	*parse_arguments(char *args)
{
	t_list	*tokens;
	t_list	*operators;

	tokens = NULL;
	operators = NULL;
	while (*args != '\0')
	{
		if (is_an_operator(args))
			add_operator(&tokens, &operators, *args);
		else if (is_parenthes(args) == 1)
			open_parenthes(&tokens, &operators);
		else if (is_parenthes(args) == 2)
			close_parenthes(&tokens, &operators);
		else
			add_number(&tokens, &operators, args);
		while (*args != '\0' && *args != ' ')
			args++;
		if (*args != '\0')
			args++;
	}
	push_all_operators(&tokens, &operators);
	return (ft_lst_reverse(&tokens));
}
