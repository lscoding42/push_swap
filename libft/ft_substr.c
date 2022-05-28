/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:03:07 by lhafsi            #+#    #+#             */
/*   Updated: 2021/12/20 12:15:17 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= (unsigned long int)ft_strlen(s))
		return (ft_strdup(""));
	if (len + start >= (unsigned long int)ft_strlen(s))
		sub = malloc (sizeof (*sub) * (ft_strlen(s) - start + 1));
	else
		sub = malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
			sub[i++] = s[j];
		j++;
	}
	sub[i] = 0;
	return (sub);
}
