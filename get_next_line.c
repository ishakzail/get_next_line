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

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

void	fd_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;	
	}
}

int main ()
{
	int fd = open("temp.txt", O_CREAT | O_WRONLY | O_RDONLY , 0644);
	fd_putstr("hello",fd);
	int ret;
	char buf[1024];

	ret = read(fd, buf, sizeof(buf)-1 );
	if (ret < 0)
	{
		printf("Error in reading ! \n");
		return (0);
	}
	while (ret > 0 )
	{
		buf[ret] = 0x00;
		printf("block read : \n<%s>\n", buf);
	}
	close(fd);
	return (0);
}
