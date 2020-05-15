/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:01:29 by bphofuya          #+#    #+#             */
/*   Updated: 2019/06/06 13:14:43 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t a;
	size_t b;

	b = 0;
	a = 0;
	while (s1[a] != '\0')
		a++;
	while (s2[b] != '\0' && b < n)
	{
		s1[a] = s2[b];
		b++;
		a++;
	}
	s1[a] = '\0';
	return (&*s1);
}
