/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:51:59 by youngcho          #+#    #+#             */
/*   Updated: 2022/04/07 20:05:44 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			result = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		result = (char *)s + i;
	return (result);
}
