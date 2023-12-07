/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/07 21:20:20 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automatas.h"

const char *s_states[] =
{
	"INIT",
	"Error",
	"Test 0",
	"Test 1",
	NULL
};

const char *dic = " 01";

int	get_state(int x, int y)
{
	const int	states[][4] = {
//   *  0  1 
	{1, 2, 3}, //0 INIT
	{1, 1, 1}, //1 ERR
	{1, 2, 3}, //2 '0'
	{1, 2, 3}  //3 '1'
	};
	printf("X: [%d] Y: [%d] -> State: [%d] [%s]\n", x, y, states[x][y], s_states[x]);
	return (states[x][y]);
}

int	get_index(char c)
{
	int i = 0;

	if (ft_isalpha(c))
		return (0);

	while (dic[i])
	{
		if (dic[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	choose_state(int state, char c)
{
	int pos = 0;

	if (c == '0')
		pos = 1;
	else if (c == '1')
		pos = 2;
	return (get_state(state, pos));
}

int	evaluate(char *str)
{
	int i = 0;
	int	state = 0;

	while (str[i])
	{
		printf("%c -> ", str[i]);
		state = choose_state(state, str[i]);
		i++;
	}
	if (state < 2)
	{
		printf("Error with state: [%d]\n", state);
		return (state);
	}
	return (state);
}

int	main(void)
{
	char	*str = "100011001010";
	int		state = evaluate(str);

	printf("Input: [%s]\n", str);
	printf("State: [%d] -> [%s]\n", state, s_states[state]);
}
