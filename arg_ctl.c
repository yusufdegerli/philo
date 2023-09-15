/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:27:12 by ydegerli          #+#    #+#             */
/*   Updated: 2023/08/30 16:28:09 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	for_spaces(char c)
{
	if ((c == ' ' || c == '\t' || c == '\r'
			|| c == '\n' || c == '\v' || c == '\f'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	argument_ctl(char **av)
{
	if (check_num(av))
		return (0);
	return (1);
}
