#include "header/cub3d.h"
#include <stdio.h>
#include <string.h>

void fill_map(t_tmp *tmp)
{
    t_node *node;

    node = tmp->head->next;
    while (node != tmp->tail)
    {
        if (node->col < tmp->max_col)
            while ((int)ft_strlen(node->line) < tmp->max_col)
                node->line = ft_strjoin(node->line, " ");
        node = node->next;
    }
}

void get_max_col(t_tmp *tmp)
{
    int max;
    t_node *node;
    
    node = tmp->head->next;
    max = 0;
    while (node != tmp->tail)
    {
        if (node->col > max)
            max = node->col;
        node = node->next;
    }
    tmp->max_col = max;
}

void get_map(t_tmp *tmp, t_game *game, int fd) {
    char	*tmp_line;
	int		count;
    int row;

    row = 0;
    count = 0;
	tmp_line = get_next_line(fd);
	while (tmp_line != NULL)
	{
        if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
                tmp_line[ft_strlen(tmp_line) - 1] = '\0';
        if (count < 4)
            set_textures(game, tmp_line);
        else if (count == 5 || count == 6)
            set_floor_ceiling(game, tmp_line);
        else if (count > 7)
        {
            ft_lstadd_back(tmp, tmp_line, ft_strlen(tmp_line));    
            tmp->row = ++row;
        }       
        free(tmp_line);
        tmp_line = get_next_line(fd);
        count++;
	}    
    // for (int i = 0; i < 4; i++) {
    //     printf("i = %d\n", game->image[i].img_ptr);
    // }
    // printf("=========================\n");
	free(tmp_line);
	close(fd);
    get_max_col(tmp);
}

int open_map(const char *file) {
    int fd;
    size_t  len;

    /* 확장자가 .cub인지 확인하는 코드 넣을 것 => 하드코딩으로 해결하자 걍... */
    len = ft_strlen(file);
    if (len <= 4)
        return (FAIL);
    if (file[len - 1] != 'b' || file[len - 2] != 'u')
        return (FAIL);
    if (file[len - 3] != 'c' || file[len - 4] != '.')
        return (FAIL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (FAIL);
    /* 파일을 성공적으로 읽을 경우 일반적으로 fd는 3 이상의 수를 반환할 것이므로 */
    /* 읽기에 실패했을 때 FAIL값(0)을 반환해도 문제가 없을거라 생각함 */
    return fd;
}
