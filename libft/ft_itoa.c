/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:32:47 by lhafsi            #+#    #+#             */
/*   Updated: 2021/12/10 16:44:16 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intsize(int k)
{
	int			size;
	long int	k2;

	size = 0;
	k2 = k;
	if (k2 == 0)
		size = 1;
	if (k2 < 0)
	{
		k2 = k2 * -1;
		size++;
	}	
	while (k2 > 0)
	{
		k2 = k2 / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int k)
{
	int			i;
	long int	n;
	char		*str;

	n = k;
	i = ft_intsize(k);
	str = malloc((ft_intsize(k) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (k < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[i] = '\0';
	if (k == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i - 1] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
