/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:17 by bsaager           #+#    #+#             */
/*   Updated: 2024/03/04 17:48:40 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	format_type(char c, va_list ap);

static int	write_percent(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c != '%')
	{
		i = format_type(c, ap);
		if (i == -1)
			return (-1);
		return (i);
	}
	else
	{
		if (write (1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

static	int	write_str(const char *str, va_list ap, int count)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + write_percent(str[i + 1], ap);
			if (count == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &str[i], 1) != 1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	i = write_str(str, ap, i);
	va_end(ap);
	return (i);
}

static int	format_type(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_hex_pointer(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_hex_lower(va_arg(ap, int)));
	if (c == 'X')
		return (ft_hex_upper(va_arg(ap, int)));
	return (0);
}
