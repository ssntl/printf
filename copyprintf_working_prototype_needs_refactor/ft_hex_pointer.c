/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:25 by bsaager           #+#    #+#             */
/*   Updated: 2024/02/24 19:43:56 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_pointer(char *base, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(base);
	if (n >= b)
	{
		c = hex_pointer(base, n / b, c);
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

int	ft_hex_pointer(void *p)
{
	unsigned long long	pointer;
	int					i;

	i = 0;
	pointer = (unsigned long long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	i = hex_pointer("0123456789abcdef", pointer, i);
	if (i == -1)
		return (-1);
	i += 2;
	return (i);
}
