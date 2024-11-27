/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:44:44 by slimane           #+#    #+#             */
/*   Updated: 2024/11/23 13:08:47 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsnbr(unsigned int nbr)
{
	int		len;

	len = 0;
	if (nbr < 10)
	{
		nbr += 48;
		len += write(1, &nbr, 1);
	}
	else
	{
		len += ft_putsnbr(nbr / 10);
		len += ft_putsnbr(nbr % 10);
	}
	return (len);
}
