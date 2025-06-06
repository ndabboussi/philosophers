/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <ndabbous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-30 12:48:21 by ndabbous          #+#    #+#             */
/*   Updated: 2025-05-30 12:48:21 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_exit(t_symposium *diner, int code)
{
	if (diner->env)
		free_double_tab(diner->env);
	if (diner->token)
		free_token_list(diner->token);
	rl_clear_history();
	exit(code);
}
