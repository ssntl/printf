/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:12:22 by bsaager           #+#    #+#             */
/*   Updated: 2024/03/04 17:35:39 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

// Function prototypes

int				ft_printf(const char *format_str, ...);
int				ft_putchar(int c);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_hex_pointer(void *p);
int				ft_hex_lower(int num);
int				ft_hex_upper(int num);
int				ft_strlen(char *s);
unsigned int	ft_unsigned(unsigned int num);

#endif
