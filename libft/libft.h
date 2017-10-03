/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:23:49 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:24:14 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFSIZE 1024

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_xcoords
{
	char		**coords;
	int			num_coords;
}				t_xcoords;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_putchar(int c);
void			ft_putstr(char *str);
void			*ft_realloc(void *ptr, size_t n);
void			ft_putnbr(int nb);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_getchar_fd(int fd);
int				ft_getchar(void);
int				get_next_line(int fd, char **line);
int				alpha_cmp(char *s1, char *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_ishexa(int c);

unsigned int	ft_hextoi(char *str);

char			*ft_strtok(char *str, char delim);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
char			**ft_listalpha(char **ls);
char			**ft_strsplit(const char *str, char c);

size_t			ft_strlen(const char *str);

t_xcoords		ft_strsplitcount(const char *str, char c);

#endif
