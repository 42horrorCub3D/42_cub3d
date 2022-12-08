#include "header/cub3d.h"
#include <stdio.h>
#include <string.h>

int check_top_bottom(char *line)
{
    size_t  index;

    index = -1;
    while (line[++index] != '\0')
        if (line[index] != ' ' && line[index] != '1')
            return (FAIL);
    return (SUCCESS);
}

int check_side(char *line)
{
    if (line[0] == '0' || line[ft_strlen(line) - 1] == '0')
        return (FAIL);
    return (SUCCESS);
}

int check_middle(t_node *node)
{
    size_t  index;
    index = 1;
    if (check_side(node->line))
        return (FAIL);
    while (index != ft_strlen(node->line))
    {
        if ((int)index >= node->prev->col)
            if (node->line[index] == '0')
                return (FAIL);
        if (node->line[index] == '0' && node->prev->line[index] == ' ')
            return (FAIL);
        else if (node->line[index] == ' ')
            if (node->prev->line[index] == '0' || \
            node->line[index - 1] == '0' || node->line[index + 1] == '0')
                return (FAIL);
        index++;   
    }
    return (SUCCESS);
}

int check_map(t_tmp *tmp)
{
    t_node  *node;

    node = tmp->head->next;
    if (check_top_bottom(node->line))
        return (FAIL);
    while (node != tmp->tail)
    {
        if (node == tmp->head->next || node == tmp->head->prev)
            if (check_top_bottom(node->line))
                return (FAIL);
        if (check_middle(node))
            return (FAIL);
        node = node->next;
    }
    return (SUCCESS);
}
