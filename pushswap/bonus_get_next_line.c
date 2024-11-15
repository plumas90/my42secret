/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:43 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:07:02 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"
#include "bonus_main_pushswap.h"

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
		byte = read(fd, buffer, 42);
		if (byte == -1)
			return (byte);
		buffer[byte] = '\0';
		befreebackup = *backup;
		*backup = ft_strjoin(*backup, buffer);
		free(befreebackup);
		if (*backup == NULL)
			return (-1);
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
	static char	*backup;
	char		*buffer;
	char		*result;

	if (fd < 0 || 42 <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * 42 + 1);
	if (buffer == NULL)
		return (NULL);
	if (backup == NULL)
		backup = ft_strdup("");
	result = get_line(fd, buffer, &backup);
	free(buffer);
	return (result);
}
