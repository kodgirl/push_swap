/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:06 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/20 18:17:50 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	ft_memdel(void **ap)
{
	if (!(*ap))
		return ;
	free(*ap);
	*ap = NULL;
}

void	*ft_memalloc(size_t size)
{
	void	*ar;
	size_t	i;

	i = 0;
	if (size && (ar = (void*)malloc(sizeof(void) * size)))
		ft_bzero(ar, size);
	else
		return (NULL);
	return (ar);
}

t_swap	*ft_lstnew(int num)
{
	t_swap	*new;

	if (!(new = (t_swap *)ft_memalloc(sizeof(t_swap))))
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);	
}

int		ft_atoi(const char *str, char **error)
{
	int					a;
	unsigned long int	b;
	size_t				check;

	a = 1;
	b = 0;
	// while ((*str >= 9 && *str <= 13) || *str == 32)
	// 	str++;
	if (*str == 45)
	{
		a = -a;
		str++;
	}
	else if (*str == 43)
		str++;
	if (*str < 48 || *str > 57)
		*error = ERROR_NOT_INT;
	while (*str >= 48 && *str <= 57)
	{
		check = b;
		b = (*str - 48) + b * 10;
		if (check != b / 10)
			return (a == 1 ? -1 : 0);
		str++;
	}
	if (*str != '\0')
		*error = ERROR_NOT_INT;
	if ((a == 1 && b > 2147483647) || (a == -1 && b > 2147483648))
		*error = ERROR_BIGGER_INT;
	return (a * b);
}
