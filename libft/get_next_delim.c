/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <msiesse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:55:32 by msiesse           #+#    #+#             */
/*   Updated: 2019/01/23 19:43:47 by martinsiesse     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

static int		crea_lst(const int fd, t_list **lst)
{
	t_list	*elem;
	char	buf[BUFF_SIZE + 1];
	int		size;
	int		finish;

	finish = 0;
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (fd == 0 && buf[size - 1] == '\n')
			finish = 1;
		buf[size] = 0;
		if (!(elem = ft_lstnew(buf, size + 1)))
		{
			ft_lstdel(lst, &ft_del);
			return (0);
		}
		ft_lstpushback(lst, elem);
		if (size == 0 || (fd == 0 && size < BUFF_SIZE) || finish)
			break ;
	}
	if (size == -1)
		return (0);
	return (1);
}

static int		mem_file(t_list **lst, int fd, char ***mem)
{
	t_list	*head;
	int		len;

	head = *lst;
	len = 0;
	while (*lst)
	{
		len += ft_strlen((*lst)->content);
		*lst = (*lst)->next;
	}
	*lst = head;
	if (!(mem[fd] = (char**)malloc(sizeof(char*) * 2)))
		return (1);
	if (!(mem[fd][0] = ft_strnew(len)))
		return (2);
	mem[fd][1] = mem[fd][0];
	while (*lst)
	{
		mem[fd][0] = ft_strcat(mem[fd][0], (*lst)->content);
		*lst = (*lst)->next;
	}
	*lst = head;
	ft_lstdel(lst, &ft_del);
	return (0);
}

static int		free_mem(char ***mem, int fd)
{
	if (mem[fd])
	{
		if (!(mem[fd][0][0]))
		{
			free(mem[fd][1]);
			free(mem[fd]);
			mem[fd] = NULL;
			return (0);
		}
		return (1);
	}
	return (0);
}

int				get_next_delim(const int fd, char **line, char delim)
{
	static char	**mem[256];
	t_list		*lst;
	int			backd;

	lst = NULL;
	if (fd >= 0)
	{
		if (!(crea_lst(fd, &lst)))
			return (-1);
		if (lst)
		{
			if (mem_file(&lst, fd, mem))
				return (-1);
		}
		if (!(free_mem(mem, fd)))
			return (0);
		backd = ft_strcspn(mem[fd][0], &delim);
		if (!(*line = ft_strnew(backd)))
			return (-1);
		*line = ft_strncpy(*line, mem[fd][0], backd);
		line[0][backd] = 0;
		mem[fd][0] += backd + 1;
		return (1);
	}
	return (-1);
}
