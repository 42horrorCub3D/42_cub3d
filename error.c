#include "header/cub3d.h"
#include <stdio.h>
#include <string.h>

void exit_with_error(const char *msg) {
    write(1, msg, ft_strlen(msg));
    exit(FAIL);
}