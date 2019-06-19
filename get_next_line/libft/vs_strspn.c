/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:37:22 by vesingh           #+#    #+#             */
/*   Updated: 2019/05/30 09:36:03 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	vs_strspn(const char *s, const char *charset)
{
	size_t	ret;

	ret = 0;
	while (*s && ft_strchr(charset, *s++))
		ret++;
	return (ret);
}
