/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:41 by ldevoude          #+#    #+#             */
/*   Updated: 2024/12/11 09:06:20 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*convert(long n, char *result, int length)
{
	result[length] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n > 0)
	{
		result[--length] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

static char	*count_for_malloc(long integer, int is_negative, int *length)

{
	char	*result;

	if (is_negative || integer == 0)
		(*length)++;
	while (integer > 0)
	{
		integer /= 10;
		(*length)++;
	}
	result = malloc((*length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	long	ln;
	int		length;

	is_negative = 0;
	length = 0;
	result = NULL;
	ln = n;
	if (ln < 0)
	{
		is_negative = 1;
		ln *= -1;
	}
	result = count_for_malloc(ln, is_negative, &length);
	if (!result)
		return (NULL);
	result = convert(ln, result, length);
	return (result);
}

/*
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int		n;
	char	*ptr;

	n = 0;
	ptr = ft_itoa(n);
	printf("FINAL : %s", ptr);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	char	*buff;
	long	ln;

	i = 0;
	ln = n;
	if (n == 0)
	{
		result = ft_strdup("0");
		if (!result)
			return (NULL);
		return (result);
	}
	buff = count_for_malloc(&ln, &i);
	if (!buff)
		return (NULL);
	result = count_for_malloc(&ln, &i);
	if (!result)
		return (free(buff), NULL);
	result = convert(ln, i, result, buff);
	if (!result)
		return (free(buff), NULL);
	return (free(buff), result);
}*/
