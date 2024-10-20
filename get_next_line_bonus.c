/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:43 by minpark           #+#    #+#             */
/*   Updated: 2024/10/19 12:51:30 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_more_read(char **backup)
{
	int		i;
	char	*line;
	char	*befreebackup;

	i = ft_strchr2(*backup);
	befreebackup = *backup;
	line = ft_substr(befreebackup, 0, i + 1);
	if (line == NULL)
		return (NULL);
	*backup = ft_strdup(&(*backup)[i + 1]);
	if (*backup == NULL)
		return (NULL);
	free(befreebackup);
	return (line);
}

int	ft_read_file(int fd, char *buffer, char **backup)
{
	int		byte;
	char	*befreebackup;

	byte = 1;
	while (!(ft_strchr2(*backup) != -1) && byte)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (byte);
		buffer[byte] = '\0';
		befreebackup = *backup;
		*backup = ft_strjoin(*backup, buffer);
		if (*backup == NULL)
			return (-1);
		free(befreebackup);
	}
	return (byte);
}

char	*get_line(int fd, char *buffer, char **backup)
{
	int		byte;
	char	*line;

	byte = ft_read_file(fd, buffer, backup);
	if (!**backup || byte == -1)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	if (ft_strchr2(*backup) != -1)
		return (ft_more_read(backup));
	line = ft_strdup(*backup);
	if (line == NULL)
		return (NULL);
	free(*backup);
	*backup = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[1025];
	char		*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1025)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (backup[fd] == NULL)
		backup[fd] = ft_strdup("");
	result = get_line(fd, buffer, &backup[fd]);
	free(buffer);
	return (result);
}
