/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:06 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/27 20:03:20 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_swap	*f_lstnew(int num)
{
	t_swap	*new;

	if (!(new = (t_swap *)ft_memalloc(sizeof(t_swap))))
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

int		f_atoi(const char *str, char **error)
{
	int		a;
	int		b;
	size_t	check;

	a = 1;
	b = 0;
	if (*str == 45 && str++)
		a = -a;
	if (*str < 48 || *str > 57)
		*error = ERROR_NOT_INT;
	while (*str >= 48 && *str <= 57)
	{
		check = b;
		b = (*str - 48) + b * 10;
		if (check != b / 10)
		{
			*error = ERROR_BIGGER_INT;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
		*error = ERROR_NOT_INT;
	return (a * b);
}
