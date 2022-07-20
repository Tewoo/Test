/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:15:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/20 11:14:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push-swap.h"

int main(int argc, char **argv)
{
	
	if (argc == 1)
		return(printf("aucun arguement."));
	sortarray(argc, argv);

	return (0);
}

