/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartypes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:14:04 by ndesprez          #+#    #+#             */
/*   Updated: 2023/04/04 18:00:43 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// %s
int	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		n++;
	}
	return (n);
}
