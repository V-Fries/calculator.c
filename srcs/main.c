/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:19:19 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 13:45:48 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokens.h"
#include "ft_io.h"
#include "ft_linked_list.h"
#include <stdlib.h>

static void	solve(t_list_i **operands, t_list *tokens)
{
	int			result;
	t_list_i	*tmp;

	if (*operands == NULL || (*operands)->next == NULL)
	{
		ft_lsti_clear(operands);
		ft_lstclear(&tokens, &free);
		ft_printf("Number of operands is wrong\n");
		exit(1);
	}
	if (((t_token *)tokens->content)->data == '+')
		result = (*operands)->next->content + (*operands)->content;
	else if (((t_token *)tokens->content)->data == '-')
		result = (*operands)->next->content - (*operands)->content;
	else if (((t_token *)tokens->content)->data == '*')
		result = (*operands)->next->content * (*operands)->content;
	else
		result = (*operands)->next->content / (*operands)->content;
	tmp = (*operands)->next;
	free(*operands);
	*operands = tmp;
	(*operands)->content = result;
}

static void	add_operand(t_list_i **operands, t_list **tokens)
{
	t_list_i	*new;

	new = malloc(sizeof(t_list_i));
	if (new == NULL)
	{
		ft_lsti_clear(operands);
		ft_lstclear(tokens, &free);
		exit(1);
	}
	new->content = ((t_token *)(*tokens)->content)->data;
	new->next = *operands;
	*operands = new;
}

int	main(int argc, char **argv)
{
	t_list		*tokens;
	t_list_i	*operands;

	if (argc != 2)
	{
		ft_putstr("Please input 1 argument\n");
		return (0);
	}
	tokens = parse_arguments(argv[1]);
	operands = NULL;
	while (tokens != NULL)
	{
		if (((t_token *)tokens->content)->type == OPERATOR)
			solve(&operands, tokens);
		else
			add_operand(&operands, &tokens);
		tokens = ft_lst_get_next_free_current(tokens, &free);
	}
	ft_printf("%s\n\t= %d\n", argv[1], operands->content);
	ft_lsti_clear(&operands);
}
