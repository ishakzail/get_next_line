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

static int	ft_nl_found(char *buff)
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
static char	*ft_get_line(char *s)
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
char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*rec;
	int			ret;

	ret = 1;
	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE - 1);
	printf("ret = %d\n", ret);
	if (ret <= 0)
		return (NULL);
	line = ft_get_line(buff);
	rec = ft_strjoin(rec,line);
	printf("record : %s\n", rec);
	return (line);
}

int main ()
{
		int fd = open("temp.txt",  O_RDONLY);
		char *f = get_next_line(fd);
		printf("%s",f);
		printf("%d", BUFFER_SIZE);
		close(fd);
		return (0);
}