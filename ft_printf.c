/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:08:37 by ndesprez          #+#    #+#             */
/*   Updated: 2023/04/05 10:42:21 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printer(char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(params, int)));
	else if (c == 's')
		return (ft_putstr((char *)va_arg(params, char *)));
	else if (c == 'p')
		return (ft_putstr("0x")
			+ ft_puthex((unsigned long)va_arg(params, void *), 'x'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr((int)va_arg(params, int)));
	else if (c == 'u')
		return (ft_putnbr((unsigned int)va_arg(params, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex((unsigned int)va_arg(params, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	params;

	count = 0;
	i = 0;
	va_start(params, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			count += printer(format[i + 1], params);
			i += 2;
		}
	}
	va_end(params);
	return (count);
}
