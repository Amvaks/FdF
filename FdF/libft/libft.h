/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:40:56 by sbart             #+#    #+#             */
/*   Updated: 2022/06/18 16:00:49 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 39
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			ft_atoi(const char *string);
void		ft_bzero(void *memptr, size_t num);
void		*ft_calloc(size_t number, size_t size);
int			ft_isalnum(int a);
int			ft_isalpha(int a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isprint(int a);
char		*ft_itoa(int n);
void		*ft_memchr(const void *memptr, int val, size_t num);
int			ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
void		*ft_memcpy(void *dest, const void *source, size_t num);
void		*ft_memmove(void *dest, const void *source, size_t num);
void		*ft_memset(void *memptr, int val, size_t num);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *source, size_t size);
size_t		ft_strlcpy(char *dest, const char *source, size_t maxlen);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *string1, const char *string2, size_t num);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *string, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int ch);
int			ft_toupper(int ch);

#endif
