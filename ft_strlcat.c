/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:04:28 by youngcho          #+#    #+#             */
/*   Updated: 2022/03/22 12:29:16 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	init_len_of_dst;
	size_t	i;

	init_len_of_dst = 0;
	while (dst[init_len_of_dst])
		init_len_of_dst++;
	i = 0;
	if (dstsize == 0 || dstsize < init_len_of_dst)
	{
		while (src[i])
			i++;
		return (dstsize + i);
	}
	while (init_len_of_dst + i + 1 < dstsize && src[i])
	{
		dst[init_len_of_dst + i] = src[i];
		i++;
	}
	dst[init_len_of_dst + i] = '\0';
	while (src[i])
		i++;
	return (init_len_of_dst + i);
}
