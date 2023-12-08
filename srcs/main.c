/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/08 02:35:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automatas.h"

const char *s_states[] =
{
	"INIT",
	"Error",
	"Found Space",
	"Found Symbol",
	"Found Digit",
	NULL
};

int	get_state(int x, int y)
{
	const int	states[][4] = {
//   *  S  +- D
	{1, 2, 3, 4},	//0 INIT
	{1, 1, 1, 1},	//1 ERR
	{1, 2, 3, 4},	//2 Found Space
	{1, 1, 1, 4}, 	//3 Found Symbol
	{1, 2, 1, 4},	//4 Found Digit
	};
	return (states[x][y]);
}

int	choose_state(int state, char c)
{
	int pos = 0;
	int prev = state;
	if (c == ' ')
		pos = 1;
	else if (c == '-' || c == '+')
		pos = 2;
	else if (ft_isdigit(c))
		pos = 3;
	state = get_state(state, pos);
	printf("[%c] -> X: [%d] Y: [%d] -> State: [%d] [%s]\n", c, prev, pos, state, s_states[state]);
	return (state);
}

int	evaluate(const char *str)
{
	int i = 0;
	int	state = 0;

	while (str[i])
	{
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

const char *tests[] =
{
	"1231231",
	"123 123",
	" 123",
	"123 ",
	" 123 ",
	" -123 +123 123 ",
	"--123",
	"123a",
	"-123a",
	" - 1",
	"1 - ",
	"",
	NULL
};

int	main(void)
{
	for (int i = 0; tests[i]; i++)
	{
		printf("Input: [%s]\n", tests[i]);
		int	state = evaluate(tests[i]);

		printf("State: [%d] -> [%s]\n\n", state, s_states[state]);	
	}
	return (0);
}
