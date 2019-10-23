/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:18:13 by msiesse           #+#    #+#             */
/*   Updated: 2019/01/06 16:22:40 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <string.h>

typedef enum		e_type
{
	hh,
	h,
	r,
	l,
	ll,
	L
}					t_type;

typedef struct		s_param
{
	int				flag_min;
	int				flag_plus;
	int				flag_0;
	int				flag_diese;
	int				flag_space;
	int				precis;
	int				width;
	t_type			type;
	char			conv;
	int				size_opt;
	int				percent;
	int				signe;
	int				num;
}					t_param;

t_param				parsor(const char *format, int i, va_list ap);
int					is_flag(char c);
int					is_ok(char c);
int					parsor_flag(const char *format, int i, t_param *params);
int					parsor_precis(const char *format, int i, t_param *params
		, va_list ap);
int					parsor_type(const char *format, int i, t_param *params);
int					parsor_pad(const char *format, int i, t_param *params
		, va_list ap);
int					size_number(long long n, int base);
int					size_u_number(unsigned long long n, int base);
int					len_int(t_param *params, long long num);
void				ft_putchar_params(char c, t_param *params);
long long			ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
void				ft_putstr_params(const char *s, t_param *params);
unsigned long long	ft_pow(unsigned long long a, int power);
void				ft_putnbr_params(int n, t_param *params);
void				ft_putnbr_params_h(short n, t_param *params);
void				ft_putnbr_params_hh(char n, t_param *params);
void				ft_putnbr_params_l(long n, t_param *params);
void				ft_putnbr_params_ll(long long n, t_param *params);
void				ft_gputnbr(void *n, t_param *params);
void				ft_u_putnbr(unsigned int n, int base, char *digit
				, t_param *params);
void				ft_u_putnbr_h(unsigned short n, int base, char *digit
				, t_param *params);
void				ft_u_putnbr_hh(unsigned char n, int base, char *digit
				, t_param *params);
void				ft_u_putnbr_l(unsigned long n, int base, char *digit
				, t_param *params);
void				ft_u_putnbr_ll(unsigned long long n, int base, char *digit
				, t_param *params);
void				ft_u_gputnbr(void *u_n, t_param *params);
void				ft_putfloat(long double x, int precision, int flag_diese
				, t_param *params);
void				print_variable(t_param *params, va_list ap);
int					print_dec(t_param *params, va_list ap);
int					print_u(t_param *params, va_list ap);
int					print_float(t_param *params, va_list ap);
int					print_char(t_param *params, va_list ap);
int					print_string(t_param *params, va_list ap);
void				print_addr(void *addr, t_param *params);

#endif
