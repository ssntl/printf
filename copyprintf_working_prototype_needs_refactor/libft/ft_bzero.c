/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:29:18 by bsaager           #+#    #+#             */
/*   Updated: 2023/12/19 10:08:27 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
	void *s: A pointer to the memory area where zeroing will occur.
	0: The value to be set (in this case, 0 represents the null byte or zero-value byte).
    size_t n: The number of bytes to set to zero, starting from the address s.
*/
