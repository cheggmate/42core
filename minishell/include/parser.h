/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:15:56 by jotong            #+#    #+#             */
/*   Updated: 2025/09/13 22:26:36 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_token t_token;

typedef	enum	e_node_type
{
	N_CMD,
	N_PIPE,
	N_REDIR
}	t_node_type;

typedef struct s_ast
{
	t_node_type		type;
	char			**argv;
	char			*filename;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

t_ast	*parse_token(t_token *tokens);
void	free_ast(t_ast *root);

#endif