/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:54 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/13 14:50:37 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	digitcheck(char *sp_inp, int *intarr)
{
	int	j;

	j = 0;
	if (sp_inp[j] == '-' || sp_inp[j] == '+')
		j++;
	if (!sp_inp[j])
		return (free (intarr), 0);
	while (sp_inp[j])
	{
		if (!ft_isdigit(sp_inp[j]))
			return (free (intarr), 0);
		else
			j++;
	}
	return (1);
}

static int	dupcheck(int *intarr, char **sp_inp, int i)
{
	if (!i)
		intarr[i] = ft_atoi(sp_inp[i], intarr, sp_inp);
	else
	{
		if (!checker(intarr, ft_atoi(sp_inp[i], intarr, sp_inp), i))
			intarr[i] = ft_atoi(sp_inp[i], intarr, sp_inp);
		else
			return (free (intarr), 0);
	}
	return (1);
}

int	*parser(char **sp_inp, int numbercount, int *list_size)
{
	int	i;
	int	*intarr;

	i = 0;
	intarr = malloc(sizeof(int) * numbercount);
	if (!intarr)
		return (freeing(sp_inp), NULL);
	while (i < numbercount)
	{
		if (digitcheck(sp_inp[i], intarr))
		{
			if (!dupcheck(intarr, sp_inp, i))
				return (freeing(sp_inp), NULL);
			else
				*list_size += 1;
		}
		else
			return (freeing(sp_inp), NULL);
		i++;
	}
	freeing(sp_inp);
	return (intarr);
}
