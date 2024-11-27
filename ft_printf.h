/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:52:54 by slimane           #+#    #+#             */
/*   Updated: 2024/11/23 11:57:37 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_str(const char *str);
int	ft_putnbr(int nbr);
int	ft_put_hexa(unsigned long nb, char x);
int	ft_put_char(char c);
int	ft_putsnbr(unsigned int nbr);

#endif
