void	get_map(t_tmp *tmp, t_game *game, int fd)
{
	char	*tmp_line;
	int		is_component;
	int		row;

	row = 0;
	is_component = FAIL;
	tmp_line = get_next_line(fd);
	while (tmp_line != NULL)
	{
		if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
		tmp_line[ft_strlen(tmp_line) - 1] = '\0';
		if (is_texture(tmp_line, &tmp->flag) == SUCCESS)
			set_textures(game, tmp_line);
		else if (is_background(tmp_line, &tmp->flag) == SUCCESS)
			set_floor_ceiling(game, tmp_line);
		else if (check_flag(&tmp->flag, COMPONENT_SIZE) == SUCCESS && check_map_content(tmp_line) == SUCCESS)
		{
			set_tmp(tmp, tmp_line, &row);
			is_component = SUCCESS;
		}
		else if (ft_strlen(tmp_line) != 1)
			exit_with_error("Error\nWrong Map Component! 1\n");
		set_next_line(fd, &tmp_line);
	}
	free(tmp_line);
	close(fd);
	if (is_component == FAIL)
		exit_with_error("Error\nWrong Map Component! 2\n");
	get_max_col(tmp);
}