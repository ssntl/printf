/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:30:22 by bsaager           #+#    #+#             */
/*   Updated: 2023/12/19 10:08:27 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
       isalpha()
              checks  for an alphabetic character; in the standard "C" locale,
              it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
              cales, there may be additional characters for which isalpha() is
              true—letters which are neither uppercase nor lowercase.
*/

#include "libft.h"

int ft_isalpha (int c)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                return (1);
        else
            return (0);
    }

/*
#include <stdio.h>

int main (void)
{
    printf("%d", ft_isalpha (97));
}
*/
