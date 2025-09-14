/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:34:16 by jotong            #+#    #+#             */
/*   Updated: 2025/09/13 22:37:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int	ft_echo(char **argv, t_shell **shell);
int	ft_cd(char **argv, t_shell **shell);
int	ft_pwd(char **argv, t_shell **shell);
int	ft_env(char **argv, t_shell **shell);
int	ft_exit(char **argv, t_shell **shell);

int	try_builtin(char **argv, t_shell **shell);

#endif