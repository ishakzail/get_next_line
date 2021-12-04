/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:02:55 by izail             #+#    #+#             */
/*   Updated: 2021/12/04 18:32:05 by izail            ###   ########.fr       */
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
char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
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

// char	*ft_read_and_save(int fd, char *rec)
// {
// 	char	*buff;
// 	int		ret;

// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	ret = 1;
// 	while (ret != 0 && !ft_nl_found(rec))
// 	{
// 		ret = read(fd, buff, BUFFER_SIZE);
// 		if (ret == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[ret] = '\0';
// 		rec = ft_strjoin(buff,rec);
// 	}
// 	free(buff);
// 	return (rec);
// }
char	*get_next_line(int fd)
{
	char		*line;
	static char	*rec;
	char		*buff;
	int		ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_nl_found(rec))
	{
		printf("buff : %s\n",buff);
		ret = read(fd, buff, BUFFER_SIZE);
		printf("ret : %d\n",ret);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		rec = ft_strjoin(buff,rec);
	}
	free(buff);
	printf("rec :%s\n",rec);
	if (!rec)
		return (NULL);
	line = ft_get_line(rec);
	rec = ft_save(rec);
	return (line);
}
int main ()
{
		int fd = open("file.txt", O_RDONLY);
		//char *f = get_next_line(fd);
		printf("get : %s",get_next_line(fd));
		close(fd);
		return (0);
}
