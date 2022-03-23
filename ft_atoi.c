/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:11:22 by youngcho          #+#    #+#             */
/*   Updated: 2022/03/23 17:11:50 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*pass_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return ((char *)str + i);
}

int	check_sign(char **str_p)
{
	if (**str_p == '-')
	{
		(*str_p)++;
		return (-1);
	}
	else if (**str_p == '+')
		(*str_p)++;
	return (1);
}

int	convert_to_int(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	char	*tmp_str;
	int		sign;

	tmp_str = pass_space(str);
	sign = check_sign(&tmp_str);
	return (sign * convert_to_int(tmp_str));
}
