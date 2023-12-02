/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/02 21:37:05 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automatas.h"

const int	*states[] = {
//   ª  0  1 \0  
	{0, 2, 3, 1}, //Empty
	{1, 2, 3, 1}, //Error
	{2, 2, 3, 1}, // 0
	{3, 2, 3, 1}  // 1
};

int	evaluate(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((state = ) < 2)
		{
			printf("Invalid char: [%c]\n", str[i]);
			return (0);
		}
	}
}

int	main(void)
{
	char	*str = "1010101010101001010111101010100111";
	printf("Input: [%s]\n", str);
}
