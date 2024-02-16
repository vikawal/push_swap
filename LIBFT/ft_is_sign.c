/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:44:16 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 16:44:24 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "libft.h"
#include <stdint.h>

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_digit_sign(char **str, int i)
{
	int	j;

	j = 0;
	if (ft_is_sign(str[i][j]))
		j++;
	while (str[i][j])
	{
		if (!ft_isdigit(str[i][j]))
			return (0);
		j++;
	}
	return (1);
}

int	ft_iabs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
