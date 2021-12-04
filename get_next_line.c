/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:02:55 by izail             #+#    #+#             */
/*   Updated: 2021/12/01 12:46:29 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nl_found(char *buff)
{
	int	i;

	i = 0;
	if (!buff || !*buff)
		return (0);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s && !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	temp = ft_substr(s,0,i+1);
	return (temp);
}

char	*ft_read_and_save(int fd, char *rec)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		//buff[ret] = '\0';
		rec = ft_strjoin(rec,buff);
	}
	free(buff);
	return (rec);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*rec;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rec = ft_read_and_save(fd,rec);
	printf("rec : %s",rec);
	if (!rec)
		return (NULL);
	line = ft_get_line(rec);
	return (line);
}
int main ()
{
		int fd = open("temp.txt",  O_RDONLY);
		char *f = get_next_line(fd);
		printf("get : %s",f);
		close(fd);
		return (0);
}