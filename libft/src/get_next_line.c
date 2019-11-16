/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <snedir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:29:40 by snedir            #+#    #+#             */
/*   Updated: 2019/11/16 05:44:37 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
# define BUFF_SIZE 10000
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define NEXT control->next
# define STOCK control->stock
# define FD control->fd
# define PREV control->prev
# define MALLNULL(x) if (!x) return (NULL);
# define MALLCHECK(x) if (!x) return (-1);

static char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return ((char *)NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}


static char	*ft_strjoinf(char *s1, char *s2)
{
	int		i;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return ((char *)NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	str = ft_strcpy(str, s1);
	free(s1);
	str = ft_strcat(str, s2);
	return (str);
}

typedef struct		s_buf
{
	struct s_buf	*next;
	struct s_buf	*prev;
	char			*stock;
	int				fd;
}					t_buf;

t_buf				*new(int fd)
{
	t_buf			*control;

	MALLNULL((control = (t_buf*)malloc(sizeof(t_buf))));
	NEXT = NULL;
	PREV = NULL;
	STOCK = NULL;
	FD = fd;
	return (control);
}

t_buf				*add_node(t_buf *elem, int fd)
{
	t_buf			*control;

	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		if (elem->next == NULL)
		{
			while (elem)
			{
				if (elem->fd == fd)
					return (elem);
				if (elem->prev == NULL)
					break ;
				elem = elem->prev;
			}
			break ;
		}
		elem = elem->next;
	}
	control = new(fd);
	NEXT = elem;
	elem->prev = control;
	return (control);
}

int					god_like(char *buf, t_buf *control, char **line, int way)
{
	char			*tmp;
	char			*tmp2;

	if ((tmp = ft_strchr(buf, '\n')) && (way == 1))
	{
		*tmp = '\0';
		*line = ft_strjoin2(STOCK, buf);
		free(STOCK);
		STOCK = ft_strdup(tmp + 1);
		return (1);
	}
	else if ((tmp = ft_strchr(STOCK, '\n')) && (way == 2))
	{
		tmp2 = ft_strdup(tmp + 1);
		*tmp = '\0';
		*line = ft_strdup(STOCK);
		free(STOCK);
		STOCK = ft_strdup(tmp2);
		free(tmp2);
		return (1);
	}
	return (0);
}

int					read_mem(int fd, char *buf, t_buf *control, char **line)
{
	int				ret;

	ret = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (god_like(buf, control, line, 1))
			return (1);
		STOCK = ft_strjoinf(STOCK, buf);
	}
	if (ret == -1)
		return (-1);
	if (STOCK)
	{
		if (*STOCK == '\0')
			return (0);
		*line = ft_strdup(STOCK);
		STOCK = NULL;
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_buf	*control = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (!line)
		return (-1);
	if (control && fd != FD)
		control = add_node(control, fd);
	if (!control)
		control = new(fd);
	if (STOCK)
		if (god_like(buf, control, line, 2))
			return (1);
	ret = read_mem(fd, buf, control, line);
	if (ret == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	else
		return (0);
}
