/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:24:28 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/18 16:57:50 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (!(mem = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(mem, (size + 1));
	return (mem);
}
