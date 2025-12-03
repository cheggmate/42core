/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:07:01 by jotong            #+#    #+#             */
/*   Updated: 2025/12/03 23:10:23 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "minishell.h"
#include "libft.h"

char *handle_asterisk(char *substr)
{
    DIR *dir;
    struct dirent *entry;
    char *result;
    int count;

    result = NULL;
    count = 0;
    if (!ft_strnstr(substr, "*", ft_strlen(substr)))
        return ft_strdup(substr); // no wildcard
    dir = opendir(".");
    if (!dir)
        return ft_strdup(substr);
    while ((entry = readdir(dir)))
    {
        if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
        {
            if (ft_strcmp(substr, ".") != 0 && ft_strcmp(substr, ".." != 0))
                continue;
        }
        if (wildcard_match(substr, entry->d_name))
        {
            if (count > 0)
            {
                char *tmp = result;
                result = ft_strjoin(result, " ");
                free(tmp);
            }
            char *tmp = result;
            result = ft_strjoin(result, entry->d_name);
            free(tmp);
            count++;
        }
    }
    closedir(dir);
    printf("resultttt: %s\n", result);
    if (!result) // no match
        return (substr); // return ft_strdup(substr);
    return (result);
}

