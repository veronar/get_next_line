/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:42:20 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/03 15:02:21 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	vs_strcspn(const char *s, const char *charset)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (ft_strchr(charset, *s))
			return (ret);
		else
		{
			s++;
			ret++;
		}
	}
	return (ret);
}
