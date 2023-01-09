/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:53:19 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 02:39:23 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "ft_io.h"
#include "tokens.h"
#include "parsing.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t	is_parenthes(char *args)
{
	if (args[0] == '(')
		return (1);
	if (args[0] == ')')
		return (2);
	return (0);
}

void	open_parenthes(t_list **tokens, t_list **operators)
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
	new_token->type = PARENTHESES;
	new_token->data = PARENTHESES;
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

void	close_parenthes(t_list **tokens, t_list **operators)
{
	while (*operators != NULL
		&& ((t_token *)(*operators)->content)->type != PARENTHESES)
		ft_lst_push(tokens, operators);
	if (*operators == NULL)
	{
		ft_lstclear(tokens, &free);
		ft_lstclear(operators, &free);
		ft_putstr(PARENTHES_ERROR);
		exit(1);
	}
	*operators = ft_lst_get_next_free_current(*operators, &free);
}
