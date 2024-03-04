/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:02 by bsaager           #+#    #+#             */
/*   Updated: 2024/02/24 19:19:51 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex_long(char *base, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(base);
	if (n >= b)
	{
		c = puthex_long(base, n / b, c);
		if (c == -1)
			return (-1);
		if (write (1, &base[n % b], 1) == -1)
			return (-1);
		c++;
	}
	else if (n < b)
	{
		if (write (1, &base[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

static int	ft_unsigned(char *base, unsigned int n, int c)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (n >= b)
	{
		c = ft_unsigned(base, n / b, c);
		if (c == -1)
			return (-1);
		if (write (1, &base[n % b], 1) == -1)
			return (-1);
		c++;
	}
	else if (n < b)
	{
		if (write (1, &base[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_hex_upper(int n)
{
	int		i;

	i = 0;
	if (n >= 0)
		i = puthex_long("0123456789ABCDEF", n, i);
	else if (n < 0)
		i = ft_unsigned("0123456789ABCDEF", n, i);
	return (i);
}
