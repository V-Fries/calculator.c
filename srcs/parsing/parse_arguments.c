/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:34:06 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 00:51:33 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list	*parse_arguments(char *args)
{
	t_list	*tokens;
	t_list	*operators;

	tokens = NULL;
	operators = NULL;
	while (*args != '\0')
	{
		if (is_an_operator(args))
			add_operator(&tokens, operators, *args);
		else if - a left parenthesis (i.e. "("):
			push it onto the operator stack
		else if - a right parenthesis (i.e. ")"):
			while the operator at the top of the operator stack is not a left parenthesis:
				{assert the operator stack is not empty}
				/* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
				pop the operator from the operator stack into the output queue
			{assert there is a left parenthesis at the top of the operator stack}
			pop the left parenthesis from the operator stack and discard it
			if there is a function token at the top of the operator stack, then:
				pop the function from the operator stack into the output queue
		else // if (is_a_number(args))
			put it into the output queue
	}
	/* After the while loop, pop the remaining items from the operator stack into the output queue. */
	while there are tokens on the operator stack:
		/* If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses. */
		{assert the operator on top of the stack is not a (left) parenthesis}
		pop the operator from the operator stack onto the output queue

}
