/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:37:12 by bsaager           #+#    #+#             */
/*   Updated: 2023/12/19 10:08:27 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit (int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_isdigit(48));
}
