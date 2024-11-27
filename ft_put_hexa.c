/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:41:52 by slimane           #+#    #+#             */
/*   Updated: 2024/11/23 12:00:46 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int	ft_put_hexa(unsigned long nb, char x)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_put_hexa(nb / 16, x);
		i += ft_put_hexa(nb % 16, x);
	}
	else
	{
		if (x == 'x')
			i += ft_put_char(base[nb % 16]);
		else if (x == 'X')
			i += ft_put_char(ft_toupper(base[nb % 16]));
	}
	return (i);
}
