/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:55:26 by ndesprez          #+#    #+#             */
/*   Updated: 2023/04/05 10:46:56 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d %i %u
int	ft_putnbr(long nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	if (nb > 9)
		return (ft_putnbr(nb / 10) + ft_putchar(nb % 10 + 48));
	else
		return (ft_putchar(nb + 48));
}

// %p %x %X
int	ft_puthex(unsigned long long nb, char maj)
{
	char		*base;

	if (maj == 'x')
		base = "0123456789abcdef";
	if (maj == 'X')
		base = "0123456789ABCDEF";
	if (nb == 0)
		return (ft_putchar(base[0]));
	if (nb != 0)
	{
		if (nb / 16 != 0)
			return (ft_puthex(nb / 16, maj) + ft_putchar(base[nb % 16]));
		else
			return (ft_putchar(base[nb % 16]));
	}
	return (0);
}
