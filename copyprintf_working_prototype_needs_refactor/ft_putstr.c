/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:37 by bsaager           #+#    #+#             */
/*   Updated: 2024/02/24 19:51:21 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (c[i])
	{
		if (write(1, &c[i], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}
