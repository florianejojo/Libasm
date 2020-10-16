/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:52:16 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/16 23:15:44 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define test_1 ""
# define test_2 "hey"
# define test_3 "mamie"
# define test_4 "j'ai perdu ma pelotte de laine"

# define STRLEN(x)			printf("Input = '%s' | ft_strlen = %d | strlen = %d\n", x, ft_strlen(x), (int)strlen(x));
# define WRITE(str, x)		printf("Input = '%s' | ft_write = '%s' | write = '%s'\n", str, ft_write(1,str,x), write (1,str,x);

int		ft_strlen(char const *str);
ssize_t	ft_read(int fd, void *buf, int nbyte);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

void	test_read(char *buffer, int x)
{
	int fd;
	int ret;
	int ret_ft;

	ret_ft = ft_read((fd = open("test.txt", O_RDONLY)), buffer, x);
	buffer[ret_ft] = 0;
	printf ("buffer = '%s' | ft_ret = %d\n", buffer, ret_ft);
	close (fd);

	printf("\n--close fd puis open fd again--\n\n");

	ret = read((fd = open("test.txt", O_RDONLY)), buffer, x);
	buffer[ret] = 0;
	printf ("buffer = '%s' | ret = %d\n", buffer, ret);
	close (fd);
}

int		main(void)
{
	int i;
	char	buffer[100];


	while (i < 100)
		buffer[i++] = 0;

	printf("-> ft_strlen.s\n");	
	STRLEN(test_1);
	STRLEN(test_2);
	STRLEN(test_3);
	STRLEN(test_4);
	printf("\n\n");

	printf("-> ft_read.s\n");	
	test_read(buffer, 1);
	test_read(buffer, 5);
	test_read(buffer, 10);
	test_read(buffer, 50);

	WRITE(test_1, 1);
	WRITE(test_2, 5);
	WRITE(test_3, 10);
	WRITE(test_4, 50);
	printf("\n\n");


	
	return (0);
}
