/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:16:03 by mavicent          #+#    #+#             */
/*   Updated: 2022/11/15 20:03:38 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont;
	size_t	j;
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (NULL);
	cont = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_str == NULL)
		return (NULL);
	while (j < len_s1)
		new_str[cont++] = s1[j++];
	j = 0;
	while (j < len_s2)
		new_str[cont++] = s2[j++];
	new_str[cont] = '\0';
	return (new_str);
}
