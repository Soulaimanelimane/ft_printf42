/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:12:59 by slimane           #+#    #+#             */
/*   Updated: 2024/11/23 13:08:11 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		len;
	long	n;

	len = 0;
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		len += write(1, "-", 1);
	}
	if (n < 10)
	{
		n = n + 48;
		len += write(1, &n, 1);
	}
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}
