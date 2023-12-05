/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/06 00:16:28 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automatas.h"

const char *s_states[] =
{
	"Empty",
	"Error",
	"Test 0",
	"Test 1",
	NULL
};

const char *dic = "01";

int	get_state(int x, int y)
{
	const int	states[][4] = {
//   0  1 \0  
	{2, 2, 3, 1}, //Empty
	{1, 2, 3, 1}, //Error
	{2, 2, 3, 1}, //0
	{3, 2, 3, 1}  //1
	};
	return (states[x][y]);
}

int	get_index(char c)
{
	int i = 0;

	while (dic[i])
	{
		if (dic[i] == c)
			return (i+1);
		i++;
	}
	return (0);
}

int get_number(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	return (c);
}

int	evaluate(char *str)
{
	int i = 0;
	int	res = 0;

	while (str[i])
	{
		res = get_state(get_index(str[i]), str[i] - 48);
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
	char	*str = "1a0001";
	int		state = evaluate(str);

	printf("Input: [%s]\n", str);
	printf("State: [%d] -> [%s]\n", state, s_states[state]);
}
