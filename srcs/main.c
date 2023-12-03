/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/03 01:44:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automatas.h"

const int	states[][4] = {
//   ª  0  1 \0  
	{2, 2, 3, 1}, //Empty
	{1, 2, 3, 1}, //Error
	{2, 2, 3, 1}, // 0
	{3, 2, 3, 1}  // 1
};

const char *dic = "-01";

int	get_index(char c)
{
	int i = 0;

	while (dic[i])
	{
		if (dic[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	evaluate(char *str)
{
	int i = 0;
	int	res = 0;

	while (str[i])
	{
		res = states[get_index(str[i])][str[i] - 48];
		printf("state: [%d]\n", res);
		i++;
	}
	if (res < 2)
	{
		printf("Error with state: [%d]\n", res);
		return (res);
	}
	return (res);
}

int	main(void)
{
	char	*str = "1111000011110101010";

	printf("Input: [%s]\n", str);
	printf("State: [%d]\n", evaluate(str));
}
