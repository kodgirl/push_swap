/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:52:47 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/17 21:18:06 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		++len;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}
