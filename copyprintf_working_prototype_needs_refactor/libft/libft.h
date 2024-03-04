/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:31:57 by bsaager           #+#    #+#             */
/*   Updated: 2024/02/20 23:33:48 by bsaager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: check first lines and endif at bottom
// add headers where?

#ifndef libft_h
#define libft_h // case sensitive and neccessary?

#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		ft_memcpy(void *b, int c, size_t len);
void		ft_memmove(void *b, int c, size_t len);
void		ft_strlcpy(void *b, int c, size_t len);
void		ft_strlcat(void *b, int c, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			*ft_strchr(const char *s, int c);
int			*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *str);

// malloc functions:
void *calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *str);

// not in libc

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
