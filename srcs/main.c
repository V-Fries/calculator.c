/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:19:19 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 00:34:19 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_linked_list.h"

int	main(int argc, char **argv)
{
	t_list	*tokens;

	if (argc != 2)
	{
		ft_putstr("Please input 1 argument");
		return (0);
	}
	tokens = parse_arguments(argv[1]);
}
