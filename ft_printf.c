/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:52:59 by slimane           #+#    #+#             */
/*   Updated: 2024/11/27 19:08:58 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	handle(va_list args, char c)
{
	int	count;

	count = 0;
	if ((c == 'd' || c == 'i'))
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putsnbr(va_arg(args, unsigned int));
	else if (c == 'c')
		count += ft_put_char(va_arg(args, int));
	else if (c == 's')
		count += ft_put_str(va_arg(args, char *));
	else if ((c == 'x' || c == 'X'))
		count += ft_put_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_put_hexa(va_arg(args, unsigned long), 'x');
	}
	else
		count += ft_put_char(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += handle(args, format[i]);
		}
		else if (format[i] != '%')
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
