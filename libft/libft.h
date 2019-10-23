/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:41:37 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/14 11:16:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define U_LONG_M 4294967295
# define BUFF_SIZE 1
# define ERR_FD_OPEN -1
# define ERR_FD_READ -2
# define ERR_NOT_IN_CHARSET -3

# include <stdlib.h>
# include "libftprintf.h"

/*
** STRUCTS
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dint
{
	int				*arr;
	int				size;
	int				capacity;
}					t_dint;

typedef struct		s_dfloat
{
	double			*arr;
	int				size;
	int				capacity;
}					t_dfloat;

/*
** FUNCTIONS
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char
		*needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
char				*ft_lutoa(unsigned long n);
int					ft_putchar(int c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*new_node_buf(size_t size);
size_t				ft_strspn(const char *s, const char *charset);
size_t				ft_strcspn(const char*s, const char *charset);
char				*ft_strtok(char *str, const char *sep);
int					ft_lstpushback(t_list **alst, t_list *new);
int					get_next_delim(const int fd, char **line, char delim);
int					ft_printf(const char *format, ...);
int					err_mem(void);
void				ft_tabdel(int **itab);
char				ft_fgetc(const int fd);
char				fgetc_pars(const int fd, const char *charset);
void				init_dint(t_dint *d_arr);
void				change_dint(t_dint *d_arr, int add_size);
void				add_integer_dint(t_dint *d_arr, int nb);
void				add_array_dint(t_dint *d_arr, int *arr_nb, int size);
void				reinit_dint(t_dint *d_arr);
void				init_dfloat(t_dfloat *d_arr);
void				change_dloat(t_dfloat *d_arr, int add_size);
void				add_float_dfloat(t_dfloat *d_arr, double nb);
void				reinit_dfloat(t_dfloat *d_arr);
void				init_dfloat(t_dfloat *d_arr);
double				fpart(double x);
double				rfpart(double x);
void				ft_dswap(double *a, double *b);
void				capitalizer(char *str);
void				ft_swap(int *a, int *b);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

#endif
