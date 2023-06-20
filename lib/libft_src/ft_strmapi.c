/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:23:01 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 20:03:57 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	cont;
	char	*result;

	cont = -1;
	if (!s || !f)
		return (NULL);
	result = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[++cont])
	{
		result[cont] = f(cont, s[cont]);
	}
	result[cont] = '\0';
	return (result);
}
