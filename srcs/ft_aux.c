/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:03:32 by jperez            #+#    #+#             */
/*   Updated: 2022/11/26 17:19:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (NULL);
	i = -1;
	while (s1[++i])
		output[i] = s1[i];
	j = 0;
	while (s2[j])
		output[i++] = s2[j++];
	output[i] = '\0';
	return (output);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n % 10 + '0');
}
